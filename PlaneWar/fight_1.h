#ifndef FIGHT_1_H
#define FIGHT_1_H

#include <QWidget>
#include<QTimer>
#include"map.h"
#include"hero.h"
#include<QKeyEvent>
#include"zidan.h"
#include"uiscence.h"
#include"mypushbutton.h"
#include"MyThread.h"
#include<QWaitCondition>
#include<QMutex>
#include<QThread>
#include"enemyplane.h"
#include "bomb.h"
class Fight_1 : public QWidget
{
    Q_OBJECT
public:
    explicit Fight_1(QWidget *parent = nullptr);
    //创建一个map对象
    map m_map;
    //启动游戏
    void gamestar();
    //更新所有游戏中的元素坐标
    void updatePosition();
    //绘制到屏幕中（重写绘图事件）
    void paintEvent(QPaintEvent*);
    //创建hero对象
    Hero hero;
    //定时器
    QTimer m_timer;
    //记录键盘按下事件
    bool keyboard=false;
    //创建ui对象
    UIscence Ui;
    Mypushbutton*mybtn=new Mypushbutton(UI_PAUSE_PATH);
    //创建thread对象用于双线程转换
//   MyThread mythread;
    //创建一个暂停按钮函数
    void PauseButton();
    //多线程暂停按钮的二次尝试
//    QWaitCondition condition;
//    QMutex mutex;
//    bool dataReady = false;
    //敌机出场函数
    void enemystart();
    //敌机数组
    Enemyplane m_enemyplane[20];
    //敌机出场间隔
    int m_recorder;
    //添加碰撞监测函数
    void collisionDetection();
    //添加分数
    int goat=0;
    //爆炸的数组
    Bomb m_bombs[BOMB_NUM];






signals:
    //创建一个暂停按键自定义信号传给主函数
    void pausebutton_signal();
    //创建一个碰撞信号
    void pengzhuang();

    // QWidget interface
protected:
    //重写键盘按下事件和松开事件
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
};

#endif // FIGHT_1_H
