#include "mypushbutton.h"
#include<QPixmap>
#include<QDebug>
//包含动画头文件
#include<QPropertyAnimation>
//函数声明和实现中不能有两个默认参数QString pressImg
Mypushbutton::Mypushbutton(QString normalImg, QString pressImg)
{
    this->normalpath=normalImg;
    this->presspath=pressImg;
    //创建Qpixmap的对象 加载图片
//    QPixmap pix;
    bool res=pix.load(normalImg);
    if(!res)
    {
        QString str=QString("加载图片失败，路径是:%1!").arg(normalImg);
        qDebug()<<str;
    }
//    //设置按钮固定大小
//    this->setFixedSize(QSize(pix.width(),pix.height()));
//    //设置不规则样式QSS语法
//    this->setStyleSheet("QPushButton{border:0px;}");
//    //设置图标
//    this->setIcon(pix);
//    //设置图标大小
//    this->setIconSize(QSize(pix.width(),pix.height()));



}

void Mypushbutton::star()
{
    //animate1向上跳跃
    //animate2向下跳跃

    //参数1 target 目标 参数2 方式
    QPropertyAnimation*animate1=new QPropertyAnimation(this,"geometry");
    QPropertyAnimation*animate2=new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animate1->setDuration(200);
    //设置起始位置
    animate1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置结束位置
    animate1->setEndValue(QRect(this->x(),this->y()-50,this->width(),this->height()));
    //设置动画效果
    animate1->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    //QAbstractAnimation::DeleteWhenStopped当执行完成时释放掉animate防止内存泄露
    animate1->start(QAbstractAnimation::DeleteWhenStopped);
    //设置动画间隔
    animate2->setDuration(200);
    //设置起始位置
    animate2->setStartValue(QRect(this->x(),this->y()-50,this->width(),this->height()));
    //设置结束位置
    animate2->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置动画效果
    animate2->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    //QAbstractAnimation::DeleteWhenStopped当执行完成时释放掉animate防止内存泄露
    animate2->start(QAbstractAnimation::DeleteWhenStopped);

}

void Mypushbutton::setmybuttonsize(int width,int height)
{
    this->pix=pix.scaled(pix.width()/width,pix.height()/height);
    //设置按钮固定大小
    this->setFixedSize(QSize(pix.width(),pix.height()));
    //设置不规则样式QSS语法
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}


