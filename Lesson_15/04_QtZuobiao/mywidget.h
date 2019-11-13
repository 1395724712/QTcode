#ifndef MYWIDGET_H
#define MYWIDGET_H
#include<QPushButton>
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
private:
    QPushButton b;
};

#endif // MYWIDGET_H
