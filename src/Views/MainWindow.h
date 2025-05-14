#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./OrderWindow.h"
#include "./ClientWindow.h"
#include "./FabricInventoryWindow.h"
#include "./WoodInventoryWindow.h"
#include "./AngleInventoryWindow.h"

// class ClientWindow;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    OrderWindow *orderWindow;
    ClientWindow *clientWindow;
    FabricInventoryWindow *fabricInventoryWindow;
    WoodInventoryWindow *woodInventoryWindow;
    AngleInventoryWindow *angleInventoryWindow;
};

#endif // MAINWINDOW_H
