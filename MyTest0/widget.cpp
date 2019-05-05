#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "richtexteditor.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *vl = new QVBoxLayout(this);
    rte = new RichTextEditor(this,"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\"F:/qt_way/MyTest0/textedit/italic.png\" width=\"32\" height=\"32\" /></p></body></html>");
    vl->addWidget(rte);
    vl->addWidget(ui->pushButton);
    setLayout(vl);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qDebug() << rte->textedit->document()->toHtml();
}
