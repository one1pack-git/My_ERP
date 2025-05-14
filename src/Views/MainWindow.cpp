#include "./MainWindow.h"
#include "./ClientWindow.h"
#include "./OrderWindow.h"
#include "./FabricInventoryWindow.h"
#include "./WoodInventoryWindow.h"
#include "./AngleInventoryWindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : 
    QMainWindow(parent),
    orderWindow(nullptr),
    clientWindow(nullptr),
    fabricInventoryWindow(nullptr),
    woodInventoryWindow(nullptr),
    angleInventoryWindow(nullptr)
{
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
    QAction *clientAction = new QAction("거래처 관리", this);
    manageMenu->addAction(orderAction);
    manageMenu->addAction(clientAction);

    // "재고 관리" 메뉴 추가
    QMenu *inventoryMenu = menuBar->addMenu("재고 관리");
    QAction *fabricAction = new QAction("원단", this);
    QAction *woodAction = new QAction("목재", this);
    QAction *angleAction = new QAction("앵글", this);
    inventoryMenu->addAction(fabricAction);
    inventoryMenu->addAction(woodAction);
    inventoryMenu->addAction(angleAction);

    connect(orderAction, &QAction::triggered, this, [this]() {
        if (!orderWindow) {
            orderWindow = new OrderWindow(this);
        }
        setCentralWidget(orderWindow);
    });
    connect(clientAction, &QAction::triggered, this, [this]() {
        if (!clientWindow) {
            clientWindow = new ClientWindow(this);
        }
        setCentralWidget(clientWindow);
    });
    connect(fabricAction, &QAction::triggered, this, [this]() {
        if (!fabricInventoryWindow) {
            fabricInventoryWindow = new FabricInventoryWindow(this);
        }
        fabricInventoryWindow->show();
        setCentralWidget(fabricInventoryWindow);
    });
    connect(woodAction, &QAction::triggered, this, [this]() {
        if (!woodInventoryWindow) {
            woodInventoryWindow = new WoodInventoryWindow(this);
        }
        woodInventoryWindow->show();
        setCentralWidget(woodInventoryWindow);
    });
    connect(angleAction, &QAction::triggered, this, [this]() {
        if (!angleInventoryWindow) {
            angleInventoryWindow = new AngleInventoryWindow(this);
        }
        angleInventoryWindow->show();
        setCentralWidget(angleInventoryWindow);
    });
}

MainWindow::~MainWindow() {
    delete orderWindow;
    delete clientWindow;
    delete fabricInventoryWindow;
    delete woodInventoryWindow;
    delete angleInventoryWindow;
}
