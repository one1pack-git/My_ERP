#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include "DatabaseManager.h"

class OrderWindow : public QWidget {
    Q_OBJECT

public:
    explicit OrderWindow(QWidget *parent = nullptr);
    ~OrderWindow();

private slots:
    void addOrder();
    void loadOrders();  // 저장된 발주 불러오기

private:
    QTableWidget *table;
    QLineEdit *productNameInput;
    QLineEdit *quantityInput;
    QPushButton *addButton;
};

#endif // ORDERWINDOW_H
