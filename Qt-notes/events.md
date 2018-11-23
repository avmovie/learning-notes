# 事件

1. 事件处理的过程

```flow
st=>start: 事件发生
op1=>operation: 创建事件对象
op2=>operation: 传递给QObject的event()函数
op3=>operation: envnt()按照事件对象的类型分配给特定的事件处理函数
ed=>end: 相应的事件处理函数
st->op1->op2->op3->ed
```

2. 事件的接受和忽略

> 事件接受后,不会继续向下传递该事件
>
> 事件忽略后,需要注意的是,需要继续向下传递该事件
>
> 向下传递该事件,不是传给其父类,而是传给其父组件
>
>  	`父组件`: 是其父类所在的父窗口

```c++
//事件的接受和忽略
	//头文件
	1. widget.h
protected:
	void mousePressEvent(QMouseEvent *event);
	void closeEvent(QMouseEvent *ev);
	2. mybutton.h
protected:
	void mousePressEvent(QMouseEvent *e);
	//源文件
	1. widget.cpp
#include <QCloseEvent>
#include <QMessageBox>
....
    connnect(ui->pushButton,&MyButton::clicked,
             [=]()
             {
                qDebug()<<"ui->pushbutton was pressed"; 
             });
	void MyWidget::mousePressEvent(QMouseEvent* event)
    {
        qDebug()<<"widget was pressed";
    }
	2. mybutton.cpp
	#include <QMouseEvent>
	#include <QPushButton>
	#include <QDebug>
	.........
       void Mybutton::mousePressEvent(QMouseEvent *e)
    {
        if(Qt::LeftButton==e->button())
        {
            qDebug()<<"MyButton was pressed";	//事件的接受,
        }
        else 
        {
            QPushButton::mousePressEvent(QMouseEvent e);
        }
    }
	/*
	事件的接受和忽略:
	QPushButton是MyButton的基类,现在面临的问题是,如果重写了MyButton的事件函数,而事件函数又都是"protected virtual"类型的,其父类即QPushButton是否会对此事件做出反应?
	在重写MyButton::mousePressEvent()的时候,满足条件,事件就会被接受,而不会继续传递;反之,不满足条件,则通过"QPushButton::mousePressEvent(QMouseEvent e)"将该事件继续传递到父类QPushButton中,因为我们无法得知父类QPushButton中是否还会有该事件所对应的事件函数.
	*/
```

3. 与之相关的两个函数:`accept()`,`ignore()`

> 如果一个事件处理函数调用了一个事件对象的`accept()`函数,那么该事件就不会继续传播给其父组件
>
> 如果调用了事件的`ignore()`函数,Qt会其父组件中寻找另外的接受者

4. event()函数

```c++
1. widget.h
protected :
bool event(QEvent* ev);
2. widget.cpp
# include <QEvent>
..........
    bool Widget::event(Qevent *ev)
{
   	1. 常见情况
        switch(ev->type)
        {
            case QEvent::mousePressEvent:
                mousePressEvent(ev);
                break;
            case QEvent::mouseMoveEvent:
                mouseMoveEvent(ev);
                break;
            default:
                break;
        }
    2. 其他应用(阻塞定时器)
        if (e->type()==QEvent::Timer)
        {
            //QTimerEvent *env = static_cast<QTimerEvent *> (ev);
            //timerEvent(env);
            return true;
            //如果传入的事件被识别二期已经被处理,则需要返回true,否则返回false.
            //如果返回的是true,那么Qt就会认为这个事件已经处理完毕,不会再讲这个事件发送给其他对象,而是会继续处理事件队列中的下一事件
            //在Event()函数中调用事件对象的accept()和ignore()函数是没有作用的，不会影响到事件的传播。
        }
    QKeyEvent *e = static_cast<QKeyEvent *> ev;
    else if (e->type()==QEvent::KeyPress)
    {
        if (env->key()==Key_B)
        {
            return QWidget::event(e);
        }
    	else 
        {
            return true;
        }
    }
    else
    {
       	return QWidget::event(e);
        //其他事件正常传递
    }
}
```

5. 事件过滤器