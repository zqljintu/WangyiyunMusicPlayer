#ifndef DOWN_SETINGWIDGET_H
#define DOWN_SETINGWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QComboBox>
#include <QPushButton>


class down_setingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit down_setingWidget(QWidget *parent = 0);
    QComboBox *patternCombox;//模式
    QPushButton *musicwordButton;//歌词
    QPushButton *musiclistButton;//列表
private:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // DOWN_SETINGWIDGET_H
