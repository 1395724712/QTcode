#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("SUB");
    resize(400,300);
    b.setParent(this);
    b.setText("切换到主窗口");

    connect(&b,&QPushButton::clicked,this,&SubWidget::sendSlot);
}

void  SubWidget::sendSlot()
{
    //发送信号
    emit mySignal();
    emit mySignal(100,"why");
}
