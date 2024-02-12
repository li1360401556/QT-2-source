#include "fightscence.h"
#include<QPixmap>
#include<QPainter>
#include"config.h"
#include<QPushButton>
#include<QMenuBar>
#include<QMessageBox>
fightScence::fightScence(QWidget *parent)
    : QMainWindow{parent}
{
    //设置固定宽高
    setFixedSize(GAME_WIDTH,GAME_HIGH);
    xuanguanzhandou();


}

void fightScence::paintEvent(QPaintEvent *)
{
    //创建画家对象
    QPainter painter(this);
    //创建图片对象
    QPixmap pix;
    pix.load(":/R-C.jfif");
    painter.drawPixmap(QRect(this->x(),this->y(),this->width(),this->height()),pix);

}

void fightScence::xuanguanzhandou()
{
    //创建画家对象
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;

    //创建五个关卡按钮，一个返回按钮设置属性并作连接
    QPushButton*btn1=new QPushButton("第一关",this);
    QPushButton*btn2=new QPushButton("第二关",this);
    QPushButton*btn3=new QPushButton("第三关",this);
    QPushButton*btn4=new QPushButton("第四关",this);
    QPushButton*btn5=new QPushButton("第五关",this);
    QPushButton*btn6=new QPushButton("返回",this);
    btn1->setFixedSize(100,50);
    btn2->setFixedSize(100,50);
    btn3->setFixedSize(100,50);
    btn4->setFixedSize(100,50);
    btn5->setFixedSize(100,50);
    btn6->setFixedSize(100,50);
    btn1->move(this->width()/2-50,this->height()/12-25);
    btn2->move(this->width()/2-50,this->height()/6+25);
    btn3->move(this->width()/2-50,this->height()/3+25);
    btn4->move(this->width()/2-50,this->height()/2+25);
    btn5->move(this->width()/2-50,this->height()/3*2+25);
    btn6->move(this->width()/2-50,this->height()/6*5+25);
    //实例化fight_1对象
   this->fight_1=new Fight_1;
    connect(btn1,&QPushButton::clicked,[=](){
        this->hide();
       this->fight_1->show();
       fight_1->gamestar();

    });
   connect(btn2,&QPushButton::clicked,[=](){
        QMessageBox::warning(this,"警告！","请通过之前关卡！");

   });
    connect(btn3,&QPushButton::clicked,[=](){
        QMessageBox::warning(this,"警告！","请通过之前关卡！");

    });
   connect(btn4,&QPushButton::clicked,[=](){
       QMessageBox::warning(this,"警告！","请通过之前关卡！");

   });
    connect(btn5,&QPushButton::clicked,[=](){
        QMessageBox::warning(this,"警告！","请通过之前关卡！");

    });

    connect(btn6,&QPushButton::clicked,[=](){
        //触发自定义信号
        emit this->ScenceBack();
    });
    //菜单栏创建，退出按钮创建
    QMenuBar*menu1=new QMenuBar(this);
    menu1->addAction("退出");
    connect(menu1,&QMenuBar::triggered,[=](){
        //QMessageBox::StandardButton result接收Qmessagebox返回值
        QMessageBox::StandardButton result = QMessageBox::question(this,"宁要走吗？","不要走好不好？");

        if(QMessageBox::Yes==result)
            this->close();
    });
}
