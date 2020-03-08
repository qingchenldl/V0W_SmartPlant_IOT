#ifndef MOTOR_H
#define MOTOR_H
#include "enddevice.h"

class Motor : public EndDevice
{
public:
    explicit Motor();

public:
    const static QByteArray MSG_MOTOR_FORE;
    const static QByteArray MSG_MOTOR_BACK;
    const static QByteArray MSG_MOTOR_STOP;

};

#endif // MOTOR_H
