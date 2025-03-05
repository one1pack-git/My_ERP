#include "ClientDatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ClientDatabaseManager::ClientDatabaseManager(QSqlDatabase &database)
    : db(database)
{
}

bool ClientDatabaseManager::createClientTable() {
    QSqlQuery query(db);
    QString createClientsTable = R"(
        CREATE TABLE IF NOT EXISTS Clients (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            companyName TEXT NOT NULL,
            businessNumber TEXT NOT NULL,
            ceoName TEXT NOT NULL,
            businessCategory TEXT,
            industry TEXT,
            address TEXT,
            email TEXT,
            phone TEXT,
            fax TEXT,
            accountNumber TEXT
        )
    )";
    if (!query.exec(createClientsTable)) {
        qDebug() << "Failed to create Clients table:" << query.lastError().text();
        return false;
    }
    qDebug() << "Clients table is ready!";
    return true;
}

bool ClientDatabaseManager::insertClient(const QString &companyName,
                                           const QString &businessNumber,
                                           const QString &ceoName,
                                           const QString &businessCategory,
                                           const QString &industry,
                                           const QString &address,
                                           const QString &email,
                                           const QString &phone,
                                           const QString &fax,
                                           const QString &accountNumber)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO Clients (companyName, businessNumber, ceoName, businessCategory, industry, address, email, phone, fax, accountNumber) "
                  "VALUES (:companyName, :businessNumber, :ceoName, :businessCategory, :industry, :address, :email, :phone, :fax, :accountNumber)");
    query.bindValue(":companyName", companyName);
    query.bindValue(":businessNumber", businessNumber);
    query.bindValue(":ceoName", ceoName);
    query.bindValue(":businessCategory", businessCategory);
    query.bindValue(":industry", industry);
    query.bindValue(":address", address);
    query.bindValue(":email", email);
    query.bindValue(":phone", phone);
    query.bindValue(":fax", fax);
    query.bindValue(":accountNumber", accountNumber);
    if (!query.exec()) {
        qDebug() << "Failed to insert client:" << query.lastError().text();
        return false;
    }
    qDebug() << "Client inserted successfully!";
    return true;
}

QVector<Client> ClientDatabaseManager::fetchClients() {
    QVector<Client> clients;
    QSqlQuery query(db);
    query.exec("SELECT * FROM Clients");
    while (query.next()) {
        Client client;
        client.id = query.value("id").toInt();
        client.companyName = query.value("companyName").toString();
        client.businessNumber = query.value("businessNumber").toString();
        client.ceoName = query.value("ceoName").toString();
        client.businessCategory = query.value("businessCategory").toString();
        client.industry = query.value("industry").toString();
        client.address = query.value("address").toString();
        client.email = query.value("email").toString();
        client.phone = query.value("phone").toString();
        client.fax = query.value("fax").toString();
        client.accountNumber = query.value("accountNumber").toString();
        clients.append(client);
    }
    return clients;
}
