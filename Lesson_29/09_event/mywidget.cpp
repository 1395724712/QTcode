#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDebug>
#include<QKeyEvent>
#include<QMessageBox>
#include<QEvent>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //启动计时器
   timerId=this->startTimer(1000);
//    this->killTimer();

    ui->label->resize(200,200);

    //加入按键时间
    connect(ui->pushButton,&MyButton::pressed,this,&MyWidget::close);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *k)
{
    qDebug()<<(char)k->key();

}

void MyWidget::timerEvent(QTimerEvent *e)
{
    static int sec = 0;
    sec++;
    ui->label->setText(
                QString("<center>Time is %1</center>").arg(sec));
    if(sec==5)
    {
        this->killTimer(this->timerId);
    }
}


//关于关闭窗口信号的接收与忽略
void MyWidget::closeEvent(QCloseEvent *e)
{
    int res = QMessageBox::question(this,"Question","close the window?");
    if(res==QMessageBox::Yes)
    {//用户确定要关闭窗口,就接收这个信号让他继续传递到this的父窗口（他自身）
        e->accept();
    }
    else if(res==QMessageBox::No)
    {//用户不想关闭这个窗口那就忽略这个信号不让他继续传递
        e->ignore();
    }
}


bool MyWidget::event(QEvent *e)
{
    //让widget只响应W按键
    if(e->type()==QEvent::KeyPress)
    {
        //进行类型转换将QEvent转换成QKeyEvent
        QKeyEvent *env =static_cast<QKeyEvent *>(e);

        if(env->key()==Qt::Key_W)
        {
            return QWidget::event(e);
        }
        else
        {
            //如果不是w就不继续传递了
            return true;
        }
    }
    else
    {
        //如果这个不是按键事件，则忽略
        return QWidget::event(e);
    }
}
