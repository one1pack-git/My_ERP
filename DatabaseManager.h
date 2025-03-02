#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QVector>

struct Order {
    int id;
    QString productName;
    int quantity;
};

class DatabaseManager {
public:
    static DatabaseManager& getInstance();
    bool openDatabase(const QString& dbName);
    void closeDatabase();

    bool insertOrder(const QString& productName, int quantity);
    QVector<Order> fetchOrders();  // 저장된 발주 목록 불러오기

private:
    DatabaseManager();
    ~DatabaseManager();
    bool createTables();
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
