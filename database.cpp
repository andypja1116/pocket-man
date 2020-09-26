#include "database.h"
#include <QDebug>

Database::Database()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))//为了防止多线程访问数据库所以进行预先的判断
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");//生成由QSQLITE驱动的数据库
        database.setDatabaseName("petDatabase.db");//命名为petDatabase
        database.setUserName("panjiaan");//登录数据库的用户名
        database.setPassword("123456");//登录数据库的密码
    }

    if (!database.open())//打开数据库
    {
        //qDebug() << "Failed to connect the database.";
    }
    else
    {
        query = new QSqlQuery(database);
        QString createSql = "CREATE TABLE player (name TEXT primary key, password TEXT, winNum INT, failNum INT, petNum INT, highPetNum INT, pet TEXT);";
        //数据库语法，表示生成的数据库表的名字叫做player，每一条记录包括name,password,winnum,failnum,petnum,highpetnum,pet7个属性
        query->prepare(createSql);
        if(!query->exec()){
            //qDebug() << "Error in create sql." << query->lastError();
        }
        else{
            //qDebug() << "Table create !";
        }
    }
}

Database::~Database()
{
    database.close();
}
