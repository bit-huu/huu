#include "jindutiao.h"
#include "ui_jindutiao.h"

jindutiao::jindutiao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jindutiao)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    ui->progressBar->setRange(0,99);
    ui->progressBar->setValue(0);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slotstop()));
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotprocessbar()));
}

jindutiao::~jindutiao()
{
    delete ui;
}

void jindutiao::slotprocessbar()
{
    static int pos = 0;
    if(pos == 100);
    {
       m_timer->stop();
       return;
    }
    ui->progressBar->setValue(pos++);
}

void jindutiao::on_pushButton_clicked()
{
    this->close();
}
