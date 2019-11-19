#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);

signals:

protected:
    //修改它的按键按下事件
    void mousePressEvent(QMouseEvent *e);


public slots:
};

#endif // MYBUTTON_H
