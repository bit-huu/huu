#include "letustalk.h"
#include "ui_letustalk.h"

letustalk::letustalk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::letustalk)
{
    ui->setupUi(this);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::yellow);
    this->setPalette(palette);
}

letustalk::~letustalk()
{
    delete ui;
}

void letustalk::on_pushButton_clicked()//发送消息
{
    send a;
    a.exec();
}

void letustalk::on_pushButton_2_clicked()//建立文本消息并发送到消息界面
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->textBrowser->append(current_date);
    QString ss = ui->textEdit->toPlainText();
    ui->textBrowser->append(ss);
    ui->textEdit->clear();
}

void letustalk::on_pushButton_3_clicked()
{
    receive i;
    i.exec();
}







void letustalk::on_textBrowser_textChanged()
{
    QPalette pal;
    pal = ui->textBrowser->palette();
    pal.setColor(QPalette::Base, QColor(0,255,0));//改变背景色
    ui->textBrowser->setPalette(pal);
}
