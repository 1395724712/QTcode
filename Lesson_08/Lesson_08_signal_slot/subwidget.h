#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include<QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = 0);

    void sendSlot();

signals:
    //信号必须在signals关键字下声明
    //信号没有返回值，但可以有参数
    //信号就是函数的声明，只需声明，无需定义
    //使用： emit mysignal();
    //信号可以重载
    void mySignal(int, QString);
    void mySignal();

public slots:

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
