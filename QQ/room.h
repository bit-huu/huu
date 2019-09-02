#ifndef ROOM_H
#define ROOM_H

#include <QDialog>
#include "send.h"
#include <QDateTime>

namespace Ui {
class room;
}

class room : public QDialog
{
    Q_OBJECT

public:
    explicit room(QWidget *parent = 0);
    ~room();

private slots:
    void on_pushButton_clicked();//聊天室发送消息接口

    void on_pushButton_2_clicked();//聊天室发送文件接口

private:
    Ui::room *ui;
};

#endif // ROOM_H
