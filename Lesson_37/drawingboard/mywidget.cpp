#include "mywidget.h"
#include<QEvent>
#include<QDebug>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    this->setMouseTracking(true);

}

void MyWidget::enterEvent(QEvent *)
{
    qDebug()<<"may be useful";
    flag_widget = true;
}

void MyWidget::leaveEvent(QEvent *)
{
    qDebug()<<"it leave the widget";
    flag_widget = false;
}
