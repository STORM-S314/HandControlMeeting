#ifndef LOGINDAILOG_H
#define LOGINDAILOG_H

#include <QDialog>

namespace Ui {
class LoginDailog;
}

class LoginDailog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDailog(QWidget *parent = 0);
    ~LoginDailog();

private slots:
    void on_loginButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::LoginDailog *ui;
};

#endif // LOGINDAILOG_H
