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

    void on_buttonBox_1_clicked(QAbstractButton *button);

    void on_AluminizerButton_clicked(bool checked);

    void on_bulkButton_clicked();

    void on_packButton_clicked(bool checked);
     void on_LearningButton_clicked();

    //void myEditClicked1();

private:
    Ui::Management *ui;
    QButtonGroup *PackingStyleGroup;
    class learn *Learn;
    void valueInt(void);
    //QMyEdit *qme1;
protected:
    bool eventFilter(QObject *, QEvent *);
public slots:
    void ShowTime(void);
};

#endif // MANAGEMENT_H
