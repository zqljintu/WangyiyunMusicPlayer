#ifndef LRC_MAINWINDOW_H
#define LRC_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>
#include <QPalette>
#include <QFont>

class lrc_mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit lrc_mainwindow(QWidget *parent = 0);
    QLabel *lrcLabel;
    bool m_pressed;
    QPoint m_point;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // LRC_MAINWINDOW_H
