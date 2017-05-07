#ifndef LOG_H
#define LOG_H


#include <QWidget>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include "globl_data.h"
#include <input.h>
#include <record.h>
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

   // void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::Log *ui;
    input *Input;
    void valueInt(void);
    //QLineEdit *n;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
public slots:
    void ShowTime(void);
    void ContentInput();
    char UsbRead ();
    void getData(QString,QLineEdit *,int row,int colum);
    void saveData(void);
    void LogInput(QLineEdit *,int row,int colum);
};

#endif // LOG_H
