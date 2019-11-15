#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QCompleter>
#include<QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //这行代码就是UI设计中所进行的内容
    ui->setupUi(this);
    ui->button->setText("change_close");

    //行编辑QLineEdit
    QString str=ui->lineEdit->text();//获取内容
//    ui->lineEdit->resize(20,20);
    qDebug()<<str;

    //设置字符显示方式，令其隐藏
    ui->lineEdit->setEchoMode(QLineEdit::Normal);

    //有提示的方式
    QStringList list;
    list<<"Hello "<<"How Are You "<<"Wendell";

    QCompleter *com=new QCompleter(list, this);

    //若不区分大小写
    com->setCaseSensitivity(Qt::CaseInsensitive);

    //给行编辑设置上
    ui->lineEdit->setCompleter(com);

    //QLabel的设置
    //文字
    ui->text->setText("^_^");
    ui->picture->setPixmap(QPixmap(":/9.pgm"));
//    ui->picture->setScaledContents(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_1_released()
{
    static int i=0;

    ui->stackedWidget->setCurrentIndex(++i%3);
}
