#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <QObject>
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

class SocketServer
{
public:
    SocketServer();
    ~SocketServer();
private slots:
    void on_pushButton_Listen_clicked();

    void on_pushButton_Send_clicked();

    void server_New_Connect();

    void socket_Read_Data();

    void socket_Disconnected();

private:
    QTcpServer* server;
    QTcpSocket* socket;
};

#endif // SOCKETSERVER_H
