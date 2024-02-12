#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class Mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    //参数1 正常显示图片路径 参数2 按下后切换的图片路径
    Mypushbutton(QString normalImg,QString pressImg="");
    QString normalpath;
    QString presspath;
    //向下跳跃
    void star();
    //设置图片大小
    void setmybuttonsize(int width,int height);
     //创建Qpixmap的对象 加载图片
    QPixmap pix;



signals:

};

#endif // MYPUSHBUTTON_H
