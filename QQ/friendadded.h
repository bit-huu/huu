#ifndef FRIENDADDED_H
#define FRIENDADDED_H

#include <QDialog>

namespace Ui {
class friendadded;
}

class friendadded : public QDialog
{
    Q_OBJECT

public:
    explicit friendadded(QWidget *parent = 0);
    ~friendadded();

private:
    Ui::friendadded *ui;//建立ui界面
};

#endif // FRIENDADDED_H
