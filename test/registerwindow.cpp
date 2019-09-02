#include "registerwindow.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_registerwindow.h"
#include <ui_registerwindow.h>
#include <QLineEdit>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QPushButton>
#include <QMessageBox>
#include <QtSql/QSql>
#include <QSqlError>
#include <QDebug>

registerwindow::registerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);
 
      setWindowTitle(tr("注册界面"));
      this->setWindowFlags (this->windowFlags () | Qt::WindowMinimizeButtonHint|Qt::MSWindowsFixedSizeDialogHint);
//      this->resize(650,400);
//      ui->label->resize(100,50);
      ui->lineEdit->setPlaceholderText("Please enter your user name");
      ui->lineEdit_2->setPlaceholderText("Please enter your password");
      ui->lineEdit_3->setPlaceholderText("Please enter your password again");
      ui->lineEdit_4->setPlaceholderText("Please enter your e-mail account number");
    
}
registerwindow::~registerwindow()
{      
    delete ui;
}
void registerwindow::on_pushButton_clicked()
{
    QString user;//username
    QString pwd;//password
    QString rpwd;//password again
    QString email;
    user=ui->lineEdit->text();//get username
    pwd=ui->lineEdit_2->text();//get password
    rpwd=ui->lineEdit_3->text();//get password again
    email=ui->lineEdit_4->text();
    if(user=="")
    {
        QMessageBox::warning(this,"","User name may not be empty.Please enter a valid username!");

    }
    else if(pwd=="")
    {
        QMessageBox::warning(this,"","Password may not be empty.Please enter a valid password!");

    }
    else if(rpwd=="")
    {
        QMessageBox::warning(this,"","Passeord may not be empty.Please enter a vaild password!");

    }
    else if(ui->lineEdit_2->text()==ui->lineEdit_3->text())
    {
        //if is true
        //QList<QHostAddress> list=QNetworkInterface::allAddresses();
        //foreach(QHostAddress address,list)
        //{
          //  if(address.protocol())
        //}
        QString S=QString("insert into U_farm (user,password,Email) values ('%1','%2','%3')").arg(user).arg(pwd).arg(email);
        QString SS=QString("select *from U_farm where user='%1'").arg(user);
        QSqlQuery query;
        if(query.exec(SS)&&query.first())
        {
             QMessageBox::warning(NULL,"Error","Username duplicate,Please try again！");

        }
        else if(query.exec(S))
        {
            QMessageBox::information(NULL, "successful", "Registration is successful！", QMessageBox::Yes);
        }
        else
        {
            qDebug() << query.lastError();
            QMessageBox::warning(NULL,"Error","Reginstration failed,Please try again！");
        }

    }
    else
    {
        QMessageBox::warning(this,"","Two password inputs are different!");
    }
}
void registerwindow::on_pushButton_2_clicked()
{
    this->hide();
        MainWindow ma;
        ma.show();
        this->show();
}
