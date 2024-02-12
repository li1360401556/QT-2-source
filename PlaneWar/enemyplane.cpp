#include "enemyplane.h"
#include<QString>
#include<QDebug>
Enemyplane::Enemyplane()
{
    //敌机资源加载


        QString str=ENEMY_PATH;
        m_enemy.load(str.arg(ENEMY_SIZENUM_1));
        qDebug()<<"加载成功路径为："<<str.arg(ENEMY_SIZENUM_1);
        m_speed=ENEMY_SPEED;
        //敌机矩形边框(碰撞检测)


        rect.setWidth(m_enemy.width());
        rect.setHeight(m_enemy.height());
        rect.moveTo(m_x,m_y);

        //敌机位置
        m_x=0;
        m_y=0;
        //敌机状态
        m_free=true;
        //子弹发射间隔
        Z_recorder=0;

    //敌机速度
    m_speed=ENEMY_SPEED;



}

void Enemyplane::updateposition()
{
    //空闲状态不发射敌机


        if(m_free)
        {
            return;
        }
        m_y+=m_speed;
        rect.moveTo(m_x,m_y);
        if(m_y>=GAME_HIGH+rect.height())
            m_free=true;


}

void Enemyplane::shoot()
{


            //累加时间间隔的记录变量
            Z_recorder++;
            //如果记录的数字未达到发射子弹时间间隔，直接return，不发射；
            if(Z_recorder<GAME_ZIDAN_INTERVAL)
                return;
            //到达发射时间间隔

             Z_recorder=0;


                    //如果是空闲子弹
                    if(Z_zidan.Z_free)
                    //将空闲改为假
                    {
                        Z_zidan.Z_free=false;
                        //设置子弹坐标
                        Z_zidan.Z_x=m_x;
                        Z_zidan.Z_y=m_y;

                        //                qDebug()<<"子弹2";

                    }




}
