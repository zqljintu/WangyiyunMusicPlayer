#ifndef DOWN_PROGRESSBARWIDGET_H
#define DOWN_PROGRESSBARWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPalette>
#include <QTimer>

class down_progressbarWidget : public QWidget
{
    Q_OBJECT
public:
    int X=56;
    qint64 druntime;
    qint64  positontime;
    QString s="0:0";
    QString t="0:0";
    explicit down_progressbarWidget(QWidget *parent = 0);
    QLabel *liftLabel;//左时间显示
    QLabel *rightLabel;//右边时间显示
    QTimer *timer3;//刷新
private:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
signals:
    void changeX();//自定义一个信号
public slots:
    void updatepos();
};

#endif // DOWN_PROGRESSBARWIDGET_H
