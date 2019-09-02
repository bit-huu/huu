#ifndef FRIEND_H
#define FRIEND_H

#include <QDialog>

namespace Ui {
class friend;
}

class friend : public QDialog
{
    Q_OBJECT

public:
    explicit friend(QWidget *parent = 0);
    ~friend();

private:
    Ui::friend *ui;
};

#endif // FRIEND_H
