#include "motor.h"

Motor::Motor()
{
}

const QByteArray Motor::MSG_MOTOR_FORE("\x40\x06\x01\x06\x0a\x57", 6);
const QByteArray Motor::MSG_MOTOR_BACK("\x40\x06\x01\x06\x0b\x58", 6);
const QByteArray Motor::MSG_MOTOR_STOP("\x40\x06\x01\x06\x0c\x59", 6);
