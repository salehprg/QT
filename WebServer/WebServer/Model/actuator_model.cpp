#include "actuator_model.h"

Actuator_Model::Actuator_Model()
{

}

QString Actuator_Model::getPrimaryKeyVarName()
{
    return "id";
}

Actuator_Model Actuator_Model::DeserializeSQLRecord(QSqlRecord record)
{
    Actuator_Model result;

    result.id = record.field("id").value().toInt();
    result.name = record.field("name").value().toString();
    result.data_type = record.field("data_type").value().toString();
    result.data_type_feedback = record.field("data_type_feedback").value().toString();
    result.group_address = record.field("group_address").value().toString();
    result.group_address_feedback = record.field("group_address_feedback").value().toString();
    result.guid = record.field("guid").value().toString();
    result.color = record.field("color").value().toString();
    result.icon_code = record.field("icon_codee").value().toString();
    result.value = record.field("value").value().toString();
    result.show_border = record.field("show_border").value().toBool();

    return result;
}

Actuator_Model* Actuator_Model::DeserializeJSON(QJsonObject jobject)
{
    id = jobject["id"].toInt();
    name = jobject["name"].toString();
    data_type = jobject["data_type"].toString();
    data_type_feedback = jobject["data_type_feedback"].toString();
    group_address = jobject["group_address"].toString();
    group_address_feedback = jobject["group_address_feedback"].toString();
    guid = jobject["guid"].toString();
    color = jobject["color"].toString();
    icon_code = jobject["icon_codee"].toString();
    value = jobject["value"].toString();
    show_border = jobject["show_border"].toBool();

    return  this;
}

QJsonObject Actuator_Model::SerializeJSON()
{
    QJsonObject jobject;

    jobject["id"] = id;
    jobject["name"] = name;
    jobject["data_type"] = data_type;
    jobject["data_type_feedback"] = data_type_feedback;
    jobject["group_address"] = group_address;
    jobject["group_address_feedback"] = group_address_feedback;
    jobject["guid"] = guid;
    jobject["color"] = color;
    jobject["icon_codee"] = icon_code;
    jobject["value"] = value;
    jobject["show_border"] = show_border;

    return  jobject;
}

