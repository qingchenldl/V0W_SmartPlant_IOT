#include "socketserver.h"

SocketServer::SocketServer()
{
    server = new QTcpServer;
    socket = new QTcpSocket;
    newListen();
    connect(server,SIGNAL(newConnection()),SLOT(acceptConnection()));//来判断是否接收到了新的连接，当服务端接收到一个客户端的连接时，就会触发信号newConnection()，此时调用相应的槽函数（acceptConnection()）保存新接收到的连接
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),SLOT(showError(QAbstractSocket::SocketError)));

}

SocketServer::~SocketServer(){
    server->close();
    server->deleteLater();
}

void SocketServer::newListen()
{
    if(!server->listen(QHostAddress::Any,2333))//通过listen()建立对端口的监听。
    {
        qDebug()<<server->errorString();
        server->close();
    }
}

void SocketServer::acceptConnection()
{
    socket = server->nextPendingConnection();//通过nextPendingConnection()函数获得连接客户端的SOCKET套接字
    connect(socket,SIGNAL(readyRead()),SLOT(onReciveData()));//readyRead()来判断是否有数据传入，当客户端向服务端成功发送数据之后，就会在服务端触发readyRead()信号，此时通过调用相应的自定义的槽函数（onReciveData()）保存接收到的数据
}

/*
void MainWindow::init()
{
    tcpServer = new QTcpServer;
    tcpSocket = new QTcpSocket;
    newListen();
    connect(tcpServer,SIGNAL(newConnection()),SLOT(acceptConnection()));//来判断是否接收到了新的连接，当服务端接收到一个客户端的连接时，就会触发信号newConnection()，此时调用相应的槽函数（acceptConnection()）保存新接收到的连接
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),SLOT(showError(QAbstractSocket::SocketError)));
}
void MainWindow::sendData()  //发送数据
{
   //QString textEdit = temp_humi_light->getTemperature();
   // QString strData =textEdit.toLocal8Bit() + "\n";
   // QByteArray sendData = strData.toLocal8Bit();
   // tcpSocket->write(sendData);
    tcpSocket->write("234");
}

void MainWindow::onReciveData()  //读取数据
{
    QString data = tcpSocket->readAll();
    qDebug()<<data;
    //mChat +=("Recv " + data);
    ui->textEdit->setText(data);
}
void MainWindow::newListen()
{
    if(!tcpServer->listen(QHostAddress::Any,6666))//通过listen()建立对端口的监听。
    {
        qDebug()<<tcpServer->errorString();
        tcpServer->close();
    }
}
void MainWindow::acceptConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();//通过nextPendingConnection()函数获得连接客户端的SOCKET套接字
    connect(tcpSocket,SIGNAL(readyRead()),SLOT(onReciveData()));//readyRead()来判断是否有数据传入，当客户端向服务端成功发送数据之后，就会在服务端触发readyRead()信号，此时通过调用相应的自定义的槽函数（onReciveData()）保存接收到的数据
}

void MainWindow::showError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();
    tcpSocket->close();
}

*/
