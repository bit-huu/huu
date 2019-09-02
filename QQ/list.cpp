#include "list.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("QQ"));   //设置标题框文本
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(addbtn()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)//进入单人聊天界面显示接口
{
    letustalk b;
    b.exec();
}

void MainWindow::on_pushButton_2_clicked()//进入聊天室接口
{
    room c;
    c.exec();
}

