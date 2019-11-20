#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include"mainwindow.h"
//尝试友元函数
//extern class MainWindow;

struct Lines
{
    float start_x,start_y;
    float end_x,end_y;
};

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
signals:

public slots:

private:
    MainWindow *ptr;
    bool flag_widget = false ;//判断鼠标是否在widget内
    bool flag_end = false; //判断是否点击完成
    bool flag_paint = false;//当前是否可以进行绘制
    struct Lines mylines[100];//最多画100条
    int num = 0;//记录当前是那一条
    int account = 0;//总数
    float start_x, start_y;
    float end_x, end_y;
};

#endif // MYWIDGET_H
