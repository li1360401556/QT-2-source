#ifndef ZIDAN_H
#define ZIDAN_H
#include"config.h"
#include<QPixmap>
#include<QRect>

class Zidan
{
public:
    Zidan();
    //发射子弹的位置坐标
    int Z_x;
    int Z_y;

    //创建QPixmap对象
    QPixmap zidan;
    //子弹速度属性
    int Z_speed;
    //子弹矩形边框
    QRect Z_rect;//用于碰撞检测
    //子弹是否闲置
    bool Z_free;
    //更新子弹
    void Z_updatePosition();
    //敌机子弹
    void Enemyzidan_updatePosition();


};

#endif // ZIDAN_H
