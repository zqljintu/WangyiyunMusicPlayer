#ifndef DOWN_PLAYWIDGET_H
#define DOWN_PLAYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QDir>
#include<QFile>
#include "iostream"
#include <QFileDialog>
#include <left_musicshowwidget.h>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QStringListIterator>
#include <QMediaMetaData>

class down_playWidget : public QWidget
{
    Q_OBJECT
public:
    explicit down_playWidget(QWidget *parent);
    QPushButton *playButton;//播放
    QPushButton *nextButton;//下一曲
    QPushButton *beforeButton;//上一曲
    void setplayIcon();//绘制界面
    QMediaPlayer *myplayer;//创建播放器
    void getmusicicon();//获取歌的icon


signals:

public slots:
};

#endif // DOWN_PLAYWIDGET_H
