#include <QCoreApplication>

#include <QtSql>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER))
        qDebug("Not available");

    QSqlDatabase firstDB = QSqlDatabase::addDatabase("QSQLITE" , "first");

    firstDB.setDatabaseName("MyDb.db");

    if(!firstDB.open())
        qWarning() << "ERROR: " << firstDB.lastError();

    firstDB.exec("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");
    return a.exec();
}
