#include "WebRequestHandler.h"

WebRequestHandler::WebRequestHandler(QObject* parent) : HttpRequestHandler(parent)
{

}

void WebRequestHandler::service(HttpRequest &request , HttpResponse &response)
{
    QByteArray responsestr = "File not Found";

    QString filepath = MyFileHelper().filepath_etc("docroot/index.html");

    int r = filepath.compare("");
    int r2 = filepath.compare("12");

    if(!filepath.isNull() && filepath.compare("") != 0)
    {
        QFile file(filepath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            responsestr = file.readAll();
    }

    response.write(responsestr , true);

}
