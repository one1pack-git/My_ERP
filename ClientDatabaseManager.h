#ifndef CLIENTDATABASEMANAGER_H
#define CLIENTDATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QVector>

struct Client {
    int id;
    QString companyName;
    QString businessNumber;
    QString ceoName;
    QString businessCategory;
    QString industry;
    QString address;
    QString email;
    QString phone;
    QString fax;
    QString accountNumber;
};

class ClientDatabaseManager {
public:
    explicit ClientDatabaseManager(QSqlDatabase& db);
    bool createClientTable();
    bool insertClient(const QString &companyName,
                      const QString &businessNumber,
                      const QString &ceoName,
                      const QString &businessCategory,
                      const QString &industry,
                      const QString &address,
                      const QString &email,
                      const QString &phone,
                      const QString &fax,
                      const QString &accountNumber);
    QVector<Client> fetchClients();

private:
    QSqlDatabase& db;
};

#endif // CLIENTDATABASEMANAGER_H
