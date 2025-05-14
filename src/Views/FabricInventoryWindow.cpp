#include "FabricInventoryWindow.h"
#include <QVBoxLayout>
#include <QLabel>

FabricInventoryWindow::FabricInventoryWindow(QWidget *parent)
    : QWidget(parent)
{
    // MainWindow의 중앙 위젯으로 사용할 경우 setWindowTitle, resize 등은 MainWindow에서 관리합니다.
    setWindowTitle("원단 재고 관리");
    
    // 간단한 예시 UI 구성
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("원단 재고 관리 창", this);
    layout->addWidget(label);

    // 추후 원단 재고 관련 위젯들을 추가합니다.
}

FabricInventoryWindow::~FabricInventoryWindow()
{
}
