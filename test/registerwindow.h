#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include <QDialog>
namespace Ui {
class registerwindow;
}


class registerwindow:public QDialog
{
    Q_OBJECT
public:
    registerwindow(QWidget *parent = 0);
        ~registerwindow();
public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::registerwindow *ui;
};

#endif // REGISTERWINDOW_H
