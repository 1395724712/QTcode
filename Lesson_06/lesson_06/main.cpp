#include<QApplication>
#include<QWidget>//窗口控件基类
#include<QPushButton>//按钮所需控件
int main(int argc, char **argv)
{
    QApplication app(argc,argv);

    //创建一个窗口对象，并让其显示
    QWidget w;
    w.setWindowTitle("My first QT-window.");

    //给按钮设置内容
    QPushButton b;
    b.setText("确定");
    b.setParent(&w);
    b.move(100,100);//移动坐标


    //方法2：
    QPushButton b2(&w);
    b2.setText("取消");
    b2.move(200,100);
    //若不指定父对象，对象与对象（窗口）是没有关系、独立的
    //若b指定w为其父对象，则意味着b放在w中
    //两种指定父对象的方法：1）setParent 2)通过构造函数传参
    //指定了父对象后，只要父对象显示，其上所有对象自动显示

    w.show();

    app.exec();
    return 0;
}
