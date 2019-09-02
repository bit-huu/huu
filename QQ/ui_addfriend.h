/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addfriend
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *addfriend)
    {
        if (addfriend->objectName().isEmpty())
            addfriend->setObjectName(QStringLiteral("addfriend"));
        addfriend->resize(400, 300);
        pushButton = new QPushButton(addfriend);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 200, 93, 28));
        label = new QLabel(addfriend);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 110, 51, 31));
        lineEdit = new QLineEdit(addfriend);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 110, 191, 31));

        retranslateUi(addfriend);

        QMetaObject::connectSlotsByName(addfriend);
    } // setupUi

    void retranslateUi(QDialog *addfriend)
    {
        addfriend->setWindowTitle(QApplication::translate("addfriend", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("addfriend", "\346\267\273\345\212\240", nullptr));
        label->setText(QApplication::translate("addfriend", "\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addfriend: public Ui_addfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
