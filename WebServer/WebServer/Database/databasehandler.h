#pragma once

#include <QObject>
#include <QtSql>
#include "Helper/filehelper.h"

class DatabaseHandler{

private:
    QString TablesName[2] = {
      "Actuators",
      "Logs",
    };

    QSqlDatabase getDatabase();


public:
    DatabaseHandler();

    enum TableName {
        Actuator,
        Logs
    };

    QList<QSqlRecord> Select(QString condition , TableName tablename);
    bool Insert(QJsonObject jobject , TableName tablename);
    bool Update(QJsonObject jobject , QString condition , TableName tablename);
    bool Delete(QString condition , TableName tablename);

    bool initDb();

    void open();
    void close();

protected:

    QString getTableName(TableName tablename);

    QSqlQuery getSQLQuery(QString query);

    QSqlQuery SelectQuery(QString condition , TableName tablename);
    QSqlQuery InsertQuery(QJsonObject jsonify , TableName tablename);
    QSqlQuery UpdateQuery(QJsonObject jobject , QString condition , TableName tablename);
    QSqlQuery DeleteQuery(QString condition , TableName tablename);


    bool Exec(QString query);

};

