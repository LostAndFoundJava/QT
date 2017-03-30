#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <QWidget>
#include <QAbstractButton>
#include <qmyedit.h>
#include <config.h>
#include <QFileDialog>
#include "globl_data.h"
#include <learn.h>
class verify;
namespace Ui {
class Management;
}

class Management : public QWidget
{
    Q_OBJECT

public:
    explicit Management(QWidget *parent = 0);
    ~Management();

private slots:

    //void on_buttonBox_1_clicked(QAbstractButton *button);

    void on_AluminizerButton_clicked(bool checked);


    void on_packButton_clicked(bool checked);
     void on_LearningButton_clicked();

    //void myEditClicked1();

     void on_bulkButton_clicked(bool checked);

     void on_FinishButton_clicked(bool checked);

     void on_OddRmove_clicked(bool checked);

     void on_AutoStart_clicked(bool checked);

     void on_Light_clicked(bool checked);

private:
    Ui::Management *ui;
    QButtonGroup *PackingStyleGroup;
    class learn *Learn;
    void valueInt(void);

    //正反检测标志位
    int PNTestFlag;
protected:
    bool eventFilter(QObject *, QEvent *);
public slots:
    void ShowTime(void);
};

#endif // MANAGEMENT_H





