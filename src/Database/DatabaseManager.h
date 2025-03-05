#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include "OrderDatabaseManager.h"
#include "ClientDatabaseManager.h"

class DatabaseManager {
public:
    static DatabaseManager& getInstance();
    bool openDatabase(const QString& dbName);
    void closeDatabase();

    OrderDatabaseManager* getOrderManager();
    ClientDatabaseManager* getClientManager();

private:
    DatabaseManager();
    ~DatabaseManager();
    bool createTables();  // 하위 모듈의 테이블 생성 호출

    QSqlDatabase db;
    OrderDatabaseManager* orderManager;
    ClientDatabaseManager* clientManager;
};

#endif // DATABASEMANAGER_H
