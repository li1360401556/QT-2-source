#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QWidget>
#include"fightscence.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Mainsence; }
QT_END_NAMESPACE

class Mainsence : public QWidget
{
    Q_OBJECT

public:
    Mainsence(QWidget *parent = nullptr);
    ~Mainsence();
    //初始化主场景
    void initScenne();
    //重写绘图事件，加载背景图片
    void paintEvent(QPaintEvent*);
    //创建一个指针维护战斗场景
    fightScence*fight;

private:
    Ui::Mainsence *ui;
};
#endif // MAINSENCE_H
