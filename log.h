#ifndef LOG_H
#define LOG_H

#include <QWidget>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include "globl_data.h"
#include <input.h>
#include <record.h>
#include <sqlite.h>
namespace Ui {
class Log;
}

class Log : public QWidget
{
    Q_OBJECT

public:
    explicit Log(QWidget *parent = 0);
    ~Log();

private slots:

    void on_NGButton_clicked();

    void on_Return_clicked();

    void on_LoadLog_2_clicked();

    void on_tableWidget_2_cellClicked(int row, int column);

    void on_USBOuput_clicked();

    void on_Save_clicked();

private:
    Ui::Log *ui;
    input *Input;
    void valueInt(void);
    int row1;
    int column1;
public slots:
    void ShowTime(void);
    void ContentInput();
    char UsbRead ();
    void getData(QString,int,int);
    void saveData(void);
};

#endif // LOG_H
