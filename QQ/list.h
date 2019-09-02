#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdialog.h>
#include <QDialog>
#include <QtGui>
#include <QWidget>
#include <QObject>
#include "addfriend.h"
#include "letustalk.h"
#include <QListWidgetItem>
#include "room.h"
#include <QListWidgetItem>      //列表框空间头文件
#include <QFileDialog>          //文件对话框控件
#include <QStringList>          //字符串容器
#include <QDir>                 //目录类头文件
#include <QString>
#include <QMessageBox>
#include<QtDebug>
#include<QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);//进入聊天界面接口

    void on_pushButton_2_clicked();//进入聊天室界面接

    void add();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
