#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    //这里重写绘图虚函数
    //这个函数可以自动调用，不需要像starttime,或者按键、鼠标那样需要用户调用
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_pressed();

private:
    Ui::Widget *ui;
    int x;
};

#endif // WIDGET_H
