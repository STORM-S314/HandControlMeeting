#include "logindailog.h"
#include "ui_logindailog.h"
#include <QMessageBox>

LoginDailog::LoginDailog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDailog)
{
    ui->setupUi(this);
}

LoginDailog::~LoginDailog()
{
    delete ui;
}

void LoginDailog::on_loginButton_clicked()
{
    if(ui->userNameEdit->text() == "1"
        && ui->passwordEdit->text() == "123456"){
        accept();
    }
    else{
        QMessageBox::warning(this,"Waring",
                             "username or password errod",
                             QMessageBox::Yes);
    }
}

void LoginDailog::on_exitButton_clicked()
{
    close();
}
