#include <QApplication>
#include "MainWindow.h"
#include "DatabaseManager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 데이터베이스 열기 (명시적으로 호출)
    DatabaseManager& dbManager = DatabaseManager::getInstance();
    if (!dbManager.openDatabase("erp_database.db")) {
        qDebug() << "❌ 프로그램을 종료합니다 (DB 연결 실패)";
        return -1;  // 데이터베이스가 열리지 않으면 프로그램 종료
    }

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
