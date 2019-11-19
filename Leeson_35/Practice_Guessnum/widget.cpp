#include "widget.h"
#include "ui_widget.h"
#include <QtGlobal>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include <QTimerEvent>
#include <QMovie>
#include <QPushButton>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置开始界面
    ui->stackedWidget->setCurrentWidget(ui->page);

    ui->label->setText("<center><h1>GUESS_FIGUER</h1></center>");

    ui->label_title->setText("<center><h1>PLEASE INPUT</h1></center>");

    //设置失败界面的内容
    QMovie *lostgif = new QMovie();
    lostgif->setFileName("E:/QTcode/Leeson_35/Practice_Guessnum/chatQQ.gif");
    ui->label_Lost->setMovie(lostgif);
    ui->label_Lost->setScaledContents(true);
    lostgif->start();

    //设置成功界面的内容
    QMovie *wingif = new QMovie();
    wingif->setFileName("E:/QTcode/Leeson_35/Practice_Guessnum/boy.gif");
    ui->label_Win->setMovie(wingif);
    ui->label_Win->setScaledContents(true);
    wingif->start();

    connect(ui->pushButton_0,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_3,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_4,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_5,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_6,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_7,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_8,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_9,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_10,&QPushButton::released,this,&Widget::dealFigure);
    connect(ui->pushButton_11,&QPushButton::released,this,&Widget::dealFigure);

    connect(ui->pushButton_del,&QPushButton::released,this,&Widget::result_del);
    connect(ui->pushButton_enter,&QPushButton::released,this,&Widget::result_clear);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Button_Begin_released()
{
    //当点击游戏开始按键时
    //根据选项设置游戏时间
    GameTime = ui->comboBox->currentText().toInt();

    //根据游戏时间设置进度条
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(GameTime);
    ui->progressBar->setValue(GameTime);

    //设置当前页面
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    //获得随机数

    //设置随机种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //需要一个四位随机数
    num = qrand()%10000;
    while(num<999)
        num=qrand()%10000;
    qDebug()<<num;


    //同时启动定时器
    GameTimeID = startTimer(1000);

    //原先结果清空
    resultfig.clear();
}

void Widget::on_Button_Close_released()
{
    //通过问题框询问用户是否要关闭窗口
    int res = QMessageBox::question(this,"Warning","Do you want to exit the game?");

    if(res == QMessageBox::Yes)
        this->close();
}


void Widget::timerEvent(QTimerEvent *e)
{
    //设置时钟时间
    if(e->timerId()==GameTimeID)
    {
        //如果是游戏运行时间则要调整进度条以及判断进入结束界面
        GameTime -=1;
        ui->progressBar->setValue(GameTime);

        //如果时间用完则要进入失败界面
        if(GameTime == 0)
        {
            //关闭定时器，避免重复报错
            killTimer(GameTimeID);

            QMessageBox::information(this,"LOST","youlost");
            ui->stackedWidget->setCurrentWidget(ui->page_3);
            LostTimeID = startTimer(3000);
        }



    }
    if(e->timerId()==LostTimeID)
    {
       //如果是失败时间，此时应询问玩家继续游戏还是退出
        int res = QMessageBox::question(this,"QUESTION","reload or exit");

        if(res == QMessageBox::Yes)
            ui->stackedWidget->setCurrentWidget(ui->page);
        else
            this->close();
        killTimer(LostTimeID);
        qDebug()<<LostTimeID<<endl;
    }
    else if(e->timerId()==WinTImeID)
    {
        //如果成功
        int res = QMessageBox::question(this,"QUESTION","reload or exit");

        if(res == QMessageBox::Yes)
            ui->stackedWidget->setCurrentWidget(ui->page);
        else
            this->close();
        killTimer(WinTImeID);
    }
}

void Widget::dealFigure()
{

    //输入前清空之前存在的内容
    if(resultfig.size()>4)
        resultfig.clear();

    //获取信号发送者
   QObject *mysender = sender();
   QPushButton *p=(QPushButton *)mysender;

   resultfig += p->text();

   //不得以0开头
   if((resultfig.size() == 1)&&resultfig == "0")
       resultfig.clear();
   else if(resultfig.size()==4)
   {
       //转换成数字
       int curnum = resultfig.toInt();
       qDebug()<<curnum;

       if(curnum<num)
       {
           resultfig += " is too small";
       }
       else if(curnum>num)
       {
           resultfig +=" is too large";
       }
       else
           {
           resultfig +=" is right";
           ui->label_title->setText("<center><h1>"+resultfig+"</h1></center>");
           QMessageBox::information(this,"WIN","you get it");
           ui->stackedWidget->setCurrentWidget(ui->page_4);
           WinTImeID = startTimer(3000);
       }

   }
   ui->label_title->setText("<center><h1>"+resultfig+"</h1></center>");
}

void Widget::result_clear()
{
    resultfig.clear();
    ui->label_title->setText("<center><h1>"+resultfig+"</h1></center>");
}

void Widget::result_del()
{
    resultfig.chop(1);
    ui->label_title->setText("<center><h1>"+resultfig+"</h1></center>");
}
