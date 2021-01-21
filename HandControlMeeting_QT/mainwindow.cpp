#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //打开文件
    QObject::connect(ui->addFile,SIGNAL(triggered(bool)),
                     this,SLOT(OpenFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addFile_triggered()
{
    //定义文件对话框类
    QFileDialog *fileChoose = new QFileDialog(this);
    //设置对话框标题
    fileChoose->setWindowTitle("打开文件");
    //设置默认文件路径
    fileChoose->setDirectory(".");
    //设置文件过滤器
    fileChoose->setNameFilter("PPT(*.ppt *.pptx);;All(*)");
    //设置选定单一文件
    fileChoose->setFileMode(QFileDialog::ExistingFile);
    //设置视图模式
    fileChoose->setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if (fileChoose->exec()){
        fileNames = fileChoose->selectedFiles();
    }
}
