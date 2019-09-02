#include "addfriend.h"
#include "ui_addfriend.h"

addfriend::addfriend(QWidget *parent) ://添加好友
    QDialog(parent),
    ui(new Ui::addfriend)
{
    ui->setupUi(this);
}

addfriend::~addfriend()
{
    delete ui;
}

void addfriend::on_pushButton_clicked()
{
    wait f;
    f.exec();
}
