#include "mybutton.h"
#include<QPushButton>
#include<QMouseEvent>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
//    connect()
}

void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        //如果是左键点击就继续传递
//        e->accept();
        //注意不能用这种方法，因为accept、ignore会将信号传递到其父节点
        //也就是说会有widget来处理，拿将失去意义

        //应当这样处理
        QPushButton::mousePressEvent(e);
    }
    else
    {//如果不是左键那就忽略
//        e->ignore();
    }
}
