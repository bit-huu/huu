#ifndef LETUSTALK_H
#define LETUSTALK_H

#include <QDialog>
#include "send.h"
#include <QDateTime>
#include "receive.h"

namespace Ui {
class letustalk;
}

class letustalk : public QDialog
{
    Q_OBJECT

public:
    explicit letustalk(QWidget *parent = 0);
    ~letustalk();

private slots:
    void on_pushButton_clicked();//发送消息接口

    void on_pushButton_2_clicked();//发送文件接口

    void on_pushButton_3_clicked();


    void on_textBrowser_textChanged();

private:
    Ui::letustalk *ui;
};

#endif // LETUSTALK_H
