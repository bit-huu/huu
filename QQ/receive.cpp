#include "receive.h"
#include "ui_receive.h"

receive::receive(QWidget *parent) ://接收界面
    QDialog(parent),
    ui(new Ui::receive)
{
    ui->setupUi(this);
}

receive::~receive()
{
    delete ui;
}

void receive::on_pushButton_clicked()
{
    receivejindutiao j;
    j.exec();
}



void receive::on_pushButton_2_clicked()
{
    this->close();
}
