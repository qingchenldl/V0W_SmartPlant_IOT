#include "plant.h"

Plant::Plant(QString name)
{
    if(name=="玫瑰")
    {
        max_humi=80;
        max_light=200;//#####
        max_temp=28;
        min_humi=50;
        min_light=100;//####
        min_temp=15;
        plant_name = "玫瑰";
    }
    else if(name=="香菇")//测试
    {
        max_humi=200;    //70
        max_light=200;//###150
        max_temp=20;
        min_humi=10;   //60
        min_light=50;  //###50
        min_temp=15;
        plant_name = "香菇";
    }
}

Plant::~Plant()
{

}
