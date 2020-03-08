#include "temp_humi_light.h"

Temp_Humi_Light::Temp_Humi_Light(){
    temperature = 0;
    humidity = 0;
    light = 0;
}

void Temp_Humi_Light::setValue(int temperature, int humidity, float light)
{
    this->temperature = temperature;
    this->humidity = humidity;
    this->light = light;
}

void Temp_Humi_Light::setValue(QByteArray& byte)
{
    temperature = (byte[5] << 8) + byte[6];
    humidity = (byte[7] << 8) + byte[8];
    light = ((byte[9] << 8) + byte[9])*3012.9/(32768*4);
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE","wconntosqlite");
            mydb.setDatabaseName("plant_data.db");
            if(mydb.open())
                {
                    Date = QDate::currentDate().toString("yyyy-MM-dd");
                    Time = QTime::currentTime().toString("hh:mm:ss");
                    QSqlQuery query(mydb);
                    query.prepare("insert into plant_data (Date,Time,Temp,Humi,Light) values (:da,:ti,:te, :hu, :li)"); //准备执行SQL查询
                    query.bindValue(":da",Date);
                    query.bindValue(":ti",Time);
                    query.bindValue(":te", temperature);   //在这定占位符上确定绑定的值
                    query.bindValue(":hu", humidity);
                    query.bindValue(":li", light);
                    bool isok=query.exec();
                    if(isok)
                        qDebug()<<temperature<<humidity<<light<<"数据写入成功";
            }



}

int Temp_Humi_Light::getTemperature()
{
    return temperature;
}

int Temp_Humi_Light::getHumidity()
{
    return humidity;
}

float Temp_Humi_Light::getLight()
{
    return light;
}
