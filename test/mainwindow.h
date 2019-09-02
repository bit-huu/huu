#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //send
//private:

//    QLabel *UserName;
//    QLabel *Password;
//    QLineEdit *UserNameEdit;
//    QLineEdit *PasswordEdit;
//    QPushButton *LoginButton;
//    QPushButton *RegisterButton;
public slots:
//    void hide();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
//    void register_slots();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
