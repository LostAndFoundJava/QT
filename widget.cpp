                                       #include "widget.h"
#include "ui_widget.h"
#include "subwidget.h"
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QDebug>
#include <QtCore/qmath.h>
#include <QTime>
#include <QSlider>
#include <qmath.h>
#include<QMap>
#define HEIGHT_Y  400
#define WIDTH_X  800
class SUBWIDGET;

Widget::Widget(QWidget *parent,bool status) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //操作数据库，读取相关保存信息，封装函数
    qDebug()<<"///////////////////////////////////////////////";
    //SQLITE sqlite;
    //sqlite.openDatabase();
    //sqlite.insert("你好11",1,-50,-50,100,100,-50,0,50,0,0,1300,0);
    //JuXingKuang *jxk = sqlite.query("你好",1);
    //qDebug()<<jxk->getTypeQ();
    //qDebug()<<"///////////////////////////////////////////////";
    //sqlite.closeDatabase();
    //假设为这么多，以后从文件中读取
    ui->setupUi(this);

    QPixmap pixmap(":/new/prefix1/image/circle_green.png");
    QPalette Pal(palette());
    // set black background
   // Pal.setColor(QPalette::Background, "#fffffe");
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->setGeometry(280,0,580,350);

    //定义子widget
    SUBWIDGET *sub =new SUBWIDGET(this);

    sub->initiation(0,1300,-20,0,20,0,40,40,0,-20,-20);
//    sub->initiation(jxk->getK1Q(),jxk->getK2Q(),jxk->getB1Q(),jxk->getB2Q(),jxk->getB3Q(),jxk->getB4Q(),
//                    jxk->getLen1Q(),jxk->getLen2Q(),jxk->getDegreeQ(),jxk->getxQ(),jxk->getyQ());
    //定义子widget背景色
    sub->setGeometryByUser(99,0,478,348);
    //Pal.(QPalette::Background, "url(image/slider.png)");
    Pal.setBrush(backgroundRole(),QBrush(pixmap));
    sub->setAutoFillBackground(true);
    sub->setPalette(Pal);

    ui->label_3->setText("0");

    //test测试产生的点
    generateDots();

    if(status == false)
        showCorridateAndPhase();

    //this->resize(WIDTH_X,HEIGHT_Y);
    //定义进度条样式
    ui->verticalSlider->setStyleSheet(" \ QSlider::add-page:vertical\{\ background-color: rgb(187, 255, 255);\width:8px;\}\QSlider::sub-page:vertical \{\ background-color:rgb(83, 148, 160);\  width:8px;\    }\ QSlider::groove:vertical \  {\ background:transparent;\  width:8px;\ border-radius:3px;\}\ QSlider::handle:vertical \ {\ width: 40px;\height:8px;\ border-image: url(image/slider.png);\ margin: 0 -30px; \}");
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),sub,SLOT(getValue(int)));
    connect(sub,SIGNAL(setData(double ,double ,double ,double ,double ,double ,
                                 double ,double ,double ,double ,double ,
                                double ,double ,double ,double ,double ,double )),
            this,SLOT(getData(double ,double ,double ,double ,double ,double ,
                                double ,double ,double ,double ,double ,
                                double ,double ,double ,double ,double ,double )));


    this->setMouseTracking(true);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_verticalSlider_valueChanged(int value)
{
    QString s = QString("%1").arg(value);
    ui->label_3->setText(s);
}

void Widget::getData(double x, double y, double x1, double y1, double x2, double y2,
                     double x3, double y3, double phase, double slope1, double slope2,
                     double length1, double length2, double b1, double b2, double b3, double b4)
{
    QString s;

//     s = QString("%1").arg(x);
//    ui->label_7->setText(s);

//     s = QString("%1").arg(x1);
//    ui->label_9->setText(s);

//     s = QString("%1").arg(x2);
//    ui->label_11->setText(s);

//     s = QString("%1").arg(x3);
//    ui->label_13->setText(s);

//     s = QString("%1").arg(phase);
//    ui->label_15->setText(s);

//     s = QString("%1").arg(y);
//    ui->label_16->setText(s);

//     s = QString("%1").arg(y1);
//    ui->label_17->setText(s);

//    s = QString("%1").arg(y2);
//    ui->label_18->setText(s);

//    s = QString("%1").arg(y3);
//    ui->label_19->setText(s);
}

void Widget::generateDots()
{
    for(int i =0; i < 10 ;i ++)
    {
        dot.append(i);
    }
    if(dot.length() > 8)
    {
        emit dotsSignal(dot);
        dot.clear();
    }
}

void Widget::showCorridateAndPhase()
{
//    ui->label_6->hide();
//    ui->label_7->hide();
//    ui->label_8->hide();
//    ui->label_9->hide();
//    ui->label_10->hide();
//    ui->label_11->hide();
//    ui->label_12->hide();
//    ui->label_13->hide();
//    ui->label_14->hide();
//    ui->label_15->hide();
//    ui->label_16->hide();
//    ui->label_17->hide();
//    ui->label_18->hide();
//    ui->label_19->hide();
//    ui->label_20->hide();
//    ui->label_21->hide();
}

