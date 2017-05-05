#include "record.h"

Record::Record(QObject *parent) :
    QObject(parent)
{
}
QString Record::getLogTime() {
    return logTime;
}

void Record::setLogTime(QString logTime) {
    this->logTime = logTime;
}

QString Record::getLogOperator() {
    return logOperator;
}

void Record::setLogOperator(QString logOperator) {
    this->logOperator = logOperator;
}

QString Record::getNgProductNumber() {
    return ngProductNumber;
}
void Record::setNgProductNumber(QString ngProductNumber) {
    this->ngProductNumber = ngProductNumber;
}
QString Record::getNgProductName() {
    return ngProductName;
}
void Record::setNgProductName(QString NgProductName) {
    this->ngProductName = ngProductName;
}
QString Record::getNgTime() {
    return ngTime;
}

void Record::setNgTime(QString ngTime) {
    this->ngTime = ngTime;
}

QString Record::getNgSignal() {
    return ngSignal;
}

void Record::setNgSignal(QString ngSignal) {
    this->ngSignal = ngSignal;
}

QString Record::getNgOperator() {
    return ngOperator;
}

void Record::setNgOperator(QString ngOperator) {
    this->ngOperator = ngOperator;
}
