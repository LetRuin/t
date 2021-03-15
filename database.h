#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>

class DataBase
{
private:
    QSqlDatabase db;
    bool DataBaseConnect();
    void dataBaseDisconect();
public:
    void DataBaseAddContactTable(QString Firstname,QString Lastname, QString Patronymic);
    void DataBaseReqvestTable();
    void DataBaseDeleteTable();
    DataBase();
};

#endif // DATABASE_H
