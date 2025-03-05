#ifndef CLIENTREGISTERDIALOG_H
#define CLIENTREGISTERDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;

class ClientRegisterDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ClientRegisterDialog(QWidget *parent = nullptr);
    ~ClientRegisterDialog();

    // 입력된 값을 가져올 getter 함수들
    QString getCompanyName() const;
    QString getBusinessNumber() const;
    QString getCEOName() const;
    QString getBusinessCategory() const;
    QString getIndustry() const;
    QString getAddress() const;
    QString getEmail() const;
    QString getPhone() const;
    QString getFax() const;
    QString getAccountNumber() const;

private slots:
    void onOkButtonClicked();
    void onCancelButtonClicked();

private:
    QLineEdit *companyNameEdit;
    QLineEdit *businessNumberEdit;
    QLineEdit *ceoNameEdit;
    QLineEdit *businessCategoryEdit;
    QLineEdit *industryEdit;
    QLineEdit *addressEdit;
    QLineEdit *emailEdit;
    QLineEdit *phoneEdit;
    QLineEdit *faxEdit;
    QLineEdit *accountNumberEdit;

    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // CLIENTREGISTERDIALOG_H
