/********************************************************************************
** Form generated from reading UI file 'jindutiao.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JINDUTIAO_H
#define UI_JINDUTIAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_jindutiao
{
public:
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *jindutiao)
    {
        if (jindutiao->objectName().isEmpty())
            jindutiao->setObjectName(QStringLiteral("jindutiao"));
        jindutiao->resize(400, 300);
        jindutiao->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\226\260\345\256\213\344\275\223\";"));
        progressBar = new QProgressBar(jindutiao);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(100, 110, 251, 41));
        progressBar->setValue(24);
        pushButton = new QPushButton(jindutiao);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 220, 93, 28));
        label = new QLabel(jindutiao);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 180, 72, 20));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";\n"
"font: 12pt \"\347\255\211\347\272\277\";"));

        retranslateUi(jindutiao);

        QMetaObject::connectSlotsByName(jindutiao);
    } // setupUi

    void retranslateUi(QDialog *jindutiao)
    {
        jindutiao->setWindowTitle(QApplication::translate("jindutiao", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("jindutiao", "\345\217\226\346\266\210\345\217\221\351\200\201", nullptr));
        label->setText(QApplication::translate("jindutiao", "\345\217\221\351\200\201\344\270\255...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jindutiao: public Ui_jindutiao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JINDUTIAO_H
