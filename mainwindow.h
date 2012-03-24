#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QMessageBox>
#include<QInputDialog>
#include<QFileDialog>
#include<QTabBar>
#include"mainframe.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MainFrame *MainWidget; //modified

private:
    QMenuBar *menubar;
    QMenu *task,*settings,*control,*help;

    QAction *newTask,*finishedTask;
    QAction *aria2Location,*speedLimit;
    QAction *continueTask,*pauseTask,*deleteTask,*cleanInfo;
    QAction *aboutThis,*aboutAria2;

private slots:
    void NewDownload();
    void LocateAria2();
    void LimitSpeed();
    void AboutAria2(bool);
    void AboutThis(bool);
};

#endif // MAINWINDOW_H
