#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

DatabaseManager& DatabaseManager::getInstance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::openDatabase(const QString& dbName) {
    db.setDatabaseName(dbName);

    if (!db.open()) {
        qDebug() << "❌ Database connection failed! Error:" << db.lastError().text();
        return false;
    }

    qDebug() << "✅ Database connected successfully!";
    return createTables();
}

bool DatabaseManager::createTables() {
    QSqlQuery query;
    QString createOrderTable = R"(
        CREATE TABLE IF NOT EXISTS Orders (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            productName TEXT NOT NULL,
            quantity INTEGER NOT NULL
        )
    )";

    if (!query.exec(createOrderTable)) {
        qDebug() << "Failed to create Orders table:" << query.lastError().text();
        return false;
    }

    qDebug() << "Orders table is ready!";
    return true;
}

bool DatabaseManager::insertOrder(const QString& productName, int quantity) {
    if (!db.isOpen()) {  // 데이터베이스가 닫혀있다면 오류 출력
        qDebug() << "❌ insertOrder 실패: 데이터베이스가 열려 있지 않음!";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Orders (productName, quantity) VALUES (:productName, :quantity)");
    query.bindValue(":productName", productName);
    query.bindValue(":quantity", quantity);

    if (!query.exec()) {
        qDebug() << "❌ Failed to insert order: " << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Order added successfully!";
    return true;
}

QVector<Order> DatabaseManager::fetchOrders() {
    QVector<Order> orders;
    QSqlQuery query("SELECT * FROM Orders");

    while (query.next()) {
        Order order;
        order.id = query.value("id").toInt();
        order.productName = query.value("productName").toString();
        order.quantity = query.value("quantity").toInt();
        orders.append(order);
    }

    return orders;
}

