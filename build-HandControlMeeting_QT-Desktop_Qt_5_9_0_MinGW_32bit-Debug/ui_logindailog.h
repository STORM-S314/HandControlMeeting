/********************************************************************************
** Form generated from reading UI file 'logindailog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDAILOG_H
#define UI_LOGINDAILOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDailog
{
public:
    QPushButton *loginButton;
    QPushButton *exitButton;
    QLineEdit *userNameEdit;
    QLineEdit *passwordEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *LoginDailog)
    {
        if (LoginDailog->objectName().isEmpty())
            LoginDailog->setObjectName(QStringLiteral("LoginDailog"));
        LoginDailog->resize(401, 189);
        loginButton = new QPushButton(LoginDailog);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(70, 130, 93, 28));
        exitButton = new QPushButton(LoginDailog);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(260, 130, 93, 28));
        userNameEdit = new QLineEdit(LoginDailog);
        userNameEdit->setObjectName(QStringLiteral("userNameEdit"));
        userNameEdit->setGeometry(QRect(150, 50, 201, 21));
        passwordEdit = new QLineEdit(LoginDailog);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setGeometry(QRect(150, 90, 201, 21));
        passwordEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(LoginDailog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 50, 51, 21));
        label_2 = new QLabel(LoginDailog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 90, 51, 21));

        retranslateUi(LoginDailog);
        QObject::connect(loginButton, SIGNAL(clicked()), LoginDailog, SLOT(accept()));

        QMetaObject::connectSlotsByName(LoginDailog);
    } // setupUi

    void retranslateUi(QDialog *LoginDailog)
    {
        LoginDailog->setWindowTitle(QApplication::translate("LoginDailog", "Dialog", Q_NULLPTR));
        loginButton->setText(QApplication::translate("LoginDailog", "\347\231\273\345\275\225", Q_NULLPTR));
        exitButton->setText(QApplication::translate("LoginDailog", "\351\200\200\345\207\272", Q_NULLPTR));
        userNameEdit->setPlaceholderText(QApplication::translate("LoginDailog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        passwordEdit->setPlaceholderText(QApplication::translate("LoginDailog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDailog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginDailog", "\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDailog: public Ui_LoginDailog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDAILOG_H
