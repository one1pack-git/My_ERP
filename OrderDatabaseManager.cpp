#include "OrderDatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

OrderDatabaseManager::OrderDatabaseManager(QSqlDatabase &database)
    : db(database)
{
}

bool OrderDatabaseManager::createOrderTable() {
    QSqlQuery query(db);
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

bool OrderDatabaseManager::insertOrder(const QString& productName, int quantity) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO Orders (productName, quantity) VALUES (:productName, :quantity)");
    query.bindValue(":productName", productName);
    query.bindValue(":quantity", quantity);
    if (!query.exec()) {
        qDebug() << "Failed to insert order:" << query.lastError().text();
        return false;
    }
    qDebug() << "Order added successfully!";
    return true;
}

QVector<Order> OrderDatabaseManager::fetchOrders() {
    QVector<Order> orders;
    QSqlQuery query(db);
    query.exec("SELECT * FROM Orders");
    while (query.next()) {
        Order order;
        order.id = query.value("id").toInt();
        order.productName = query.value("productName").toString();
        order.quantity = query.value("quantity").toInt();
        orders.append(order);
    }
    return orders;
}
