#ifndef PLANT_H
#define PLANT_H

#include <QObject>

class Plant
{
public:
    QString plant_name;
    int max_temp;
    int min_temp;
    int max_humi;
    int min_humi;
    float max_light;
    float min_light;
    Plant(QString);
    ~Plant();
};

#endif // PLANT_H
