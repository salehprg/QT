
#include "Model.h"


class Actuator_Model {

public:
    Actuator_Model();

    int id;
    QString name;
    QString data_type;
    QString data_type_feedback;
    QString value;
    QString group_address;
    QString group_address_feedback;
    QString icon_code;
    QString color;
    bool show_border;
    QString guid;


    DatabaseHandler databaseHandler;

    QString getPrimaryKeyVarName();

    QJsonObject SerializeJSON();
    Actuator_Model* DeserializeJSON(QJsonObject json);
    Actuator_Model DeserializeSQLRecord(QSqlRecord record);
};

