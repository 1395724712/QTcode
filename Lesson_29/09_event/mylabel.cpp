#include "mylabel.h"
#include<QMouseEvent>
#include<QDebug>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //默认追踪鼠标
    this->setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();

    //
    QString text = QString("<center><h1>Mouse Press:(%1,%2)</h1></center>").arg(i).arg(j);

    this->setText(text);

    //判断是那个鼠标键被按下
    if(ev->button()==Qt::LeftButton)
    {
        qDebug()<<"It is left";
    }
    else if(ev->button()==Qt::RightButton)
    {
        qDebug()<<"It is right";
    }
    else if(ev->button()==Qt::MidButton)
    {
        qDebug()<<"It is mid";
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Release: (%1,%2)<h1></center>").arg(ev->x()).arg(ev->y());
    this->setText(text);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse move: (%1,%2)</h1></center>").arg(ev->x()).arg(ev->y());
    this->setText(text);
}

void MyLabel::enterEvent(QEvent *e)
{
    QString text = QString("<center><h1>Mouse Enter</h1></center>");
    this->setText(text);
    qDebug()<<"Mouse Enter";
}

void MyLabel::leaveEvent(QEvent *e)
{
    QString text = QString("<center><h1>Mouse Leave</h1></center>");
    this->setText(text);
}

