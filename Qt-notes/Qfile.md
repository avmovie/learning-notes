# 文件操作

1. 文件系统![filesystem](./image/01_文件系统.png)



2.  QFile读文件

```c++
#include <QFile>
#include <QFileDialog>
..........
    void Widget::on_pushButtonRead_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"打卡文件","../","all(*.*)");
    if(path.isEmpty()==false)
    {
        QFile file(path);
        bool isOk=file.open(QIODevice::ReadOnly);		//以只读模式打开文件
        if (isOk==true)
        {
            QByteArray array=file.readAll();
            ui->textEdit->setText(QString(array));
            //ui->textEdit->setText(array);
        }
        QByteArray 
    }
}
```

