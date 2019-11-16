#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItem>
#include<QStandardItemModel>
#include<QFile>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //在这里设置样式表吗
    QFile file("E:/QTcode/19_11_15_tree&qss/tree_qss_test/resource/Qss/tree.qss");
    if(file.open(QFile::ReadOnly))
    {
        qApp->setStyleSheet(file.readAll());
        file.close();
        qDebug()<<"Open success";
    }
    else
        qDebug()<<"Open failed";

    //在下面设置QtreeWidget,希望我在下面使用的内容，我都能够掌握
    //这个是列数
    ui->treeWidget->setColumnCount(2);
    //这个是列表头
    ui->treeWidget->setHeaderLabels(QStringList()<<"first"<<"second");

    //列表项
    //根目录
    QTreeWidgetItem *rootItem_1= new QTreeWidgetItem(ui->treeWidget);
    //子目录
    //这样写不行： QTreeWidgetItem *childItem_1_1 = new QTreeWidgetItem(childItem_1_1);
    QTreeWidgetItem *childItem_1_1 = new QTreeWidgetItem();
    QTreeWidgetItem *childItem_1_2 = new QTreeWidgetItem();
    QTreeWidgetItem *childItem_1_2_1 = new QTreeWidgetItem();

    //第二列
    QTreeWidgetItem *rootItem_2 = new QTreeWidgetItem(ui->treeWidget);
    QTreeWidgetItem *childItem_2_1 = new QTreeWidgetItem();
    QTreeWidgetItem *childItem_2_2 = new QTreeWidgetItem();
    QTreeWidgetItem *childItem_2_3 = new QTreeWidgetItem();

    //为他们设置内容
    rootItem_1->setText(0,"Files");
    childItem_1_1->setText(0,"Allunread");
    childItem_1_2->setText(0,"Assignemail");
    childItem_1_2_1->setText(0,"Test");
    //这是设置颜色的吗,确实是
    childItem_1_2_1->setForeground(0,QBrush(QColor(Qt::blue)));

    ui->treeWidget->addTopLevelItem(rootItem_1);
    rootItem_1->addChild(childItem_1_1);
    rootItem_1->addChild(childItem_1_2);
    childItem_1_2->addChild(childItem_1_2_1);

    rootItem_2->setText(0,"mailbox");
    childItem_2_1->setText(0,"Inbox");
    childItem_2_1->setText(1,"num:1");
    childItem_2_1->setForeground(1,QBrush(QColor(Qt::red)));
    childItem_2_2->setText(0,"draft");
    childItem_2_2->setText(1,"num:2");
    childItem_2_3->setText(0,"outbox");
    childItem_2_3->setText(1,"num:3");

    ui->treeWidget->addTopLevelItem(rootItem_2);
    rootItem_2->addChild(childItem_2_1);
    rootItem_2->addChild(childItem_2_2);
    rootItem_2->addChild(childItem_2_3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
