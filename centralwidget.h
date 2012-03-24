/*#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include<QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QProcess>

class myLineEdit:public QLineEdit
{
    Q_OBJECT
signals:
    void notEmpty(bool);
public slots:
    void testText(QString);
};

class CentralWidget : public QWidget
{
    Q_OBJECT

public:
    CentralWidget(QWidget *parent=0);
    ~CentralWidget();

private:
    myLineEdit *Input;
    QPushButton *Down;
    QPushButton *Pause;
    QHBoxLayout *Layout;
    QLabel *Show;

private slots:
    void Download();
    void PauseDownload();
};

#endif // CENTRALWIDGET_H
*/
