#include "down_playwidget.h"

down_playWidget::down_playWidget(QWidget *parent) : QWidget(parent)
{
    myplayer=new QMediaPlayer(this);
    myplayer->setVolume(60);
    playButton=new QPushButton(this);
    nextButton=new QPushButton(this);
    beforeButton=new QPushButton(this);
    beforeButton->setGeometry(30,15,40,40);
    playButton->setGeometry(100,10,50,50);
    nextButton->setGeometry(180,15,40,40);
    beforeButton->setCursor(Qt::PointingHandCursor);
    beforeButton->setToolTip(QString("上一曲"));
    playButton->setCursor(Qt::PointingHandCursor);
    playButton->setToolTip(QString("播放"));
    nextButton->setCursor(Qt::PointingHandCursor);
    nextButton->setToolTip(QString("下一曲"));
    beforeButton->setStyleSheet("QPushButton{border-image:url(:/image/image/before_normal.png)}\
                                QPushButton:hover{border-image:url(:/image/image/before_pressed.png)}");
    playButton->setCheckable(true);
    playButton->setChecked(false);
    playButton->setStyleSheet("QPushButton:checked{border-image:url(:/image/image/stop.png)}\
                                QPushButton:!checked{border-image:url(:/image/image/play_pressed.png)}");
    nextButton->setStyleSheet("QPushButton{border-image:url(:/image/image/next_normal.png)}\
                                QPushButton:hover{border-image:url(:/image/image/next_pressed.png)}");

}
void down_playWidget::setplayIcon()
{
}
void down_playWidget::getmusicicon()
{

}















