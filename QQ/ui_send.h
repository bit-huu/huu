/********************************************************************************
** Form generated from reading UI file 'send.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEND_H
#define UI_SEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_send
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;

    void setupUi(QDialog *send)
    {
        if (send->objectName().isEmpty())
            send->setObjectName(QStringLiteral("send"));
        send->resize(400, 300);
        pushButton = new QPushButton(send);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 110, 61, 31));
        pushButton_2 = new QPushButton(send);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 210, 93, 31));
        comboBox = new QComboBox(send);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 110, 251, 31));

        retranslateUi(send);

        QMetaObject::connectSlotsByName(send);
    } // setupUi

    void retranslateUi(QDialog *send)
    {
        send->setWindowTitle(QApplication::translate("send", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("send", "\346\265\217\350\247\210", nullptr));
        pushButton_2->setText(QApplication::translate("send", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class send: public Ui_send {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEND_H
