#include "mywidget.h"
#include<QPushButton>
#include "mybutton.h"
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //移动当前窗口
    //原点：父窗口左上角
    //x:右为正方向
    //y:下为正方向
    move(0,0);
    resize(200,300);
    b.setParent(this);
    b.resize(50,70);

    MyButton *b3=new MyButton(this);
    b3->setText("yes");
}

MyWidget::~MyWidget()
{

}
