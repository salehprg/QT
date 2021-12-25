#include "requestmapper.h"
#include "WebRequestHandler.h"

#include "global.h"

RequestMapper::RequestMapper(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path = request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if (path=="/" || path=="/hello") {
        requestHandler.service(request, response);
    }
    else if (path.contains(APIRoute))
    {
        routeController.routeHandler(request, response);
    }
    else if (path.startsWith("/")) {
        staticFileController->service(request,response);
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.",true);
    }

    qDebug("RequestMapper: finished request");
}
