/*#include "centralwidget.h"

void myLineEdit::testText(QString)
{
    if(!text().isEmpty())
        emit notEmpty(true);
    else
        emit notEmpty(false);
}

CentralWidget::CentralWidget(QWidget *parent):QWidget(parent)
{
    Show=new QLabel(tr("URL"));
    Input=new myLineEdit();

    Down=new QPushButton(tr("&Down"));
    Down->setDisabled(true);
    Pause=new QPushButton(tr("&Stop"));

    Layout=new QHBoxLayout();
    Layout->addWidget(Show);
    Layout->addWidget(Input);
    Layout->addWidget(Down);
    Layout->addWidget(Pause);
    this->setLayout(Layout);

   connect(Input,SIGNAL(textChanged(QString)),Input,SLOT(testText(QString)));
   connect(Input,SIGNAL(notEmpty(bool)),Down,SLOT(setEnabled(bool)));
   connect(Down,SIGNAL(clicked()),this,SLOT(Download()));
}

void CentralWidget::Download()
{
    QString url(Input->text());
    QProcess::execute(QString("aria2c %1").arg(url));
}

void CentralWidget::PauseDownload()
{

}

CentralWidget::~CentralWidget()
{
    delete Input;
    delete Down;
    delete Pause;
    delete Layout;
}
*/
