#ifndef PWM_H
#define PWM_H
#include <QObject>

class PWM
{
public:
    PWM();

public:
    static QByteArray RANGE;
    static QByteArray MSG_PWM;
    int LightVal;
};

#endif // PWM_H
