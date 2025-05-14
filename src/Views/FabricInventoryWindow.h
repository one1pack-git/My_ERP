#ifndef FABRICINVENTORYWINDOW_H
#define FABRICINVENTORYWINDOW_H

#include <QWidget>

class FabricInventoryWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FabricInventoryWindow(QWidget *parent = nullptr);
    ~FabricInventoryWindow();

private:
    // 필요한 UI 요소들 (예: QTableWidget, 버튼 등)을 멤버 변수로 선언
};

#endif // FABRICINVENTORYWINDOW_H
