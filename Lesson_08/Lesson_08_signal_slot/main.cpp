#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget W;//执行到MainWidget的构造函数
    W.show();

    return a.exec();
}
