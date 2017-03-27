#include "systemset.h"
#include "ui_systemset.h"

Systemset::Systemset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Systemset)
{
    ui->setupUi(this);
    setWindowTitle(tr("系统设置"));

    ui->stackedWidget->setCurrentIndex(0);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);
    buttonGroup->addButton(ui->pushButton_1,1);
    buttonGroup->addButton(ui->pushButton_2,2);
    buttonGroup->addButton(ui->pushButton_3,3);
    buttonGroup->addButton(ui->pushButton_4,4);
    buttonGroup->addButton(ui->pushButton_5,5);
    buttonGroup->addButton(ui->pushButton_6,6);
    buttonGroup->addButton(ui->pushButton_7,7);
    buttonGroup->addButton(ui->pushButton_8,8);
    buttonGroup->addButton(ui->pushButton_9,9);
    buttonGroup->addButton(ui->pushButton_10,10);
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));

}

Systemset::~Systemset()
{
    delete ui;
}

void Systemset::buttonJudge(int buttonID)
{
    switch (buttonID) {
    case 1:
        ui->stackedWidget->setCurrentIndex(0);
        break;
    case 2:
        ui->stackedWidget->setCurrentIndex(1);
        break;
    case 3:
        ui->stackedWidget->setCurrentIndex(2);
        break;
    case 4:
        ui->stackedWidget->setCurrentIndex(3);
        break;
    case 5:
        ui->stackedWidget->setCurrentIndex(4);
        break;
    case 6:
        ui->stackedWidget->setCurrentIndex(5);
        break;
    case 7:
        ui->stackedWidget->setCurrentIndex(6);
        break;
    case 8:
        ui->stackedWidget->setCurrentIndex(7);
        break;
    case 9:
        ui->stackedWidget->setCurrentIndex(8);
        break;
    case 10:
        ui->stackedWidget->setCurrentIndex(9);
        break;
    default:
        break;
    }
}
