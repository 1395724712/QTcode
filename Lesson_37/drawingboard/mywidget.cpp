#include "mywidget.h"
#include<QEvent>
#include<QDebug>
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    this->setMouseTracking(true);
    ptr = (MainWindow *)topLevelWidget();

    qDebug()<<ptr;

    qDebug()<<&ptr->r<<" "<<&ptr->g<<" "<<&ptr->b;
//    qDebug()<<"for son_widget: "<<ptr->r;
}

void MyWidget::mousePressEvent(QMouseEvent *env)
{
    qDebug()<<"1";
    if(flag_widget == true)
    {
       //当前在窗口内
        if(flag_end == false)
        {
            //当前是起点
//            start_x = env->x();
//            start_y = env->y();*/
            mylines[num].start_x = env ->x();
            mylines[num].start_y = env ->y();
            flag_end = true; //当前为终点
        }
        else
        {
//            end_x = env->x();
//            end_y = env->y();
            mylines[num].end_x =env->x();
            mylines[num].end_y = env->y();

            num += 1;


            flag_paint = true;
            flag_end = false;//下一个为起点
        }
    }

    update();
}

void MyWidget::enterEvent(QEvent *)
{
//    qDebug()<<"may be useful";
    flag_widget = true;
}

void MyWidget::leaveEvent(QEvent *)
{
//    qDebug()<<"it leave the widget";
    flag_widget = false;
}

void MyWidget::paintEvent(QPaintEvent *)
{
    qDebug()<<"2"<<endl;
    QPainter p(this);

    int r = ptr->r;
    int g = ptr->g;
    int b = ptr->b;

    int size = ptr->size;

    QPen mypen(QColor(r,g,b));
    mypen.setWidth(size);



    p.setPen(mypen);
    p.drawLine(0,0,100,100);

    if(flag_paint == true)
    {
        //可以进行绘制
        for(int i=0;i<100;i++)
        {
            p.drawLine(mylines[i].start_x,mylines[i].start_y,mylines[i].end_x,mylines[i].end_y);
        }
        flag_paint = false;
    }



//    p.drawLine(0,00,100,100);
}
