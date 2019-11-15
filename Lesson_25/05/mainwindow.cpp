#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QCompleter>
#include<QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //将2号输入框设成密码的形式
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    //给一号输入框加入提示
    QStringList s;
    s<<"wendell"<<"wanghan";

    QCompleter *com=new QCompleter(s,this);

    //将行编辑设置上提示
    ui->lineEdit->setCompleter(com);

    connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::close);

    //通过滑动的距离给微调框复制


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
