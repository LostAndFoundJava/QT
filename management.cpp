#include "management.h"
#include "ui_management.h"
#include <string>
#include <QWidget>
#include <sys/time.h>
#include <time.h>
#include <globl_data.h>
Management::Management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Management)
{
    ui->setupUi(this);
    setWindowTitle(tr("产品管理"));
    //设置背景色
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#D4E6CA");
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    //标签页
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,200);
    ui->tableWidget->setWindowFlags(Qt::FramelessWindowHint);


    QPalette Pal1(palette());
    Pal1.setColor(QPalette::Background, "#D4E6CA");
    ui->tabWidget->setAutoFillBackground(true);
    ui->tabWidget->setPalette(Pal1);
    //ui->tabWidget->setStyleSheet("background:rgb(212, 230, 202)");

    PackingStyleGroup = new QButtonGroup(this);
    PackingStyleGroup->setExclusive(true);
    PackingStyleGroup->addButton(ui->packButton);
    PackingStyleGroup->addButton(ui->bulkButton);

//    ui->buttonBox_1->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
//    ui->buttonBox_1->button(QDialogButtonBox::Ok)->setText(tr("确定"));
//    ui->buttonBox_1->button(QDialogButtonBox::Cancel)->setText(tr("取消"));

    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setStyleSheet("QTabBar::tab{width:122px}");
    ui->line_1->setFixedHeight(1);
     ui->line_2->setFixedHeight(1);

    //镀铝膜隐藏
    ui->AluminizerButton->hide();
    //基本信息
    ui->NumEdit->installEventFilter(this);
    ui->NameEdit->installEventFilter(this);
    ui->LengthEdit->installEventFilter(this);
    ui->SpeedEdit->installEventFilter(this);
     //学习
    ui->label_14->installEventFilter(this);
    ui->label_15->installEventFilter(this);
    ui->label_18->installEventFilter(this);
    ui->label_20->installEventFilter(this);
    ui->label_29->installEventFilter(this);
    ui->label_30->installEventFilter(this);
    ui->label_31->installEventFilter(this);
    ui->label_32->installEventFilter(this);
    ui->label_33->installEventFilter(this);

    ui->LightTime->installEventFilter(this);
    ui->PositiveTest->installEventFilter(this);
    ui->NagtiveTest->installEventFilter(this);
     //剔除
    ui->RemovedButton->installEventFilter(this);
    ui->StopButton->installEventFilter(this);
    ui->BackButton->installEventFilter(this);

    ui->RmoveTime->installEventFilter(this);
    ui->RmoveKeep->installEventFilter(this);
    ui->StopTime->installEventFilter(this);
    ui->BackTime->installEventFilter(this);

    ui->StartTime->setDisabled(true);
    //时间显示
    valueInt();
    QTimer *timer = new QTimer(this);
    this->setFocusPolicy(Qt::NoFocus);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
    timer->start(500);
    //新建学习界面
    Learn = new learn();
}

bool Management::eventFilter(QObject *watched,QEvent *event)
{
    int x =pos().x();
    int y = pos().y();
    if(watched==ui->NumEdit)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            Window_show.ShowKeyBoard(this,false,ui->NumEdit,x,y);
        }
    }
    if(watched==ui->NameEdit)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            Window_show.ShowKeyBoard(this,false,ui->NameEdit,x,y);
        }
    }
    if(watched==ui->LengthEdit)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            Window_show.ShowKeyBoard(this,false,ui->LengthEdit,x,y);
        }
    }
    if(watched==ui->SpeedEdit)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            Window_show.ShowKeyBoard(this,false,ui->SpeedEdit,x,y);
        }
    }
    if(watched==ui->label_14)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_14->setPixmap(name);
        }
    }
    if(watched==ui->label_15)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_15->setPixmap(name);
        }
    }
    if(watched==ui->label_18)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_18->setPixmap(name);
        }
    }
    if(watched==ui->label_20)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_20->setPixmap(name);
        }
    }
    if(watched==ui->label_29)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_29->setPixmap(name);
        }
    }
    if(watched==ui->label_30)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_30->setPixmap(name);
        }
    }
    if(watched==ui->label_31)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_31->setPixmap(name);
        }
    }
    if(watched==ui->label_32)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_32->setPixmap(name);
        }
    }
    if(watched==ui->label_33)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QString name=QFileDialog::getOpenFileName(0,"Image",QDir::currentPath()+"/image");
            ui->label_33->setPixmap(name);
        }
    }
    if(watched==ui->LightTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
             Window_show.ShowKeyBoard(this,false,ui->LightTime,x,y);
        }
    }
    if(watched==ui->PositiveTest)
    {
        if(event->type()==QEvent::FocusIn)
        {
            ui->PositiveTest->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
        }
        else if(event->type()==QEvent::FocusOut)
        {
            ui->PositiveTest->setStyleSheet("QPushButton{background-color:#5394a0;color:#fff;border-radius:5px;}");
        }
    }
    if(watched==ui->NagtiveTest)
    {
        if(event->type()==QEvent::FocusIn)
        {
            ui->NagtiveTest->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
        }
        else if(event->type()==QEvent::FocusOut)
        {
            ui->NagtiveTest->setStyleSheet("QPushButton{background-color:#5394a0;color:#fff;border-radius:5px;}");
        }
    }
    if(watched==ui->RmoveTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
             Window_show.ShowKeyBoard(this,false,ui->RmoveTime,x,y);
        }
    }
    if(watched==ui->RmoveKeep)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
             Window_show.ShowKeyBoard(this,false,ui->RmoveKeep,x,y);
        }
    }
    if(watched==ui->StopTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
             Window_show.ShowKeyBoard(this,false,ui->StopTime,x,y);
        }
    }
    if(watched==ui->StartTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
             Window_show.ShowKeyBoard(this,false,ui->StartTime,x,y);
        }
    }
    if(watched==ui->BackTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
             Window_show.ShowKeyBoard(this,false,ui->BackTime,x,y);
        }
    }
//剔除
if(watched==ui->RemovedButton)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        ui->RemovedButton->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
        ui->StopButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->BackButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->RmoveTime->setDisabled(false);
        ui->RmoveKeep->setDisabled(false);
        ui->OddRmove->setDisabled(false);
        ui->StopTime->setDisabled(true);
        ui->AutoStart->setDisabled(true);
        ui->BackTime->setDisabled(true);
        ui->Light->setDisabled(true);
    }
}
if(watched==ui->StopButton)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        ui->StopButton->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
        ui->RemovedButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->BackButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->RmoveTime->setDisabled(true);
        ui->RmoveKeep->setDisabled(true);
        ui->OddRmove->setDisabled(true);
        ui->StopTime->setDisabled(false);
        ui->AutoStart->setDisabled(false);
        ui->BackTime->setDisabled(true);
        ui->Light->setDisabled(true);
    }
}
if(watched==ui->BackButton)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        ui->BackButton->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
        ui->StopButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->RemovedButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->RmoveTime->setDisabled(true);
        ui->RmoveKeep->setDisabled(true);
        ui->OddRmove->setDisabled(true);
        ui->StopTime->setDisabled(true);
        ui->AutoStart->setDisabled(true);
        ui->BackTime->setDisabled(false);
        ui->Light->setDisabled(false);
    }
}
   return QWidget::eventFilter(watched,event);
}

Management::~Management()
{
    delete ui;
}

void Management::valueInt(void)
{
    System_RunTime.hour=0;
    System_RunTime.minute=0;
    System_RunTime.second=0;
    ShowTime();
}

void Management::ShowTime()
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
//void Management::on_buttonBox_1_clicked(QAbstractButton *button)
//{
//    if(ui->buttonBox_1->button(QDialogButtonBox::Ok)==button)
//    {
//        ui->tabWidget->setCurrentIndex(1);

//    }
//    else if(ui->buttonBox_1->button(QDialogButtonBox::Cancel))
//    {
//        this->close();

//    }
//    Window_show.CloseKeyBoard();
//}

void Management::on_AluminizerButton_clicked(bool checked)
{

    if(checked == true)
    {
        ui->AluminizerButton->hide();
        ui->LengthEdit->setDisabled(true);
        ui->LengthEdit->removeEventFilter(this);
    }else if(checked == false){
        ui->LengthEdit->setDisabled(false);
        ui->LengthEdit->installEventFilter(this);
    }
}
//散装逻辑
void Management::on_bulkButton_clicked(bool checked)
{
    if(checked == true)
    {
        ui->AluminizerButton->hide();
        ui->LengthEdit->setDisabled(true);
        ui->LengthEdit->removeEventFilter(this);
    }else if(checked == false){
        ui->LengthEdit->setDisabled(false);
        ui->LengthEdit->installEventFilter(this);
    }
}
//包装逻辑
void Management::on_packButton_clicked(bool checked)
{
    if(checked == true)
    {
        ui->AluminizerButton->show();
        ui->LengthEdit->setDisabled(false);
        ui->LengthEdit->installEventFilter(this);
    }
    else if(checked == false)
    {
        ui->AluminizerButton->hide();
        ui->AluminizerButton->setChecked(false);
    }
}

//产品学习弹出
void Management::on_LearningButton_clicked()
{

    Learn->show();
    Learn->move(pos().x(),pos().y());
    this->hide();
}
//剔除完成
void Management::on_FinishButton_clicked(bool checked)
{
    w->activateWindow();
    this->hide();
}
//单程剔除
void Management::on_OddRmove_clicked(bool checked)
{
    if(checked == true)
    {
         ui->RmoveKeep->setDisabled(true);
         ui->RmoveKeep->removeEventFilter(this);

    }else{
         ui->RmoveKeep->setDisabled(false);
         ui->RmoveKeep->installEventFilter(this);
    }
}
//自启动
void Management::on_AutoStart_clicked(bool checked)
{
    if(checked == true)
    {
        ui->StartTime->setDisabled(false);
        ui->StartTime->installEventFilter(this);
    }else{
         ui->StartTime->setDisabled(true);
         ui->StartTime->removeEventFilter(this);
    }
}
//警灯
void Management::on_Light_clicked(bool checked)
{
    if(checked == true)
    {
        ui->green->hide();
       ui->red->show();
    }else{
        ui->red->hide();
        ui->green->show();
    }
}
