#pragma once

#include <QCoreApplication>
#include <QDir>
#include "httprequesthandler.h"
#include "Helper/filehelper.h"

using namespace stefanfrings;

class WebRequestHandler : public HttpRequestHandler{
    Q_OBJECT
public:
    WebRequestHandler(QObject* parent = 0);
    void service(HttpRequest& request, HttpResponse& response);
};

