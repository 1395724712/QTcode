#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

//#include "mywidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int r,g,b;
    int size;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //此函数应用于从根据输入的值设置slider滑块的位置
    //x为数值，flag为哪一个滑块0，1，2
    int labeltoslider(int x, int flag);

    //下列函数用于当Slider滑动时改变实例框的颜色
    void Colorchanged();
protected:
    //重写绘图事件
private slots:
    void on_spinBox_valueChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    bool flag_in = false;//当前鼠标是否在widget内

};

#endif // MAINWINDOW_H

