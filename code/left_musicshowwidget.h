#ifndef LEFT_MUSICSHOWWIDGET_H
#define LEFT_MUSICSHOWWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QTimer>
#include <QLabel>

class left_musicshowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit left_musicshowWidget(QWidget *parent = 0);
     QPushButton *lessButton;//缩小
     QColor color;
     QTimer *updateTimer;//更新
     QTimer *updateTimer1;
     int i=0;//角度
     int j=0;//角度
     QPixmap pix2;//背景图
     QLabel *musictitelLabel;//歌曲名label
     QLabel *musicerLabel;//创作者
     QLabel *specialLabel;//专辑

private:
    void paintEvent(QPaintEvent *event);


signals:

public slots:
    void changemusicWidget();
    void updateheijiaopian();
    void updatechangegan();
    void updatechangegan1();
};

#endif // LEFT_MUSICSHOWWIDGET_H
