#include "OrderWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QHeaderView>

OrderWindow::OrderWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("발주 관리");
    resize(500, 400);

    QVBoxLayout *layout = new QVBoxLayout(this);

    // 테이블 생성
    table = new QTableWidget(this);
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels({"제품명", "수량"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(table);

    // 입력 폼
    QHBoxLayout *formLayout = new QHBoxLayout();
    
    productNameInput = new QLineEdit(this);
    productNameInput->setPlaceholderText("제품명 입력");
    formLayout->addWidget(productNameInput);

    quantityInput = new QLineEdit(this);
    quantityInput->setPlaceholderText("수량 입력");
    formLayout->addWidget(quantityInput);

    addButton = new QPushButton("추가", this);
    formLayout->addWidget(addButton);

    layout->addLayout(formLayout);

    // 버튼 클릭 시 addOrder() 실행
    connect(addButton, &QPushButton::clicked, this, &OrderWindow::addOrder);

    // 프로그램 실행 시 저장된 데이터 불러오기
    loadOrders();
}

OrderWindow::~OrderWindow() {}

void OrderWindow::addOrder() {
    QString productName = productNameInput->text();
    QString quantityStr = quantityInput->text();
    
    if (productName.isEmpty() || quantityStr.isEmpty()) {
        return;  // 빈 값 방지
    }

    int quantity = quantityStr.toInt();
    DatabaseManager::getInstance().insertOrder(productName, quantity);

    // 테이블에 새로운 행 추가
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(productName));
    table->setItem(row, 1, new QTableWidgetItem(quantityStr));

    // 입력 필드 초기화
    productNameInput->clear();
    quantityInput->clear();
}

void OrderWindow::loadOrders() {
    QVector<Order> orders = DatabaseManager::getInstance().fetchOrders();

    for (const Order &order : orders) {
        int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(order.productName));
        table->setItem(row, 1, new QTableWidgetItem(QString::number(order.quantity)));
    }
}
