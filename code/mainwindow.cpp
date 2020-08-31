#include "mainwindow.h"
#include "searchwidget.h"
#include "qbjectwidget.h"
#include "qapplication.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    lrcshowwidget=new lrc_mainwindow;

    setMaximumSize(1300,800);
    setMinimumSize(1300,800);//固定软件界面的大小
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());//实现无边框
    topwidget=new QWidget(this);
    settopWidget(topwidget);

    downwidget=new QWidget(this);
    setdownWidget(downwidget);

    leftwidget=new QWidget(this);
    setleftWidget(leftwidget);

    searchWidget=new searchwidget(topwidget);
    searchWidget->setGeometry(348,20,360,48);
    redwidget=new QWidget(this);
    setredWidget(redwidget);
    wangyi_labe=new QLabel(this);
    QPixmap pix(":/image/image/wangyiyunicon .png");
    settoplightIcon(wangyi_labe,pix);

    doWidgwt=new dowidget(topwidget);
    doWidgwt->setGeometry(260,22,70,25);


    objectWidget=new Qbjectwidget(topwidget);
    objectWidget->setGeometry(940,22,360,48);

    downplaywidget=new down_playWidget(downwidget);
    downplaywidget->setGeometry(0,0,250,70);

    musictagshowWidget=new center_tagshow(this);
    musictagshowWidget->setGeometry(250,69,1050,661);

    progressbarWidget=new down_progressbarWidget(downwidget);
    progressbarWidget->setGeometry(250,0,690,70);

    voicebarWidget=new down_voicewidget(downwidget);
    voicebarWidget->setGeometry(940,0,180,70);

    downsetingWidget=new down_setingWidget(downwidget);
    downsetingWidget->setGeometry(1120,0,180,70);

    musicshowwidget=new left_musicshowWidget(this);
    musicshowwidget->setGeometry(0,730,0,0);

     usershowWidget=new qbject_showUserWidget(this);
     usershowWidget->setGeometry(0,0,0,0);

     messageshowWidget=new qbject_showmessageWidget(this);
     messageshowWidget->setGeometry(0,0,0,0);

     musiclistshowWidget=new seting_showmusiclistWidget(this);
     musiclistshowWidget->setGeometry(0,0,0,0);

     musicbigerButton=new left_musicButton(leftwidget);
     musicbigerButton->setGeometry(0,597,250,64);

     lefttableWidget=new left_tablewidget(leftwidget);
     lefttableWidget->setGeometry(0,0,260,597);


     timer4=new QTimer(this);
     timer4->setInterval(500);


    connect(objectWidget->closeButton,SIGNAL(clicked(bool)),this,SLOT(closeMainwindow()));
    connect(objectWidget->MinButton,SIGNAL(clicked(bool)),this,SLOT(minMainwindow()));
    connect(objectWidget->UserButton,SIGNAL(clicked(bool)),this,SLOT(showUserWidget()));
    connect(objectWidget->MessageButton,SIGNAL(clicked(bool)),this,SLOT(showMessageWidget()));
    connect(downsetingWidget->musiclistButton,SIGNAL(clicked(bool)),this,SLOT(showMusiclistWidget()));
    connect(musicbigerButton,SIGNAL(clicked(bool)),this,SLOT(showMusicWidget()));
    connect(downplaywidget->playButton,SIGNAL(toggled(bool)),this,SLOT(updatemusicWidget()));
    connect(musiclistshowWidget->addButton,SIGNAL(clicked(bool)),musiclistshowWidget,SLOT(getmusicList()));
    connect(musiclistshowWidget->songlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleclcklistwidget(QModelIndex)));//双击之后有惊喜
    connect(musiclistshowWidget->deleteButon,SIGNAL(clicked(bool)),this,SLOT(removeItemMusic()));//移除目标歌曲，但TXT文件移除模块有BUG
    connect(downplaywidget->nextButton,SIGNAL(clicked(bool)),this,SLOT(playnextmusic()));
    connect(downplaywidget->beforeButton,SIGNAL(clicked(bool)),this,SLOT(playbeforemusic()));
    connect(musiclistshowWidget->musicplaylist,SIGNAL(currentIndexChanged(int)),this,SLOT(updatemusicbutton(int)));
    connect(downplaywidget->myplayer,SIGNAL(metaDataChanged()),this,SLOT(updatemusiicon()));
    connect(voicebarWidget,SIGNAL(changeX()),this,SLOT(changevoice()));
    connect(voicebarWidget->voiceButton,SIGNAL(clicked(bool)),this,SLOT(closevoice()));
    connect(objectWidget->MinniButton,SIGNAL(clicked(bool)),this,SLOT(begainMinistyle()));
    connect(progressbarWidget,SIGNAL(changeX()),this,SLOT(changeMusicposition()));//这段有bug但是我不知道咋咋改  愁人啊。。占用内存过高
    connect(downsetingWidget->musicwordButton,SIGNAL(clicked(bool)),this,SLOT(showLrcMainwidget()));//显示歌词框
    connect(lefttableWidget,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(getTableWidgetItem(QTableWidgetItem*)));
    connect(lefttableWidget,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(getTableWidgetItem(QTableWidgetItem*)));
    //以上两个信号都连接了redline状态显示符号，但其中有若干bug，最为严重的是只能进行4次选择，并且无法解决---2016.12.26
}
MainWindow::~MainWindow()
{

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y()<69)
    {
        event->ignore();
        if(event->button()==Qt::LeftButton)
        {
            m_pressed=true;
            m_point=event->pos();
        }
    }

}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->pos().y()<69)
    {
            if(m_pressed)
            {
                move(event->pos()-m_point+pos());
            }
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
     if(event->pos().y()<69)
     {
         m_pressed=false;
     }
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
}
void MainWindow::settopWidget(QWidget *widget)
{
    topwidget->setGeometry(0,0,1300,65);
    QPalette pal(widget->palette());
    pal.setColor(QPalette::Background,QColor(50,50,50));
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    widget->show();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

}
void MainWindow::settoplightIcon(QLabel *label, QPixmap pix)
{
    wangyi_labe->setPixmap(pix);
    label->setGeometry(0,0,pix.width(),pix.height());
    label->show();
}
void MainWindow::setredWidget(QWidget *widget)
{
    redwidget->setGeometry(0,65,1300,4);
    QPalette pal(widget->palette());
    pal.setColor(QPalette::Background,QColor(161,11,11));
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    widget->show();
}
void MainWindow::closeMainwindow()
{
    this->setMinimumSize(0,0);
   QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
   animation->setDuration(500);
   animation->setStartValue(geometry());
   animation->setEndValue(QRect(geometry().x(),geometry().y(),0,geometry().height()));
   connect(animation,SIGNAL(finished()),this,SLOT(close()));
   animation->start(QAbstractAnimation::DeleteWhenStopped);
   lrcshowwidget->close();
}
void MainWindow::minMainwindow()
{
    showMinimized();
}
void MainWindow::showUserWidget()
{
    usershowWidget->show();
    usershowWidget->setGeometry(0,0,1300,800);
}
void MainWindow::showMessageWidget()
{
    messageshowWidget->show();
    messageshowWidget->setGeometry(0,0,1300,800);
}
void MainWindow::setdownWidget(QWidget *widget)
{
    widget->setGeometry(0,730,1300,70);
    QPalette pal(widget->palette());
    pal.setColor(QPalette::Background,QColor(50,50,50));
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    widget->show();
}
void MainWindow::showMusiclistWidget()
{
    musiclistshowWidget->show();
    musiclistshowWidget->setGeometry(0,0,1300,800);
    musiclistshowWidget->updateMusiclist();
}
void MainWindow::setleftWidget(QWidget *widget)
{
    widget->setGeometry(0,69,250,661);
    QPalette pal(widget->palette());
    pal.setColor(QPalette::Background,QColor(52,53,44));
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    widget->show();
}
void MainWindow::showMusicWidget()
{
    musicshowwidget->show();
    QPropertyAnimation *animation=new QPropertyAnimation(musicshowwidget,"geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(0,730,1300,0));
    animation->setEndValue(QRect(0,69,1300,661));
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}
void MainWindow::updatemusicWidget()
{
    if(downplaywidget->playButton->isChecked()==true)
    {
        if(!musiclistshowWidget->musicplaylist->isEmpty())
        {
                progressbarWidget->timer3->start();
                downplaywidget->myplayer->play();
                timer4->start();
                connect(timer4,SIGNAL(timeout()),this,SLOT(getMusictime()));
        }
        musicshowwidget->updateTimer->start();
        musicshowwidget->updateTimer1->start();
    }
    if(downplaywidget->playButton->isChecked()==false)
    {
        musicshowwidget->updateTimer->stop();
        musicshowwidget->updatechangegan1();
        progressbarWidget->timer3->stop();
        timer4->stop();
        downplaywidget->myplayer->pause();
        if(musicshowwidget->j>0)//判断回复杆是否归零
        {
            musicshowwidget->j=0;
        }
    }
}
void MainWindow::doubleclcklistwidget(QModelIndex index)
{
    downplaywidget->myplayer->setMedia(musiclistshowWidget->musicplaylist);
    musiclistshowWidget->musicplaylist->setPlaybackMode(QMediaPlaylist::Loop);
    int n=index.row();
    downplaywidget->playButton->setChecked(true);
    musiclistshowWidget->musicplaylist->setCurrentIndex(n);
    downplaywidget->myplayer->play();
    downplaywidget->playButton->setChecked(true);
    downplaywidget->update();
}
void MainWindow::getMusictime()
{
    progressbarWidget->druntime=downplaywidget->myplayer->duration();
    progressbarWidget->positontime=downplaywidget->myplayer->position();
    downplaywidget->update();
}
void MainWindow::playnextmusic()
{
   if(musiclistshowWidget->musicplaylist->mediaCount()-musiclistshowWidget->musicplaylist->currentIndex()!=1)
    {
        musiclistshowWidget->musicplaylist->setCurrentIndex(musiclistshowWidget->musicplaylist->nextIndex());
        downplaywidget->myplayer->play();
        downplaywidget->playButton->setChecked(true);
        downplaywidget->update();
    }
    else
    {
         musiclistshowWidget->musicplaylist->setCurrentIndex(0);
         downplaywidget->myplayer->play();
         downplaywidget->playButton->setChecked(true);
         downplaywidget->update();
    }
}
void MainWindow::playbeforemusic()
{
   if(musiclistshowWidget->musicplaylist->currentIndex()!=0)
    {
        musiclistshowWidget->musicplaylist->setCurrentIndex(musiclistshowWidget->musicplaylist->previousIndex());
        downplaywidget->myplayer->play();
        downplaywidget->playButton->setChecked(true);
        downplaywidget->update();
    }
    else
    {
        musiclistshowWidget->musicplaylist->setCurrentIndex(musiclistshowWidget->musicplaylist->mediaCount()-1);
        downplaywidget->myplayer->play();
        downplaywidget->playButton->setChecked(true);
        downplaywidget->update();
    }
}
void MainWindow::updatemusicbutton(int n)
{
        QString filename=musiclistshowWidget->songlistmodel->item(n)->text();
        musicbigerButton->musictitleLabel->setText(filename);
}
void MainWindow::updatemusiicon()
{
    QImage cover=downplaywidget->myplayer->metaData("ThumbnailImage").value<QImage>();
    QString title=downplaywidget->myplayer->metaData(QMediaMetaData::Title).toString();
    QString musicerstr=downplaywidget->myplayer->metaData(QMediaMetaData::Author).toString();
    QString specialstr=downplaywidget->myplayer->metaData(QMediaMetaData::AlbumTitle).toString();
    if(!cover.isNull())
    {
        QPixmap pixmap=QPixmap::fromImage(cover);
        musicbigerButton->pix=pixmap;
        musicshowwidget->pix2=pixmap;
        musicbigerButton->update();
    }
    else
    {
        musicbigerButton->pix=musicbigerButton->pix;
    }
    musicshowwidget->musictitelLabel->setText(title);
    musicshowwidget->musicerLabel->setText(musicerstr);
    musicshowwidget->specialLabel->setText(specialstr);
    lrcshowwidget->lrcLabel->setText(title);
}
void MainWindow::changevoice()
{
   downplaywidget->myplayer->setVolume(voicebarWidget->X-60);
}
void MainWindow::changeMusicposition()
{
    downplaywidget->myplayer->stop();
    progressbarWidget->timer3->stop();
    qint64 num=downplaywidget->myplayer->duration();
    qint64 nowposition=num*((float)(progressbarWidget->X-56)/(float)564);
    downplaywidget->myplayer->setPosition(nowposition);
    downplaywidget->myplayer->play();
    progressbarWidget->timer3->start();
    downplaywidget->playButton->setChecked(true);
}
void MainWindow::closevoice()
{
    if(voicebarWidget->voiceButton->isChecked())
    {
       downplaywidget->myplayer->setVolume(0);
        voicebarWidget->X=60;
        voicebarWidget->update();
    }
    else
    {
        downplaywidget->myplayer->setVolume(50);
        voicebarWidget->X=100;
        voicebarWidget->update();
    }
}
void MainWindow::begainMinistyle()
{
    this->hide();
    trayIcon=new QSystemTrayIcon(this);
    QIcon icon=QIcon(":/image/image/wangyimini.png");
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("网易云音乐");
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(creativeTrayivon(QSystemTrayIcon::ActivationReason)));
    trayIcon->show();
}
void MainWindow::creativeTrayivon(QSystemTrayIcon::ActivationReason reason)
{
    menu=new QMenu(this);
    showMainAction=new QAction(this);
    showMainAction->setText("显示主界面");
    closeMainAction=new QAction(this);
    closeMainAction->setText(tr("退出"));
    menu->addAction(showMainAction);
    menu->addSeparator();
    menu->addAction(closeMainAction);
    connect(showMainAction,SIGNAL(triggered(bool)),this,SLOT(show()));
    connect(closeMainAction,SIGNAL(triggered(bool)),this,SLOT(close()));
    trayIcon->setContextMenu(menu);
    switch (reason) {
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}
void MainWindow::removeItemMusic()
{
    QModelIndex currentIndex=musiclistshowWidget->songlist->currentIndex();
    int n=currentIndex.row();
    musiclistshowWidget->musicplaylist->removeMedia(n);
    musiclistshowWidget->songlistmodel->removeRow(n);
    /*if(!musiclistshowWidget->file0.open(QIODevice::ReadWrite|QIODevice::Text))
        return;
    QTextStream stream0(&musiclistshowWidget->file0);
    int i;
    while(!stream0.atEnd())
    {
        QString line0;
        i++;
    }
    musiclistshowWidget->file0.close();*/
}
void MainWindow::showLrcMainwidget()
{
    if(downsetingWidget->musicwordButton->isChecked()==true)
    {
        lrcshowwidget->show();
        lrcshowwidget->raise();
    }
    else if(downsetingWidget->musicwordButton->isChecked()==false)
    {
        lrcshowwidget->hide();
    }
}
void MainWindow::getTableWidgetItem(QTableWidgetItem *item)
{
    T=item->row();
    switch (T) {
    case 1:
        lefttableWidget->setCellWidget(1,0,lefttableWidget->label00);
        break;
    case 2:

        lefttableWidget->setCellWidget(2,0,lefttableWidget->label00);
        break;
    case 3:

        lefttableWidget->setCellWidget(3,0,lefttableWidget->label00);
        break;
    case 4:

        lefttableWidget->setCellWidget(4,0,lefttableWidget->label00);
        break;
    default:
        T=0;
        break;
    }
}













