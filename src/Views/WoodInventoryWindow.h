#ifndef WoodINVENTORYWINDOW_H
#define WoodINVENTORYWINDOW_H

#include <QWidget>

class WoodInventoryWindow : public QWidget
{
    Q_OBJECT
public:
    explicit WoodInventoryWindow(QWidget *parent = nullptr);
    ~WoodInventoryWindow();

private:
    // 필요한 UI 요소들 (예: QTableWidget, 버튼 등)을 멤버 변수로 선언
};

#endif // WoodINVENTORYWINDOW_H
