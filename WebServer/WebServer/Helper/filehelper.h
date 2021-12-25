#pragma once

#include <QObject>
#include <QCoreApplication>
#include <QDir>

class MyFileHelper{

public:
    MyFileHelper();

    QString filepath_etc(QString filename);
};


