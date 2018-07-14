#ifndef QBJECTWIDGET_H
#define QBJECTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "qbject_showuserwidget.h"

class Qbjectwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Qbjectwidget(QWidget *parent = 0);
    QPushButton *closeButton;//关闭软件界面
    QPushButton *MaxButton;//最大化
    QPushButton *MinButton;//最小化
    QPushButton *MinniButton;//迷你模式
    QPushButton *SetingButton;//设置
    QPushButton *MessageButton;//信息
    QPushButton *SkinButton;//皮肤
    QPushButton *UserButton;//用户
private:
    void setQbjectIcon();

signals:

public slots:

};

#endif // QBJECTWIDGET_H
