#ifndef WIDGET_H
#define WIDGET_H
#include "richtexteditor.h"

#include <QWidget>

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
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    RichTextEditor *rte;
};

#endif // WIDGET_H
