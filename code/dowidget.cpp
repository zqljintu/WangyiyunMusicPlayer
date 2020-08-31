#include "dowidget.h"

dowidget::dowidget(QWidget *parent) : QWidget(parent)
{
    doButton=new QPushButton(this);
    undoButton=new QPushButton(this);
    doButton->setGeometry(0,0,35,25);
    undoButton->setGeometry(35,0,35,25);
    doButton->setCursor(Qt::PointingHandCursor);
    undoButton->setCursor(Qt::PointingHandCursor);
    doButton->setStyleSheet("QPushButton{background:rgb(0,20,20);border:1px solid rgb(100,100,100);border-radius:2px;}\
                                                QPushButton{image:url(:/image/image/do_flase.png)}\
                                                QPushButton:pressed{image:url(:/image/image/do_true.png);border:0px;}");
    undoButton->setStyleSheet("QPushButton{background:rgb(0,20,20);border:1px solid rgb(100,100,100);border-radius:2px;}\
                                                    QPushButton{image:url(:/image/image/undo_flase.png)}\
                                                    QPushButton:pressed{image:url(:/image/image/undo_true.png);border:0px;}");
     connect(doButton,SIGNAL(clicked(bool)),this,SLOT(doSlot()));
     connect(undoButton,SIGNAL(clicked(bool)),this,SLOT(undoSlot()));
}
void dowidget::doSlot()
{

}
void dowidget::undoSlot()
{

}
