#include "zidan.h"
#include<QDebug>
Zidan::Zidan()
{
    //创建子弹图片
    zidan.load(GAME_ZIDAN_PATH_1);
    //设置子弹矩形边框
    Z_rect.setWidth(zidan.width());
    Z_rect.setHeight(zidan.height());
    Z_rect.moveTo(Z_x,Z_y);
    //初始化子弹位置信息
    Z_x=GAME_WIDTH*0.5;
    Z_y=GAME_HIGH*0.5;
    //子弹状态 (默认空闲)
    Z_free=true;
    Z_speed=GAME_ZIDAN_SPEED;


}

void Zidan::Z_updatePosition()
{
    //空闲状态下，不需要计算坐标
    if(Z_free)
    {
        return;
    }
    //非空闲，子弹向上移动
    else
    {
        Z_y-=Z_speed;
        Z_rect.moveTo(Z_x,Z_y);
        //子弹位置超出窗口，重新变为空闲状态
        if(Z_y<=-Z_rect.height())
        {
            Z_free=true;
        }
//        qDebug()<<"子弹1";
    }


}
void Zidan::Enemyzidan_updatePosition()
{
    //空闲状态下，不需要计算坐标
    if(Z_free)
    {
        return;
    }
    //非空闲，子弹向下移动
    else
    {
        Z_y+=Z_speed;
        Z_rect.moveTo(Z_x,Z_y);
        //子弹位置超出窗口，重新变为空闲状态
        if(Z_y>=GAME_HIGH)
        {
            Z_free=true;
        }
        //        qDebug()<<"子弹2";
    }


}
