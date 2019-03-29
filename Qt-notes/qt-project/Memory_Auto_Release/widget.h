#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "mybutton.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    MyButton *button;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
