/********************************************************************************
** Form generated from reading UI file 'management.ui'
**
** Created: Mon Mar 27 20:07:06 2017
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENT_H
#define UI_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Management
{
public:
    QLabel *DateTime;
    QLabel *ManaLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QRadioButton *packButton;
    QRadioButton *bulkButton;
    QDialogButtonBox *buttonBox_1;
    QRadioButton *AluminizerButton;
    QLabel *label_27;
    QLabel *label_28;
    QLineEdit *NumEdit;
    QLineEdit *NameEdit;
    QLineEdit *SpeedEdit;
    QLineEdit *LengthEdit;
    QWidget *tab3;
    QLabel *label_11;
    QLabel *label_12;
    QRadioButton *radioButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit;
    QLabel *label_13;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *LearningButton;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QWidget *tab5;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEdit_2;
    QLabel *label_21;
    QLineEdit *lineEdit_3;
    QLabel *label_22;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_19;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QRadioButton *radioButton_2;
    QLabel *line_1;
    QLabel *line_2;
    QLabel *SpeedDisLabel;

    void setupUi(QWidget *Management)
    {
        if (Management->objectName().isEmpty())
            Management->setObjectName(QString::fromUtf8("Management"));
        Management->resize(751, 426);
        QPalette palette;
        QBrush brush(QColor(212, 230, 202, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Management->setPalette(palette);
        Management->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 230, 202);"));
        DateTime = new QLabel(Management);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setGeometry(QRect(512, 10, 228, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        DateTime->setFont(font);
        DateTime->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        DateTime->setFrameShape(QFrame::NoFrame);
        ManaLabel = new QLabel(Management);
        ManaLabel->setObjectName(QString::fromUtf8("ManaLabel"));
        ManaLabel->setEnabled(true);
        ManaLabel->setGeometry(QRect(20, 10, 101, 31));
        ManaLabel->setFont(font);
        ManaLabel->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        ManaLabel->setFrameShape(QFrame::NoFrame);
        ManaLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        gridLayoutWidget = new QWidget(Management);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 50, 741, 381));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(gridLayoutWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 9)
            tableWidget->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);\n"
"background-color: rgb(212, 230, 202);"));
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);\n"
"background-color: rgb(212, 230, 202);"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        label = new QLabel(tab1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 81, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        label_2 = new QLabel(tab1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 81, 16));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        label_3 = new QLabel(tab1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 111, 16));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        label_4 = new QLabel(tab1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 30, 71, 21));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        label_5 = new QLabel(tab1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 100, 91, 21));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        packButton = new QRadioButton(tab1);
        packButton->setObjectName(QString::fromUtf8("packButton"));
        packButton->setEnabled(true);
        packButton->setGeometry(QRect(160, 170, 71, 23));
        packButton->setFont(font2);
        bulkButton = new QRadioButton(tab1);
        bulkButton->setObjectName(QString::fromUtf8("bulkButton"));
        bulkButton->setGeometry(QRect(260, 170, 61, 23));
        bulkButton->setFont(font2);
        bulkButton->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        buttonBox_1 = new QDialogButtonBox(tab1);
        buttonBox_1->setObjectName(QString::fromUtf8("buttonBox_1"));
        buttonBox_1->setGeometry(QRect(80, 290, 161, 23));
        buttonBox_1->setFont(font1);
        buttonBox_1->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);\n"
"font: 12pt \"\345\271\274\345\234\206\";"));
        buttonBox_1->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        AluminizerButton = new QRadioButton(tab1);
        AluminizerButton->setObjectName(QString::fromUtf8("AluminizerButton"));
        AluminizerButton->setEnabled(true);
        AluminizerButton->setGeometry(QRect(160, 220, 81, 21));
        AluminizerButton->setFont(font2);
        AluminizerButton->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        label_27 = new QLabel(tab1);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(140, 100, 21, 20));
        QFont font3;
        font3.setPointSize(12);
        label_27->setFont(font3);
        label_28 = new QLabel(tab1);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(310, 100, 51, 20));
        label_28->setFont(font3);
        NumEdit = new QLineEdit(tab1);
        NumEdit->setObjectName(QString::fromUtf8("NumEdit"));
        NumEdit->setEnabled(true);
        NumEdit->setGeometry(QRect(80, 30, 101, 20));
        NumEdit->setFocusPolicy(Qt::StrongFocus);
        NumEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        NameEdit = new QLineEdit(tab1);
        NameEdit->setObjectName(QString::fromUtf8("NameEdit"));
        NameEdit->setEnabled(true);
        NameEdit->setGeometry(QRect(260, 30, 91, 20));
        NameEdit->setFocusPolicy(Qt::StrongFocus);
        NameEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        SpeedEdit = new QLineEdit(tab1);
        SpeedEdit->setObjectName(QString::fromUtf8("SpeedEdit"));
        SpeedEdit->setEnabled(true);
        SpeedEdit->setGeometry(QRect(260, 100, 61, 20));
        SpeedEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        LengthEdit = new QLineEdit(tab1);
        LengthEdit->setObjectName(QString::fromUtf8("LengthEdit"));
        LengthEdit->setEnabled(true);
        LengthEdit->setGeometry(QRect(80, 100, 61, 20));
        LengthEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        tabWidget->addTab(tab1, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        label_11 = new QLabel(tab3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 200, 81, 16));
        label_11->setFont(font2);
        label_12 = new QLabel(tab3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 240, 171, 16));
        label_12->setFont(font2);
        radioButton = new QRadioButton(tab3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 280, 141, 16));
        radioButton->setFont(font2);
        pushButton_6 = new QPushButton(tab3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(100, 170, 75, 23));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);"));
        pushButton_7 = new QPushButton(tab3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(240, 170, 75, 23));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);"));
        lineEdit = new QLineEdit(tab3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(210, 240, 101, 20));
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        label_13 = new QLabel(tab3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(320, 240, 31, 16));
        label_13->setFont(font2);
        label_6 = new QLabel(tab3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 20, 111, 16));
        label_6->setFont(font2);
        label_7 = new QLabel(tab3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 50, 81, 16));
        label_7->setFont(font2);
        label_8 = new QLabel(tab3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 80, 81, 16));
        label_8->setFont(font2);
        label_9 = new QLabel(tab3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 110, 71, 16));
        label_9->setFont(font2);
        label_10 = new QLabel(tab3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 140, 91, 16));
        label_10->setFont(font2);
        LearningButton = new QPushButton(tab3);
        LearningButton->setObjectName(QString::fromUtf8("LearningButton"));
        LearningButton->setGeometry(QRect(140, 312, 75, 23));
        LearningButton->setFont(font2);
        LearningButton->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);"));
        label_14 = new QLabel(tab3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(110, 50, 71, 21));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        label_15 = new QLabel(tab3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(200, 50, 71, 21));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        label_18 = new QLabel(tab3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(280, 50, 71, 21));
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        label_20 = new QLabel(tab3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(110, 80, 71, 21));
        label_20->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        label_29 = new QLabel(tab3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(200, 80, 71, 21));
        label_29->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        label_30 = new QLabel(tab3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(280, 80, 71, 21));
        label_30->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        label_31 = new QLabel(tab3);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(110, 110, 71, 21));
        label_31->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        label_32 = new QLabel(tab3);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(280, 110, 71, 21));
        label_32->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        label_33 = new QLabel(tab3);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(200, 110, 71, 21));
        label_33->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 237, 237);"));
        tabWidget->addTab(tab3, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QString::fromUtf8("tab5"));
        label_16 = new QLabel(tab5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(210, 50, 81, 16));
        label_16->setFont(font2);
        label_17 = new QLabel(tab5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(40, 140, 71, 16));
        label_17->setFont(font2);
        lineEdit_2 = new QLineEdit(tab5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 50, 51, 20));
        lineEdit_2->setFont(font2);
        lineEdit_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        label_21 = new QLabel(tab5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(170, 50, 21, 16));
        label_21->setFont(font2);
        lineEdit_3 = new QLineEdit(tab5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(280, 50, 51, 20));
        lineEdit_3->setFont(font2);
        lineEdit_3->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        label_22 = new QLabel(tab5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(340, 50, 21, 16));
        label_22->setFont(font2);
        lineEdit_4 = new QLineEdit(tab5);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(120, 140, 71, 20));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        lineEdit_5 = new QLineEdit(tab5);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 180, 71, 20));
        lineEdit_5->setFont(font2);
        lineEdit_5->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        lineEdit_6 = new QLineEdit(tab5);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(160, 250, 71, 20));
        lineEdit_6->setFont(font2);
        lineEdit_6->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-bottom:1px solid #000;\n"
"background-color: rgb(212, 230, 202);"));
        label_23 = new QLabel(tab5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(200, 140, 16, 16));
        label_23->setFont(font2);
        label_24 = new QLabel(tab5);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(200, 180, 21, 16));
        label_24->setFont(font2);
        label_25 = new QLabel(tab5);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(240, 250, 21, 16));
        label_25->setFont(font2);
        label_26 = new QLabel(tab5);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(30, 50, 81, 16));
        label_26->setFont(font2);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        checkBox = new QCheckBox(tab5);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 80, 91, 16));
        checkBox->setFont(font2);
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));
        checkBox_2 = new QCheckBox(tab5);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(40, 180, 71, 16));
        checkBox_2->setFont(font2);
        label_19 = new QLabel(tab5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(90, 250, 81, 16));
        label_19->setFont(font2);
        pushButton = new QPushButton(tab5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 315, 75, 23));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);"));
        pushButton_2 = new QPushButton(tab5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 315, 75, 23));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);"));
        pushButton_3 = new QPushButton(tab5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 10, 75, 23));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);"));
        pushButton_4 = new QPushButton(tab5);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 110, 75, 23));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);"));
        pushButton_5 = new QPushButton(tab5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 210, 75, 23));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 148, 160);\n"
"color: rgb(255, 250, 240);"));
        radioButton_2 = new QRadioButton(tab5);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(100, 280, 89, 17));
        radioButton_2->setFont(font2);
        line_1 = new QLabel(tab5);
        line_1->setObjectName(QString::fromUtf8("line_1"));
        line_1->setGeometry(QRect(10, 102, 351, 20));
        line_1->setStyleSheet(QString::fromUtf8("\n"
"border:1px dashed #fff;"));
        line_2 = new QLabel(tab5);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 205, 351, 20));
        line_2->setStyleSheet(QString::fromUtf8("\n"
"border:1px dashed #fff;"));
        tabWidget->addTab(tab5, QString());

        gridLayout->addWidget(tabWidget, 0, 2, 1, 1);

        SpeedDisLabel = new QLabel(Management);
        SpeedDisLabel->setObjectName(QString::fromUtf8("SpeedDisLabel"));
        SpeedDisLabel->setGeometry(QRect(310, 10, 111, 31));
        SpeedDisLabel->setFont(font);
        SpeedDisLabel->setStyleSheet(QString::fromUtf8("color: rgb(33, 28, 23);"));

        retranslateUi(Management);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Management);
    } // setupUi

    void retranslateUi(QWidget *Management)
    {
        Management->setWindowTitle(QApplication::translate("Management", "Form", 0, QApplication::UnicodeUTF8));
        DateTime->setText(QApplication::translate("Management", "2017/02/01 \346\230\237\346\234\237\346\227\245 13:28", 0, QApplication::UnicodeUTF8));
        ManaLabel->setText(QApplication::translate("Management", "\344\272\247\345\223\201\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Management", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Management", "\344\272\247\345\223\201\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Management", "\344\272\247\345\223\201\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("Management", "\346\226\260\345\273\272\350\241\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Management", "\344\272\247\345\223\201\347\274\226\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Management", "\344\272\247\345\223\201\351\225\277\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Management", "\345\214\205\350\243\205\346\226\271\345\274\217\351\200\211\346\213\251\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Management", "\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Management", "\350\276\223\351\200\201\345\270\246\351\200\237\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        packButton->setText(QApplication::translate("Management", "\345\214\205\350\243\205", 0, QApplication::UnicodeUTF8));
        bulkButton->setText(QApplication::translate("Management", "\346\225\243\350\243\205", 0, QApplication::UnicodeUTF8));
        AluminizerButton->setText(QApplication::translate("Management", "\351\225\200\351\223\235\350\206\234", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("Management", "mm", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("Management", "M/MIN", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("Management", "\345\237\272\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Management", "\345\255\246\344\271\240\351\200\211\346\213\251\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Management", "\344\272\247\345\223\201\350\277\207\345\205\211\347\224\265\345\207\272\346\216\242\345\244\264\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Management", "\350\276\223\351\200\201\345\270\246\350\207\252\345\212\250\345\276\200\345\244\215", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Management", "\346\255\243\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Management", "\345\217\215\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Management", "SEC", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Management", "\344\272\247\345\223\201\347\211\271\345\276\201\351\200\211\346\213\251\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Management", "\344\272\247\345\223\201\345\220\253\346\260\264\351\207\217", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Management", "\344\272\247\345\223\201\345\220\253\347\233\220\351\207\217", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Management", "\344\272\247\345\223\201\344\275\223\347\247\257", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Management", "\345\205\250\346\211\213\345\212\250\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        LearningButton->setText(QApplication::translate("Management", "\344\272\247\345\223\201\345\255\246\344\271\240", 0, QApplication::UnicodeUTF8));
        label_14->setText(QString());
        label_15->setText(QString());
        label_18->setText(QString());
        label_20->setText(QString());
        label_29->setText(QString());
        label_30->setText(QString());
        label_31->setText(QString());
        label_32->setText(QString());
        label_33->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("Management", "\345\255\246\344\271\240", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Management", "\345\211\224\351\231\244\344\277\235\346\214\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Management", "\345\201\234\346\234\272\345\273\266\346\227\266\357\274\232", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Management", "ms", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Management", "ms", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Management", "ms", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Management", "ms", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Management", "ms", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("Management", "\345\211\224\351\231\244\345\273\266\346\227\266\357\274\232", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Management", "\345\215\225\347\250\213\345\211\224\351\231\244", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("Management", "\350\207\252\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Management", "\345\200\222\345\270\246\345\273\266\346\227\266\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Management", "\345\211\224\351\231\244\346\243\200\351\252\214", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Management", "\345\256\214\346\210\220", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Management", "\345\211\224\351\231\244\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Management", "\345\201\234\346\234\272\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Management", "\345\200\222\345\270\246\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Management", "\350\255\246\347\201\257\345\274\200\345\220\257", 0, QApplication::UnicodeUTF8));
        line_1->setText(QString());
        line_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab5), QApplication::translate("Management", "\345\211\224\351\231\244", 0, QApplication::UnicodeUTF8));
        SpeedDisLabel->setText(QApplication::translate("Management", "\346\235\203\351\231\220/\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Management: public Ui_Management {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENT_H
