#include "mainwindow.h"
#include<iostream>
using std::cout;
using std::endl;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MainWidget=new MainFrame(this);
    setCentralWidget(MainWidget);

    menubar=new QMenuBar();
    task=new QMenu(tr("&Task"));
    settings=new QMenu(tr("&Settings"));
    control=new QMenu(tr("&Control"));
    help=new QMenu(tr("&Help"));
    menubar->addMenu(task);
    menubar->addMenu(settings);
    menubar->addMenu(control);
    menubar->addMenu(help);

    newTask=new QAction(tr("&New Task"),this);
    connect(newTask,SIGNAL(triggered()),this,SLOT(NewDownload()));
    finishedTask=new QAction(tr("Finished Tasks"),this);

    aria2Location=new QAction(tr("Locate the aria2"),this);
    connect(aria2Location,SIGNAL(triggered()),this,SLOT(LocateAria2()));

    speedLimit=new QAction(tr("Limit speed"),this);
    connect(speedLimit,SIGNAL(triggered()),this,SLOT(LimitSpeed()));

    continueTask=new QAction(tr("Continue"),this);
    pauseTask=new QAction(tr("Pause"),this);
    deleteTask=new QAction(tr("Cancel"),this);
    cleanInfo=new QAction(tr("&Clear Information"),this);
    connect(cleanInfo,SIGNAL(triggered()),MainWidget->DownPage,SLOT(clearInfo()));

    aboutThis=new QAction(tr("About Spirit"),this);
    connect(aboutThis,SIGNAL(triggered(bool)),this,SLOT(AboutThis(bool)));

    aboutAria2=new QAction(tr("About Aria2"),this);
    connect(aboutAria2,SIGNAL(triggered(bool)),this,SLOT(AboutAria2(bool)));

    task->addAction(newTask);
    task->addAction(finishedTask);

    settings->addAction(aria2Location);
    settings->addAction(speedLimit);

    control->addAction(continueTask);
    control->addAction(pauseTask);
    control->addAction(deleteTask);
    control->addAction(cleanInfo);

    help->addAction(aboutThis);
    help->addAction(aboutAria2); 

    setMenuBar(menubar);
}

void MainWindow::NewDownload()
{
    QString url=QInputDialog::getText(this,tr("New Download"),tr("URL"));
    if(!url.isEmpty())
    {
        QString FileName=QFileDialog::getSaveFileName(this);
        if(!url.isEmpty())
        {
        MainWidget->DownPage->setUrl(url);
        MainWidget->DownPage->setFileName(FileName);
        MainWidget->DownPage->NewDownload(url,FileName);
        }
    }
}

void MainWindow:: LocateAria2()
{
    QString aria2;
    if(!(aria2=QFileDialog::getOpenFileName()).isEmpty())
        MainWidget->DownPage->Aria2c->setLocation(aria2);
}

void MainWindow::LimitSpeed()
{
    QInputDialog::getInt(this,tr("Limit the Download Speed"),tr("Max Download Speed:"));
    //todo
}

void MainWindow::AboutAria2(bool)
{
    QMessageBox::about(this,tr("About Aria2"),tr("Aria2 is a command line tool for downloading."));
}

void MainWindow::AboutThis(bool)
{
    QMessageBox::about(this,tr("About Spirit"),tr("Spirit is a front end for Aria2,written by JiFeng Hu."));
}

MainWindow::~MainWindow()
{

}
