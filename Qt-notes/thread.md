# 线程

1. 为什么使用线程?

> 进行非常复杂的数据处理,耗时较长,将这样的任务放在线程中执行

2. 线程的使用方法

   1. Qt4中的用法

   ```c++
   1.1 MyWidget.h
   	#include <QWidget>
   	#include <QTimer>
   	#include "MyThread.h"
   	.......
      	public :
   		void dealTimer();
   		void dealDone();
   		void stopThread();
   	protected:
   		void run();	//虚函数,线程处理函数(和主线程不在一个线程)
   	private slots:
   		void on_pushButton_clicked();
   	private:	
   		QTimer *myTimer;
   		MyThread *thread;
   1.2 MyWidget.cpp
   	#include <QDebug>
   	.....
       myTimer = new QTimer(this);
   	connect(myTimer,&QTimer::timeout,this,&MyWidget::dealTimer);
   	thread = new MyThread(this);
   	connect(thread,&MyThread::isDone,this,&MyWidget::dealDone);
   	connect(this,&MyWdiget::destroyed,this,&MyWidget::stopThread);
   	void MyWidget::dealTimer()
       {
           static int i=0;
           i++;
           ui->lcdNumber->display(i);
       }
   
   	void MyWidget::dealDone()
       {
           myTimer->stop();
           qDebug()<<"it is over";
       }
   	
   	void MyWidget::on_pushButton_clicked()
       {
           if(false == myTimer->isActive())
           {
               myTimer->start(100);
           }
           thread->start();			//启动线程,间接调用run()函数
       }
   	
   	void MyWidget::stopThread()
       {
           thread->quit();		
           	1. terminate();			//直接终止线程,不考虑线程任务是否完成,不常用
              	2. quit();				//考虑线程中的任务的完成情况,推荐使用
           thread->wait();
       }
   1.3	MyThread.h
   	#include <QThread>
   	..........
       protected:
   	void run();
   	signals:
   	void isDone();
   1.4	MyThread.cpp
   	void MyThread::run()
   {
       sleep(5);
       emit isDone();
   }
   ```

   2. Qt5中的使用方法


> 1. 自定义一个线程相关的类,继承于QObject
>
> 2. 类中设置一个线程函数(只有一个线程函数)
>
> 3. 创建线程对象(不能指定父对象)
>
> 4. 创建QThread子线程对象
>
> 5. 将自定义线程类,加入到子线程
>
>    > (1) 启动子线程,只是把线程开启了,并没有启动线程处理函数
>    >
>    > ```c++
>    > thread.start();
>    > ```
>    >
>    > (2)   线程函数的启动必须通过`signal`和`slot`的方式来启动
>    >
>    > ```c++
>    > connect(this,&startThread,myT,&mytimer)
>    > ```
>
> 6. connect()函数第五个参数的作用:默认,队列,直接.
>
>    默认时候,如果是多线程,用队列
>
>    如果是单线程,默认使用直接方式
>
>    队列方式:槽函数所在线程与接受者一致
>
>    直接方式: 槽函数所在线程和发送者一致


```c++
1. MyWdiget.h
#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
#include "mythread.h"
#include <QThread>
namespace Ui {
class MyWidget;
}
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void dealSignal();
    void dealDestroy();
signals:
    void startThread(); //启动子线程的信号
private slots:
    void on_btnStart_clicked();
    void on_btnStop_clicked();
private:
    Ui::MyWidget *ui;
    MyThread *myT;
    QThread *thread;
};
#endif // MYWIDGET_H
2. MyThread.h
#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QObject>
class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    //线程处理函数
    void Mytimerout();
    void setFlag(bool flag=true);
signals:
    void mySignal();
public slots:
private:
    bool isStop;
};
#endif // MYTHREAD_H
3. MyWidget.cpp
#include "mywidget.h"
#include "ui_mywidget.h"
#include <QThread>
#include <QDebug>
#include <QMessageBox>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //动态分配空间,不能指定父对象
    myT=new MyThread;
    thread = new QThread(this);
    //将自定义的线程添加到子线程中
    myT->moveToThread(thread);
    connect(myT,&MyThread::mySignal,this,&MyWidget::dealSignal);
    qDebug()<<"主线程号:"<<QThread::currentThread();
    connect(this,&MyWidget::startThread,myT,&MyThread::Mytimerout);
    connect(this,&MyWidget::destroyed,this,&MyWidget::dealDestroy);
}
MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_btnStart_clicked()
{
    if(thread->isRunning()==true)
    {
        return ;
    }
    //启动线程,但是没有启动线程处理函数
    thread->start();
    myT->setFlag(false);
    //如果不能直接调用线程处理函数
    //直接调用,导致线程处理函数和主线程是在同一个线程
    //myT->Mytimerout();
    //只能通过signal-slot的方式来进行调用
    emit  startThread();
}

void MyWidget::dealSignal()
{
    static int i=0;
    i++;
    ui->lcdNumber->display(i);
}

void MyWidget::on_btnStop_clicked()
{
    if(thread->isRunning()==false)
    {
        return;
    }
    myT->setFlag(true);
    thread->quit();
    thread->wait();
}

void MyWidget::dealDestroy()
{
    on_btnStop_clicked();
    delete myT;
}
//线程处理函数内补不允许操作图形界面

4. MyThread.cpp
#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop=false;
}

void MyThread::Mytimerout()
{
    while(isStop==false)
    {
        QThread::sleep(1);
        emit mySignal();
        qDebug()<<"子线程号:"<<QThread::currentThread();
        if(isStop==true)
        {
            break;
        }
    }
}

void MyThread::setFlag(bool flag)
{
    isStop=flag;
}


```



3. 在线程中绘图

>