
#include <QObject>
#include "httprequesthandler.h"
#include "httpresponse.h"
#include <QCoreApplication>

#include "actuatorcontroller.h"


using namespace stefanfrings;

#define ActuatorRoute "actuator"

#define APIRoute "/api/"


class ControllerRoute : public HttpRequestHandler{


public:

    ControllerRoute();

    void routeHandler(HttpRequest& request, HttpResponse& response);


private:

    ActuatorController actuatorController;

};

