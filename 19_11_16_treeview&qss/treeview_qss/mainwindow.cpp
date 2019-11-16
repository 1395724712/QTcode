#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItem>
#include<QStandardItemModel>
#include<QStringList>
#include<QFile>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFile file("E:/QTcode/19_11_16_treeview&qss/treeview_qss/Qss/treeview.qss");
    if(file.open(QFile::ReadOnly))
    {
        qApp->setStyleSheet(file.readAll());
        file.close();
        qDebug()<<"Open success";
    }
    else
        qDebug()<<"Open failed";

    ui->setupUi(this);
    this->resize(500,700);


    QStandardItemModel *model = new QStandardItemModel(ui->treeView);
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("id")<<QStringLiteral("name"));

    for(int i =0;i<5;i++)
    {
        //这个循环是用来创建一级节点的
        QList<QStandardItem*> items1;
        QStandardItem *item1 = new QStandardItem(QString::number(i));
        QStandardItem *item2 = new QStandardItem(QStringLiteral("The top point"));
        items1.append(item1);
        items1.append(item2);

        model->appendRow(items1);

        for(int j =0;j<5;j++)
        {
            //这个循环用于创建二级节点
            QList<QStandardItem*> items2;
            QStandardItem* item2_1 = new QStandardItem(QString::number((j)));
            QStandardItem* item2_2 = new QStandardItem(QStringLiteral("The second point"));
            items2.append(item2_1);
            items2.append(item2_2);
            item1->appendRow(items2);
        }
    }

    //这里的思路似乎是先创建一个model，然后将该model加到treeview上
    ui->treeView->setModel(model);
    ui->treeView->resize(300,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}
