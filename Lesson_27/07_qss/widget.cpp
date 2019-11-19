#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->resize(160,160);
    ui->pushButton->resize(100,100);
    //这个文件用于添加style sheet
    QFile file("E:/QTcode/Lesson_27/07_qss/resource/test.qss");
    if(file.open(QFile::ReadOnly))
    {
        this->setStyleSheet(file.readAll());
        file.close();
        qDebug()<<"Open success";
    }
    else
        qDebug()<<"Open failed";
}

Widget::~Widget()
{
    delete ui;
}
