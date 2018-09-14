# 信号与槽

1. 信号，类似于普通函数，只需声明，无需实现

2. 槽函数，qt5中的任意成员函数，静态函数，全局函数，lambda表达式

3. 可以使用qt 内部定义好的，也可以自定义

4. 没有返回值，但是有参数

5. 信号和槽的参数列表顺序是一致的

6. 信号的参数数目可以大于槽函数的，反过来不行

   ```c++
   void mysignal();
   emit myslot();
   
   void mysgnal();
   void myslot();
   ```

   lamada函数，匿名槽函数

    ```c++
   void fun()
   {
       
   }
   [=]()mutable 
   {
       
   }
   
   // = or &
   值传递或者引用传递
   this 
       lamade表达式所在类的所有成员
       
    ```

   编辑框相关函数：

   ```c++
   text();											//获取编辑框内容
   setText(const QString &)						//设置编辑框内容
   ui->lineEdit->setTextMargins(15,0,0,0);			//设置显示间距
   ui->lineEdit->setEchoMode(QLineEdit::Password);	//设置显示方式
   
   //设置显示提示
   # include<Qcompleter>
   # include<QStringList>
   QString list;
   list<<"hello"<<"holy"<<"high";
   Qcompleter *com =new Qcompleter(list,this);
   com->setCaseSensitivity(Qt::CaseInsensitive);	//不区分大小写 	
   ui->lineEdit->setCompleter(com);
   ```

   文本编辑框相关内容：

   1. > text edit 		//可以显示文字以外的其他东西
      >
      > plain text edit 	//只能显示文字
      >
      >

   ```c++
   
   ```

   label控件的使用

   > 1. 显示文字
   >
   > ```c++
   > ui->labelText->setText("jianghuiwen");
   > ```
   >
   > 2. 显示图片
   >
   > ```c++
   > ui->labelImage->setPixmap(QPixmap("资源文件的路径"));
   > ui->labelImage->setScaledContents(true);		//让图片自动适应label的大小
   > 
   > ```
   >
   > 3. 显示gif动画
   >
   > ```c++
   > #include<QMovie>
   > ......
   > QMovie *mymovie = new QMovie("gif文件的路径");
   > ui->labelImage->setMovie(mymovie);
   > mymovie->start();
   > ui->labeLgif->setScaledContents()
   > ```
   >
   > 4. 显示网址(可以显示HTML格式的字符串)
   >
   > ```c++
   > QLabel *label = new QLabel(this);
   > ui->labelurl ->setText("jianghuiwen");
   > ui->labelurl ->setText("
   >                 <h1><a href=\"https://baidu.com\">百度一下</a></h1>;
   >                 ")
   > label->setOpenExternalLinks(true);  
   > ```

Qt布局管理器

1. 两种组建定位机制

   > 1. 绝对定位
   > 2. 布局定位
   >
   > (1) 水平布局
   >
   > (2) 垂直布局
   >
   > (3) 网格布局

2. 

