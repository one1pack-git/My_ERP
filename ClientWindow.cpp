#include "ClientWindow.h"
#include "ClientRegisterDialog.h"
#include "DatabaseManager.h"

#include <QTableWidgetItem>
#include <QLabel>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QMessageBox>

ClientWindow::ClientWindow(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *layout = new QVBoxLayout(this);


    // 추가 버튼 생성
    addButton = new QPushButton("추가", this);
    layout->addWidget(addButton);
    connect(addButton, &QPushButton::clicked, this, &ClientWindow::onAddButtonClicked);

    // 테이블 생성
    table = new QTableWidget(this);
    table->setColumnCount(10);
    table->setHorizontalHeaderLabels({
        "상호",
        "사업자 번호",
        "대표자",
        "업태",
        "종목",
        "사업장 주소",
        "이메일",
        "전화번호",
        "Fax",
        "계좌번호"
        });
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(table);

    loadClients();
}

ClientWindow::~ClientWindow()
{
    // 특별한 정리 작업이 없다면 비워둡니다.
}

void ClientWindow::onAddButtonClicked()
{
    ClientRegisterDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        // 다이얼로그에서 입력된 데이터 추출
        QString companyName = dialog.getCompanyName();
        QString businessNumber = dialog.getBusinessNumber();
        QString ceoName = dialog.getCEOName();
        QString businessCategory = dialog.getBusinessCategory();
        QString industry = dialog.getIndustry();
        QString address = dialog.getAddress();
        QString email = dialog.getEmail();
        QString phone = dialog.getPhone();
        QString fax = dialog.getFax();
        QString accountNumber = dialog.getAccountNumber();

        // 데이터베이스에 삽입
        bool success = DatabaseManager::getInstance().getClientManager()->insertClient(
            companyName,
            businessNumber,
            ceoName,
            businessCategory,
            industry,
            address,
            email,
            phone,
            fax,
            accountNumber);
        
        if(success) {
            // int row = table->rowCount();
            // table->insertRow(row);
            // table->setItem(row, 0, new QTableWidgetItem(companyName));
            // table->setItem(row, 1, new QTableWidgetItem(businessNumber));
            // table->setItem(row, 2, new QTableWidgetItem(ceoName));
            // table->setItem(row, 3, new QTableWidgetItem(businessCategory));
            // table->setItem(row, 4, new QTableWidgetItem(industry));
            // table->setItem(row, 5, new QTableWidgetItem(address));
            // table->setItem(row, 6, new QTableWidgetItem(email));
            // table->setItem(row, 7, new QTableWidgetItem(phone));
            // table->setItem(row, 8, new QTableWidgetItem(fax));
            // table->setItem(row, 9, new QTableWidgetItem(accountNumber));
            loadClients();
        } else {
            QMessageBox::warning(this, "등록 실패", "거래처 등록에 실패하였습니다.");
        }
    }
}

void ClientWindow::loadClients()
{
    // 기존 테이블 데이터 초기화
    table->setRowCount(0);
    
    // DB에서 클라이언트 데이터 불러오기
    QVector<Client> clients = DatabaseManager::getInstance().getClientManager()->fetchClients();
    
    for (const Client &client : clients) {
        int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(client.companyName));
        table->setItem(row, 1, new QTableWidgetItem(client.businessNumber));
        table->setItem(row, 2, new QTableWidgetItem(client.ceoName));
        table->setItem(row, 3, new QTableWidgetItem(client.businessCategory));
        table->setItem(row, 4, new QTableWidgetItem(client.industry));
        table->setItem(row, 5, new QTableWidgetItem(client.address));
        table->setItem(row, 6, new QTableWidgetItem(client.email));
        table->setItem(row, 7, new QTableWidgetItem(client.phone));
        table->setItem(row, 8, new QTableWidgetItem(client.fax));
        table->setItem(row, 9, new QTableWidgetItem(client.accountNumber));
    }
}