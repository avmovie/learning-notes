# 数据库

1. 数据库的相关操作

```c++
1. database.pro
QT += core gui sql 
2. widget.h
#include <QWidget>
.........
    private slots:
void onBtn_Delete_clicked();
void onBtn_Definite_clicked();
void onBtn_Cancel_clicked();
3. widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<QSqlDatabase::drivers();

    //连接数据库
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");            //主机名
    db.setUserName("root");                 //用户名
    db.setPassword("484936");               //登录密码
    db.setDatabaseName("info");             //数据库名称

    //打开数据库
    if (false ==db.open())
    {
        QMessageBox::warning(this,"错误","数据库打开失败",db.lastError().text());
        return ;
    }
    QSqlQuery query;
    query.exec("create table student(id int primary key auto_increment, name varchar(255), age int, score int);");
    query.exec("insert into student(id, name, age) values(1, 'mike', 18);");


    //如果使用多个数据库
    QSqlDatabase db1= QSqlDatabase::addDatabase("QMYSQL","a");
    db1.setHostName("127.0.0.1");
    db1.setUserName("root");
    db1.setPassword("484936");
    db1.setDatabaseName("test");
    QSqlQuery query1(db1);
    db1.open();
    query1.exec("create table student(id int primary key, name varchar(255), age int, score int);");
    query1.exec("drop table student;");


  	两种批量插入的方法:
    1.odbc风格
    //预处理语句,"?"相当于占位符
    query.prepare("insert into student(name,age,score) values(?,?,?);");
    //给字段设置内容 list
    QVariantList nameList;
    nameList<<"jianghuiwen"<<"jiangliwen"<<"jiangcheng";
    QVariantList ageList;
    ageList<<"22"<<"23"<<"12";
    QVariantList scoreList;
    scoreList<<"420"<<"320"<<"440";
    //给字段绑定相应的值,按照顺序绑定,否则会失败
    query.addBindValue(nameList);
    query.addBindValue(ageList);
    query.addBindValue(scoreList);
    //执行预处理命令
    query.execBatch();

    2. oracle风格
    //预处理语句,占位符发生了变化
    query.prepare("inser into student(name,age,score)values(:name,:age,:score);");
    QVariantList nameList;
    nameList<<"jianghuiwenn"<<"jiangliwenn"<<"jiangchengn";
    QVariantList ageList;
    ageList<<32<<23<<32;
    QVariantList scoreList;
    scoreList<<422<<322<<443;
    //给字段绑定
    query.bindValue(":name",nameList);
    query.bindValue(":age",ageList);
    query.bindValue(":score",scoreList);
    //以上绑定顺序不局限于固定的顺序
    //执行预处理命令
    query.execBatch();
*/

    //遍历数据库
    query.exec("select * from student");
    while (query.next())        //一行一行进行遍历
    {
        //取出当前行的内容(以列为单位)
        qDebug()<<query.value(0).toInt()
                <<query.value(1).toString()
                <<query.value(2).toInt()
                  //或者直接指定列名
                <<query.value("age").toInt()
                <<query.value("score").toInt();
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_delete_clicked()
{
    QString name =ui->lineEdit->text();
    QString str = QString("delete from student where name = '%1';").arg(name);
    //开启事务
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(str);
}

void Widget::on_btn_definite_clicked()
{
    //确定删除
    QSqlDatabase::database().commit();
}

void Widget::on_btn_cancel_clicked()
{
    //回滚,撤销删除
    QSqlDatabase::database().rollback();
}
```

1. model- -view 可视化数据库的相关操作

```c++
1. widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void on_btn_Add_clicked();
    void on_btn_Ok_clicked();
    void on_btn_Cancel_clicked();
    void on_btn_Del_clicked();
    void on_btn_Find_clicked();
private:
    Ui::Widget *ui;
    QSqlTableModel *model;
};

#endif // WIDGET_H
2. widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //连接数据库
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("484936");
    db.setDatabaseName("info");

    //打开数据库
    if (false ==db.open())
    {
        QMessageBox::warning(this,"错误","数据库打开失败",db.lastError().text());
        return ;
    }

    //设置模型
    model=new QSqlTableModel(this);
    model->setTable("student");         //指定使用的表格
    //把model放在view中
    ui->tableView->setModel(model);
    //显示model中的数据
    model->select();
    //设置列名字段
    model->setHeaderData(0,Qt::Horizontal,"学号");
    //设置model的编辑模式,手动提交
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //view只显示,不修改
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_Add_clicked()
{
    //添加空记录
    QSqlRecord record = model->record();
    int row = model->rowCount();
    model->insertRecord(row,record);
}

void Widget::on_btn_Ok_clicked()
{
    model->submitAll();     //提交所有修改
}

void Widget::on_btn_Cancel_clicked()
{
    model->revertAll();     //取消所有动作
    model->submitAll();     //提交之前的所有动作
}

void Widget::on_btn_Del_clicked()
{
    //获取选中的模型
    QItemSelectionModel *sModel=ui->tableView->selectionModel();
    //取出模型中的索引
    QModelIndexList list = sModel->selectedRows();
    //删除所有选中的行
    for (int i=0;i<list.size();i++)
    {
        model->removeRow(list.at(i).row());
    }
}

void Widget::on_btn_Find_clicked()
{
    QString name =ui->lineEdit->text();
    QString sql =QString("name='%1'").arg(name);
    model->setFilter(sql);      
    model->select();
}
```



 