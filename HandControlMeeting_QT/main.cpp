#include "mainwindow.h"
#include "logindailog.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //登录对话框
    LoginDailog login;
    //确认密码
    if(login.exec() == QDialog :: Accepted)
    {
        //显示主窗口
            w.show();
            return a.exec();
    }
    else return a.exec();
}
