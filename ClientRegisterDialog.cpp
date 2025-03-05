#include "ClientRegisterDialog.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>

ClientRegisterDialog::ClientRegisterDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("거래처 등록");

    QFormLayout *formLayout = new QFormLayout(this);

    companyNameEdit = new QLineEdit(this);
    businessNumberEdit = new QLineEdit(this);
    ceoNameEdit = new QLineEdit(this);
    businessCategoryEdit = new QLineEdit(this);
    industryEdit = new QLineEdit(this);
    addressEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    phoneEdit = new QLineEdit(this);
    faxEdit = new QLineEdit(this);
    accountNumberEdit = new QLineEdit(this);

    formLayout->addRow("상호:", companyNameEdit);
    formLayout->addRow("사업자 번호:", businessNumberEdit);
    formLayout->addRow("대표자:", ceoNameEdit);
    formLayout->addRow("업태:", businessCategoryEdit);
    formLayout->addRow("종목:", industryEdit);
    formLayout->addRow("사업장 주소:", addressEdit);
    formLayout->addRow("이메일:", emailEdit);
    formLayout->addRow("전화번호:", phoneEdit);
    formLayout->addRow("Fax:", faxEdit);
    formLayout->addRow("계좌번호:", accountNumberEdit);

    // 버튼 영역
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    okButton = new QPushButton("등록", this);
    cancelButton = new QPushButton("취소", this);
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    formLayout->addRow(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &ClientRegisterDialog::onOkButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &ClientRegisterDialog::onCancelButtonClicked);
}

ClientRegisterDialog::~ClientRegisterDialog()
{
}

void ClientRegisterDialog::onOkButtonClicked()
{
    // 여기서 필요한 입력값 검증을 수행할 수 있습니다.
    // 예를 들어, 필수 항목이 비어있는지 확인하고 경고 메시지를 띄울 수 있습니다.
    // 모두 정상이라면 accept()를 호출합니다.
    accept();
}

void ClientRegisterDialog::onCancelButtonClicked()
{
    reject();
}

// Getter 함수들 구현
QString ClientRegisterDialog::getCompanyName() const { return companyNameEdit->text(); }
QString ClientRegisterDialog::getBusinessNumber() const { return businessNumberEdit->text(); }
QString ClientRegisterDialog::getCEOName() const { return ceoNameEdit->text(); }
QString ClientRegisterDialog::getBusinessCategory() const { return businessCategoryEdit->text(); }
QString ClientRegisterDialog::getIndustry() const { return industryEdit->text(); }
QString ClientRegisterDialog::getAddress() const { return addressEdit->text(); }
QString ClientRegisterDialog::getEmail() const { return emailEdit->text(); }
QString ClientRegisterDialog::getPhone() const { return phoneEdit->text(); }
QString ClientRegisterDialog::getFax() const { return faxEdit->text(); }
QString ClientRegisterDialog::getAccountNumber() const { return accountNumberEdit->text(); }
