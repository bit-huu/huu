#include "friendadded.h"
#include "ui_friendadded.h"

friendadded::friendadded(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendadded)
{
    ui->setupUi(this);
}

friendadded::~friendadded()
{
    delete ui;
}
