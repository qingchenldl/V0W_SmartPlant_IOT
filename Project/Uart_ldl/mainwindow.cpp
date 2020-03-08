#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
QString Variety;
bool mulian = false;        //true 表示幕帘开启，false表示幕帘关闭
bool mode = true;           //true自动，false手动
bool open_serial = false;           //true打开串口，false关闭串口
MainWindow::MainWindow(QString n, QString p, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)                  //ui 构造
{
    database = QSqlDatabase::addDatabase("QSQLITE");
            database.setDatabaseName("plant_data.db");
            if(database.open())
                {
                    qDebug()<<"Database Opened";
                    QSqlQuery sql_query;
                    QString create_sql = "create table plant_data (Date QString,Time QString,Temp int, Humi int, Light float)"; //创建数据表
                    sql_query.prepare(create_sql); //创建表
                    if(!sql_query.exec()) //查看创建表是否成功
                    {
                        qDebug()<<QObject::tr("Table Create failed");
                        qDebug()<<sql_query.lastError();
                    }
                    else
                    {
                        qDebug()<< "Table Created" ;
                    }
            }

    ui->setupUi(this);
    temp_humi_light = new Temp_Humi_Light();
    pwm = new PWM();
    pir = new PIR();
    sms = new Sms();
    ui->PwmSlider->setRange(0, 9);
    ui->PwmSlider->setTickPosition(QSlider::TicksRight);
    ui->PwmSlider->setPageStep(1);

    init();

    connect(ui->SendButton,SIGNAL(clicked(bool)),SLOT(sendData()));

    connect(ui->PwmSlider, SIGNAL(valueChanged(int)), this, SLOT(changePwm(int)));
    //查找可用的串口
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->PortBox->addItem(serial.portName());
            serial.close();
        }
    }
    //ui->Plant_varieties->setCurrentIndex(0);
    pe_black.setColor(QPalette::WindowText,Qt::black);
    pe_red.setColor(QPalette::WindowText,Qt::red);
    //实时显示图表
    setupRealtimelight(ui->qwtPlot);
    setupRealtimeHumidity(ui->qwtPlot_2);
    setupRealtimeTemperature(ui->qwtPlot_3);

    //实时显示时间
    QTimer *timer = new QTimer(this);    //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));    //关联定时器计满信号和相应的槽函数
    timer->start(1000);    //定时器开始计时，其中1000表示1000ms即1秒

}

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
    QString textEdit = QString::number(temp_humi_light->getTemperature()) + "C" + ' '+ QString::number(temp_humi_light->getHumidity()) + "%" + ' '+ QString::number(temp_humi_light->getLight()) + "lx";
    QString strData =QString::fromLocal8Bit("Time: ") + QTime::currentTime().toString() + "\n" + textEdit.toLocal8Bit() + "\n";
    QByteArray sendMessage = strData.toLocal8Bit();
    qDebug() << sendMessage;
    //mChat += ("Send " + sendMessage);
    ui->textEdit_2->setText(strData);
    tcpSocket->write(sendMessage);
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

char ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}

QByteArray QString2Hex(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
}
    senddata.resize(hexdatalen);
    return senddata;
}

MainWindow::~MainWindow()
{
    database.close();
    delete ui;
}

//打开串口
void MainWindow::on_OpenSerialButton_clicked()
{
    if(ui->OpenSerialButton->text() == tr("打开串口"))
    {
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(ui->PortBox->currentText());
        //打开串口
        serial->open(QIODevice::ReadWrite);
        //设置波特率
        serial->setBaudRate(115200);
        //设置流控制
        serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制
        //设置全局open
        open_serial = true;
        //关闭设置菜单使能
        ui->PortBox->setEnabled(false);
        ui->Plant_varieties->setEnabled(false);

        ui->Model_selection->setEnabled(false);
        ui->OpenSerialButton->setText(tr("关闭串口"));

        //设置植物种类
        Variety = ui->Plant_varieties->currentText();
        plant = new Plant(Variety);

        //连接信号槽
        QObject::connect(serial,&QSerialPort::readyRead,this,&MainWindow::ReadData);
    }
    else
    {
        //关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();

        open_serial = false;
        //恢复设置使能
        ui->PortBox->setEnabled(true);
        ui->Plant_varieties->setEnabled(true);

        ui->Model_selection->setEnabled(true);
        ui->OpenSerialButton->setText(tr("打开串口"));

    }
}
//读取接收到的信息
void MainWindow::ReadData()
{
    QByteArray buf;
    buf = serial->readAll();
    QDataStream out(&buf,QIODevice::ReadWrite);
    ProcessMsgFromSerial(buf);

    while(!out.atEnd()){
        qint8 outChar = 0;
        out>>outChar;   //每字节填充一次，直到结束
        //十六进制的转换
        QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));
        ui->textEdit->insertPlainText(str.toUpper());//大写
        ui->textEdit->insertPlainText(" ");//每发送两个字符后添加一个空格
        ui->textEdit->moveCursor(QTextCursor::End);
    }

    ui->textEdit->insertPlainText("\n");
    buf.clear();
}

//发送按钮槽函数
void MainWindow::on_SendButton_clicked()
{
    if(open_serial){
        QString str=ui->textEdit_2->toPlainText().toLatin1();
        serial->write(QString2Hex(str));
    }
}

//消息处理函数
void MainWindow::ProcessMsgFromSerial(QByteArray &msg){
    if(msg.length() < 6)
            return;
    //温湿亮度
    if(msg[3] == 0x02 && msg[4] == 0x01)
    {
        temp_humi_light->setValue(msg);
        updateTempHumiLig();
        SmartControl();
    }
    //热释红外，看有没有盗贼之类的
    else if((int)msg[3]==0x05 && (int)msg[4]==0x01){
        if((int)msg[5]==0x00){
            pir->person == false;
        }
        else if ((int)msg[5]==0x01){
            pir->person == true;
            b = new Warn(this);
            QLabel *pLabel = new QLabel(b);
            pLabel->setText("警告:有人(可能是盗贼)出现在工厂！");
//            pLabel->setText("警告:有烟雾，可能出现火情！");
            b->show();
            //SendMessage();
        }
    }
    //烟雾检测，判断火情
    else if((int)msg[3]==0x04 && (int)msg[4]==0x01){
        if((int)msg[5] == 0x01)
               {
                    b = new Warn(this);
                    QLabel *pLabel = new QLabel(b);
                    pLabel->setText("警告:有烟雾，可能出现火情！");
                    b->show();
//                    SendMessage();
               }
        else if((int)msg[5] == 0x00)
               {
                   //ui->SmokelineEdit->setPalette(pe_black);
                   //ui->SmokelineEdit->setText("无烟雾");
               }
    }

}

//发送短信
void MainWindow::SendMessage(){
    QString tel = "17863975270";
    QString name = "管理员";
    int type=0;
    //sms->singleMessage(ui->TellineEdit->displayText(),ui->NamelineEdit->displayText());
    sms->singleMessage(tel, name, type);
}

//温湿度光照显示
void MainWindow::updateTempHumiLig()
{
    ui->LcdTemp->display(temp_humi_light->getTemperature());
    ui->LcdHumi->display(temp_humi_light->getHumidity());
    ui->LcdLight->display(temp_humi_light->getLight());

    if(temp_humi_light->getTemperature()>plant->max_temp||temp_humi_light->getTemperature()<plant->min_temp)
        {
            b=new Warn(this);
            QLabel *pLabel = new QLabel(b);
            pLabel->setText("温度异常");
            b->show();
        }
        if(temp_humi_light->getHumidity()>plant->max_humi||temp_humi_light->getHumidity()<plant->min_humi)
        {
            b=new Warn(this);
            QLabel *pLabel = new QLabel(b);
            pLabel->setText("湿度异常");
            b->show();
        }
        if(temp_humi_light->getLight()>plant->max_light||temp_humi_light->getLight()<plant->min_light)
        {
            b=new Warn(this);
            QLabel *pLabel = new QLabel(b);
            pLabel->setText("光照异常");
            b->show();
        }
        updatedataSlot_Temperature();
        updatedataSlot_Humidity();
        updatedataSlot_light();
        sendData();
}

//调节光的亮度
void MainWindow::changePwm(int value)
{
    unsigned char range = PWM::RANGE[value];
    pwm->LightVal = range;
    PWM::MSG_PWM[4] = range;
    PWM::MSG_PWM[5] = 0x50 + range;
    serial->write(PWM::MSG_PWM);
    sleep(0.5);
    serial->write(PWM::MSG_PWM);            //  发送两次,以防丢包
    ui->PwmLineEdit->setText(QString("%1").arg(range));
}

//日志按钮
void MainWindow::on_BntMotor_2_clicked()
{
    if(!open_serial){
        a=new Dialog(this);
        a->show();
    }
}

//实时数据图像
void MainWindow::setupRealtimelight(QwtPlot *qwtplot)
{
    //初始化xdata,x对应长度为5的坐标，y初始全为0
    for(int i=1;i<5001;i++)
    {
        x_light.append(double(i)/1000-5);
        y_light.append(0);
    }

    //light_Name = "实时变化曲线";
   // qwtplot->setTitle(light_Name);
    qwtplot->setCanvasBackground(Qt::white);//背景
    qwtplot->insertLegend(new QwtLegend(),QwtPlot::RightLegend);//标签

    curve = new QwtPlotCurve();
    //curve->setTitle("光照强度变化曲线");//曲线名字
    curve->setPen( Qt::green, 1 );//曲线的颜色 宽度;

    QTime curtime;
    curtime=curtime.currentTime();
    qwtplot->setAxisTitle(QwtPlot::xBottom, " time/s");
    qwtplot->setAxisTitle(QwtPlot::yLeft,"Light/lx");
    qwtplot->setAxisScale(QwtPlot::yLeft,0,300,10);
    qwtplot->setAxisScale(QwtPlot::xBottom,-5,0,1);



    QwtPlotZoomer *zoomer = new QwtPlotZoomer( qwtplot->canvas() );
    zoomer->setRubberBandPen( QColor( Qt::black ) );
    zoomer->setTrackerPen( QColor( Qt::black ) );
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2,Qt::RightButton, Qt::ControlModifier );
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton );
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( qwtplot->canvas() );                 //默认的滑轮及右键缩放功能  图形的整体缩放

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->enableX( true );//设置网格线
    grid->enableY( true );
    grid->setMajorPen( Qt::black, 0, Qt::DotLine );
    grid->attach(qwtplot);

    connect(&updateTimer,SIGNAL(timeout()),this,SLOT(updatedataSlot_light()));
    updateTimer.start(0);


}

//用于更新y_light,实际情况就是read数据
void MainWindow::updatedataSlot_light(){
    static QTime dataTime(QTime::currentTime());
    long int eltime = dataTime.elapsed();
    static int lastpointtime = 0;

    int size = (eltime - lastpointtime);

    if(size>0){//有数据传入

        y_light.erase(y_light.begin(),y_light.begin()+size);//擦除多余的数据
        for(int i=1;i<size+1;++i){
            y_light.append(temp_humi_light->getLight());
//            qDebug() << temp_humi_light->getLight();
        }
        lastpointtime = eltime;
    }

    curve->setSamples(x_light,y_light);
    curve->attach(ui->qwtPlot);
    ui->qwtPlot->replot();

    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    double fpstime = (double)eltime/1000.0-lastFpsKey;
    if ( fpstime> 2) // average fps over 2 seconds
    {
        ui->statusBar->showMessage(
                    QString("%1 FPS")
                    .arg(frameCount/fpstime, 0, 'f', 0)
                    , 0);
        lastFpsKey = (double)eltime/1000.0;
        frameCount = 0;
    }
}
void MainWindow::setupRealtimeHumidity(QwtPlot *qwtplot)
{
    //初始化_Humidity,x对应长度为5的坐标，y初始全为0
    for(int i=1;i<5001;i++)
    {
        x_Humidity.append(double(i)/1000-5);
        y_Humidity.append(0);
    }

   // Humidity_Name = "实时变化曲线";
   // qwtplot->setTitle(Humidity_Name);
    qwtplot->setCanvasBackground(Qt::white);//背景
    qwtplot->insertLegend(new QwtLegend(),QwtPlot::RightLegend);//标签

    curve1 = new QwtPlotCurve();
    //curve1->setTitle("湿度变化曲线");//曲线名字
    curve1->setPen( Qt::blue, 1 );//曲线的颜色 宽度;

    QTime curtime;
    curtime=curtime.currentTime();
    qwtplot->setAxisTitle(QwtPlot::xBottom, " time/s");
    qwtplot->setAxisTitle(QwtPlot::yLeft,"Humidity/%");
    qwtplot->setAxisScale(QwtPlot::yLeft,0,100,5);
    qwtplot->setAxisScale(QwtPlot::xBottom,-5,0,1);



    QwtPlotZoomer *zoomer = new QwtPlotZoomer( qwtplot->canvas() );
    zoomer->setRubberBandPen( QColor( Qt::green ) );
    zoomer->setTrackerPen( QColor( Qt::black ) );
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2,Qt::RightButton, Qt::ControlModifier );
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton );
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( qwtplot->canvas() );                 //默认的滑轮及右键缩放功能  图形的整体缩放

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->enableX( true );//设置网格线
    grid->enableY( true );
    grid->setMajorPen( Qt::black, 0, Qt::DotLine );
    grid->attach(qwtplot);


}

//用于更新y_Humidity,实际情况就是read数据
void MainWindow::updatedataSlot_Humidity(){
    static QTime dataTime(QTime::currentTime());
    long int eltime = dataTime.elapsed();
    static int lastpointtime = 0;

    int size = (eltime - lastpointtime);
    if(size>0){//有数据传入

       y_Humidity.erase(y_Humidity.begin(),y_Humidity.begin()+size);//擦除多余的数据
        for(int i=1;i<size+1;++i){
            y_Humidity.append(temp_humi_light->getHumidity());
//            qDebug() << temp_humi_light->getHumidity();
        }
        lastpointtime = eltime;
    }

    curve1->setSamples(x_Humidity,y_Humidity);
    curve1->attach(ui->qwtPlot_2);
    ui->qwtPlot_2->replot();

}

void MainWindow::setupRealtimeTemperature(QwtPlot *qwtplot)
{
    //初始化x_Temperature,x对应长度为5的坐标，y初始全为0
    for(int i=1;i<5001;i++)
    {
        x_Temperature.append(double(i)/1000-5);
        y_Temperature.append(0);
    }

    //Temperature_Name = "实时变化曲线";
    //qwtplot->setTitle(Temperature_Name);
    qwtplot->setCanvasBackground(Qt::white);//背景
    qwtplot->insertLegend(new QwtLegend(),QwtPlot::RightLegend);//标签

    curve2 = new QwtPlotCurve();
    //curve2->setTitle("温度变化曲线");//曲线名字
    curve2->setPen( Qt::red, 1 );//曲线的颜色 宽度;

    QTime curtime;
    curtime=curtime.currentTime();
    qwtplot->setAxisTitle(QwtPlot::xBottom, " time/s");
    qwtplot->setAxisTitle(QwtPlot::yLeft,"Temperature/℃");
    qwtplot->setAxisScale(QwtPlot::yLeft,-10,50,2);
    qwtplot->setAxisScale(QwtPlot::xBottom,-5,0,1);



    QwtPlotZoomer *zoomer = new QwtPlotZoomer( qwtplot->canvas() );
    zoomer->setRubberBandPen( QColor( Qt::blue ) );
    zoomer->setTrackerPen( QColor( Qt::black ) );
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2,Qt::RightButton, Qt::ControlModifier );
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton );
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( qwtplot->canvas() );                 //默认的滑轮及右键缩放功能  图形的整体缩放

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->enableX( true );//设置网格线
    grid->enableY( true );
    grid->setMajorPen( Qt::black, 0, Qt::DotLine );
    grid->attach(qwtplot);

    connect(&updateTimer,SIGNAL(timeout()),this,SLOT(updatedataSlot()));
    updateTimer.start(0);

}

//用于更新y_Temperature,实际情况就是read数据
void MainWindow::updatedataSlot_Temperature(){
    static QTime dataTime(QTime::currentTime());
    long int eltime = dataTime.elapsed();
    static int lastpointtime = 0;

    int size = (eltime - lastpointtime);

    if(size>0){//有数据传入

        y_Temperature.erase(y_Temperature.begin(),y_Temperature.begin()+size);//擦除多余的数据
        for(int i=1;i<size+1;++i){
            y_Temperature.append(temp_humi_light->getTemperature());
//            qDebug() << temp_humi_light->getTemperature();
        }
        lastpointtime = eltime;
    }

    curve2->setSamples(x_Temperature,y_Temperature);
    curve2->attach(ui->qwtPlot_3);
    ui->qwtPlot_3->replot();

}

//实时显示时间
void MainWindow::timerUpDate()

{
QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");//设置系统时间显示格式
ui->label_3->setText(str);//在标签上显示时间
}


//加热
void MainWindow::on_HotButton_clicked()
{
    if(open_serial){
        if(ui->HotButton->text() == tr("加热"))
        {
            HandleFuction(1);
            ui->HotButton->setText(tr("停止加热"));
        }
        else if(ui->HotButton->text() == tr("停止加热")){
            HandleFuction(2);
            ui->HotButton->setText(tr("加热"));
        }

    }

}

//制冷
void MainWindow::on_ColdButton_clicked()
{
    if(open_serial){
        if(ui->ColdButton->text() == tr("制冷"))
        {
            HandleFuction(3);
            ui->ColdButton->setText(tr("停止制冷"));
        }
        else if(ui->ColdButton->text() == tr("停止制冷")){
            HandleFuction(4);
            ui->ColdButton->setText(tr("制冷"));
        }
    }
}

//加湿
void MainWindow::on_WetButton_clicked()
{
    if(open_serial){
        if(ui->WetButton->text() == tr("加湿"))
        {
            HandleFuction(5);
            ui->WetButton->setText(tr("停止加湿"));
        }
        else if(ui->WetButton->text() == tr("停止加湿")){
            HandleFuction(6);
            ui->WetButton->setText(tr("加湿"));
        }

    }

}

//通风
void MainWindow::on_WindBotton_clicked()
{
    if(open_serial){
        if(ui->WindBotton->text() == tr("通风"))
        {
            HandleFuction(7);
            ui->WindBotton->setText(tr("停止通风"));
        }
        else if(ui->WindBotton->text() == tr("停止通风")){
            HandleFuction(8);
            ui->WindBotton->setText(tr("通风"));
        }
    }
}

//处理措施
void MainWindow::HandleFuction(int type){
    QByteArray st;
    QString str;
    switch(type){
    case 1:
    //case1 加热
        str = "40060106014e";//电机LED1亮指令
        st = QString2Hex(str);
        serial->write(st);
        //发送到串口
        serial->write(st);
        serial->write(st);
        qDebug() << st;
        break;
    case 2:
    //case2 停止加热
        str = "40060106024f";//关闭LED1指令
        st = QString2Hex(str);
        serial->write(st);
        serial->write(st);
        serial->write(st);
        qDebug() << st;
        break;
    case 3:
    //case3 制冷
        str = "400601060350";//电机LED2亮表示制冷
        st = QString2Hex(str);
        serial->write(st);      //发送到串口
        serial->write(st);
        serial->write(st);
        qDebug() << st;
        break;
    case 4:
    //case4 停止制冷
        str = "400601060451";//关闭LED2指令
        st = QString2Hex(str);
        serial->write(st);
        serial->write(st);
        serial->write(st);
        qDebug() << st;
        break;
    case 5:
    //case5 加湿
        str = "400601060552";//电机LED3亮表示加湿
        st = QString2Hex(str);
        serial->write(st);      //发送到串口
        serial->write(st);
        serial->write(st);
        qDebug() << st;
        break;
    case 6:
    //case6 停止加湿
        str = "400601060653";//关闭LED3指令
        st = QString2Hex(str);
        serial->write(st);
        serial->write(st);
        serial->write(st);
        qDebug() << st;
        break;
    case 7:
    //case7 通风
        str = "400601060a57";//电机正转表示通风
        st = QString2Hex(str);
        serial->write(st);      //发送到串口
        serial->write(st);
        serial->write(st);
        qDebug() << st;
        break;
    case 8:
        str = "400601060c59";//关闭电机
        st = QString2Hex(str);
        serial->write(st);
        serial->write(st);
        serial->write(st);
        break;
    case 9:
    //case9 提高光照
        if (pwm->LightVal < 9){
//            qDebug() << pwm->LightVal;
            changePwm(pwm->LightVal + 1);
            sleep(1);
        }
        else{
            //电机正转打开大棚幕帘
            if(!mulian){
                str = "400601060b58";
                st = QString2Hex(str);
                serial->write(st);
                sleep(1);
                str = "400601060c59";
                st = QString2Hex(str);
                serial->write(st);
                mulian = true;
            }
        }
        break;
    case 10:
    //case 10 降低光照
        if(mulian){
            //电机正转打开大棚幕帘
            str = "400601060a57";
            st = QString2Hex(str);
            serial->write(st);
            sleep(1);
            str = "400601060c59";
            st = QString2Hex(str);
            serial->write(st);
            mulian = false;
        }
        else{ 
        if (pwm->LightVal > 0){
//            qDebug() << pwm->LightVal;
            changePwm(pwm->LightVal - 1);
            sleep(1);
        }
        break;
        }
    }
}

//自动化控制
void MainWindow::SmartControl(){
    if(temp_humi_light->getTemperature() > plant->max_temp){
        HandleFuction(2);
        HandleFuction(3);
        HandleFuction(7);
    }
    else if(temp_humi_light->getTemperature() < plant->min_temp){
        HandleFuction(4);
        HandleFuction(8);
        HandleFuction(1);
    }

    if(temp_humi_light->getHumidity() > plant->max_humi){
        HandleFuction(6);
        HandleFuction(7);
    }
    else if(temp_humi_light->getHumidity() < plant->min_humi){
        HandleFuction(8);
        HandleFuction(5);
    }

    if(temp_humi_light->getLight() > plant->max_light){
        HandleFuction(10);
    }
    else if(temp_humi_light->getLight() < plant->min_light){
        HandleFuction(9);
    }
}
