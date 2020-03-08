#ifndef ENDDEVICE_H
#define ENDDEVICE_H

#include <QObject>

class EndDevice : public QObject
{
    Q_OBJECT
public:
    explicit EndDevice(QObject *parent = 0);
    void setState(int);
    int getState();
signals:

public slots:

protected:
    int state;
};

#endif // ENDDEVICE_H
