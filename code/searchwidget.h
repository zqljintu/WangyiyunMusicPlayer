#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class searchwidget : public QWidget
{
    Q_OBJECT
public:
    explicit searchwidget(QWidget *parent = 0);
    QPushButton *searchButton;
    QLineEdit *searchEdit;

private:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void search();
};

#endif // SEARCHWIDGET_H
