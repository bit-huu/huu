#ifndef WAIT_H
#define WAIT_H

#include <QDialog>

namespace Ui {
class wait;
}

class wait : public QDialog
{
    Q_OBJECT

public:
    explicit wait(QWidget *parent = 0);
    ~wait();

private:
    Ui::wait *ui;
};

#endif // WAIT_H
