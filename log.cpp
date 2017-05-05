#include "log.h"
#include "ui_log.h"
#include <QGridLayout>
#include <sys/time.h>
#include <time.h>
#include <globl_data.h>
#include <QDebug>
#include<QString>
#include<QtGui/QWidget>
#include <CO_OD.h>
#include<QIODevice>
#include<QFile>
#include<QMessageBox>
Log::Log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);
    setWindowTitle(tr("日志"));

    //设置背景色
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#D4E6CA");
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->Stack->setCurrentIndex(0);
    ui->DisLabel->setText(tr("登陆日志"));

    char str[15];
    sprintf(str,"%d",CO_OD_RAM.readInput8Bit[0]);
    qDebug(str);

    //时间显示
    valueInt();
    QTimer *timer = new QTimer(this);
    this->setFocusPolicy(Qt::NoFocus);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
    timer->start(500);

    //从数据库读出已存入的基本信息
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止表格修改

    SQLITE sqlite;
    sqlite.openDatabase();
    QList<Record*> *ql = sqlite.queryRecord();


    ui->tableWidget->setColumnCount(2);
    ui->tableWidget_2->setColumnCount(6);
    if(ql->length()>0)
    {
        ui->tableWidget->setRowCount(ql->size());
        ui->tableWidget_2->setRowCount(ql->size());
        for(int i = 0;i < ql->size();i++)
        {
            Record *p = ql->at(i);
            //qDebug()<<"+++++++++++++++++++";
            //qDebug()<<p->getProductNumber();
            //qDebug()<<"+++++++++++++++++++";
            ui->tableWidget->setRowHeight(i,55);
            ui->tableWidget->setColumnWidth(0,382);
            ui->tableWidget->setColumnWidth(1,382);

            ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->getLogTime()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->getLogOperator()));

            ui->tableWidget_2->setRowHeight(i,48);
            ui->tableWidget_2->setColumnWidth(0,73);
            ui->tableWidget_2->setColumnWidth(1,73);
            ui->tableWidget_2->setColumnWidth(2,73);
            ui->tableWidget_2->setColumnWidth(3,73);
            ui->tableWidget_2->setColumnWidth(4,73);
            ui->tableWidget_2->setColumnWidth(5,73);

            ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i)));
            ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(p->getNgProductNumber()));
            ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(p->getNgProductName()));
            ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(p->getNgTime()));
            ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(p->getNgSignal()));
            ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(p->getNgOperator())); }

    }else{
        ui->tableWidget->setRowCount(1);
        ui->tableWidget_2->setRowCount(1);
        ui->tableWidget->setRowHeight(0,55);
        ui->tableWidget->setColumnWidth(0,382);
        ui->tableWidget->setColumnWidth(1,382);
        ui->tableWidget_2->setRowHeight(0,48);
        ui->tableWidget_2->setColumnWidth(0,73);
        ui->tableWidget_2->setColumnWidth(1,73);
        ui->tableWidget_2->setColumnWidth(2,73);
        ui->tableWidget_2->setColumnWidth(3,73);
        ui->tableWidget_2->setColumnWidth(4,73);
        ui->tableWidget_2->setColumnWidth(5,73);
    }
    sqlite.closeDatabase();
}

Log::~Log()
{
    delete ui;
}
char Log::UsbRead ()
{

}

void Log::valueInt(void)
{
    System_RunTime.hour=0;
    System_RunTime.minute=0;
    System_RunTime.second=0;
    ShowTime();
}

void Log::ShowTime()
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


void Log::on_NGButton_clicked()
{
    ui->Stack->setCurrentIndex(1);
    ui->DisLabel->setText(tr("NG日志"));
}

void Log::on_Return_clicked()
{
    close();
}



void Log::on_LoadLog_2_clicked()
{
    ui->Stack->setCurrentIndex(0);
    ui->DisLabel->setText(tr("登陆日志"));
}
void Log::ContentInput(){
    Input=new input();

    //Input->move(pos().x(),pos().y());
    //Input->show();

}
void Log::getData(QString text,int row,int column)
{
  ui->tableWidget_2->item(row,column)->setText(text);
  qDebug("printf('%d',row,'%d',column)");

}
void Log::on_tableWidget_2_cellClicked(int row, int column)
{
     row1 = row;
     column1=column;
    Input=new input();
    Input->move(pos().x(),pos().y());
    Input->show();
    Input->setReferenceA(row1,column1);

    connect(Input,SIGNAL(setData1(QString,int,int)),this,SLOT(getData(QString,int,int)));
}


void Log::on_USBOuput_clicked()
{
    qDebug("43");
    if(QFile::exists("/media/sda"))
    {
        qDebug("12");
        QFile file("/medis/sda");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
           { qDebug()<<file.errorString();}
        else{
           QFile file("a.txt");
           SQLITE sqlite;
           sqlite.openDatabase();
           QList<Record*> *ql = sqlite.queryRecord();
           for(int i=0;i<=ql->size();i++)
           {
               for(int j=0;j<=6;j++)
               {

               }
           }

        }
    }else{

        QMessageBox::critical(0,"critical message","未检测到USB设备",
                           QMessageBox::Ok | QMessageBox::Default,
                              QMessageBox::Cancel | QMessageBox::Escape,0);

    }
}

void Log::on_Save_clicked()
{

}
void Log::saveData(){
    Record *r = new Record;

}
