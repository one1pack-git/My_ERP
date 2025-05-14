#ifndef AngleINVENTORYWINDOW_H
#define AngleINVENTORYWINDOW_H

#include <QWidget>

class AngleInventoryWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AngleInventoryWindow(QWidget *parent = nullptr);
    ~AngleInventoryWindow();

private:
    // 필요한 UI 요소들 (예: QTableWidget, 버튼 등)을 멤버 변수로 선언
};

#endif // AngleINVENTORYWINDOW_H
