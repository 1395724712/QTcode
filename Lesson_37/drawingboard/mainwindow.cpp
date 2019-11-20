#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywidget.h"
#include <QDebug>
#include <QPalette>
#include <QMouseEvent>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<<this;
    qDebug()<<&r<<" "<<&g<<" "<<&b;

    //设置spinbox的最小值
    size = 1;
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(10);

    //RGB的最大值均为255，最小值为0，当前设为87，250，255（天蓝色）
    ui->verticalSlider->setMaximum(255);
    ui->verticalSlider_2->setMaximum(255);
    ui->verticalSlider_3->setMaximum(255);

    //设置最小值
    ui->verticalSlider->setMinimum(0);
    ui->verticalSlider_2->setMinimum(0);
    ui->verticalSlider_3->setMinimum(0);

    //设置当前值
    r = 87;
    g = 250;
    b = 255;
    MainWindow::labeltoslider(87,0);
    MainWindow::labeltoslider(250,1);
    MainWindow::labeltoslider(255,2);

    //设置实例栏的颜色
    QPalette pale = ui->label_4->palette();
//    pale.setColor(ui->label_4->backgroundRole(),QColor(87,250,255));实在不知道bei'j背景怎么改变颜色
    ui->label_4->setText(QString("<center><h1>COLOR</h1></center>"));
    pale.setColor(ui->label_4->foregroundRole(),QColor(87,250,255));
    ui->label_4->setPalette(pale);


    //如果Slider的内容改变
    //我不仅仅是希望信号传递给槽，我还希望穿过去之后要大写
    connect(ui->verticalSlider,&QSlider::valueChanged,
            [=]()
    {
        ui->label->setText(QString("<center>%1</center>").arg(ui->verticalSlider->value()));
        MainWindow::Colorchanged();
    });
    connect(ui->verticalSlider_2,&QSlider::valueChanged,
            [=]()
    {
        ui->label_2->setText(QString("<center>%1</center>").arg(ui->verticalSlider_2->value()));
        MainWindow::Colorchanged();
    });
    connect(ui->verticalSlider_3,&QSlider::valueChanged,
            [=]()
    {
        ui->label_3->setText(QString("<center>%1</center>").arg(ui->verticalSlider_3->value()));
        MainWindow::Colorchanged();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::labeltoslider(int x, int flag)
{
    switch (flag) {
    case 0:
        ui->verticalSlider->setValue(x);
        ui->label->setText(QString("<center>%1</center>").arg(x));
        break;
    case 1:
        ui->verticalSlider_2->setValue(x);
        ui->label_2->setText(QString("<center>%1</center>").arg(x));
        break;
    case 2:
        ui->verticalSlider_3->setValue(x);
        ui->label_3->setText(QString("<center>%1</center>").arg(x));
        break;
    default:
        qDebug()<<"Please check again , can not chose number bigger than 3";
        break;
    }

    return 0;
}

void MainWindow::Colorchanged()
{
    r = ui->verticalSlider->value();
    g = ui->verticalSlider_2->value();
    b = ui->verticalSlider_3->value();

//    qDebug()<<"r: "<<r<<" g "<<g<<" b "<<b;

    QPalette pale = ui->label_4->palette();
    pale.setColor(ui->label_4->foregroundRole(),QColor(r,g,b));
    ui->label_4->setPalette(pale);
}




void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    size = arg1.toInt();
//    qDebug()<<"Linewidth: "<<size;
}
