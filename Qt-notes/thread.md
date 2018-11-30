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
           thread->start();		//启动线程
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

   > 1. 设定一个类,继承于QObject
   > 2. 类中设置一个线程函数(只有一个)

   ```c++
   
   ```


> 1. 自定义一个类,继承于QThread
>
>    ```c++
>    class MyThread:public QThread 
>    {
>    	public:
>    		//run()函数是一个虚函数
>    		void run();			//线程处理函数(和主线程不在一个线程) 
>    	signals:
>    		void isDone();		//线程结束的信号
>    }
>    ........   
>    void MyThread::run()
>    {
>        QThread::sleep(5);
>        emit isDone();
>    }
>    ```
>
> 2. 不能直接调用run()函数
>
> ```c++
> MyThread thread ;
> thread .start();	//相当于间接调用run()函数
> ```
>
> 3. 线程停止函数
>
> > 1. terminate ()			//动态分配空间的时候容易出错
> > 2. quit()                               //处理完之后停止

3. 线程的第二种用法

> 1. 设定一个类,继承于QObject
>
> 2. 类中设置一个线程函数(只有一个是线程函数)
>
> 3. 创建线程对象,(不能指定父对象)
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
>
>
>    ```c++
>    class MyThread:public QObject
>    {
>    void myTimer()
>    {
>    	while(1)
>        {
>        	emit MySignal();
>        	
>        }
>    }
>    }
>    ```
>
> 6. 创建线程对象,不能指定父对象
>
> ```c++
> Mythrea *MyT;
> MyT = new MyThread;
> //创建子线程对象
> QThread *thread = new QThread(this);
> ```
>
> > (1)启动子线程,只是把线程开启了,并没有启动线程处理函数
> >
> > ```c++
> > thread.start();
> > ```
> >
> > (2)线程函数的启动必须通过`signal`和`slot`的方式来启动
> >
> > ```c++
> > connect(this,&startThread,myT,&mytimer)
> > ```
> >

3. 在线程中绘图

> ```c++
> class Mythread:public QObject
> {
> public:
> 	void drawImage()
>     {
>     	QImage imamge(600,600,)
>     	Qpaint p(&image);
>     	QPoint a;
>     	p.drawxxx();
>     }
>     signals:
>     void updateImage(QImage);
> }
> ```
>
>

 