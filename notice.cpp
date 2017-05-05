#include "notice.h"
#include "ui_notice.h"
#include <QDialog>
notice::notice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::notice)
{
    ui->setupUi(this);
//    QDialog dialog(this);
//    dialog.setModal(true);
//    QWidget *pWid= new QWidget(NULL);
//   // pWid->setWindowFlags(Qt::FramelessWindowHint|Qt::Dialog);
//    pWid->setWindowModality(Qt::WindowModal);
//    pWid->show();
    //设置背景色
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#D4E6CA");
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    this->setWindowFlags(Qt::FramelessWindowHint);
}

notice::~notice()
{
    delete ui;
}

void notice::on_pushButton_clicked()
{
    this->hide();
}
