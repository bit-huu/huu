/********************************************************************************
** Form generated from reading UI file 'wait.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAIT_H
#define UI_WAIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_wait
{
public:
    QLabel *label;

    void setupUi(QDialog *wait)
    {
        if (wait->objectName().isEmpty())
            wait->setObjectName(QStringLiteral("wait"));
        wait->resize(400, 161);
        label = new QLabel(wait);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 60, 111, 31));
        label->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));

        retranslateUi(wait);

        QMetaObject::connectSlotsByName(wait);
    } // setupUi

    void retranslateUi(QDialog *wait)
    {
        wait->setWindowTitle(QApplication::translate("wait", "Dialog", nullptr));
        label->setText(QApplication::translate("wait", "\351\202\200\350\257\267\345\267\262\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wait: public Ui_wait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAIT_H
