#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   //database

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    a.addLibraryPath("./plugins/");
    db.setHostName("192.168.144.128");
    db.setDatabaseName("huang");
    db.setUserName("root");
    db.setPort(3306);
    db.setPassword("123456");
    if(db.open())
    {
        w.show();
    }
    else
    {
        QMessageBox::warning(NULL,"error","Failure of database connection!");
    }
    return a.exec();
}
