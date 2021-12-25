#include "ControllerRoute.h"

ControllerRoute::ControllerRoute()
{

}

void ControllerRoute::routeHandler(HttpRequest& request, HttpResponse& response)
{
    QByteArray path = request.getPath();

    QList<QByteArray> splitted = path.split('//');

    QString controllername = splitted[2];

    if (controllername.toLower().compare(ActuatorRoute) == 0)
    {
        actuatorController.service(request , response , splitted.sliced(1 , splitted.size() - 1));
    }
    else
    {
        response.setStatus(404 , "Not Found !");
        response.write("Not Found !");
    }
}
