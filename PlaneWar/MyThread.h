//#ifndef MYTHREAD_H
//#define MYTHREAD_H
////#include<QThread>
//////互斥量头文件
////#include<QMutex>
////#include<QKeyEvent>
////class MyThread:public QThread
////{
////public:
////    MyThread();
////     //创建两个接口控制主线程暂停与开始
////    void TH_pause();
////    void TH_start();
////protected:
////    //重写run（）虚函数主函数通过star（）调用
////    void run();
////    //重写键盘事件
////    void keyPressEvent(QKeyEvent *key_value);
////    //创建一个bool类型的变量用于控制暂停和开始
////    //一开始为真
////    bool pauseORstart=true;

////signals:
////     void MythreadisDone();
////private:
////    //互斥量
////    QMutex m_mutex;



////};
//#include <QCoreApplication>
//#include <QThread>
//#include <QWaitCondition>
//#include <QMutex>
//#include <QDebug>



//class MyThread : public QThread
//{
//public:
//    QWaitCondition condition;
//    QMutex mutex;
//    bool dataReady = false;
//    void run();
////    {
////        mutex.lock();  // 加锁

////        while (!dataReady) {
////            qDebug() << "Consumer Thread is waiting...";
////            condition.wait(&mutex);  // 等待条件满足
////        }

////        qDebug() << "Consumer Thread received data";
////        dataReady = false;

////        mutex.unlock();  // 解锁
////    }
//};
//#endif // MYTHREAD_H
