/********************************************************************************
** Form generated from reading UI file 'friendadded.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDADDED_H
#define UI_FRIENDADDED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_friendadded
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *friendadded)
    {
        if (friendadded->objectName().isEmpty())
            friendadded->setObjectName(QStringLiteral("friendadded"));
        friendadded->resize(400, 300);
        pushButton = new QPushButton(friendadded);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 250, 93, 28));
        pushButton_2 = new QPushButton(friendadded);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 250, 93, 28));
        label = new QLabel(friendadded);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 120, 191, 31));

        retranslateUi(friendadded);

        QMetaObject::connectSlotsByName(friendadded);
    } // setupUi

    void retranslateUi(QDialog *friendadded)
    {
        friendadded->setWindowTitle(QApplication::translate("friendadded", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("friendadded", "\345\220\214\346\204\217", nullptr));
        pushButton_2->setText(QApplication::translate("friendadded", "\346\213\222\347\273\235", nullptr));
        label->setText(QApplication::translate("friendadded", "...\350\257\267\346\261\202\346\267\273\345\212\240\346\202\250\344\270\272\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class friendadded: public Ui_friendadded {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDADDED_H
