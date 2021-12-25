#include "actuatorcontroller.h"
#include <QJsonDocument>
#include <QJsonObject>


void ActuatorController::service(HttpRequest &request, HttpResponse &response , QList<QByteArray> routeData)
{
    QJsonDocument doc = QJsonDocument().fromJson(request.getBody());

    QJsonObject jObject = doc.object();

    QJsonDocument result;

    if(request.getMethod() == "POST")
    {
         result = Insert(jObject);
    }
    else if(routeData.size() > 2)
    {
        if(routeData[2].compare("select") == 0)
        {
            result = Select();
        }
    }
    else if (request.getMethod() == "GET")
    {
        result = Select();
    }


    qDebug() << result.toJson();
    response.write(result.toJson() , true);
}

QString ActuatorController::getActuators()
{
    return "";
}

QJsonDocument ActuatorController::Select()
{
    QList<Actuator_Model> models;

    QList<QSqlRecord> results = databaseHandler.Select("" , DatabaseHandler::TableName::Actuator);

    QJsonArray recordsArray;

    foreach (QSqlRecord record, results)
    {
        Actuator_Model model = Actuator_Model().DeserializeSQLRecord(record);
        models.push_back(model);

        recordsArray.push_back(model.SerializeJSON());
    }

    QJsonDocument doc(recordsArray);
    return doc;
}

QJsonDocument ActuatorController::Insert(QJsonObject model)
{

    bool result = databaseHandler.Insert(model , DatabaseHandler::TableName::Actuator);

    QJsonDocument doc;
    QJsonObject jobject;
    jobject["result"] = result;

    doc.setObject(jobject);

    return doc;
}

QJsonDocument ActuatorController::Update(QJsonObject model)
{
    QString condition = actuatormodel.getPrimaryKeyVarName() + " = " + model.toVariantMap().find("id").value().toString();

    bool result = databaseHandler.Update(model , condition , DatabaseHandler::TableName::Actuator);

    QJsonDocument doc;
    QJsonObject jobject;
    jobject["result"] = result;

    doc.setObject(jobject);

    return doc;
}

QJsonDocument ActuatorController::Delete(int act_id)
{
    QString condition = actuatormodel.getPrimaryKeyVarName() + " = " + QString::number(act_id);

    bool result = databaseHandler.Delete(condition , DatabaseHandler::TableName::Actuator);

    QJsonDocument doc;
    QJsonObject jobject;
    jobject["result"] = result;

    doc.setObject(jobject);

    return doc;
}


