#include "map.h"

map::map()
{
    //初始化加载地图对象
    map_1.load(MAP_PATH_1);
    map_2.load(MAP_PATH_1);
    //初始化Y坐标
    m_map1_posY=-GAME_HIGH+10;
    m_map2_posY=0;
    //地图滚动速度
    m_scroll_speed=MAP_SCROLL_SPEED;
}

void map::map_position()
{
    //处理第一张图片的位置
    m_map1_posY+=MAP_SCROLL_SPEED;
    if(m_map1_posY>=0)
    {
        m_map1_posY=-GAME_HIGH+10;
    }
    //处理第二张图片的位置
    m_map2_posY+=MAP_SCROLL_SPEED;
    if(m_map2_posY>=GAME_HIGH)
    {
        m_map2_posY=0;
    }
}
