#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
protected:
    //这里是与鼠标按下、释放、移动相关的虚函数
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

    //进入窗口区域
    void enterEvent(QEvent *);
    //离开窗口区域
    void leaveEvent(QEvent *);


signals:

public slots:
};

#endif // MYLABEL_H
