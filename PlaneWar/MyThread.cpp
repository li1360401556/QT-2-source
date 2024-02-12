//#include "MyThread.h"
//#include<QDebug>
////MyThread::MyThread():QThread()
////{

////}
////void MyThread::run()
////{
//////    this->TH_pause();

////}

////void MyThread::keyPressEvent(QKeyEvent *key_value)
////{

////switch(key_value->key())
////{
////case Qt::Key_Space:
////    pauseORstart=false;
////    this->m_mutex.unlock();
////    break;
////}
////}

////void MyThread::TH_pause()
////{
////    QKeyEvent*key_value;
//////while(pauseORstart)
//////    {
//////    this->m_mutex.lock();
//////      qDebug()<<"启动11";
//////    if(key_value->key()==Qt::Key_Space)
//////    {pauseORstart=false;
//////      qDebug()<<"启动10";
//////    }
////    this->m_mutex.lock();
////    if(key_value->key()==Qt::Key_Space)
////    this->m_mutex.unlock();
////    }
//////    while(pauseORstart)
//////        {
//////     this->m_mutex.lock();

//////      this->m_mutex.unlock();
//////        }
////////    this->thread()->sleep(10);
//////    this->m_mutex.unlock();
//////}

////void MyThread::TH_start()
////{
////if(!pauseORstart)
////    this->m_mutex.unlock();
////}
//void MyThread::run()
//{
//    mutex.lock();  // 加锁

//    while (!dataReady) {
//        qDebug() << "Consumer Thread is waiting...";
//        condition.wait(&mutex);  // 等待条件满足
//    }

//    qDebug() << "Consumer Thread received data";
//    dataReady = false;

//    mutex.unlock();  // 解锁
//}
