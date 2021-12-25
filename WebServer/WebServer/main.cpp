#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>

#include <QSettings>
#include <QFile>
#include <QDir>
#include <QString>

#include "httplistener.h"
#include "httprequesthandler.h"

#include "RequestMapper.h"

#include "staticfilecontroller.h"

#include "global.h"
#include "Database/databasehandler.h"

using namespace stefanfrings;


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString configFileName = MyFileHelper().filepath_etc("webapp.ini");

    QSettings* listenerSettings = new QSettings(configFileName , QSettings::IniFormat , &app);
    listenerSettings->beginGroup("listener");

    QSettings* fileSettings=new QSettings(configFileName , QSettings::IniFormat,&app);
    fileSettings->beginGroup("files");

    staticFileController = new StaticFileController(fileSettings , &app);

    // Start the HTTP server
    new HttpListener(listenerSettings, new RequestMapper(&app), &app);

    DatabaseHandler databaseHandler;

    databaseHandler.initDb();

    return app.exec();
}
