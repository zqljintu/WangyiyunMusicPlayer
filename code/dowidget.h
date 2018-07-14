#ifndef DOWIDGET_H
#define DOWIDGET_H

#include <QWidget>
#include <QPushButton>

class dowidget : public QWidget
{
    Q_OBJECT
public:
    explicit dowidget(QWidget *parent = 0);
    QPushButton *doButton;//向前
    QPushButton *undoButton;//向后

signals:

public slots:
    void doSlot();
    void undoSlot();
};

#endif // DOWIDGET_H
