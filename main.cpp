#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void testDatabase() {
    // SQLite 데이터베이스 연결
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");  // 로컬 파일 기반 SQLite 데이터베이스

    if (!db.open()) {
        qDebug() << "데이터베이스 연결 실패:" << db.lastError().text();
        return;
    }
    qDebug() << "데이터베이스 연결 성공";

    QSqlQuery query;

    // 테이블 생성
    if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER)")) {
        qDebug() << "테이블 생성 실패:" << query.lastError().text();
        return;
    }
    qDebug() << "테이블 생성 완료";

    // 데이터 삽입
    if (!query.exec("INSERT INTO users (name, age) VALUES ('Alice', 25), ('Bob', 30), ('Charlie', 22)")) {
        qDebug() << "데이터 삽입 실패:" << query.lastError().text();
        return;
    }
    qDebug() << "데이터 삽입 완료";

    // 데이터 조회
    if (!query.exec("SELECT id, name, age FROM users")) {
        qDebug() << "데이터 조회 실패:" << query.lastError().text();
        return;
    }

    qDebug() << "테이블 데이터:";
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "ID:" << id << ", 이름:" << name << ", 나이:" << age;
    }

    db.close();
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    testDatabase();
    return app.exec();
}
