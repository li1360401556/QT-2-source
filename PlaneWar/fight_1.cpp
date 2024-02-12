#include "fight_1.h"
#include"config.h"
#include<QPainter>
#include<QPixmap>
#include<QKeyEvent>
#include<QDebug>
#include<QMessageBox>
#include<QRandomGenerator>
#include<QLineEdit>
#include<QSoundEffect>
//线程头文件

Fight_1::Fight_1(QWidget *parent)
    : QWidget{parent}
{
    //设置固定宽高
    setFixedSize(GAME_WIDTH,GAME_HIGH);
    //定时器设置
    m_timer.setInterval(GAME_RATE);
    //启动游戏

//    gamestar();
    //暂停UI界面
    mybtn->setmybuttonsize(10,10);
    mybtn->setParent(this);
    mybtn->move(GAME_WIDTH-mybtn->width(),0);
    //取消焦点
    mybtn->setFocusPolicy(Qt::NoFocus);
    //监听暂停按钮
//    connect(mybtn,&QPushButton::clicked,[=](){
////        QMessageBox::critical(this,"暂停","暂停中。。。");
//        //暂停画面,阻塞住
////        this->mythread.start();
//        qDebug()<<"启动3";
////        this->mythread.TH_pause();
//        qDebug()<<"启动4";
////        this->mythread.TH_start();
//        qDebug()<<"启动5";
////        this->PauseButton();
        connect(mybtn,&QPushButton::clicked,[=](){
            QPushButton*btn_pause=new QPushButton("暂停中",this);
            btn_pause->move((GAME_WIDTH-btn_pause->width())*0.5,(GAME_HIGH-btn_pause->height())*0.5);
            btn_pause->show();
            m_timer.stop();
            connect(btn_pause,&QPushButton::clicked,[=](){
                m_timer.start();
                btn_pause->hide();
            });

        });

//    });
//    connect(this,&Fight_1::pausebutton_signal,[=](){
//        this->mythread.TH_start();
//    });
    //敌机出场间隔初始化
    m_recorder=0;
    //new一个Qlineedit对象显示得分
    QLineEdit*edt=new QLineEdit(this);
    edt->move((GAME_WIDTH-edt->width())*0.5,0);
    edt->setEnabled(false);

    //监听碰撞事件
    connect(this,&Fight_1::pengzhuang,[=](){
        QString str=QString("您的得分是:%1").arg(goat);
                      edt->setText(str);
        goat++;

    });



}

void Fight_1::gamestar()
{
    //启动定时器
    m_timer.start(GAME_RATE);
    //监听定时器发送的信号
    connect(&m_timer,&QTimer::timeout,[=](){
        //敌机出场
        enemystart();
        //更新元素坐标
        updatePosition();
        //绘制到屏幕中
        update();
        //碰撞检测
        collisionDetection();
        //监听暂停信号
//        connect(mybtn,&QPushButton::clicked,[=](){
//            m_timer.stop();
//            QPushButton*btn_pause=new QPushButton("暂停中",this);
//            btn_pause->setFixedSize((GAME_WIDTH-btn_pause->width())*0.5,(GAME_HIGH-btn_pause->height())*0.5);
//            connect(btn_pause,&QPushButton::clicked,[=](){
//                m_timer.start();
//                this->hide();
//            });

//        });

    });


}

void Fight_1::updatePosition()
{
    //更新地图坐标
    m_map.map_position();
    //发射子弹
    hero.shoot();


    //计算所有非空闲子弹的当前坐标
    for(int i=0;i<GAME_ZIDAN_NUM;i++)
    {
        //如果非空闲计算发射位置
        if(hero.Z_zidans[i].Z_free==false)
        {
            hero.Z_zidans[i].Z_updatePosition();
        }
    }
    //敌机出场
    for(int i=0;i<ENEMY_NUM;i++)
    {

    if(m_enemyplane[i].m_free==false)
        {
            m_enemyplane[i].updateposition();
            m_enemyplane[i].shoot();
            //计算所有非空闲子弹的当前坐标


                //如果非空闲计算发射位置
                if(m_enemyplane[i].Z_zidan.Z_free==false)
                {
                    m_enemyplane[i].Z_zidan.Enemyzidan_updatePosition();
                }


        }
    }
    //计算爆炸的播放图片
    for(int i=0;i<BOMB_NUM;i++)
    {
    if(m_bombs[i].m_free==false)
        m_bombs[i].updatePosition();

    }
}

void Fight_1::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.map_1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.map_2);
    //绘制英雄战机
    painter.drawPixmap(this->hero.h_X,this->hero.h_Y,hero.hero_1);
//    qDebug()<<"子弹4";
    //绘制英雄子弹
    for(int i=0;i<GAME_ZIDAN_NUM;i++)
    {
        //如果非空闲,绘制子弹
        if(hero.Z_zidans[i].Z_free==false)
        {
            painter.drawPixmap(hero.Z_zidans[i].Z_x,hero.Z_zidans[i].Z_y,hero.Z_zidans[i].zidan);
//            qDebug()<<"子弹3";
        }
    }
    //绘制敌机子弹
    for(int k=0;k<ENEMY_NUM;k++)
    {


            //如果非空闲,绘制子弹
            if(m_enemyplane[k].Z_zidan.Z_free==false)
            {
                painter.drawPixmap(m_enemyplane[k].Z_zidan.Z_x,m_enemyplane[k].Z_zidan.Z_y,m_enemyplane[k].Z_zidan.zidan);
                //            qDebug()<<"子弹3";
            }

    }
    //战机生命值ui绘制
    for(int i=0;i<GAMEN_HEALTH;i++)
    {
        painter.drawPixmap(0+i*Ui.ui_health.width(),0,Ui.ui_health);
    }

    //绘制敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemyplane[i].m_free==false)
        painter.drawPixmap(m_enemyplane[i].m_x,m_enemyplane[i].m_y,m_enemyplane[i].m_enemy);
    }
    //绘制爆炸
    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_free==false)
        {
        painter.drawPixmap(m_bombs[i].m_x,m_bombs[i].m_y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }


}

void Fight_1::PauseButton()
{
    QPushButton*P_btn=new QPushButton("暂停中",this);
    P_btn->setFixedSize(100,100);
    P_btn->move((GAME_WIDTH-P_btn->width())*0.5,(GAME_HIGH-P_btn->height())*0.5);
    P_btn->show();
    connect(P_btn,&QPushButton::clicked,[=](){
        P_btn->hide();
        emit void pausebutton_signal();
    });

}

void Fight_1::enemystart()
{
    m_recorder++;
    //未到达出场间隔
    if(m_recorder<ENEMY_INTERVAL)
        return;
    m_recorder=0;
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //如果空闲 出场



        if(m_enemyplane[i].m_free)
        {
            m_enemyplane[i].m_free=false;
            //坐标
            m_enemyplane[i].m_x=QRandomGenerator::global()->bounded(0,GAME_WIDTH-m_enemyplane[i].rect.width());
            m_enemyplane[i].m_y=-m_enemyplane[i].rect.height();
            break;

        }


    }
}

void Fight_1::collisionDetection()
{
    //遍历所有非空闲敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //如果空闲继续下一次循环
        if(m_enemyplane[i].m_free)
            continue;
        //遍历所有非空闲子弹
        for(int j=0;j<GAME_ZIDAN_NUM;j++)
        {
            //如果空闲继续下一次循环
            if(hero.Z_zidans[j].Z_free)
                continue;

            //如果子弹和战机相交，发生碰撞，同时将飞机和子弹空闲状态设为真
            if(hero.Z_zidans[j].Z_rect.intersects(m_enemyplane[i].rect))
            {
                hero.Z_zidans[j].Z_free=true;
                m_enemyplane[i].m_free=true;
                m_enemyplane[i].Z_zidan.Z_free=true;
                emit pengzhuang();
                //爆炸效果播放
                for(int k=0;k<BOMB_NUM;k++)
                {
                    if(m_bombs[k].m_free)

                    {
                        //爆炸音效添加
                        //创建背景音乐
                        QSoundEffect*m_sound=new QSoundEffect(this);
                        //  启动音乐
                        m_sound->setSource(QUrl::fromLocalFile(SOUND_BOMB));
                        //启动
                        m_sound->play();

                        //空闲状态，爆炸开始
                        m_bombs[k].m_free=false;
                        m_bombs[k].m_x=m_enemyplane[i].m_x;
                        m_bombs[k].m_y=m_enemyplane[i].m_y;

                        break;
                    }
                }

            }


        }


    }
}

void Fight_1::keyPressEvent(QKeyEvent *e)
{


    //边界检测
    switch(e->key())
    {
    case Qt::Key_W:
        if(hero.h_Y>=GMAE_HERO_POSRATE)
        this->hero.h_Y-=GMAE_HERO_POSRATE;
        break;
    case Qt::Key_S:
        if(hero.h_Y<=GAME_HIGH-hero.hero_1.height())
        this->hero.h_Y+=GMAE_HERO_POSRATE;
        break;
    case Qt::Key_A:
        if(hero.h_X>=0)
        this->hero.h_X-=GMAE_HERO_POSRATE;
        break;
    case Qt::Key_D:
        if(hero.h_X<=GAME_WIDTH-hero.hero_1.width())
        this->hero.h_X+=GMAE_HERO_POSRATE;
        break;



    }

}

void Fight_1::keyReleaseEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_W:
        if(hero.h_Y>=GMAE_HERO_POSRATE)
        this->hero.h_Y-=GMAE_HERO_POSRATE;
        break;
    case Qt::Key_S:
        if(hero.h_Y<=GAME_HIGH-hero.hero_1.height())
        this->hero.h_Y+=GMAE_HERO_POSRATE;
        break;
    case Qt::Key_A:
        if(hero.h_X>=0)
        this->hero.h_X-=GMAE_HERO_POSRATE;
        break;
    case Qt::Key_D:
        if(hero.h_X<=GAME_WIDTH-hero.hero_1.width())
        this->hero.h_X+=GMAE_HERO_POSRATE;
        break;



    }

}


