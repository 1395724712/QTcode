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
    void dealFigure();

    void result_clear();

    void result_del();
protected:
    void timerEvent(QTimerEvent *);

private slots:
    void on_Button_Begin_released();

    void on_Button_Close_released();

private:
    Ui::Widget *ui;
    int GameTime;
    int num;
    int GameTimeID;
    int LostTimeID;
    int WinTImeID;
    QString resultfig;

};

#endif // WIDGET_H
