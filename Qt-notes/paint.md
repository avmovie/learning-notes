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
> `QImage`:和平台无关;修改图片(像素点);在线程中进行绘图
>
> `QPicture`:保存绘图的状态(二进制文件)

```c++
1. QPixmap 绘图设备
	1.1 painter.cpp
#include <QPainter>
#include <QBrush>
.........
    QPixmap pixmap(400,300);
	QPainter p(&pixmap);						//指定绘图设备
	p.fillRect(0,0,400,300,QBrush(Qt::white));	//通过画家进行填充
	pixmap.fill(Qt::white);						//通过绘图设备进行填充
	p.drawPixmap(0,0,80,80,QPixmap("../Image/face.png"));	
	pixmap.save("../Image/pixmap.png");			//必须是由绘图设备保存图片
2. QImage 绘图设备 
	2.1 image.cpp
#include <QPainter>
	QImage image(400,300,QImage::Format_ARGB32);	//透明背景
	QPainter p;
	p.begin(&image);
	p.drawImage(0,0,QImage("../Image/face.png"));
		//操作像素点
	for(int i;i<50;i++)
    {
        for(int j;j<50;j++)
        {
            image.setPixel(QPoint(i,j),qRgb(0,255,255));
        }
    }
	p.end();
	image.save("../Image.image.png");
3. QPicture 绘图设备
3.1 picture.h
protected:
	void paintEvent(QPaintEvent *ev);
3.2 picture.cpp
#include <QPainter>
#include <QPicture>
........
    QPicture picture;
	QPainter p;
	p.beging(&picture);
	p.drawPixmap(0,0,80,80,QPixmap("../Image/face.png"));
	p.drawLine(50,50,150,150);
	p.end();
	
	picture.save("../Image/picture.png");			//由绘图设备保存文件
													//发现保存的图片是二进制文件,打不开
	//在窗口设备中重新加载该二进制图片
	void Widget::paintEvent(QPaintEvent* ev)
    {
        QPicture pic;
        pic.load("../Image/picture.png");			//加载刚才保存的二进制图片
        QPainter p(this);
        p.drawPicture(0,0,pic);						//只有通过"drawPicture"函数才可以将之前的二进制图片显示出来
    }
```

tips:三者之间的用法基本相同,只有少数不同

5. QImage和QPixmap之间的相互转换

> QImage与平台无关,有利于图片的修改和传输
>
> QPixmap与平台相关,有利于图片的显示

```c++
1. widget.cpp
//QPixmap-->QImage
	QPainter p(this);
	QPixmap pixmap;
	pixmap.load("../Image/face.png");
	QImage tempImage = pixmap.toImage(pixmap);
	p.drawImage(0,0.tempImage);

//QImage-->QPixmap
	QImage image;
	image.load("../Image/face.png");
	QPixmap tempPixmap = QPixmap::fromImage(image);
	p.drawPixmap(100,0,tempPixmap);
```

6. 不规则窗口:

> 1. 给窗口画一张背景图
> 2. 去边框
> 3. 设定属性(背景透明)

```c++
1. shape.h
protected:
	void mousepressEvent(QMouseEvent *ev);
	void mouseMoveEvent(QMouseEvent *e);
private:
	QPoint p;
2. shape.cpp
#include <QPainter>
#include <QMouseEvent>
............
    setWindowFlags(Qt::FrameleassWindowHint | windowsFlags());	//设置边框隐藏
	setAttribute(Qt::WA_TranslucentBackground);					//设置背景透明
void Widget::mousePressEvent(QmouseEvent *ev)
{
    if(ev->button()==Qt::RightButton)
    {
        close();
    }
    else if(ev->button()==Qt::LeftButton)
    {
        //求出相对距离(全局坐标)-(窗口左上角坐标)
    	p=ev->globalPos()-this->frameGeometry().topleft();
    }
}
    void Widget::mouseMoveEvent(QMouseEvent *e)
    {
        if(e->buttons()&Qt::LeftButton)
        {
            move(e->globalPos()-p);
        }
    }
```