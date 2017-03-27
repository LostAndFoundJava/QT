/********************************************************************************
** Form generated from reading UI file 'systemset.ui'
**
** Created: Mon Mar 27 20:07:06 2017
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSET_H
#define UI_SYSTEMSET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Systemset
{
public:
    QLabel *label;
    QPushButton *Jur_And_User;
    QLabel *DateTime;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QLabel *label_2;
    QWidget *page2;
    QLabel *label_3;
    QWidget *page3;
    QLabel *label_4;
    QWidget *page4;
    QLabel *label_5;
    QWidget *page5;
    QLabel *label_6;
    QWidget *page6;
    QLabel *label_7;
    QWidget *page7;
    QLabel *label_8;
    QWidget *page8;
    QLabel *label_9;
    QWidget *page9;
    QLabel *label_10;
    QWidget *page10;
    QLabel *label_11;

    void setupUi(QWidget *Systemset)
    {
        if (Systemset->objectName().isEmpty())
            Systemset->setObjectName(QString::fromUtf8("Systemset"));
        Systemset->resize(751, 426);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(114, 137, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Systemset->setPalette(palette);
        Systemset->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Systemset);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 12, 41, 20));
        label->setFrameShape(QFrame::Box);
        Jur_And_User = new QPushButton(Systemset);
        Jur_And_User->setObjectName(QString::fromUtf8("Jur_And_User"));
        Jur_And_User->setGeometry(QRect(330, 10, 91, 31));
        DateTime = new QLabel(Systemset);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setGeometry(QRect(570, 10, 161, 20));
        DateTime->setFrameShape(QFrame::Box);
        pushButton_1 = new QPushButton(Systemset);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(40, 50, 90, 30));
        pushButton_2 = new QPushButton(Systemset);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 50, 90, 30));
        pushButton_3 = new QPushButton(Systemset);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 50, 90, 30));
        pushButton_4 = new QPushButton(Systemset);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(310, 50, 90, 30));
        pushButton_5 = new QPushButton(Systemset);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(400, 50, 90, 30));
        pushButton_6 = new QPushButton(Systemset);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(490, 50, 90, 30));
        pushButton_7 = new QPushButton(Systemset);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(580, 50, 90, 30));
        pushButton_8 = new QPushButton(Systemset);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(40, 80, 90, 30));
        pushButton_9 = new QPushButton(Systemset);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(130, 80, 90, 30));
        pushButton_10 = new QPushButton(Systemset);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(220, 80, 90, 30));
        stackedWidget = new QStackedWidget(Systemset);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(50, 120, 671, 281));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        label_2 = new QLabel(page1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 20, 54, 12));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        label_3 = new QLabel(page2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 20, 54, 12));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        label_4 = new QLabel(page3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 20, 54, 12));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        label_5 = new QLabel(page4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 20, 54, 12));
        stackedWidget->addWidget(page4);
        page5 = new QWidget();
        page5->setObjectName(QString::fromUtf8("page5"));
        label_6 = new QLabel(page5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 20, 54, 12));
        stackedWidget->addWidget(page5);
        page6 = new QWidget();
        page6->setObjectName(QString::fromUtf8("page6"));
        label_7 = new QLabel(page6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 20, 54, 12));
        stackedWidget->addWidget(page6);
        page7 = new QWidget();
        page7->setObjectName(QString::fromUtf8("page7"));
        label_8 = new QLabel(page7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 20, 54, 12));
        stackedWidget->addWidget(page7);
        page8 = new QWidget();
        page8->setObjectName(QString::fromUtf8("page8"));
        label_9 = new QLabel(page8);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 20, 54, 12));
        stackedWidget->addWidget(page8);
        page9 = new QWidget();
        page9->setObjectName(QString::fromUtf8("page9"));
        label_10 = new QLabel(page9);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 20, 54, 12));
        stackedWidget->addWidget(page9);
        page10 = new QWidget();
        page10->setObjectName(QString::fromUtf8("page10"));
        label_11 = new QLabel(page10);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 20, 54, 12));
        stackedWidget->addWidget(page10);

        retranslateUi(Systemset);

        stackedWidget->setCurrentIndex(9);


        QMetaObject::connectSlotsByName(Systemset);
    } // setupUi

    void retranslateUi(QWidget *Systemset)
    {
        Systemset->setWindowTitle(QApplication::translate("Systemset", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Systemset", "\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        Jur_And_User->setText(QApplication::translate("Systemset", "\346\235\203\351\231\220/\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        DateTime->setText(QApplication::translate("Systemset", "2017\345\271\26402\346\234\21001\346\227\245\346\230\237\346\234\237\346\227\245 13:28", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("Systemset", "\346\235\203\351\231\220", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Systemset", "\350\257\255\350\250\200", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Systemset", "\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Systemset", "\345\261\217\345\271\225\344\270\216\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Systemset", "\345\233\276\345\275\242\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Systemset", "\350\201\224\347\275\221", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Systemset", "\350\276\223\345\205\245\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Systemset", "\350\256\276\345\244\207\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("Systemset", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("Systemset", "\346\201\242\345\244\215\345\207\272\345\216\202\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Systemset", "1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Systemset", "2", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Systemset", "3", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Systemset", "4", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Systemset", "5", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Systemset", "6", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Systemset", "7", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Systemset", "8", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Systemset", "9", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Systemset", "10", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Systemset: public Ui_Systemset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSET_H
