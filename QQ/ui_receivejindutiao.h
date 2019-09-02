/********************************************************************************
** Form generated from reading UI file 'receivejindutiao.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEJINDUTIAO_H
#define UI_RECEIVEJINDUTIAO_H

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

class Ui_receivejindutiao
{
public:
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *receivejindutiao)
    {
        if (receivejindutiao->objectName().isEmpty())
            receivejindutiao->setObjectName(QStringLiteral("receivejindutiao"));
        receivejindutiao->resize(400, 300);
        progressBar = new QProgressBar(receivejindutiao);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(70, 90, 271, 41));
        progressBar->setValue(24);
        pushButton = new QPushButton(receivejindutiao);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 190, 93, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\344\273\277\345\256\213\";\n"
"font: 9pt \"Academy Engraved LET\";\n"
"font: 9pt \"Academy Engraved LET\";"));
        label = new QLabel(receivejindutiao);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 150, 81, 21));

        retranslateUi(receivejindutiao);

        QMetaObject::connectSlotsByName(receivejindutiao);
    } // setupUi

    void retranslateUi(QDialog *receivejindutiao)
    {
        receivejindutiao->setWindowTitle(QApplication::translate("receivejindutiao", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("receivejindutiao", "\345\217\226\346\266\210\346\216\245\346\224\266", nullptr));
        label->setText(QApplication::translate("receivejindutiao", "\346\216\245\346\224\266\344\270\255...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class receivejindutiao: public Ui_receivejindutiao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEJINDUTIAO_H
