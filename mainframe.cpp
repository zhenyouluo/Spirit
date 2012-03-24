#include "mainframe.h"
DownloadingPage::DownloadingPage(QWidget *parent):QWidget(parent)
{
    Text=new QTextEdit(this);
    Text->setReadOnly(true);
    Aria2c=new Aria2();
    connect(Aria2c,SIGNAL(OutputUpdated(QString)),Text,SLOT(append(QString)));
    connect(Aria2c->Aria2Process,SIGNAL(finished(int)),this,SLOT(TestStatus(int)));
    connect(this,SIGNAL(DownloadFinished()),this,SLOT(AfterFinished()));

    Layout=new QHBoxLayout();
    Layout->addWidget(Text);
    this->setLayout(Layout);
}

void DownloadingPage::NewDownload(const QString &in,const QString &out,QString argu)
{

    Aria2c->NewDownload(in,out,argu);
}
void DownloadingPage::TestStatus(int exitCode)
{
    if(exitCode==0)
        emit DownloadFinished();
}

void DownloadingPage::AfterFinished()
{
    Text->clear();
}

void DownloadingPage::clearInfo()
{
    Text->clear();
}

DownloadedPage::DownloadedPage(QWidget *parent):QWidget(parent)
{

}

void DownloadedPage::clearInfo()
{

}

void DownloadingPage::setFileName(const QString &filename)
{
    FileName=filename;
}

void DownloadingPage::setUrl(const QString &url)
{
    Url=url;
}

MainFrame::MainFrame(QWidget *parent):QFrame(parent)
{
    WidgetList=new QListWidget(this);
    WidgetList->addItem(tr("Downloading"));
    WidgetList->addItem(tr("Downloaded"));
    WidgetList->setCurrentRow(0);
    WidgetList->setMaximumWidth(128);

    Pages=new QStackedWidget(this);
    DownPage=new DownloadingPage(this);//
    Pages->addWidget(DownPage);
    Pages->addWidget(new DownloadedPage(this));
    connect(WidgetList,SIGNAL(currentRowChanged(int)),this,SLOT(changePage(int)));

    layout=new QHBoxLayout();
    layout->addWidget(WidgetList);
    layout->addWidget(Pages);
    this->setLayout(layout);
}

void MainFrame::clearInfo()
{
    if(Pages->currentIndex()==0)
        DownPage->clearInfo();
    else
       //todo
        ;
}

void MainFrame::changePage(int row)
{
    Pages->setCurrentIndex(row);
}
