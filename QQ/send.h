#ifndef SEND_H
#define SEND_H

#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <QComboBox>
#include <QFile>
#include <QWidget>
#include "QDir"
#include "QTextStream"
#include "jindutiao.h"
#include "receivejindutiao.h"

namespace Ui {
class send;
}

class send : public QDialog
{
    Q_OBJECT

public:
    explicit send(QWidget *parent = 0);
    ~send();

private slots:
    void on_pushButton_clicked();//添加文件路径

    void on_pushButton_2_clicked();

private:
    Ui::send *ui;
};

#endif // SEND_H
