#include "systemset.h"
#include "ui_systemset.h"
#include <string>
#include <QWidget>
#include <sys/time.h>
#include <time.h>
#include <globl_data.h>
Systemset::Systemset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Systemset)
{
    ui->setupUi(this);
    setWindowTitle(tr("系统设置"));

    //设置背景色
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#D4E6CA");
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

   // ui->stackedWidget->setCurrentIndex(0);

//    buttonGroup = new QButtonGroup(this);
//    buttonGroup->setExclusive(true);
//    buttonGroup->addButton(ui->pushButton_1,1);
//    buttonGroup->addButton(ui->pushButton_2,2);
//    buttonGroup->addButton(ui->pushButton_3,3);
//    buttonGroup->addButton(ui->pushButton_4,4);
//    buttonGroup->addButton(ui->pushButton_5,5);
//    buttonGroup->addButton(ui->pushButton_6,6);
//    buttonGroup->addButton(ui->pushButton_7,7);
//    buttonGroup->addButton(ui->pushButton_8,8);
//    buttonGroup->addButton(ui->pushButton_9,9);
//    buttonGroup->addButton(ui->pushButton_10,10);
//    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));
    ui->power->installEventFilter(this);
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_4->installEventFilter(this);
    ui->pushButton_5->installEventFilter(this);
    ui->pushButton_6->installEventFilter(this);
    ui->pushButton_7->installEventFilter(this);
    ui->pushButton_8->installEventFilter(this);
    ui->pushButton_9->installEventFilter(this);
    ui->setting->installEventFilter(this);

    //时间显示
    valueInt();
    QTimer *timer = new QTimer(this);
    this->setFocusPolicy(Qt::NoFocus);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
    timer->start(500);

}

Systemset::~Systemset()
{
    delete ui;
}
void Systemset::valueInt(void)
{
    System_RunTime.hour=0;
    System_RunTime.minute=0;
    System_RunTime.second=0;
    ShowTime();
}

void Systemset::ShowTime()
{
     QDateTime time = QDateTime(QDateTime::currentDateTime());
     QString text = time.toString(tr("yyyy/M/d"));
//     if(time.date().dayOfWeek() == 1) text=text+tr("星期一");
//     else if(time.date().dayOfWeek() == 2) text=text+tr("星期二");
//     else if(time.date().dayOfWeek() == 3) text=text+tr("星期三");
//     else if(time.date().dayOfWeek() == 4) text=text+tr("星期四");
//     else if(time.date().dayOfWeek() == 5) text=text+tr("星期五");
//     else if(time.date().dayOfWeek() == 6) text=text+tr("星期六");
//     else if(time.date().dayOfWeek() == 7) text=text+tr("星期日");
     ui->DateTime->setText((text+time.toString(" hh:mm")));

}
bool Systemset::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->power)
    {
        if(event->type() == QEvent::FocusIn)
          {
                Button_AMP_1(ui->power);
           }
        else if(event->type() == QEvent::FocusOut)
            {
              Button_AMP_0(ui->power);
           }
    }
    if(watched == ui->pushButton_2)
    {
        if(event->type() == QEvent::FocusIn)
        {
           Button_AMP_1(ui->pushButton_2);
        }else if(event->type() == QEvent::FocusOut)
        {
             Button_AMP_0(ui->pushButton_2);
        }
    }
    if(watched == ui->pushButton_3)
    {
        if(event->type() == QEvent::FocusIn)
        {
            Button_AMP_1(ui->pushButton_3);
        }else if(event->type() == QEvent::FocusOut)
        {
           Button_AMP_0(ui->pushButton_3);
        }
    }
    if(watched == ui->pushButton_4)
    {
        if(event->type() == QEvent::FocusIn)
        {
           Button_AMP_1(ui->pushButton_4);
        }else if(event->type() == QEvent::FocusOut)
        {
            Button_AMP_0(ui->pushButton_4);
        }
    }
    if(watched == ui->pushButton_5)
    {
        if(event->type() == QEvent::FocusIn)
        {
          Button_AMP_1(ui->pushButton_5);
        }else if(event->type() == QEvent::FocusOut)
        {
           Button_AMP_0(ui->pushButton_5);
        }
    }
    if(watched == ui->pushButton_6)
    {
        if(event->type() == QEvent::FocusIn)
        {
           Button_AMP_1(ui->pushButton_6);
        }else if(event->type() == QEvent::FocusOut)
        {
            Button_AMP_0(ui->pushButton_6);
        }
    }
    if(watched==ui->pushButton_7)
    {
        if(event->type() == QEvent::FocusIn)
        {
           Button_AMP_1(ui->pushButton_7);
        }else if(event->type() == QEvent::FocusOut)
        {
            Button_AMP_0(ui->pushButton_7);
        }
    }
    if(watched==ui->pushButton_8)
    {
        if(event->type() == QEvent::FocusIn)
        {
           Button_AMP_1(ui->pushButton_8);
        }else if(event->type() == QEvent::FocusOut)
        {
           Button_AMP_0(ui->pushButton_8);
        }
    }
    if(watched==ui->pushButton_9)
    {
        if(event->type() == QEvent::FocusIn)
        {
           Button_AMP_1(ui->pushButton_9);
        }else if(event->type() == QEvent::FocusOut)
        {
           Button_AMP_0(ui->pushButton_9);
        }
    }
    if(watched==ui->setting)
    {
        if(event->type() == QEvent::FocusIn)
        {
            Button_AMP_1(ui->setting);
        }else if(event->type() == QEvent::FocusOut)
        {
            Button_AMP_0(ui->setting);
        }
    }
 return QWidget::eventFilter(watched,event);
}
//点击和释放对应不同的颜色处理
void Systemset::Button_AMP_1(QPushButton *button)
{
    button->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
}

void Systemset::Button_AMP_0(QPushButton *button)
{

    button->setStyleSheet("QPushButton{background-color:#5394a0;color:#fff;border-radius:5px;}");

}

