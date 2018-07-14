#ifndef QBJECT_SHOWUSERWIDGET_H
#define QBJECT_SHOWUSERWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>

class qbject_showUserWidget : public QWidget
{
    Q_OBJECT
public:
    explicit qbject_showUserWidget(QWidget *parent = 0);
private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:

};

#endif // QBJECT_SHOWUSERWIDGET_H
