# 绘图

1. 背景图,画笔,画刷等工具的使用
2. 手动刷新,重绘

```c++
1. widget.h
protected :
	void paintEvent(QPaintEvent * ev);
	//如果在窗口绘图,必须放在绘图事件中完成
	//绘图事件内部自动调用,窗口需要改变的时候(窗口状态改变)
private :
	int x;
private slots:
	void on_PushButton_clicked();
2. widget.cpp
#include <QPainter>
#include <QPen>
#include <QBrush>
...................
    int x = 0 ;
void Widget::paintEvent(QPaintEvent *ev)
{	
    1.第一种用法
    //QPainter p(this);
    2. 第二种方法
   	QPainter p;
    p.begin(this);
    	//背景图
    p.drawPixmap(0,0,width(),height(),QPixmap("../Image/background.png"));
    p.drawPixmap(rect(),QPixmap("../Image/background.png"))
        //设定画笔的状态
  	QPen pen;
 	pen.setWidth(5);				//设置线宽
 	p.setPen(pen);					//设置画笔
 	p.setColor(Qt::black);			//设置指定颜色
 	p.setColor(QColor(50,50,50));	//设置RGB颜色
 		//画线
   	p.drawLine(50,50,100,50);
    	//画刷的使用
    		/*画刷可以填充闭合图形,但必须在其之前进行定义*/
    QBrush brush;
    brush.setColor(Qt::red);			
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    	//画矩形
    p.drawRect(0,0,50,50);
    p.drawRect(100,100,50);
    	//画圆
    p.drawEllipse(QPoint(50,50)10,20);
    	//画笑脸
    p.drawPixmap(x,200,80,80,QPixmap("../Image/face.png"));
    p.end();
}

void widget::on_PushButton_clicked()
{
    x += 20;
    if(x>width())
    {
        x = 0;
    }
    //刷新窗口,让窗口重绘
    update();	//间接调用paintEvent();
}
```

3. QBitmap(黑白)与QPixmap(彩色)

```c++
1. widget.h
#incldue <QWidget>
protected :
	void paintEvent(QPaintEvent *ev);
2. widget.cpp
#include <QPainter>
#include <QBitmap>
void Widget::paintEvent(QPaintEvent *ev)
{
	QPainter p(this);
    /*	这里有两只蝴蝶的图片,其中:
    	1.butterfly.png-->透明背景
    	2.butterfly1.png->白色背景
    */
	p.drawPixmap(0,0,QPixmap("../Image/buterfly.png"));
  	p.drawPixmap(200,0,QBitmap("../Image/butterfly.png"));			//背景变成黑色
    
    QPixmap pixmap;
    pixmap.load("../Image/butterfly1.png");
    p.drawPixmap(0,200,pixmap);
    
    QBitmap bitmap;
    bitmap.load("../Image/butterfly1.png");
    p.drawPixmap(200,200,bitmap);									//背景变成白色
}
```

> 图片背景透明
>
> > `QPixmap`					//显示出原图
> >
> > `Qbitmap`					//背景变成黑色
>
> 图片背景白色
>
> > `QPixmap`					//显示出原图
> >
> > `QBitmap`					//背景变成透明

4. 三种绘图设备

> `QPixmap`:最常用的,针对屏幕进行优化过,和平台相关
>
> `QImage`:和平台无关,可以对图片进行修改,(可以进行像素点的修改),可以在线程中进行绘图
>
> `QPicture`:保存绘图的状态(二进制文件)

tips:三者之间的用法基本相同

QImage和QPixmap之间的相互转换

不规则窗口:

> 1. 给窗口画一张背景图
> 2. 去边框
> 3. 设定属性(背景透明)
> 4. 移动坐标是相对于屏幕而言