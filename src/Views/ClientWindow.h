#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>

class QTableWidget;
class QPushButton;
class ClientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void onAddButtonClicked();
    
private:
    void loadClients();
    QTableWidget *table;
    // QLineEdit *productNameInput;
    // QLineEdit *quantityInput;
    QPushButton *addButton;
};

#endif // CLIENTWINDOW_H
