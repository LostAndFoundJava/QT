    #include "log.h"
#include "ui_log.h"
#include <QGridLayout>
#include <QDebug>
#include "CANopen.h"
Log::Log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);
    setWindowTitle(tr("日志"));

    ui->tableWidget->setColumnWidth(0,365);
    ui->tableWidget->setColumnWidth(1,365);
    ui->tableWidget->setRowHeight(0,55);
    ui->tableWidget->setRowHeight(1,55);
    ui->tableWidget->setRowHeight(2,55);
    ui->tableWidget->setRowHeight(3,55);
    ui->tableWidget->setRowHeight(4,55);

    ui->tableWidget_2->setColumnWidth(0,70);
    ui->tableWidget_2->setColumnWidth(1,70);
    ui->tableWidget_2->setColumnWidth(2,70);
    ui->tableWidget_2->setColumnWidth(3,70);
    ui->tableWidget_2->setColumnWidth(4,70);
    ui->tableWidget_2->setColumnWidth(5,70);
    ui->tableWidget_2->setRowHeight(0,48);
    ui->tableWidget_2->setRowHeight(1,48);
    ui->tableWidget_2->setRowHeight(2,48);
    ui->tableWidget_2->setRowHeight(3,48);
    ui->tableWidget_2->setRowHeight(4,48);
    ui->tableWidget_2->setRowHeight(5,48);

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
    dataTx[0]=0x60;
    if(err1 == 0) {
        err1 = sdoClientDownload(
                CO->SDOclient,
                2,
                0x6000,
                0x01,
                dataTx,
                dataTxLen,
                &SDOabortCode,
                500,
                0);
        if(err1==0)
            qDebug("send SDO to node 2 success");
        else
            qDebug("send SDO to node 2 failed in error:%d",err1);
    }
    //--------------------------------------------------------------------------//

    qDebug("0x600001:%Xh 0x600002:%Xh 0x620001:%Xh 0x620002:%Xh",CO_OD_RAM.readInput8Bit[0],
           CO_OD_RAM.readInput8Bit[1],CO_OD_RAM.writeOutput8Bit[0],CO_OD_RAM.writeOutput8Bit[1]);
    qDebug("0x640101:%Xh 0x640102:%Xh ",CO_OD_RAM.readAnalogueInput32Bit[0],
           CO_OD_RAM.readAnalogueInput32Bit[1]);

}

Log::~Log()
{
    delete ui;
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
