/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *addFile;
    QAction *deleteFile;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *file;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(501, 300);
        addFile = new QAction(MainWindow);
        addFile->setObjectName(QStringLiteral("addFile"));
        deleteFile = new QAction(MainWindow);
        deleteFile->setObjectName(QStringLiteral("deleteFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 501, 23));
        file = new QMenu(menuBar);
        file->setObjectName(QStringLiteral("file"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(file->menuAction());
        file->addAction(addFile);
        file->addAction(deleteFile);

        retranslateUi(MainWindow);
        QObject::connect(addFile, SIGNAL(triggered()), MainWindow, SLOT(addFile()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        addFile->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        deleteFile->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
