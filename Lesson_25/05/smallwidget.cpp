#include "smallwidget.h"
#include<QSpinBox>//数值框
#include<QSlider>//滑块
#include<QHBoxLayout>//水平布局

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    //设置数值框
    QSpinBox *spin = new QSpinBox(this);
    //滑条
    QSlider *slider = new QSlider(Qt::Horizontal,this);
    //添加水平布局
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    //给水平布局加入元素
    hLayout->addWidget(spin);
    hLayout->addWidget(slider);

    connect(spin,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider,&QSlider::setValue);

    connect(slider,&QSlider::valueChanged,spin,&QSpinBox::setValue);
}

