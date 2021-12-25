QT -= gui
QT += network
QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

OTHER_FILES += etc/config.ini

SOURCES += \
        Controller/ControllerRoute.cpp \
        Controller/actuatorcontroller.cpp \
        Database/databasehandler.cpp \
        Helper/filehelper.cpp \
        Model/actuator_model.cpp \
        RequestMapper.cpp \
        WebRequestHandler.cpp \
        global.cpp \
        main.cpp

TRANSLATIONS += \
    WebServer_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(E:/QT/Tools/QtWebApp/httpserver/httpserver.pri)

HEADERS += \
    Controller/ControllerRoute.h \
    Controller/actuatorcontroller.h \
    Controller/basecontroller.h \
    Database/databasehandler.h \
    Helper/filehelper.h \
    Model/Model.h \
    Model/actuator_model.h \
    RequestMapper.h \
    WebRequestHandler.h \
    global.h
