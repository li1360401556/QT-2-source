#include "mainsence.h"
#include "ui_mainsence.h"
#include"config.h"
#include<QPushButton>
#include<QLabel>
#include<QTextLine>
#include<QLineEdit>
#include<QMenuBar>
#include<QMessageBox>
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QSoundEffect>
Mainsence::Mainsence(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mainsence)
{

    ui->setupUi(this);
    initScenne();
    //创建Mypushbutton对象
    Mypushbutton*Mybtn=new Mypushbutton(":/bomb-2.png");
    //创建战斗场景
    this->fight=new fightScence;
    Mybtn->setParent(this);
    Mybtn->setmybuttonsize(1,1);
    Mybtn->move(this->width()*0.5-Mybtn->width()*0.5,this->height()*0.5-Mybtn->height()*0.5);

    //连接mypushbutton
    connect(Mybtn,&Mypushbutton::clicked,[=](){
        qDebug()<<"运行成功！";
        Mybtn->star();
        this->fight->show();
        this->hide();
    });
    //监听返回按钮信号
    connect(this->fight,&fightScence::ScenceBack,[=](){
        this->fight->hide();
        this->show();
    });
    //创建背景音乐
    QSoundEffect*m_sound=new QSoundEffect(this);
    //  启动音乐
    m_sound->setSource(QUrl::fromLocalFile(SOUND_BACKGROUND));
    //启动
    m_sound->play();



}

Mainsence::~Mainsence()
{
    delete ui;
}

void Mainsence::initScenne()
{
    //设置标题
    setWindowTitle(GAME_TITLE);
    //设置固定宽高
    setFixedSize(GAME_WIDTH,GAME_HIGH);
    //设1个按钮

    QPushButton*btn2=new QPushButton("结束游戏",this);

    btn2->move(this->width()*0.5-btn2->width(),this->height()*0.7-btn2->height()*0.5);

    btn2->setFixedSize(200,100);
//    //设置标签栏显示历史得分最高
//    QLabel*lab1=new QLabel(this);
//    lab1->setText("历史最高记录为：");
//    lab1->setFixedSize(200,100);
//    lab1->move(50,350);
//    QLineEdit*edit1=new QLineEdit(this);
//    edit1->setFixedSize(200,100);
//    edit1->move(250,350);
    //设置图标
    this->setWindowIcon(QIcon(":/app.ico"));
    //菜单栏创建，退出按钮创建
    QMenuBar*menu1=new QMenuBar(this);
    menu1->addAction("退出");
    connect(menu1,&QMenuBar::triggered,[=](){
        //QMessageBox::StandardButton result接收Qmessagebox返回值
        QMessageBox::StandardButton result = QMessageBox::question(this,"宁要走吗？","不要走好不好？");

        if(QMessageBox::Yes==result)
            this->close();
    });
    connect(btn2,&QPushButton::clicked,[=](){
        //QMessageBox::StandardButton result接收Qmessagebox返回值
        QMessageBox::StandardButton result = QMessageBox::question(this,"宁要走吗？","不要走好不好？");

        if(QMessageBox::Yes==result)
            this->close();
    });



}

void Mainsence::paintEvent(QPaintEvent *)
{
    //创建画家对象
    QPainter painter(this);
    //创建Qpixmap对象
    QPixmap pix;
    pix.load(":/R-C.jfif");
    //绘制背景
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

