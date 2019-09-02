#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QDialog>
#include <QtGui>
#include <wait.h>

namespace Ui {
class addfriend;
}

class addfriend : public QDialog
{
    Q_OBJECT

public:
    explicit addfriend(QWidget *parent = 0);
    ~addfriend();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addfriend *ui;
};

#endif // ADDFRIEND_H
