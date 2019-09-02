#include "receivejindutiao.h"
#include "ui_receivejindutiao.h"

receivejindutiao::receivejindutiao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receivejindutiao)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    ui->progressBar->setRange(0,99);
    ui->progressBar->setValue(0);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slotstop()));
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotprocessbar()));
}

receivejindutiao::~receivejindutiao()
{
    delete ui;

}

void receivejindutiao::slotprocessbar()
{
    static int pos = 0;
    if(pos == 100);
    {
       m_timer->stop();
       return;
    }
    ui->progressBar->setValue(pos++);
}

void receivejindutiao::on_pushButton_clicked()
{
    this->close();
}


