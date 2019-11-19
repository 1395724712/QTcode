#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *);

    //定时器事件
    void timerEvent(QTimerEvent *e);

    //重写广阔关闭实践
    void closeEvent(QCloseEvent *);

    //通过event函数对一些事件进行修改
    bool event(QEvent *);

private:
    Ui::MyWidget *ui;
    int timerId;
};

#endif // MYWIDGET_H
