#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QFrame>
#include<QWidget>
#include<QListWidget>
#include<QHBoxLayout>
#include<QStackedWidget>
#include<QTextEdit>
#include"aria2.h"
class DownloadingPage:public QWidget
{
    Q_OBJECT

public:
    DownloadingPage(QWidget *parent);
    void setFileName(const QString &filename);
    void setUrl(const QString &url);
    void NewDownload(const QString &in,const QString &out,QString argu=QString());
     Aria2 *Aria2c;
private:
    QTextEdit *Text;
    QHBoxLayout *Layout;
    QString FileName;    //The file name to be stored.
    QString Url;
signals:
    void DownloadFinished();
private slots:
    void TestStatus(int exitCode);
    void AfterFinished();

public slots:
    void clearInfo();
};

class DownloadedPage:public QWidget
{
    Q_OBJECT

public:
    DownloadedPage(QWidget *parent);

private:

public slots:
    void clearInfo();
};

class MainFrame : public QFrame
{
    Q_OBJECT

public:
    MainFrame(QWidget *parent);
    DownloadingPage *DownPage;
private:
    QListWidget *WidgetList;
    QHBoxLayout *layout;
    QStackedWidget *Pages;

private slots:
    //void ShowDownloading();
    //void ShowDownloaded();
    void changePage(int);
public slots:
    void clearInfo();
};

#endif // MAINFRAME_H
