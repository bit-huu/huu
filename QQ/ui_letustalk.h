/********************************************************************************
** Form generated from reading UI file 'letustalk.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LETUSTALK_H
#define UI_LETUSTALK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_letustalk
{
public:
    QTextEdit *textEdit;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *letustalk)
    {
        if (letustalk->objectName().isEmpty())
            letustalk->setObjectName(QStringLiteral("letustalk"));
        letustalk->resize(752, 578);
        textEdit = new QTextEdit(letustalk);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(-2, 379, 511, 171));
        label_3 = new QLabel(letustalk);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(560, 400, 151, 31));
        label = new QLabel(letustalk);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(560, 100, 151, 31));
        label_2 = new QLabel(letustalk);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 130, 151, 31));
        label_4 = new QLabel(letustalk);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(560, 430, 151, 31));
        textBrowser = new QTextBrowser(letustalk);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 511, 351));
        pushButton = new QPushButton(letustalk);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 550, 93, 28));
        pushButton_2 = new QPushButton(letustalk);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 550, 93, 31));
        pushButton_3 = new QPushButton(letustalk);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 220, 151, 28));

        retranslateUi(letustalk);

        QMetaObject::connectSlotsByName(letustalk);
    } // setupUi

    void retranslateUi(QDialog *letustalk)
    {
        letustalk->setWindowTitle(QApplication::translate("letustalk", "Dialog", nullptr));
        label_3->setText(QApplication::translate("letustalk", "\347\224\250\346\210\267\345\220\215", nullptr));
        label->setText(QApplication::translate("letustalk", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("letustalk", "IP\345\234\260\345\235\200", nullptr));
        label_4->setText(QApplication::translate("letustalk", "IP\345\234\260\345\235\200", nullptr));
        pushButton->setText(QApplication::translate("letustalk", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        pushButton_2->setText(QApplication::translate("letustalk", "\345\217\221\351\200\201", nullptr));
        pushButton_3->setText(QApplication::translate("letustalk", "\345\257\271\346\226\271\346\255\243\345\234\250\345\217\221\351\200\201\346\226\260\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class letustalk: public Ui_letustalk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LETUSTALK_H
