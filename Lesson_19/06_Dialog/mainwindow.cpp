#include "mainwindow.h"
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QDialog>//对话框所需
#include<QMessageBox>//标准对话框
#include<QDebug>
#include<QFileDialog>//文件对话框
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,400);
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("Dialog");
    QAction *p1 = menu->addAction("模态对话框");
    connect(p1,&QAction::triggered,this,&MainWindow::myslot);

    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2,&QAction::triggered,this,&MainWindow::myslot_2);

    menu->addSeparator();
    //标准对话框
    QAction *p3=menu->addAction("Standrad_Dialog");
    connect(p3,&QAction::triggered,
    [=]()
    {
        QMessageBox::about(this,"about","标准对话框中的关于对话框");
    }
           );
    //问题对话框
    QAction *p4=menu->addAction("Question_Dialog");
    connect(p4,&QAction::triggered,
            [=]()
    {
        //本函数有返回值
        int res=QMessageBox::question(this,
                                      "question","Are you ok?",
                                      QMessageBox::Yes,
                                      QMessageBox::No,
                                      QMessageBox::Cancel);
        qDebug()<<"You push is "<<res;
    }
            );

    //文件对话框,可以获得路径名
    QAction *p5=menu->addAction("FILEDIALOG");
    connect(p5,&QAction::triggered,this,&MainWindow::myslot_3);

}
void MainWindow::myslot_3()
{
    QString path=QFileDialog::getOpenFileName(this,"open","../","souce(*.cpp);;Text(*.txt);;all(*.*)");
    qDebug()<<path;
}

void MainWindow::myslot_2()
{
    dlg_2.resize(200,150);
    dlg_2.move(200,200);
    dlg_2.show();
}

void MainWindow::myslot()
{
    //这是一个模态框，在这里用户无法操作主窗口的内容
    QDialog dlg;
    dlg.resize(200,150);
    dlg.exec();
}

MainWindow::~MainWindow()
{

}
