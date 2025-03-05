#include "./DatabaseManager.h"

#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager()
    : db(QSqlDatabase::addDatabase("QSQLITE")),
      orderManager(nullptr),
      clientManager(nullptr)
{
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
    delete orderManager;
    delete clientManager;
}

DatabaseManager& DatabaseManager::getInstance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::openDatabase(const QString& dbName) {
    db.setDatabaseName(dbName);
    if (!db.open()) {
        qDebug() << "❌ Database connection failed:" << db.lastError().text();
        return false;
    }
    qDebug() << "✅ Database connected successfully!";
    
    // 각 매니저 생성 및 테이블 생성
    orderManager = new OrderDatabaseManager(db);
    clientManager = new ClientDatabaseManager(db);
    return createTables();
}

bool DatabaseManager::createTables() {
    if (!orderManager->createOrderTable()) return false;
    if (!clientManager->createClientTable()) return false;
    return true;
}

void DatabaseManager::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

OrderDatabaseManager* DatabaseManager::getOrderManager() {
    return orderManager;
}

ClientDatabaseManager* DatabaseManager::getClientManager() {
    return clientManager;
}
