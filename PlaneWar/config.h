#ifndef CONFIG_H
#define CONFIG_H
/*********************游戏配置数据宏***********************************/
#define GAME_WIDTH 512 //宽度
#define GAME_HIGH  768 //高度
#define GAME_TITLE "飞机大战V2.0"//标题
#define GAME_RATE 10//定时器刷新速率 ms
#define GAME_HERO_1 ":/hero.png"//英雄图片路径
#define GMAE_HERO_POSRATE 20 //英雄战机位移像素
#define GAME_ZIDAN_PATH_1 ":/bullet_1.png" //子弹图片路径
#define GAME_ZIDAN_SPEED 20 //子弹射击速度
#define GAME_ZIDAN_NUM 30 //弹夹数量
#define GAME_ZIDAN_INTERVAL 10 //发射间隔
#define GAMEN_HEALTH 5 //生命值大小
/*********************地图配置数据宏***********************************/
#define MAP_PATH_1 ":/img_bg_level_1.jpg"//地图路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度
/*********************UI配置数据宏***********************************/
#define UI_HEALTH ":/bullet_9.png" //生命值ui路径
#define UI_PAUSE_PATH ":/pause.png" //暂停按钮路径
/*********************敌机配置数据宏***********************************/
#define ENEMY_PATH  ":/img-plane_%1.png"//敌机图片路径 需要填补占位符
#define ENEMY_SPEED 5 //敌机速度
#define ENEMY_NUM 20 // 敌机数量
#define ENEMY_INTERVAL 30 //间隔
#define ENEMY_SIZENUM_1 1 //敌机种类数量,挑选敌机
#define ENEMY_RANDOM QRandomGenerator::global()->bounded(6) //敌机出现的随机种类
/*********************爆炸配置数据宏***********************************/
#define BOMB_PATH ":/bomb-%1.png"//爆炸路径
#define BOMB_NUM 20 //爆炸数量
#define BOMB_MAX 7 //爆炸图片数量
#define BOMB_INTERVAL 20 //爆炸切图时间
/*********************音效配置数据宏***********************************/
#define SOUND_BACKGROUND ":/bg.wav" // 背景音乐
#define SOUND_BOMB ":/bomb.wav" // 爆炸音效
#endif // CONFIG_H
