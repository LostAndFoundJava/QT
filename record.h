#ifndef RECORD_H
#define RECORD_H

#include <QObject>
#include <QString>
class Record : public QObject
{
    Q_OBJECT
public:
    explicit Record(QObject *parent = 0);
    QString   getLogTime();
    void   setLogTime(QString logTime);
    QString   getLogOperator();
    void  setLogOperator(QString logOperator);
    QString  getNgProductNumber();
    void  setNgProductNumber(QString ngProductNumber);
    QString  getNgProductName();
    void  setNgProductName(QString NgProductName);
    QString  getNgTime();
    void  setNgTime(QString ngTime);
    QString  getNgSignal();
    void  setNgSignal(QString ngSignal);
    QString  getNgOperator();
    void  setNgOperator(QString ngOperator);
    
private:
    QString logTime;
    QString logOperator;
    QString ngProductNumber;
    QString ngProductName;
    QString ngTime;
    QString ngSignal;
    QString ngOperator;
    
};

#endif // RECORD_H
