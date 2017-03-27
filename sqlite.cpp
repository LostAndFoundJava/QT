#include "sqlite.h"
#include <QtSql/QSqlQuery>


SQLITE::SQLITE()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("CashSystem.db");
}

bool SQLITE::openDatabase()
{

    if(database.open())
        qDebug()<<"Database Opened";
    sql_query = new QSqlQuery;
}

bool SQLITE::closeDatabase()
{
    database.close();
}

void SQLITE::insert(QString typeQ,int numberQ,double xQ,double yQ,double len1Q,double len2Q,double b1Q,double b2Q,double b3Q,
                    double b4Q,double k1Q,double k2Q,double degreeQ)
{
    QString insert_sql = "insert into juxingkang (type,number,x,y,len1,len2,b1,b2,b3,b4,k1,k2,degree) values (?,?,?,?,?,?,?,?,?,?,?,?,?)";

    sql_query->prepare(insert_sql);

//    QVariantList id;
//    id.append();

    QVariantList type;
    type.append(typeQ);

    QVariantList number;
    number.append(numberQ);

    QVariantList x;
    x.append(xQ);

    QVariantList y;
    y.append(yQ);

    QVariantList len1;
    len1.append(len1Q);

    QVariantList len2;
    len2.append(len2Q);

    QVariantList b1;
    b1.append(b1Q);

    QVariantList b2;
    b2.append(b2Q);

    QVariantList b3;
    b3.append(b3Q);

    QVariantList b4;
    b4.append(b4Q);

    QVariantList k1;
    k1.append(k1Q);

    QVariantList k2;
    k2.append(k2Q);

    QVariantList degree;
    degree.append(degreeQ);


    //sql_query->addBindValue(id);
    sql_query->addBindValue(type);
    sql_query->addBindValue(number);
    sql_query->addBindValue(x);
    sql_query->addBindValue(y);
    sql_query->addBindValue(len1);
    sql_query->addBindValue(len2);
    sql_query->addBindValue(b1);
    sql_query->addBindValue(b2);
    sql_query->addBindValue(b3);
    sql_query->addBindValue(b4);
    sql_query->addBindValue(k1);
    sql_query->addBindValue(k2);
    sql_query->addBindValue(degree);


    if(!sql_query->execBatch())
    {
        qDebug()<<sql_query->lastError();
    }
    else
    {
        qDebug()<<"success";
    }
}

JuXingKuang *SQLITE::query(QString typeQ,int numberQ)
{
    JuXingKuang *jxk = new JuXingKuang;
    QString select_all_sql = "select * from juxingkang";
    sql_query->prepare(select_all_sql);

    if(!sql_query->exec())
    {
        qDebug()<<sql_query->lastError();
    }
    else
    {
        while(sql_query->next())
        {
            //int id = sql_query->value(0).toInt();

            jxk->setTypeQ(sql_query->value(1).toString());
            jxk->setNumberQ(sql_query->value(2).toInt());
            jxk->setxQ(sql_query->value(3).toString().toDouble());
            jxk->setyQ(sql_query->value(4).toString().toDouble());
            jxk->setLen1Q(sql_query->value(5).toString().toDouble());
            jxk->setLen2Q(sql_query->value(6).toString().toDouble());
            jxk->setB1Q(sql_query->value(7).toString().toDouble());
            jxk->setB2Q(sql_query->value(8).toString().toDouble());
            jxk->setB3Q(sql_query->value(9).toString().toDouble());
            jxk->setB4Q(sql_query->value(10).toString().toDouble());
            jxk->setK1Q(sql_query->value(11).toString().toDouble());
            jxk->setK2Q(sql_query->value(12).toString().toDouble());
            jxk->setDegreeQ(sql_query->value(13).toString().toDouble());

            //qDebug()<<QString("type:%1").arg(id).arg(name).arg(address);
            return jxk;
        }
    }
}



