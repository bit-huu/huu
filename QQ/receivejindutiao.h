#ifndef RECEIVEJINDUTIAO_H
#define RECEIVEJINDUTIAO_H

#include <QDialog>
#include <QtWidgets/QMainWindow>
#include "receivejindutiao.h"
#include<QTimer>
namespace Ui {
class receivejindutiao;
}

class receivejindutiao : public QDialog
{
    Q_OBJECT

public:
    explicit receivejindutiao(QWidget *parent = 0);
    ~receivejindutiao();

private slots:
    void on_pushButton_clicked();
    void slotprocessbar();

private:
    Ui::receivejindutiao *ui;
    QTimer *m_timer;
};

#endif // RECEIVEJINDUTIAO_H
