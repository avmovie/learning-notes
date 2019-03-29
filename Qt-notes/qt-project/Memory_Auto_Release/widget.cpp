#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new MyButton(this);
}

Widget::~Widget()
{

}
