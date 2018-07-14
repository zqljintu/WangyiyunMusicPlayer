#ifndef DOWN_VOICEWIDGET_H
#define DOWN_VOICEWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>

class down_voicewidget : public QWidget
{
    Q_OBJECT
public:
    explicit down_voicewidget(QWidget *parent = 0);
    QPushButton *voiceButton;//声音开关
    int X=120;

private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void changeX();//自定义一个信号
public slots:
};

#endif // DOWN_VOICEWIDGET_H
