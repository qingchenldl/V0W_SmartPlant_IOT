/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[433];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_OpenSerialButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 8), // "ReadData"
QT_MOC_LITERAL(4, 49, 21), // "on_SendButton_clicked"
QT_MOC_LITERAL(5, 71, 21), // "on_BntMotor_2_clicked"
QT_MOC_LITERAL(6, 93, 20), // "ProcessMsgFromSerial"
QT_MOC_LITERAL(7, 114, 11), // "QByteArray&"
QT_MOC_LITERAL(8, 126, 3), // "msg"
QT_MOC_LITERAL(9, 130, 17), // "updateTempHumiLig"
QT_MOC_LITERAL(10, 148, 9), // "changePwm"
QT_MOC_LITERAL(11, 158, 11), // "SendMessage"
QT_MOC_LITERAL(12, 170, 20), // "on_HotButton_clicked"
QT_MOC_LITERAL(13, 191, 21), // "on_ColdButton_clicked"
QT_MOC_LITERAL(14, 213, 20), // "on_WetButton_clicked"
QT_MOC_LITERAL(15, 234, 21), // "on_WindBotton_clicked"
QT_MOC_LITERAL(16, 256, 20), // "updatedataSlot_light"
QT_MOC_LITERAL(17, 277, 23), // "updatedataSlot_Humidity"
QT_MOC_LITERAL(18, 301, 26), // "updatedataSlot_Temperature"
QT_MOC_LITERAL(19, 328, 11), // "timerUpDate"
QT_MOC_LITERAL(20, 340, 9), // "newListen"
QT_MOC_LITERAL(21, 350, 4), // "init"
QT_MOC_LITERAL(22, 355, 8), // "sendData"
QT_MOC_LITERAL(23, 364, 12), // "onReciveData"
QT_MOC_LITERAL(24, 377, 16), // "acceptConnection"
QT_MOC_LITERAL(25, 394, 9), // "showError"
QT_MOC_LITERAL(26, 404, 28) // "QAbstractSocket::SocketError"

    },
    "MainWindow\0on_OpenSerialButton_clicked\0"
    "\0ReadData\0on_SendButton_clicked\0"
    "on_BntMotor_2_clicked\0ProcessMsgFromSerial\0"
    "QByteArray&\0msg\0updateTempHumiLig\0"
    "changePwm\0SendMessage\0on_HotButton_clicked\0"
    "on_ColdButton_clicked\0on_WetButton_clicked\0"
    "on_WindBotton_clicked\0updatedataSlot_light\0"
    "updatedataSlot_Humidity\0"
    "updatedataSlot_Temperature\0timerUpDate\0"
    "newListen\0init\0sendData\0onReciveData\0"
    "acceptConnection\0showError\0"
    "QAbstractSocket::SocketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x08 /* Private */,
       3,    0,  125,    2, 0x08 /* Private */,
       4,    0,  126,    2, 0x08 /* Private */,
       5,    0,  127,    2, 0x08 /* Private */,
       6,    1,  128,    2, 0x08 /* Private */,
       9,    0,  131,    2, 0x08 /* Private */,
      10,    1,  132,    2, 0x08 /* Private */,
      11,    0,  135,    2, 0x08 /* Private */,
      12,    0,  136,    2, 0x08 /* Private */,
      13,    0,  137,    2, 0x08 /* Private */,
      14,    0,  138,    2, 0x08 /* Private */,
      15,    0,  139,    2, 0x08 /* Private */,
      16,    0,  140,    2, 0x08 /* Private */,
      17,    0,  141,    2, 0x08 /* Private */,
      18,    0,  142,    2, 0x08 /* Private */,
      19,    0,  143,    2, 0x08 /* Private */,
      20,    0,  144,    2, 0x08 /* Private */,
      21,    0,  145,    2, 0x08 /* Private */,
      22,    0,  146,    2, 0x08 /* Private */,
      23,    0,  147,    2, 0x08 /* Private */,
      24,    0,  148,    2, 0x08 /* Private */,
      25,    1,  149,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_OpenSerialButton_clicked(); break;
        case 1: _t->ReadData(); break;
        case 2: _t->on_SendButton_clicked(); break;
        case 3: _t->on_BntMotor_2_clicked(); break;
        case 4: _t->ProcessMsgFromSerial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->updateTempHumiLig(); break;
        case 6: _t->changePwm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SendMessage(); break;
        case 8: _t->on_HotButton_clicked(); break;
        case 9: _t->on_ColdButton_clicked(); break;
        case 10: _t->on_WetButton_clicked(); break;
        case 11: _t->on_WindBotton_clicked(); break;
        case 12: _t->updatedataSlot_light(); break;
        case 13: _t->updatedataSlot_Humidity(); break;
        case 14: _t->updatedataSlot_Temperature(); break;
        case 15: _t->timerUpDate(); break;
        case 16: _t->newListen(); break;
        case 17: _t->init(); break;
        case 18: _t->sendData(); break;

        case 20: _t->acceptConnection(); break;
        case 21: _t->showError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
