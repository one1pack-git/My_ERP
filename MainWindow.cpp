#include "MainWindow.h"
#include "OrderWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), orderWindow(nullptr) {
    setWindowTitle("ERP 시스템");
    resize(800, 600);

    // 메뉴바 생성
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // "파일" 메뉴 추가
    QMenu *fileMenu = menuBar->addMenu("파일");
    QAction *exitAction = new QAction("종료", this);
    fileMenu->addAction(exitAction);
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    // "관리" 메뉴 추가
    QMenu *manageMenu = menuBar->addMenu("관리");
    QAction *orderAction = new QAction("발주 관리", this);
    manageMenu->addAction(orderAction);

    // 발주 관리 창 열기
    connect(orderAction, &QAction::triggered, this, [this]() {
        if (!orderWindow) {
            orderWindow = new OrderWindow(this);
        }
        orderWindow->show();
    });
}

MainWindow::~MainWindow() {
    delete orderWindow;
}
