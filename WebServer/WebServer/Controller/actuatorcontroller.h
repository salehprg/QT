#pragma once

#include <QObject>
#include "Model/actuator_model.h"

#include "basecontroller.h"

using namespace stefanfrings;
class ActuatorController {


public:
    ActuatorController() {}


    QJsonDocument Select();
    QJsonDocument Insert(QJsonObject model);
    QJsonDocument Update(QJsonObject model);
    QJsonDocument Delete(int act_id);

    QString getActuators();


    void service(HttpRequest& request, HttpResponse& response , QList<QByteArray> routeData);

private:

    DatabaseHandler databaseHandler;
    Actuator_Model actuatormodel;


};

