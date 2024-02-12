#include "bomb.h"
#include<QString>
Bomb::Bomb()
{
    for(int i=1;i<=BOMB_MAX;i++)
    {
        QString str=QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }
    //坐标
    m_x=0;
    m_y=0;
    //空闲状态
    m_free=true;
    //当前播放爆炸图片下标
    m_index=0;
    //播放记录间隔
    m_recorder=0;


}

void Bomb::updatePosition()
{
    //如果空闲状态下的炸弹爆炸
    if(m_free)
        return;
    m_recorder++;
    //如果记录小于爆炸间隔,不需要切图
    if(m_recorder<BOMB_INTERVAL)
        return;
    //重置记录
    m_recorder=0;
    //切换爆炸图片下标
    m_index++;
    //数组下标从0开始,图片下标从1开始
    if(m_index>BOMB_MAX-1)
    {
        m_index=0;
        m_free=true;
    }

}
