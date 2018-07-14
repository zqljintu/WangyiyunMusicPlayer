#ifndef QBJECT_SHOWMESSAGEWIDGET_H
#define QBJECT_SHOWMESSAGEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

class qbject_showmessageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit qbject_showmessageWidget(QWidget *parent = 0);
private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:

public slots:
};

#endif // QBJECT_SHOWMESSAGEWIDGET_H
