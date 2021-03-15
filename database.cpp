#include "database.h"

DataBase::DataBase()
{};

bool DataBase::DataBaseConnect(){
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={MySQL ODBC 8.0 Unicode Driver};Server=mysql60.hostland.ru;Database=host1323541_irkutsk6;Uid=host1323541_itstep;Port=3306;Pwd=269f43dc");
    bool ok = db.open();
    return ok;
};
void DataBase::dataBaseDisconect(){
    db.close();
};

void DataBase::DataBaseAddContactTable(QString Firstname,QString Lastname, QString Patronymic){
    DataBaseConnect();
    QSqlQuery query;
         QString sql_insert = "INSERT INTO table_contact(firstname, lastname, patronymic) "
                     "VALUES ('%1', '%2', '%3');";
         QString sql = sql_insert.arg(Firstname)
                     .arg(Lastname)
                     .arg(Patronymic);
         bool b = query.exec(sql);
             if (!b) {
                 qDebug() << "Кажется данные не вставляются, проверьте дверь, может она закрыта?";
             }
             dataBaseDisconect();
};

void DataBase::DataBaseReqvestTable(){
    DataBaseConnect();
    QSqlQuery query;
         QString sql_insert = "SELECT firstname,lastname,patronymic"
                     "FROM table_contact;";
         bool b = query.exec(sql_insert);
             if (!b) {
                 qDebug() << "Кажется данные не вставляются, проверьте дверь, может она закрыта?";
             }
    dataBaseDisconect();
};

void DataBase::DataBaseDeleteTable(){
    DataBaseConnect();

    dataBaseDisconect();
};
