#ifndef MAP_H
#define MAP_H
#include<QPixmap>
#include"config.h"

class map
{
public:
    //构造函数
    map();
    //地图滚动坐标函数
    void map_position();
public:
    //地图图片对象
    QPixmap map_1;
    QPixmap map_2;
    //地图Y坐标
    int m_map1_posY;
    int m_map2_posY;
    //地图滚动幅度
    int m_scroll_speed;


};

#endif // MAP_H
