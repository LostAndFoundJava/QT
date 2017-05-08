#include "management.h"
#include "ui_management.h"
#include <string>
#include <QWidget>
#include <sys/time.h>
#include <time.h>
#include <globl_data.h>
#include <QDialog>
#include <QColor>
#include "CANopen.h"
#include<input.h>
#include<QLineEdit>
Management::Management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Management)
{
//    qDebug("0x600001:%Xh 0x600002:%Xh 0x620001:%Xh 0x620002:%Xh\n",CO_OD_RAM.readInput8Bit[0],
//           CO_OD_RAM.readInput8Bit[1],CO_OD_RAM.writeOutput8Bit[0],CO_OD_RAM.writeOutput8Bit[1]);
//    qDebug("0x640101:%Xh 0x640102:%Xh ",CO_OD_RAM.readAnalogueInput32Bit[0],
//           CO_OD_RAM.readAnalogueInput32Bit[1]);

    ui->setupUi(this);
    setWindowTitle(tr("产品管理"));
    //设置背景色
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#D4E6CA");
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    this->setWindowFlags(Qt::FramelessWindowHint);

    //标签页
    ui->tableWidget->setColumnWidth(0,120);
    ui->tableWidget->setColumnWidth(1,120);
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

    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setStyleSheet("QTabBar::tab{width:181px}");


    //镀铝膜隐藏
    ui->AluminizerButton->hide();

    //基本信息

    //弹出键盘

    ui->NumEdit->installEventFilter(this);
    ui->NameEdit->installEventFilter(this);
    ui->LengthEdit->installEventFilter(this);
    ui->SpeedEdit->installEventFilter(this);

    ui->low->setChecked(true);
    ui->high->setStyleSheet("color:#a1a3a6");
    ui->widget_2->hide();
    ui->one_p->setChecked(true);

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


    //tablewidget设置数据
    //从数据库读出已存入的基本信息
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止表格修改

    SQLITE sqlite;
    sqlite.openDatabase();
    QList<Product*> *ql = sqlite.queryProduct();

    ui->tableWidget->setRowCount(ql->size());
    ui->tableWidget->setColumnCount(2);

    for(int i = 0;i < ql->size();i++)
    {
        Product *p = ql->at(i);
        //qDebug()<<"+++++++++++++++++++";
        //qDebug()<<p->getProductNumber();
        //qDebug()<<"+++++++++++++++++++";
        ui->tableWidget->setRowHeight(i,30);
        ui->tableWidget->setColumnWidth(0,120);
        ui->tableWidget->setColumnWidth(1,120);

        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->getProductName()));
    }

    sqlite.closeDatabase();


    ////////////////////////////////////////////////////////////////////////////////////
    connect(ui->tableWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(tableWidgtShowInformation(QModelIndex)));
    //tabwidget设置数据

    //设置正反检测 0：正 1：反
    PNTestFlag = 0;
    ui->PositiveTest->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
    ui->NagtiveTest->setStyleSheet("QPushButton{background-color:#5394a0;color:#fff;border-radius:5px;}");
    //包装
    ui->packButton->setChecked(true);
    ui->AluminizerButton->show();
    PackFlag=0;
    //
    LearnFlag=0;
    //输送带自动往复
    AutoFlag=1;
    //剔除
    ui->RemovedButton->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
    ui->StopButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
    ui->BackButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
    //剔除设置
    ui->RmoveTime->setDisabled(false);
    ui->RmoveTime->installEventFilter(this);
    ui->RmoveTime->setStyleSheet("border:none;border-bottom:1px solid #000");
    ui->label_26->setStyleSheet("color: rgb(33, 28, 23);");
     ui->label_21->setStyleSheet("color: rgb(33, 28, 23);");

    ui->RmoveKeep->setDisabled(false);
    ui->RmoveKeep->installEventFilter(this);
    ui->RmoveKeep->setStyleSheet("border:none;border-bottom:1px solid #000");
    ui->label_16->setStyleSheet("color: rgb(33, 28, 23);");
    ui->label_22->setStyleSheet("color: rgb(33, 28, 23);");

    ui->OddRmove->setDisabled(false);
    ui->OddRmove->setStyleSheet("color: rgb(33, 28, 23);");
    //停机设置
    ui->StopTime->setDisabled(true);
    ui->StopTime->removeEventFilter(this);
    ui->StopTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
    ui->label_17->setStyleSheet("color:#a1a3a6");
    ui->label_23->setStyleSheet("color:#a1a3a6");

    ui->AutoStart->setDisabled(true);
    ui->StartTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
    ui->label_24->setStyleSheet("color:#a1a3a6");
    //倒带设置
    ui->BackTime->setDisabled(true);
    ui->BackTime->removeEventFilter(this);
    ui->BackTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
    ui->label_19->setStyleSheet("color:#a1a3a6");
    ui->label_25->setStyleSheet("color:#a1a3a6");

    ui->Light->setDisabled(true);
    //


}
bool Management::eventFilter(QObject *watched,QEvent *event)
{
    if(watched==ui->NumEdit)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            ContentInput(ui->NumEdit);
        }
    }
    if(watched==ui->NameEdit)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
           ContentInput(ui->NameEdit);
        }
    }
    if(watched==ui->LengthEdit)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
           ContentInput(ui->LengthEdit);
        }
    }
    if(watched==ui->SpeedEdit)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
           ContentInput(ui->SpeedEdit);
        }
    }
    if(watched==ui->LightTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
           ContentInput(ui->LightTime);
        }
    }
    if(watched==ui->PositiveTest)
    {

        if(event->type()==QEvent::MouseButtonPress)
        {
            PNTestFlag = 0;
            ui->PositiveTest->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
            ui->NagtiveTest->setStyleSheet("QPushButton{background-color:#5394a0;color:#fff;border-radius:5px;}");
        }
    }
    if(watched==ui->NagtiveTest)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            PNTestFlag = 1;
            ui->NagtiveTest->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
            ui->PositiveTest->setStyleSheet("QPushButton{background-color:#5394a0;color:#fff;border-radius:5px;}");
        }
    }
    if(watched==ui->RmoveTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
           ContentInput(ui->RmoveTime);
        }
    }
    if(watched==ui->RmoveKeep)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
             ContentInput(ui->RmoveKeep);
        }
    }
    if(watched==ui->StopTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            ContentInput(ui->StopTime);
        }
    }
    if(watched==ui->StartTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            ContentInput(ui->StartTime);
        }
    }
    if(watched==ui->BackTime)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
             ContentInput(ui->BackTime);
        }
    }
//剔除设置
if(watched==ui->RemovedButton)
{
    if(event->type() == QEvent::MouseButtonPress)
    {

        ui->RemovedButton->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
        ui->StopButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->BackButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        //剔除设置
        ui->RmoveTime->setDisabled(false);
        ui->RmoveTime->installEventFilter(this);
        ui->RmoveTime->setStyleSheet("border:none;border-bottom:1px solid #000");
        ui->label_26->setStyleSheet("color: rgb(33, 28, 23);");
         ui->label_21->setStyleSheet("color: rgb(33, 28, 23);");

        ui->RmoveKeep->setDisabled(false);
        ui->RmoveKeep->installEventFilter(this);
        ui->RmoveKeep->setStyleSheet("border:none;border-bottom:1px solid #000");
        ui->label_16->setStyleSheet("color: rgb(33, 28, 23);");
        ui->label_22->setStyleSheet("color: rgb(33, 28, 23);");

        ui->OddRmove->setDisabled(false);
        ui->OddRmove->setStyleSheet("color: rgb(33, 28, 23);");
        //停机设置
        ui->StopTime->setDisabled(true);
        ui->StopTime->removeEventFilter(this);
        ui->StopTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_17->setStyleSheet("color:#a1a3a6");
        ui->label_23->setStyleSheet("color:#a1a3a6");

        ui->AutoStart->setDisabled(true);
        ui->StartTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_24->setStyleSheet("color:#a1a3a6");
        //倒带设置
        ui->BackTime->setDisabled(true);
        ui->BackTime->removeEventFilter(this);
        ui->BackTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_19->setStyleSheet("color:#a1a3a6");
        ui->label_25->setStyleSheet("color:#a1a3a6");

        ui->Light->setDisabled(true);
    }
}
//停机设置
if(watched==ui->StopButton)
{
    if(event->type() == QEvent::MouseButtonPress)
    {

        ui->StopButton->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
        ui->RemovedButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->BackButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        //剔除设置
        ui->RmoveTime->setDisabled(true);
        ui->RmoveTime->removeEventFilter(this);
        ui->RmoveTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_26->setStyleSheet("color: #a1a3a6;");
        ui->label_21->setStyleSheet("color: #a1a3a6;");

        ui->RmoveKeep->setDisabled(true);
        ui->RmoveKeep->removeEventFilter(this);
        ui->RmoveKeep->setStyleSheet("border:none;border-bottom:1px solid  #a1a3a6");
        ui->label_16->setStyleSheet("color: #a1a3a6;");
        ui->label_22->setStyleSheet("color: #a1a3a6;");

        ui->OddRmove->setDisabled(true);
        ui->OddRmove->setStyleSheet("color: #a1a3a6;");
        //停机设置
        ui->StopTime->setDisabled(false);
        ui->StopTime->installEventFilter(this);
        ui->StopTime->setStyleSheet("border:none;border-bottom:1px solid #000");
        ui->label_17->setStyleSheet("color:rgb(33, 28, 23);");
        ui->label_23->setStyleSheet("color:rgb(33, 28, 23);");

        ui->AutoStart->setDisabled(false);
        ui->StartTime->setStyleSheet("border:none;border-bottom:1px solid #000");
        ui->label_24->setStyleSheet("color:rgb(33, 28, 23);");
        //倒带设置
        ui->BackTime->setDisabled(true);
        ui->BackTime->removeEventFilter(this);
        ui->BackTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_19->setStyleSheet("color:#a1a3a6");
        ui->label_25->setStyleSheet("color:#a1a3a6");

        ui->Light->setDisabled(true);
    }
}
//倒带设置
if(watched==ui->BackButton)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        ui->BackButton->setStyleSheet("QPushButton{background-color:#b8dedf;color:#000;border-radius:5px;}");
        ui->StopButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        ui->RemovedButton->setStyleSheet("QPushButton{background-color:#5394A0;color:#fff;border-radius:5px;}");
        //剔除设置
        ui->RmoveTime->setDisabled(true);
        ui->RmoveTime->removeEventFilter(this);
        ui->RmoveTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_26->setStyleSheet("color: #a1a3a6;");
        ui->label_21->setStyleSheet("color: #a1a3a6;");

        ui->RmoveKeep->setDisabled(true);
        ui->RmoveKeep->removeEventFilter(this);
        ui->RmoveKeep->setStyleSheet("border:none;border-bottom:1px solid  #a1a3a6");
        ui->label_16->setStyleSheet("color: #a1a3a6;");
        ui->label_22->setStyleSheet("color: #a1a3a6;");

        ui->OddRmove->setDisabled(true);
        ui->OddRmove->setStyleSheet("color: #a1a3a6;");
        //停机设置
        //停机设置
        ui->StopTime->setDisabled(true);
        ui->StopTime->removeEventFilter(this);
        ui->StopTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_17->setStyleSheet("color:#a1a3a6");
        ui->label_23->setStyleSheet("color:#a1a3a6");

        ui->AutoStart->setDisabled(true);
        ui->StartTime->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_24->setStyleSheet("color:#a1a3a6");
         //倒带设置
        ui->BackTime->setDisabled(false);
        ui->BackTime->installEventFilter(this);
        ui->BackTime->setStyleSheet("border:none;border-bottom:1px solid #000");
        ui->label_19->setStyleSheet("color:rgb(33, 28, 23);");
        ui->label_25->setStyleSheet("color:rgb(33, 28, 23);");

        ui->Light->setDisabled(false);
    }
}
   return QWidget::eventFilter(watched,event);
}
void Management::ContentInput(QLineEdit *input_edit){
    Input=new input();
    Input->setReference(input_edit);
    Input->move(pos().x(),pos().y());
    Input->show();
    connect(Input,SIGNAL(setData(QString,QLineEdit *,int,int)),this,SLOT(getData(QString,QLineEdit *)));
}
void Management::getData(QString text,QLineEdit *input_edit)
{
  input_edit->insert(text);

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
//镀铝膜
void Management::on_AluminizerButton_clicked(bool checked)
{


    if(checked==true)
    {
        PackFlag=2;
        ui->bulkButton->setDisabled(true);
        ui->bulkButton->setStyleSheet("color:#a1a3a6");

        ui->low->setStyleSheet("color:#a1a3a6");
        ui->low->setCheckable(false);
        ui->high->setStyleSheet("color:#a1a3a6");
        ui->high->setCheckable(false);
    }
    else if(checked==false)
    {
        PackFlag=0;
        ui->bulkButton->setDisabled(false);
        ui->bulkButton->setStyleSheet("color: rgb(33, 28, 23);");

        ui->low->setStyleSheet("color:rgb(33, 28, 23);");
        ui->low->setCheckable(true);
        ui->high->setStyleSheet("color:rgb(33, 28, 23);");
        ui->high->setCheckable(true);

    }
}
//散装逻辑
void Management::on_bulkButton_clicked(bool checked)
{
    if(checked == true)
    {
        PackFlag=1;
        ui->AluminizerButton->hide();
        //长度禁止
        ui->LengthEdit->setDisabled(true);
        ui->LengthEdit->removeEventFilter(this);
        ui->LengthEdit->setStyleSheet("border:none;border-bottom:1px solid #a1a3a6");
        ui->label_2->setStyleSheet("color:#a1a3a6");
         ui->label_27->setStyleSheet("color:#a1a3a6");
        //反检测禁止
        ui->NagtiveTest->removeEventFilter(this);
        ui->NagtiveTest->setStyleSheet("background-color:#a1a3a6;border-radius:5px");
        ui->PositiveTest->removeEventFilter(this);
        ui->PositiveTest->setStyleSheet("background-color:#b8dedf;color:#000;border-radius:5px;");
    }
}

//包装逻辑
void Management::on_packButton_clicked(bool checked)
{
    if(checked == true)
    {
        PackFlag=0;
        ui->AluminizerButton->show();
        ui->LengthEdit->setDisabled(false);
        ui->LengthEdit->installEventFilter(this);
        ui->LengthEdit->setStyleSheet("border:none;border-bottom:1px solid #000");
        ui->label_2->setStyleSheet("color: rgb(33, 28, 23);");
         ui->label_27->setStyleSheet("color: rgb(33, 28, 23);");
        //反检测禁止
        ui->NagtiveTest->installEventFilter(this);
        ui->NagtiveTest->setStyleSheet("background-color: rgb(83, 148, 160);border-radius:5px;color:rgb(255, 250, 240)");
        ui->PositiveTest->installEventFilter(this);
    }
}

//产品学习弹出
void Management::on_LearningButton_clicked()
{
    if(!(ui->NumEdit->text().isEmpty())&&!(ui->NameEdit->text().isEmpty())&&!(ui->SpeedEdit->text().isEmpty())&&!(ui->LightTime->text().isEmpty()))
    {
        if(PackFlag==0||PackFlag==2)
        {
            if(!(ui->LengthEdit->text().isEmpty()))
            {
                SaveData();
                Learn->show();
                Learn->move(pos().x(),pos().y());
                this->hide();
            }
        }else if(PackFlag==1)
        {
            SaveData();
            Learn->show();
            Learn->move(pos().x(),pos().y());
            this->hide();
        }
    }else{
        Notice=new notice();
        Notice->show();
       Notice->move(pos().x(),pos().y());

//        QDialog *dlg = new QDialog(this);

//        dlg->resize(400,200);

//        QLabel *ql = new QLabel(dlg);
//        ql->setGeometry(110,10,250,100);
//        ql->setText(tr("信息未填写完整！！"));

//        QPushButton *qb = new QPushButton(dlg);
//        qb->setGeometry(250,120,60,25);
//        qb->setText(tr("确定"));

//        connect(qb,SIGNAL(clicked()),dlg,SLOT(close()));
//        dlg->exec();
//        Learn->show();
//        Learn->move(pos().x(),pos().y());
//        this->hide();
    }
}
void Management::SaveData(){
    Product *p = new Product;
    p->setProductNumber(ui->NumEdit->text());
    p->setProductName(ui->NameEdit->text());
    p->setProductSpeed(ui->SpeedEdit->text());
    p->setProductPhotoelectricTime(ui->LightTime->text());
    QString autoflag=tr("%1").arg(AutoFlag);
    p->setProductAutomaticFlag(autoflag);
    QString packflag=tr("%1").arg(PackFlag);
    p->setProductPackage(packflag);
    QString pntestflag=tr("%1").arg(PNTestFlag);
    p->setProductDetect(pntestflag);
    QString learnflag=tr("%1").arg(LearnFlag);
    p->setProductFeatures(learnflag);
    if(PackFlag==0||PackFlag==2)
    {
        p->setProductLength(ui->LengthEdit->text());

    }
    SQLITE sqlite;
    sqlite.openDatabase();
    sqlite.insertProduct(p->getProductName(),p->getProductName(),p->getProductLength(),p->getProductSpeed()
                          ,p->getProductPackage(),p->getProductFeatures(),p->getProductDetect()
                          ,p->getProductPhotoelectricTime(),p->getProductAutomaticFlag(),p->getProductExcluseiveSetting());
    sqlite.closeDatabase();
    int row = ui->tableWidget->rowCount();

    ui->tableWidget->setRowCount(row+1);
    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setRowHeight(row,30);
    ui->tableWidget->setColumnWidth(0,120);
    ui->tableWidget->setColumnWidth(1,120);


    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString("%1").arg(row)));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(p->getProductName()));
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
//输送带自动往复
void Management::on_radioButton_clicked(bool checked)
{
    if(checked == true)
    {
        AutoFlag=0;
    }else if(checked == false)
    {
        AutoFlag=1;
    }
}

//tableWidget 点击事件
void Management::tableWidgtShowInformation(QModelIndex qmi)
{
    //qDebug()<<qmi.row();
    //qDebug()<<qmi.column();
}


//频率
void Management::on_low_clicked(bool checked)
{
    if(checked==true)
    {
        LearnFlag=0;
       ui->widget_2->hide();
       ui->low->setStyleSheet("color: rgb(33, 28, 23);");
        ui->high->setStyleSheet("color:#a1a3a6");
    }
}
void Management::on_high_clicked(bool checked)
{
    if(checked==true)
    {
        LearnFlag=1;
        ui->widget_2->show();
        ui->high->setStyleSheet("color: rgb(33, 28, 23);");
         ui->low->setStyleSheet("color:#a1a3a6");
    }
}
void Management::on_one_p_clicked(bool checked)
{
    if(checked==true)
    {
        LearnFlag=1;
    }
}
void Management::on_two_p_clicked(bool checked)
{
    if(checked==true)
    {
        LearnFlag=2;
    }
}

void Management::on_three_p_clicked(bool checked)
{
    if(checked==true)
    {
        LearnFlag=3;
    }
}
