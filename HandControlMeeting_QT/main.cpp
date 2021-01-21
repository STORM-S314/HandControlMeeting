#include "mainwindow.h"
#include "logindailog.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDailog login;
    if(login.exec() == QDialog :: Accepted)
    {
            w.show();
            return a.exec();
    }
    else return 0;
}
