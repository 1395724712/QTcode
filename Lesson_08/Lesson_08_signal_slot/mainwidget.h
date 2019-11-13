#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPushButton>
#include"subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    //这是我自己定义的槽函数，在cpp中进行定义
    void myslot();
    void myslot_1();
    void myslot_2();

    //用于处理子窗口反馈信号的函数
    void dealSub();

    //重载信号的槽函数
    void dealSub_2(int, QString);

private:
    //在这里定义按钮，然后到mainwidget.cpp里去设置
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    SubWidget w;
};

#endif // MAINWIDGET_H
