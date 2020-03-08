#-------------------------------------------------
#
# Project created by QtCreator 2018-07-05T22:20:22
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += network
QT       += sql
CONFIG += qwt
DEFINES += QT_DLL QWT_DLL
LIBS += -L"C:\Qt\qwt-6.1.3\lib" -lqwtd
LIBS+=-L"C:/Qt/Qt5.11.1/5.11.1/mingw53_32/lib" -lqwt
#添加qwt
INCLUDEPATH+=C:/Qt/Qt5.11.1/5.11.1/mingw53_32/include/qwt


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Uart
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    debug/dialog.cpp \
    temp_humi_light.cpp \
    pwm.cpp \
    pir.cpp \
    sms.cpp \
    plant.cpp \
    logindialog.cpp \
    warn.cpp

HEADERS += \
        mainwindow.h \
    debug/dialog.h \
    temp_humi_light.h \
    pwm.h \
    pir.h \
    sms.h \
    plant.h \
    logindialog.h \
    warn.h

FORMS += \
        mainwindow.ui \
    debug/dialog.ui \
    warn.ui

DISTFILES += \
    test.rc
#添加exe图标
RC_FILE += test.rc

RESOURCES += \
    imcsources.qrc
