#ifndef RECEIVE_H
#define RECEIVE_H

#include <QDialog>
#include"receivejindutiao.h"
namespace Ui {
class receive;
}

class receive : public QDialog
{
    Q_OBJECT

public:
    explicit receive(QWidget *parent = 0);
    ~receive();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::receive *ui;//接收文件界面ui
};

#endif // RECEIVE_H
