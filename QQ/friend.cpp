#include "friend.h"
#include "ui_friend.h"

friend::friend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friend)
{
    ui->setupUi(this);
}

friend::~friend()
{
    delete ui;
}
