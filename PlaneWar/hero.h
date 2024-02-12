#ifndef HERO_H
#define HERO_H
#include<QPixmap>
#include<QRect>
#include"zidan.h"
class Hero
{
public:
    Hero();
    //记录操控英雄的位置坐标
    int h_X;
    int h_Y;
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition(int x,int y);


public:
    //英雄图片对象
    QPixmap hero_1;

    //飞机矩形边框
    QRect h_rect;
    //弹夹
    Zidan Z_zidans[GAME_ZIDAN_NUM];
   //发射间隔
    int Z_recorder;


};

#endif // HERO_H
