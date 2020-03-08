#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QApplication>
#include <QCoreApplication>
#include <QtSql/QtSql>
#include <error.h>
#include <QDateTime>
#include <QObject>
#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void startTimer();

private slots:
    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

private:
    Ui::Dialog *u;
    QTimer *my_Timer;
    QSqlTableModel *X;
};

#endif // DIALOG_H
