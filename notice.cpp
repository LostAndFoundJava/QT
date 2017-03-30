#include "notice.h"
#include "ui_notice.h"

notice::notice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::notice)
{
    ui->setupUi(this);
    //设置背景色
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, "#D4E6CA");
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

notice::~notice()
{
    delete ui;
}
