#include "log.h"
#include "ui_log.h"
#include <QGridLayout>
#include <sys/time.h>
#include <time.h>
#include <globl_data.h>
#include <QDebug>
#include<QString>
#include <CO_OD.h>
#include<QIODevice>
#include<QFile>
#include<QMessageBox>
#include <QWidget>
#include <QDialog>
#include <QTableWidgetItem>
#include<QTableWidget>
#include<QHBoxLayout>
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

    tableWidget = new QTableWidget(1,2,ui->tableWidget);
    tableWidget->resize(765,321);
    tableWidget->setRowHeight(0,55);
    tableWidget->setColumnWidth(0,382);
    tableWidget->setColumnWidth(1,382);
     QStringList header;
    tableWidget->setShowGrid(true); //设置表格边框
    header<<"年/月/日/时/分 "<<"操作人";
    tableWidget->setHorizontalHeaderLabels(header);
    tableWidget->verticalHeader()->hide();

    tableWidget_2 = new QTableWidget(1,7,ui->tableWidget_2);
    tableWidget_2->resize(438,311);
    tableWidget_2->setRowHeight(0,48);
    tableWidget_2->setColumnWidth(0,73);
    tableWidget_2->setColumnWidth(1,73);
    tableWidget_2->setColumnWidth(2,73);
    tableWidget_2->setColumnWidth(3,73);
    tableWidget_2->setColumnWidth(4,73);
    tableWidget_2->setColumnWidth(5,73);
     QStringList header_2;
    tableWidget_2->setShowGrid(true); //设置表格边框
    header_2<<"序号 "<<" 产品编号  "<<" 产品名称  "<<"NG时间"<<"信号 "<<"操作人";
    tableWidget_2->setHorizontalHeaderLabels(header_2);
    tableWidget_2->verticalHeader()->hide();

    connect(tableWidget_2,SIGNAL(cellClicked(int,int)),this,SLOT(getCell_2(int,int)));
    connect(tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(getCell(int,int)));
    //从数据库读出已存入的基本信息

  SQLITE sqlite;
   sqlite.openDatabase();
  QList<Record*> *ql1 = sqlite.queryRecord();
    if(ql1->size()>0)
    {
        tableWidget->setRowCount(ql1->size());
        tableWidget_2->setRowCount(ql1->size());
        tableWidget->setColumnCount(2);
        tableWidget_2->setColumnCount(6);
        for(int i = 0;i < ql1->size();i++)
        {
            Record *r = ql1->at(i);
            //qDebug()<<"+++++++++++++++++++";
            //qDebug()<<p->getProductNumber();
            //qDebug()<<"+++++++++++++++++++";
            tableWidget->setRowHeight(i,55);
            tableWidget->setColumnWidth(0,382);
            tableWidget->setColumnWidth(1,382);

            tableWidget->setItem(i,0,new QTableWidgetItem(r->getLogTime()));
            tableWidget->setItem(i,1,new QTableWidgetItem(r->getLogOperator()));

            tableWidget_2->setRowHeight(i,48);
            tableWidget_2->setColumnWidth(0,73);
            tableWidget_2->setColumnWidth(1,73);
            tableWidget_2->setColumnWidth(2,73);
            tableWidget_2->setColumnWidth(3,73);
            tableWidget_2->setColumnWidth(4,73);
            tableWidget_2->setColumnWidth(5,73);

            tableWidget_2->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i)));
            tableWidget_2->setItem(i,1,new QTableWidgetItem(r->getNgProductNumber()));
            tableWidget_2->setItem(i,2,new QTableWidgetItem(r->getNgProductName()));
            tableWidget_2->setItem(i,3,new QTableWidgetItem(r->getNgTime()));
            tableWidget_2->setItem(i,4,new QTableWidgetItem(r->getNgSignal()));
            tableWidget_2->setItem(i,5,new QTableWidgetItem(r->getNgOperator())); }

    }else{
        tableWidget->setRowCount(1);
        tableWidget_2->setRowCount(1);
        tableWidget->setColumnCount(2);
        tableWidget_2->setColumnCount(6);
        tableWidget->setRowHeight(0,55);
        tableWidget->setColumnWidth(0,382);
        tableWidget->setColumnWidth(1,382);
        tableWidget_2->setRowHeight(0,48);
        tableWidget_2->setColumnWidth(0,73);
        tableWidget_2->setColumnWidth(1,73);
        tableWidget_2->setColumnWidth(2,73);
        tableWidget_2->setColumnWidth(3,73);
        tableWidget_2->setColumnWidth(4,73);
        tableWidget_2->setColumnWidth(5,73);
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

}
void Log::getData(QString text,QLineEdit *n,int row,int column)
{
   QTableWidgetItem *m = new QTableWidgetItem;
      m->setText(text);
    tableWidget->setItem(row,column,m);
}
void Log::LogInput(QLineEdit *n,int row,int column)
{
    Input=new input();
    Input->setLogReference(n,row,column);
    Input->move(pos().x(),pos().y());
    Input->show();
    connect(Input,SIGNAL(setData(QString,QLineEdit *,int,int)),this,SLOT(getData(QString,QLineEdit *,int,int)));
}
void Log::getCell(int row,int column)
{
    this->row1=row;
    this->column1=column;
    LogInput(ui->lineEdit,row1,column1);
}
void Log::getData_2(QString text,QLineEdit *n,int row,int column)
{
   QTableWidgetItem *m_2 = new QTableWidgetItem;
      m_2->setText(text);
    tableWidget_2->setItem(row,column,m_2);
}
void Log::LogInput_2(QLineEdit *n,int row,int column)
{
    Input=new input();
    Input->setLogReference(n,row,column);
    Input->move(pos().x(),pos().y());
    Input->show();
    connect(Input,SIGNAL(setData(QString,QLineEdit *,int,int)),this,SLOT(getData_2(QString,QLineEdit *,int,int)));
}
void Log::getCell_2(int row,int column)
{
    this->row1=row;
    this->column1=column;
    LogInput_2(ui->lineEdit,row1,column1);
}

void Log::on_USBOuput_clicked()
{

//    if(QFile::exists("/media/sda"))
//    {
//        qDebug("12");
//        QFile file("/medis/sda");
//        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
//           { qDebug()<<file.errorString();}
//        else{
//           QFile file("a.txt");
//           SQLITE sqlite;
//           sqlite.openDatabase();
//           QList<Record*> *ql = sqlite.queryRecord();
//           for(int i=0;i<=ql->size();i++)
//           {
//               for(int j=0;j<=6;j++)
//               {

//               }
//           }

//        }
//    }else{

//        QMessageBox::critical(0,"critical message","未检测到USB设备",
//                           QMessageBox::Ok | QMessageBox::Default,
//                              QMessageBox::Cancel | QMessageBox::Escape,0);

//    }
}

void Log::on_Save_clicked()
{

}
void Log::saveData(){
//    Record *r = new Record;

}
