#ifndef ARIA2_H
#define ARIA2_H
#include<QtCore/QProcess>
#include<QtCore/QStringList>
#include<QtCore/QString>
#include<QFileInfo>
#include<QObject>
class Aria2:public QObject
{
    Q_OBJECT
public:
    Aria2();
    void NewDownload(const QString &in,const QString &out,QString argu=QString());
    void setLocation(const QString &aria2);
    QByteArray OutputText() const;
    QProcess *Aria2Process;
private:
    QStringList argu;       //Extra arguments.
    QString Aria2c;       //Where the aria2 is.
    QString Dir;            //Where the aira2 will Work.
    QString FileName;
    QByteArray Output;
    int MaxSpeed;
signals:
    void OutputUpdated(QString);
    void DownloadFinished();
private slots:
    void UpdateOutput();
   // void testError(QProcess::ProcessError);

};

#endif // ARIA2_H

