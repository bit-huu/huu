/********************************************************************************
** Form generated from reading UI file 'room.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOM_H
#define UI_ROOM_H

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

class Ui_room
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *room)
    {
        if (room->objectName().isEmpty())
            room->setObjectName(QStringLiteral("room"));
        room->resize(666, 574);
        pushButton = new QPushButton(room);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(312, 541, 93, 28));
        pushButton_2 = new QPushButton(room);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(412, 541, 93, 31));
        textEdit = new QTextEdit(room);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 370, 511, 171));
        textBrowser = new QTextBrowser(room);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 511, 351));
        label = new QLabel(room);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(560, 20, 72, 61));
        label->setStyleSheet(QString::fromUtf8("font: 28pt \"Agency FB\";\n"
"font: 28pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_2 = new QLabel(room);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 90, 72, 61));
        label_2->setStyleSheet(QString::fromUtf8("font: 28pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_3 = new QLabel(room);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(560, 170, 72, 51));
        label_3->setStyleSheet(QString::fromUtf8("font: 28pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_4 = new QLabel(room);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(560, 390, 72, 61));
        label_4->setStyleSheet(QString::fromUtf8("font: 28pt \"Agency FB\";\n"
"font: 28pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_5 = new QLabel(room);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(560, 320, 72, 61));
        label_5->setStyleSheet(QString::fromUtf8("font: 28pt \"Agency FB\";\n"
"font: 28pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_6 = new QLabel(room);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(560, 240, 72, 61));
        label_6->setStyleSheet(QString::fromUtf8("font: 28pt \"Agency FB\";\n"
"font: 28pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_7 = new QLabel(room);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(560, 460, 72, 61));
        label_7->setStyleSheet(QString::fromUtf8("font: 28pt \"Agency FB\";\n"
"font: 28pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        retranslateUi(room);

        QMetaObject::connectSlotsByName(room);
    } // setupUi

    void retranslateUi(QDialog *room)
    {
        room->setWindowTitle(QApplication::translate("room", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("room", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        pushButton_2->setText(QApplication::translate("room", "\345\217\221\351\200\201", nullptr));
        label->setText(QApplication::translate("room", "\346\254\242", nullptr));
        label_2->setText(QApplication::translate("room", "\350\277\216", nullptr));
        label_3->setText(QApplication::translate("room", "\346\235\245", nullptr));
        label_4->setText(QApplication::translate("room", "\345\244\251", nullptr));
        label_5->setText(QApplication::translate("room", "\350\201\212", nullptr));
        label_6->setText(QApplication::translate("room", "\345\210\260", nullptr));
        label_7->setText(QApplication::translate("room", "\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class room: public Ui_room {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_H
