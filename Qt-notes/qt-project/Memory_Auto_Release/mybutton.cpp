#include "mybutton.h"

MyButton::MyButton(QWidget* parent):QPushButton (parent)
{
    b = new QPushButton(this);
    b->setText("hello world");
}

MyButton::~MyButton()
{
    qDebug()<<"the destructor of MyButton was called";
}
