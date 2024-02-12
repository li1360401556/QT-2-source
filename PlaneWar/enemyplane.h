#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include<QPixmap>
#include"config.h"
#include"zidan.h"
class Enemyplane
{
public:
    Enemyplane();
    //更新坐标
    void updateposition();
    //设置设计属性
    void shoot();
public:
    //敌机图片资源对象
    QPixmap m_enemy;
    //位置信息
    int m_x;
    int m_y;
    //矩形边框
    QRect rect;
    //状态
    bool m_free;
    //速度
    int m_speed;
    //弹夹
    Zidan Z_zidan;
    //发射间隔
    int Z_recorder;
};

#endif // ENEMYPLANE_H
