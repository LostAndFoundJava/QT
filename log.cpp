    #include "log.h"
#include "ui_log.h"
#include <QGridLayout>
#include <sys/time.h>
#include <time.h>
#include <globl_data.h>
#include <QDebug>
#include "CANopen.h"
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
#include<QDir>
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

    int err1=0;
    uint8_t dataTx[100]; /* SDO transmit buffer */
    uint32_t dataTxLen = 1;  /* Length of data to transmit. */
    uint32_t SDOabortCode = 1;
    //------------------------------发送SDO-------------------------------------//
//    dataTx[0]=0x50;
//    if(err1 == 0) {
//        err1 = sdoClientDownload(
//                CO->SDOclient,
//                3,
//                0x6000,
//                0x01,
//                dataTx,
//                dataTxLen,
//                &SDOabortCode,
//                500,
//                0);
//        if(err1==0)
//            qDebug("send SDO to node 3 success");
//        else
//            qDebug("send SDO to node 3 failed in error:%d",err1);
//    }
    //--------------------------------------------------------------------------//

    //-------------------------------发送SDO-------------------------------------//
//    dataTx[0]=0x60;
//    if(err1 == 0) {
//        err1 = sdoClientDownload(
//                CO->SDOclient,
//                2,
//                0x6000,
//                0x01,
//                dataTx,
//                dataTxLen,
//                &SDOabortCode,
//                500,
//                0);
//        if(err1==0)
//            qDebug("send SDO to node 2 success");
//        else
//            qDebug("send SDO to node 2 failed in error:%d",err1);
  //  }
    //--------------------------------------------------------------------------//

//    qDebug("0x600001:%Xh 0x600002:%Xh 0x620001:%Xh 0x620002:%Xh",CO_OD_RAM.readInput8Bit[0],
//           CO_OD_RAM.readInput8Bit[1],CO_OD_RAM.writeOutput8Bit[0],CO_OD_RAM.writeOutput8Bit[1]);
//    qDebug("0x640101:%Xh 0x640102:%Xh ",CO_OD_RAM.readAnalogueInput32Bit[0],
//           CO_OD_RAM.readAnalogueInput32Bit[1]);

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


    //从数据库读出已存入的基本信息
//登录日志数据库读取
  SQLITE sqlite;
   sqlite.openDatabase();
  QList<Record*> *ql = sqlite.queryLogRecord();
    if(ql->size()>0)
    {
        tableWidget->setRowCount(ql->size());
        tableWidget->setColumnCount(2);
        for(int i = 0;i < ql->size();i++)
        {
            Record *r = ql->at(i);
            //qDebug()<<"+++++++++++++++++++";
            //qDebug()<<p->getProductNumber();
            //qDebug()<<"+++++++++++++++++++";
            tableWidget->setRowHeight(i,55);
            tableWidget->setColumnWidth(0,382);
            tableWidget->setColumnWidth(1,382);

            tableWidget->setItem(i,0,new QTableWidgetItem(r->getLogTime()));
            tableWidget->setItem(i,1,new QTableWidgetItem(r->getLogOperator()));

            }

    }else{
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(2);
        tableWidget->setRowHeight(0,55);
        tableWidget->setColumnWidth(0,382);
        tableWidget->setColumnWidth(1,382);
    }
    sqlite.closeDatabase();

}

Log::~Log()
{
    //delete ui;
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

//ng
void Log::on_NGButton_clicked()
{
        //NG日志数据库读取
            SQLITE sqlite_2;
             sqlite_2.openDatabase();
            QList<Record*> *ql_2 = sqlite_2.queryNgRecord();
              if(ql_2->size()>0)
              {
                  tableWidget_2->setRowCount(ql_2->size());
                  tableWidget_2->setColumnCount(6);
                  for(int i = 0;i < ql_2->size();i++)
                  {
                      Record *r = ql_2->at(i);


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
                  tableWidget_2->setRowCount(1);
                  tableWidget_2->setColumnCount(6);
                  tableWidget_2->setRowHeight(0,48);
                  tableWidget_2->setColumnWidth(0,73);
                  tableWidget_2->setColumnWidth(1,73);
                  tableWidget_2->setColumnWidth(2,73);
                  tableWidget_2->setColumnWidth(3,73);
                  tableWidget_2->setColumnWidth(4,73);
                  tableWidget_2->setColumnWidth(5,73);
              }
              sqlite_2.closeDatabase();
    ui->Stack->setCurrentIndex(1);
    ui->DisLabel->setText(tr("NG日志"));
}

void Log::on_Return_clicked()
{
    close();
}


//登陆日志
void Log::on_LoadLog_2_clicked()
{
    ui->Stack->setCurrentIndex(0);
    ui->DisLabel->setText(tr("登陆日志"));
}



void Log::on_USBOuput_clicked()
{
    if(QDir("/media/sda").exists())
    {
        QDir file("/media/sda");

               QFile file1("a.txt");
               if(!file1.open(QFile::WriteOnly | QFile::Truncate))
               {
                    qDebug()<<file1.errorString();
               }else
               {
                   QTextStream in(&file1);
                   SQLITE sqlite;
                   sqlite.openDatabase();
                   QList<Record*> *ql = sqlite.queryLogRecord();
                   for(int i=0;i<=ql->size();i++)
                   {
                           Record *record=ql->at(i);
                            QString logtime=record->getLogTime();
                            QString logoperator=record->getLogOperator();
                            in<<logtime;
                            in<<logoperator;
                   }
                   sqlite.closeDatabase();
                   SQLITE sqlite_2;
                   sqlite_2.openDatabase();
                   QList<Record*> *ql_2 = sqlite.queryNgRecord();
                   for(int i=0;i<=ql_2->size();i++)
                   {
                           Record *record_2=ql_2->at(i);
                            QString ngproductnumber=record_2->getNgProductNumber();
                            QString ngproductname=record_2->getNgProductName();
                            QString ngtime=record_2->getNgTime();
                            QString ngsignal=record_2->getNgSignal();
                            QString ngoperator=record_2->getNgOperator();
                            in<<ngproductnumber;
                            in<<ngproductname;
                            in<<ngtime;
                            in<<ngsignal;
                            in<<ngoperator<<'\n';
                   }
                   sqlite_2.closeDatabase();
                   file1.close();
               }
               file1.copy("/media/sda");
    }else{

        QMessageBox::critical(0,"critical message","未检测到USB设备",
                           QMessageBox::Ok | QMessageBox::Default,
                              QMessageBox::Cancel | QMessageBox::Escape,0);

    }
}
