#include "settings.h"
#include <QVariant>


Settings::Settings()
{
    QString filename = qApp->applicationDirPath() + "/settings.ini";
    settings = new QSettings(filename, QSettings::IniFormat);
    settings->setValue("version", 1.1);
}

Settings* Settings::instance()
{
    static Settings instance;
    return &instance;
}

QString Settings::getStringValue(QString key, QString defaultValue)
{
    return Settings::instance()->settings->value(key, defaultValue).toString();
}

int Settings::getIntValue(QString key, int defaultValue)
{
    return Settings::instance()->settings->value(key, defaultValue).toInt();
}

float Settings::getFloatValue(QString key, float defaultValue)
{
    return Settings::instance()->settings->value(key, defaultValue).toFloat();
}
