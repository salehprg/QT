#include "filehelper.h"

MyFileHelper::MyFileHelper()
{

}

QString MyFileHelper::filepath_etc(QString filename)
{
    QString binDir = QCoreApplication::applicationDirPath();
    QString appName = QCoreApplication::applicationName();
    QFile file;
    file.setFileName(binDir + filename);
    if (!file.exists()) {
        file.setFileName(binDir + "/etc/" + filename);
        if (!file.exists()) {
            file.setFileName(binDir+"/../etc/" + filename);
            if (!file.exists()) {
                file.setFileName(binDir+"/../"+appName+"/etc/" + filename);
                if (!file.exists()) {
                    file.setFileName(binDir+"/../../"+appName+"/etc/" + filename);
                    if (!file.exists()) {
                        file.setFileName(binDir+"/../../../../../" + appName + "/etc/" + filename);
                    }
                }
            }
        }
    }
    if (file.exists()) {
        QString configFileName=QDir(file.fileName()).canonicalPath();
        qDebug("using file %s", qPrintable(configFileName));
        return configFileName;
    }
    else {
        qDebug("file not found");

        return "";
    }
}
