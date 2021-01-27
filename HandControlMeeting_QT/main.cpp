#include "mainwindow.h"
#include "logindailog.h"
#include "bootanimation.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //登录对话框
    LoginDailog login;
    BootAnimation *boot = new BootAnimation("点击启动",QPoint(40,40),40);
    boot->show();

    //修改登录窗口标题
    login.setWindowTitle("登录");
    //去除登录窗口右上角的问号，保留标题和关闭按钮
    login.setWindowFlags(Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
    //当登录成功时显示主页面
    //确认密码
    if(login.exec() == QDialog :: Accepted)
    {
        //显示主窗口
            w.show();
            return a.exec();
    }
    else return a.exec();
}
