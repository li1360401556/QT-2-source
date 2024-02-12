#include "hero.h"
#include"config.h"
#include<QDebug>
Hero::Hero()
{
    //加载英雄战机图片路径
    hero_1.load(GAME_HERO_1);
    //初始化战机位置信息
    h_Y=(GAME_HIGH-hero_1.height())*0.5;
    h_X=(GAME_WIDTH-hero_1.width())*0.5;
    //初始化矩形边框
    h_rect.setWidth(hero_1.width());
    h_rect.setHeight(hero_1.height());
    h_rect.moveTo(h_X,h_Y);
    //初始化时间间隔的记录变量为0
    Z_recorder=0;
}

void Hero::shoot()
{
    //累加时间间隔的记录变量
    Z_recorder++;
    //如果记录的数字未达到发射子弹时间间隔，直接return，不发射；
    if(Z_recorder<GAME_ZIDAN_INTERVAL)
        return;
    //到达发射时间间隔
    else
    {
        Z_recorder=0;
        for(int i=0;i<GAME_ZIDAN_NUM;i++)
        {
            //如果是空闲子弹
            if(Z_zidans[i].Z_free)
            //将空闲改为假
            {
                Z_zidans[i].Z_free=false;
                //设置子弹坐标
                Z_zidans[i].Z_x=h_X;
                Z_zidans[i].Z_y=h_Y;
                break;
//                qDebug()<<"子弹2";

            }
        }
    }

}

void Hero::setPosition(int x,int y)
{
    h_X=x;
    h_Y=y;
    h_rect.moveTo(h_X,h_Y);
}




