#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
signals:

public slots:

private:
    bool flag_widget = false ;//判断鼠标是否在widget内
    bool flag_end = false; //判断是否点击完成
};

#endif // MYWIDGET_H
