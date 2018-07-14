#ifndef LEFT_TABLEWIDGET_H
#define LEFT_TABLEWIDGET_H
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLabel>
#include <QPalette>



class left_tablewidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit left_tablewidget(QWidget *parent=0);
    QLabel *recommendMusicLabel;//推荐
    QLabel *label0;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label00;
};

#endif // LEFT_TABLEWIDGET_H
