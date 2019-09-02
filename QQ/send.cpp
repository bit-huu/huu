#include "send.h"
#include "ui_send.h"

send::send(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::send)
{
    ui->setupUi(this);
}

send::~send()
{
    delete ui;
}
//显示文件路径
void send::on_pushButton_clicked()
{
    QString path=QDir::toNativeSeparators(QFileDialog::getOpenFileName(this,tr("Save path"),QDir::currentPath()));  //文件路径
            if(!path.isEmpty())
            {
                if(ui->comboBox->findText(path)==-1)
                    ui->comboBox->addItem(path);    //在comboBox中显示文件路径
            }
}

void send::on_pushButton_2_clicked()
{
    jindutiao e;
    e.exec();
}
