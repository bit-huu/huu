#include "room.h"
#include "ui_room.h"

room::room(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room)
{
    ui->setupUi(this);

}

room::~room()
{
    delete ui;
}

void room::on_pushButton_clicked()//聊天室界面发送消息
{
    send a;
    a.exec();
}


void room::on_pushButton_2_clicked()//聊天室界面发送文件
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->textBrowser->append(current_date);
    QString ss = ui->textEdit->toPlainText();
    ui->textBrowser->append(ss);
    ui->textEdit->clear();
}
