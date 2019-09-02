#ifndef JINDUTIAO_H
#define JINDUTIAO_H

#include <QDialog>
#include <QtWidgets/QMainWindow>
#include "ui_jindutiao.h"
#include<QTimer>
namespace Ui {
class jindutiao;
}

class jindutiao : public QDialog
{
    Q_OBJECT

public:
    explicit jindutiao(QWidget *parent = 0);
    ~jindutiao();

private slots:
    void slotprocessbar();

    void on_pushButton_clicked();

private:
    Ui::jindutiao *ui;
    QTimer *m_timer;
};

#endif // JINDUTIAO_H
