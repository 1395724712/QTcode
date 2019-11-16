#include "mainwindow.h"
#include<QMenuBar>//菜单栏所需头文件
#include<QMenu>
#include<QAction>
#include<QDebug>
#include<QToolBar>//工具栏所需头文件
#include<QPushButton>
#include<QStatusBar>//状态栏所需头文件
#include<QLabel>//标签
#include<QTextEdit>//文本编辑
#include<QDockWidget>//浮动窗口

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,300);
    //菜单栏
    QMenuBar *mBar=menuBar();

    //添加菜单
    QMenu *pFile=mBar->addMenu("File");
    QMenu *pEditor=mBar->addMenu("Editor");

    //添加菜单项（添加动作）
    QAction *pNew = pFile->addAction("new");
    //添加分割线
    pFile->addSeparator();
    QAction *pOpen=pFile->addAction("open");

    //Lambat表达式
    connect(pNew,&QAction::triggered,
            []()
    {
        qDebug()<<"the button has been pressed";
    }
                );

    //工具栏,相当于菜单栏的快捷方式
    QToolBar *toolBar=addToolBar("toolBar");

    //工具栏添加快捷键
    toolBar->addAction(pNew);
    toolBar->addAction(pOpen);

    QPushButton *b = new QPushButton(this);
    //添加小控件
    toolBar->addWidget(b);
    b->setText("close");

    //添加功能
    connect(b,&QPushButton::released,this,&MainWindow::close);

    //状态栏
    //这里不需要分配空间
    QStatusBar *statusbar=statusBar();
    QLabel *label=new QLabel(this);
    label->setText(" no file");
    //从左往右添加
    statusbar->addWidget(label);
    //从右往左添加
    statusbar->addPermanentWidget(new QLabel("files",this));

    //核心控件
    QTextEdit *textEdit= new QTextEdit(this);
    setCentralWidget(textEdit);

    //浮动窗口
    QDockWidget *dock=new QDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,dock);
    dock->setWidget(b);
}

MainWindow::~MainWindow()
{

}
