#include "enddevice.h"

EndDevice::EndDevice(QObject *parent) :
    QObject(parent),
    state(0)
{
}

void EndDevice::setState(int state)
{
    this->state = state;
}

int EndDevice::getState()
{
    return state;
}
