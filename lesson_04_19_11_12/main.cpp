 #include "mywidget.h"

//QApplication是应用程序类
//Qt的头文件以Q开头，头两个字母大写，不以.h结尾
//头文件名与类名一致
#include <QApplication>

int main(int argc, char *argv[])
{
    //无论创建多少个窗口，应用程序类的对象有且只有一个
    QApplication a(argc, argv);

    //MyWidge继承于QWidget,后者是一个窗口基类
    //所以前者也是窗口类，w就是一个窗口
    MyWidget w;

    //窗口默认是隐藏的，需要show
    w.show();

    //a.exec()是让程序一直执行让窗口一直存在，等待用户操作
    return a.exec();
}
