#include "databasehandler.h"

DatabaseHandler::DatabaseHandler()
{
    qDebug("Database Handler");
}

QString DatabaseHandler::getTableName(TableName tablename)
{
    return TablesName[tablename];
}

QSqlDatabase DatabaseHandler::getDatabase()
{
    QSqlDatabase temp = QSqlDatabase::database();
    return temp;
}

void DatabaseHandler::open(){

    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER))
        qDebug("Not available");

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");

    database.setDatabaseName("MyDb.db");

    if(!database.open())
        qWarning() << "ERROR: " << database.lastError();

}

void DatabaseHandler::close()
{
    getDatabase().close();
    qWarning() << "ERROR: " << getDatabase().lastError();

    getDatabase().removeDatabase(QSqlDatabase::defaultConnection);
    qWarning() << "ERROR: " << getDatabase().lastError();

}

bool DatabaseHandler::initDb()
{

    open();

    bool result = false;

    QString createPath = MyFileHelper().filepath_etc("Create.txt");

    QFile file(createPath);
    if(file.open(QIODevice::ReadOnly))
    {
        QString query = file.readAll();

        Exec(query);
    }

    close();

    return result;
}


QList<QSqlRecord> DatabaseHandler::Select(QString condition , TableName tablename)
{
    QList<QSqlRecord> records;

    open();

    QSqlQuery query = SelectQuery(condition , tablename);

    bool result =  query.exec();
    qWarning() << "ERROR: " << getDatabase().lastError();

    while (query.next())
    {
        records.push_back(query.record());
    }

    close();

    qWarning() << "ERROR: " << getDatabase().lastError();

    return records;
}

bool DatabaseHandler::Insert(QJsonObject jobject  , TableName tablename)
{
    open();

    QSqlQuery query = InsertQuery(jobject , tablename);

    bool result = query.exec();

    close();

    return result;
}

bool DatabaseHandler::Update(QJsonObject jobject , QString condition , TableName tablename)
{
    open();

    QSqlQuery query = UpdateQuery(jobject , condition , tablename);

    bool result = query.exec();

    close();
    return result;
}

bool DatabaseHandler::Delete(QString condition, TableName tablename)
{
    open();

    QSqlQuery query = DeleteQuery(condition , tablename);

    bool result = query.exec();

    close();

    return result;
}






QSqlQuery DatabaseHandler::SelectQuery(QString condition, TableName tablename)
{
    QString query = "Select * From " + getTableName(tablename);

    if(condition.compare("") != 0)
        query += " Where " + condition;

    query += ";";

    return getSQLQuery(query);
}

QSqlQuery DatabaseHandler::InsertQuery(QJsonObject jsonify , TableName tablename)
{
    QVariantMap variants = jsonify.toVariantMap();
    QStringList keys = jsonify.keys();

    QString query = "Insert into ";

    query += getTableName(tablename) + " ( ";

    for (int i = 0; i < variants.size(); i++)
    {
        query += keys[i];

        if(i != variants.size() - 1)
            query += ",";
    }

    query += ") Values (";

    for (int i = 0; i < variants.size(); i++)
    {
        query += "'" + variants.find(keys[i]).value().toString() + "'";

        if(i != variants.size() - 1)
            query += ",";
    }

    query += ");";

    return getSQLQuery(query);
}

QSqlQuery DatabaseHandler::UpdateQuery(QJsonObject jobject , QString condition , TableName tablename)
{
    QVariantMap variants = jobject.toVariantMap();
    QStringList keys = jobject.keys();

    QString query = "Update " + getTableName(tablename);

    query += " Set ";

    for (int i = 0; i < variants.size(); i++)
    {
        query += keys[i] + " = ";

        query += "'" + variants.find(keys[i]).value().toString() + "'";

        if(i != variants.size() - 1)
            query += ",";
    }

    query += " Where " + condition + ";";

    return getSQLQuery(query);
}

QSqlQuery DatabaseHandler::DeleteQuery(QString condition, TableName tablename)
{
    QString query = "Delete From " + getTableName(tablename);

    if(condition.compare("") != 0)
        query += " Where " + condition + ";";

    return getSQLQuery(query);
}

QSqlQuery DatabaseHandler::getSQLQuery(QString query)
{
    return QSqlQuery(query , getDatabase());
}

bool DatabaseHandler::Exec(QString query)
{
    open();

    getDatabase().exec(query);
    qWarning() << "ERROR: " << getDatabase().lastError();

    return true;

}
