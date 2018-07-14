#include "qbjectwidget.h"

Qbjectwidget::Qbjectwidget(QWidget *parent) : QWidget(parent)
{
    setQbjectIcon();
}
void Qbjectwidget::setQbjectIcon()
{
    closeButton=new QPushButton(this);
    MaxButton=new QPushButton(this);
    MinButton=new QPushButton(this);
    MinniButton=new QPushButton(this);
    SetingButton=new QPushButton(this);
    MessageButton=new QPushButton(this);
    SkinButton=new QPushButton(this);
    UserButton=new QPushButton(this);
    closeButton->setGeometry(315,0,25,25);
    MaxButton->setGeometry(285,0,25,25);
    MinButton->setGeometry(255,0,25,25);
    MinniButton->setGeometry(225,0,25,25);
    SetingButton->setGeometry(175,0,22,22);
    MessageButton->setGeometry(125,0,25,25);
    SkinButton->setGeometry(75,0,28,25);
    UserButton->setGeometry(0,0,30,30);
    closeButton->setCursor(Qt::PointingHandCursor);
    closeButton->setToolTip(QString("关闭"));
    MaxButton->setCursor(Qt::PointingHandCursor);
    MaxButton->setToolTip(QString("最大化"));
    MinButton->setCursor(Qt::PointingHandCursor);
    MinButton->setToolTip(QString("最小化"));
    MinniButton->setCursor(Qt::PointingHandCursor);
    MinniButton->setToolTip(QString("mini 模式"));
    SetingButton->setToolTip(QString("设置"));
    SetingButton->setCursor(Qt::PointingHandCursor);
    MessageButton->setCursor(Qt::PointingHandCursor);
    MessageButton->setToolTip(QString("信息"));
    SkinButton->setCursor(Qt::PointingHandCursor);
    SkinButton->setToolTip(QString("皮肤"));
    UserButton->setCursor(Qt::PointingHandCursor);
    UserButton->setToolTip(QString("用户"));
    closeButton->setStyleSheet("QPushButton{background:rgb(50,50,50);border:0px;}\
                               QPushButton{image:url(:/image/image/close_normal.png)}\
                               QPushButton:hover{image:url(:/image/image/close_pressed.png);}");
     MaxButton->setStyleSheet("QPushButton{background:rgb(50,50,50);border:0px;}\
                                QPushButton{image:url(:/image/image/max_normal .png)}\
                                QPushButton:hover{image:url(:/image/image/max_pressed.png)}");
     MinButton->setStyleSheet("QPushButton{background:rgb(50,50,50);border:0px;}\
                                QPushButton{image:url(:/image/image/min_pressed.png)}\
                                QPushButton:hover{image:url(:/image/image/min_normal.png)}");
      MinniButton->setStyleSheet("QPushButton{background:rgb(50,50,50);border:0px;}\
                                QPushButton{border-image:url(:/image/image/mini_normal.png)}\
                                QPushButton:hover{border-image:url(:/image/image/mini_pressed.png)}");
      SetingButton->setStyleSheet("QPushButton{background:rgb(50,50,50);border:0px}\
                                QPushButton{border-image:url(:/image/image/seting_normal.png)}\
                                QPushButton:hover{border-image:url(:/image/image/seting_pressed.png)}");
      MessageButton->setStyleSheet("QPushButton{background:rgb(50,50,50);border:0px}\
                                QPushButton{border-image:url(:/image/image/xin_normal.png)}\
                                QPushButton:hover{border-image:url(:/image/image/xin_pressed.png)}");
      SkinButton->setStyleSheet("QPushButton{background:rgb(50,50,50);border:0px;}\
                                QPushButton{border-image:url(:/image/image/skin_normal.png)}\
                                QPushButton:hover{border-image:url(:/image/image/skin_pressed.png)}");
      UserButton->setStyleSheet ("QPushButton{border:2px solid rgb(100,100,100);border-radius:15px;}\
                                QPushButton:pressed{border:2px solid rgb(255,255,255);border-radius:15px;}");
}
