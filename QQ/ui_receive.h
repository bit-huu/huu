/********************************************************************************
** Form generated from reading UI file 'receive.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVE_H
#define UI_RECEIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_receive
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *receive)
    {
        if (receive->objectName().isEmpty())
            receive->setObjectName(QStringLiteral("receive"));
        receive->resize(400, 300);
        label = new QLabel(receive);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(131, 80, 121, 41));
        pushButton = new QPushButton(receive);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 220, 93, 28));
        pushButton_2 = new QPushButton(receive);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 220, 93, 28));

        retranslateUi(receive);

        QMetaObject::connectSlotsByName(receive);
    } // setupUi

    void retranslateUi(QDialog *receive)
    {
        receive->setWindowTitle(QApplication::translate("receive", "Dialog", nullptr));
        label->setText(QApplication::translate("receive", "...\350\257\267\346\261\202\344\274\240\350\276\223\346\226\207\344\273\266", nullptr));
        pushButton->setText(QApplication::translate("receive", "\346\216\245\346\224\266", nullptr));
        pushButton_2->setText(QApplication::translate("receive", "\346\213\222\347\273\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class receive: public Ui_receive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVE_H
