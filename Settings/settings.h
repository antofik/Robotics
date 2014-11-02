#ifndef SETTINGS_H
#define SETTINGS_H

#include <Qt>
#include <QtCore>
#include <QSettings>

class Settings
{

public:
    static QString getStringValue(QString key, QString defaultValue = "");
    static int getIntValue(QString key, int defaultValue = 0);
    static float getFloatValue(QString key, float defaultValue = 0.0);

private:
    Settings();
    QSettings *settings;
    static Settings* instance();
};

#endif // SETTINGS_H
