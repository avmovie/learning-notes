# 线程

1. 为什么使用线程?

> 进行非常复杂的数据处理,耗时较长,将这样的任务放在线程中执行

2. 线程的使用方法

> 1. 自定义一个类,继承于QThread
>
>    ```c++
>    class MyThread:public QThread 
>    {
>    	public:
>    	//run()函数是一个虚函数
>    	void run();	//才是线程处理函数(和主线程不在一个线程) 
>    	signals:
>    	void isDone();	//线程结束的信号
>    }
>    
>    ........
>        
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
> 3. 创建线程对象,不能指定父对象
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

 