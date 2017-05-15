#ifndef LOG_H
#define LOG_H


#include <QWidget>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include "globl_data.h"
#include <input.h>
#include <record.h>
#include<mainwindow.h>
#include<QStringList>
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



    void on_USBOuput_clicked();



private:
    Ui::Log *ui;
    input *Input;
    void valueInt(void);
    class MainWindow *mainWindow;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
public slots:
    void ShowTime(void);

    char UsbRead ();
};

#endif // LOG_H
