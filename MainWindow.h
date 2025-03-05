#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "OrderWindow.h"

class ClientWindow;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    OrderWindow *orderWindow;
    ClientWindow *clientWindow;
};

#endif // MAINWINDOW_H
