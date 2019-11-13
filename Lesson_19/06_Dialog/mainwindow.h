#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDialog>
#include<QFileDialog>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void myslot();
    void myslot_2();
    void myslot_3();
    QDialog dlg_2;
};

#endif // MAINWINDOW_H

