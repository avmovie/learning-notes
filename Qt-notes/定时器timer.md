# 定时器的相关使用

1. 定时器事件

```c++
1. 头文件
private:
	int timerId;
	int timerid;
protected:
	void timerEvent(QTimerEvent *ev);
2. 源文件
#include <QTimerEvent>
......
    timerId=this->timerStart(1000);			//以毫秒为单位每隔一秒启动一次
	timerid=this->timerStart(500);			//每隔500毫秒启动一次
........
    void MyWidget::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId()=this->timerId)
    {
        static int sec=0;
        QString str = QString("<center>timer out: %1</center>").arg(++sec);
        this->label->setText(str);
        if(5==sec)
        {
            this->killTimer(timerId);
        }
    }
    else if (ev->timerid()=this->timerid)
    {
        static int sec =0 ;
        QString str = QString("<center>time out:%1</center>").arg(++sed);
        this ->label->setText(str);
        if(15==sed)
        {
            this->killTimer(this->timerid);
        }
    }
}
```

