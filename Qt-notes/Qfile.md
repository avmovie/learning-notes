# 文件操作

1. 文件系统![filesystem](./image/01_文件系统.png)



2.  QFile读文件

```c++
#include <QFile>
#include <QFileDialog>
..........
    void Widget::on_pushButtonRead_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"打开文件","../","all(*.*)");
    if(path.isEmpty()==false)
    {
        QFile file(path);
        bool isOk=file.open(QIODevice::ReadOnly);		//以只读模式打开文件
        if (isOk==true)
        {
            //读文件
            1. 一次性读完
                //默认只识别utf8编码
            QByteArray array=file.readAll();
            ui->textEdit->setText(QString(array));
            //ui->textEdit->setText(array);
            2. 一行一行来读
                QByteArray array;
            while (file.atEnd==false)
            {
                //读一行
                array += file.readLine();
            }
            ui->textEdit->setText(array);
        }
        //关闭文件
        file.close();
        QByteArray 
    }
}
```

3. QFile 写文件

```c++
void Widget::on_pushButtonWrite_clicked()
{
    QString path=QFileDialog::getSaveFileName(this,"保存文件","../","text(*.txt)");
    if(pat.isEmpty==false)
    {
        QFile file;
        //关联文件名字
        file.setFileName(path);		//QFile file(path);
        //打开文件,只写方式
      	bool isOK=file.open(QIODevice::WriteOnly);
        if(isOK==true)
        {
            QString str=ui->textEdit->toPalinText();	//获取编辑区的内容
            //写文件
            file.write(str->toUtf8());					//QString-->QByteArray
            //文件编码格式的转换
            1. 	QString-->string->char*
            	str.toStdString().data();
            2. 	QString-->QByteArray
                2.1		str.toUtf8();		//针对中文
            	2.2 	str.toLocal8Bit();	//本地编码
            3. 	QByteArray-->char*
                QByteArray a;
                char *b = a.data();
            4. 	char * -->QString 
               	char * p = "abc";
            	QString c =QString (p);
        }
        file.close();
    }
}
```

