#ifndef FIGHTSCENCE_H
#define FIGHTSCENCE_H

#include <QMainWindow>
#include"fight_1.h"

class fightScence : public QMainWindow
{
    Q_OBJECT
public:
    explicit fightScence(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent*);
    //选关战斗场景搭建
    void xuanguanzhandou();
    //创建一个维护fight_1的指针
    Fight_1*fight_1;


signals:
    //创建自定义信号返回主场景
    void ScenceBack();


};

#endif // FIGHTSCENCE_H
