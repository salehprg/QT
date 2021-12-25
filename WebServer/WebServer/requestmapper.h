
#include "WebRequestHandler.h"

#include <httprequesthandler.h>
#include <QObject>

#include "Controller/ControllerRoute.h"


using namespace stefanfrings;


class RequestMapper : public HttpRequestHandler{
    Q_OBJECT

public:
    RequestMapper(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);

private:

    ControllerRoute routeController;
    WebRequestHandler requestHandler;
};


