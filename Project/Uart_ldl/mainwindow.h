#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include "warn.h"
#include "temp_humi_light.h"
#include "pwm.h"
#include "pir.h"
#include "sms.h"
#include "plant.h"
#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QTime>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <math.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_grid.h>
#include <qwt_scale_draw.h>
#include <QtCore>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString n, QString p, QWidget *parent = 0);
    ~MainWindow();
    void setupRealtimelight(QwtPlot *qwtplot);
    void setupRealtimeHumidity(QwtPlot *qwtplot);
    void setupRealtimeTemperature(QwtPlot *qwtplot);

private slots:
    void on_OpenSerialButton_clicked();
    void ReadData();
    void on_SendButton_clicked();
    void on_BntMotor_2_clicked();
    void ProcessMsgFromSerial(QByteArray &msg);
    void updateTempHumiLig();
    void changePwm(int);
    void SendMessage();        //发送手机信息
    void on_HotButton_clicked();
    void on_ColdButton_clicked();
    void on_WetButton_clicked();
    void on_WindBotton_clicked();
    //实时曲线
    void updatedataSlot_light();
    void updatedataSlot_Humidity();
    void updatedataSlot_Temperature();

    //实时显示时间
    void timerUpDate();

    //
    void newListen(); //建立tcp监听事件
    void init();
    void sendData(); //发送消息
    void onReciveData();  //接收数据
    void acceptConnection(); //接收客户端连接
    void showError(QAbstractSocket::SocketError); //错误输出

private:
    QPalette pe_red;
    QPalette pe_black;
    Ui::MainWindow *ui;
    QSerialPort *serial;
    Dialog *a;
    Warn *b;
    QSqlDatabase database;
    Temp_Humi_Light *temp_humi_light;
    PWM *pwm;
    PIR *pir;
    Sms *sms;
    Plant *plant;
    QTimer *timer;
    QString name;
    QString pwd;

    //实时曲线
           QVector<double> x_light;
           QVector<double> y_light;
           QVector<double> x_Humidity;
           QVector<double> y_Humidity;
           QVector<double> x_Temperature;
           QVector<double> y_Temperature;
           QTimer updateTimer;

           QString light_Name;
           QString Humidity_Name;
           QString Temperature_Name;
           QwtPlotCurve *curve ;
           QwtPlotCurve *curve1 ;
           QwtPlotCurve *curve2 ;

    double getData(double inteval);
    void SmartControl();
    void HandleFuction(int type);
    //
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;

};

#endif // MAINWINDOW_H
