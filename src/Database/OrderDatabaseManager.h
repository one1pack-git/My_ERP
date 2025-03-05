#ifndef ORDERDATABASEMANAGER_H
#define ORDERDATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QVector>

struct Order {
    int id;
    QString productName;
    int quantity;
};

class OrderDatabaseManager {
public:
    explicit OrderDatabaseManager(QSqlDatabase& db);
    bool createOrderTable();
    bool insertOrder(const QString& productName, int quantity);
    QVector<Order> fetchOrders();

private:
    QSqlDatabase& db;
};

#endif // ORDERDATABASEMANAGER_H
