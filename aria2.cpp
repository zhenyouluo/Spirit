#include "aria2.h"
//#include<iostream>
//using std::cout;
//using std::endl;
Aria2::Aria2()
{
    Aria2c="/usr/bin/aria2c";

    Aria2Process=new QProcess();
    connect(Aria2Process,SIGNAL(readyRead()),this,SLOT(UpdateOutput()));
   // connect(Aria2Process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(testError(QProcess::ProcessError)));
}

void Aria2::NewDownload(const QString & in,const QString & out,QString args)
{
    QFileInfo *FileInfo=new QFileInfo(out);
    Dir=FileInfo->absolutePath();
    Aria2Process->setWorkingDirectory(Dir);
    FileName=FileInfo->baseName();
    QString tool=Aria2c;
    tool.append(" -o ").append(FileName).append(" ").append(in);
    //argu<<" -o "<<FileName<<" "<<in<<" "<<args;
    //cout<<in.toStdString()<<endl<<FileName.toStdString()<<endl;
    Aria2Process->start(tool);
    Aria2Process->waitForStarted(1000);
}

void Aria2::setLocation(const QString &aria2)
{
    if(Aria2c!=aria2)
        Aria2c=aria2;
}

void Aria2::UpdateOutput()
{
    QByteArray tmp=Aria2Process->readAll();
    if(Output!=tmp)
    {
        Output=tmp;
        char *str=Output.data();
        emit OutputUpdated(QString(str));
    }
}
/*void Aria2::testError(QProcess::ProcessError)
{
    cout<<"Error occur!"<<endl;
}
*/
