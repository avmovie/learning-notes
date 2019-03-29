#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

class MyButton : public QPushButton
{
    QPushButton *b;
public:
    MyButton(QWidget *parent=0);
    ~MyButton();
};

#endif // MYBUTTON_H
