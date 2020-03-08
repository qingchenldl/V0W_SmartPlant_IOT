#ifndef TEMP_HUMI_LIGHT_H
#define TEMP_HUMI_LIGHT_H
#include <QApplication>
#include <QCoreApplication>
#include <QtSql/QtSql>
#include <error.h>
#include <QDateTime>
#include <QObject>

class Temp_Humi_Light
{
public:
    explicit Temp_Humi_Light();
    void setValue(QByteArray&);
    void setValue(int, int, float);
    int getTemperature();
    int getHumidity();
    float getLight();

private :
    int temperature;
    int humidity;
    float light;
    QString Date;
    QString Time;

};

#endif // TEMP_HUMI_LIGHT_H
