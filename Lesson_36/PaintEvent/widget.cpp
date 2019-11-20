#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    x=0;
    this->resize(700,600);
}

Widget::~Widget()
{
    delete ui;
}


//在这里对绘图函数进行重写
void Widget::paintEvent(QPaintEvent *)
{
    //因为参数用不到，所以这里不进行定义
    QPainter p(this);
    //p为绘图对象，this为QDeviceEvent类型的绘图设备，或者说是当前窗口

    //进行背景图的绘制
    p.drawPixmap(0,0,width(),height(),
                 QPixmap("E:/QTcode/Lesson_36/04_Image/OnePiece.png"));

    p.drawLine(50,50,100,100);

    p.drawPixmap(x,300,77,77,QPixmap("../04_Image/sunny.png"));

}

void Widget::on_pushButton_pressed()
{
    x += 10;
    //刷新，间接调用paintevent
    update();
}
