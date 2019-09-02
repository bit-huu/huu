#include "mainwindow.h"
#include "registerwindow.h"
#include "ui_mainwindow.h"
#include <ui_mainwindow.h>
#include <QLineEdit>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QPushButton>
#include <QMessageBox>
#include <QtSql/QSql>

//login
//class MainWindow:public QMainWindow
//{ma.exec();
//    Q_OBJECT
//}
//public:
//explicit MainWindow()
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
  ui(new Ui::MainWindow)
{
   ui->setupUi(this);

     setWindowTitle(tr("登陆界面"));
     this->setWindowFlags (this->windowFlags () | Qt::WindowMinimizeButtonHint|Qt::MSWindowsFixedSizeDialogHint);

//    UserName = new QLabel(tr("用户名："));
//    Password = new QLabel(tr("密码："));
//    lineEdit = new QLineEdit();
//    lineEdit_2 = new QLineEdit();
//    LoginButton = new QPushButton(tr("登陆"));
//    RegisterButton = new QPushButton(tr("注册"));

//     connect(LoginButton,SIGNAL(clicked()),this,SLOT(on_pushButton_login_clicked()));
//     connect(RegisterButton,SIGNAL(clicked()),this,SLOT(Register_slots()));
//    this->resize(650,400);
//    ui->label->resize(100,50);
    ui->lineEdit->setPlaceholderText("Please enter your user name");
    ui->lineEdit_2->setPlaceholderText("Please enter your password");

}
//void MainWindow::hide()
//{
//    ui->frame->hide();
//}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    QString user;//username
    QString pwd;//password
    QString ip;
    user=ui->lineEdit->text();//get username
    pwd=ui->lineEdit_2->text();//get password
    ip=ui->lineEdit_3->text();//get ip
    if(user=="")
    {
        QMessageBox::warning(this,"","User name may not be empty.Please enter a valid username!");

    }
    else if(pwd=="")
    {
        QMessageBox::warning(this,"","Password may not be empty.Please enter a valid password!");

    }
    else
    {
        //if is true
        QString S=QString("select *from U_farm where user='%1' and password='%2'").arg(user).arg(pwd);
        QSqlQuery query;
        if(query.exec(S))
        {
//            index.show();
//            this->close;
            QMessageBox::information(this,"",tr("Login Success!"));

        }
        else
        {
            QMessageBox::warning(NULL,"Error","Error incorrect username or password!!");
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    registerwindow re;
    re.show();
    re.exec();
    this->show();
}

