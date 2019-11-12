//信号和槽的学习
#include "mainwidget.h"
#include<QPushButton>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Boss");
    //窗口大小
    resize(400,300);
    b1.setParent(this);
    b1.setText("确定");
    b1.move(100,100);

    //注意，指针得先分配空间
    b2=new QPushButton(this);
    b2->setText("取消");
    b2->move(200,100);

    //窗口切换按钮
    b3.setParent(this);
    b3.setText("切换窗口");
    b3.move(125,50);

    //实现按下确定时窗口关闭功能
    //connect:信号从哪里来，什么动作（信号），那个窗口响应，信号处理函数（槽函数）

    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
//    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);

    //自定义槽：普通函数的用法：任意成员函数（头文件里的成员函数）
    //槽函数需要和信号一致（参数，返回值）
    //信号没有返回值，故槽函数也没有

    connect(b2,&QPushButton::pressed,&b1,&QPushButton::hide);
    connect(b2,&QPushButton::released,this,&MainWidget::myslot);

    //当前窗口隐藏，另一个窗口出现
    connect(&b3,&QPushButton::released,this,&MainWidget::myslot_2);

//    w.show();

//    SubWidget h;
//    h.show();

    //隐藏自身，显示另一个
    //    connect(&b3,&QPushButton::released,this,&MainWidget::myslot_2);

    //处理子窗口的信号
    connect(&w,&SubWidget::mySignal,this,&MainWidget::dealSub);
}

void MainWidget::myslot()
{
    //改变按钮的内容
    b2->setText("改变内容");
}

void MainWidget::myslot_2()
{
    //隐藏当前窗口
    w.show();
    //打开子窗口
    this->hide();
}

void MainWidget::myslot_1()
{
    b1.setText("close");
}

void MainWidget::dealSub()
{
    //显示当前窗口
    this->show();
    //隐藏子窗口
    w.hide();
}

MainWidget::~MainWidget()
{

}
