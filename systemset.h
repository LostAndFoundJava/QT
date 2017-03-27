#ifndef SYSTEMSET_H
#define SYSTEMSET_H

#include <QWidget>
#include <QAbstractButton>
namespace Ui {
class Systemset;
}

class Systemset : public QWidget
{
    Q_OBJECT

public:
    explicit Systemset(QWidget *parent = 0);
    ~Systemset();

private slots:
    void buttonJudge(int);


private:
    Ui::Systemset *ui;
    QButtonGroup *buttonGroup;
};

#endif // SYSTEMSET_H
