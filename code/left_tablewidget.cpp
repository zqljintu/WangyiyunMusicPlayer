#include "left_tablewidget.h"
#include <QTableWidget>

left_tablewidget::left_tablewidget(QWidget *parent) :QTableWidget(parent)
{
    setCursor(Qt::PointingHandCursor);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameShape(QFrame::NoFrame);
    setFocusPolicy(Qt::NoFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setShowGrid(false);
    setStyleSheet("QTableView{background-color:rgb(239,240,220);}\
                            QTableView::item{border:none;}");
    setStyleSheet("selection-background-color:rgb(62,55,55);\
                            background-color:rgb(52,53,44);");
    setColumnCount(2);
    setRowCount(5);
    for(int i=0;i<=5;i++)
    {
        setColumnWidth(0,10);
        setColumnWidth(1,250);
        setRowHeight(i,50);
    }

    setRowHeight(0,35);
    recommendMusicLabel=new QLabel(this);
    recommendMusicLabel->setText("   推荐");
    QPalette pal;//胆大心细脸皮厚，大长腿就是一块石头。
    pal.setColor(QPalette::Text,Qt::white);
    recommendMusicLabel->setPalette(pal);
    recommendMusicLabel->setFixedWidth(260);
    recommendMusicLabel->setFixedHeight(35);
    label00=new QLabel(this);
    label00->setPixmap(QPixmap(":/image/image/redLine.jpg"));
    label0=new QLabel(this);
    label0->setPixmap(QPixmap(":/image/image/findMusic.png"));
    label0->setFixedSize(55,35);
    label1=new QLabel(this);
    label1->setPixmap(QPixmap(":/image/image/fmLabel.png"));
    label1->setFixedSize(55,37);
    label2=new QLabel(this);
    label2->setPixmap(QPixmap(":/image/image/mvlabel.png"));
    label2->setFixedSize(55,37);
    label3=new QLabel(this);
    label3->setPixmap(QPixmap(":/image/image/friendlabel.png"));
    label3->setFixedSize(58,37);
    label0->setScaledContents(true);
    label1->setScaledContents(true);
    label2->setScaledContents(true);
    label3->setScaledContents(true);
    QTableWidgetItem *item1=new QTableWidgetItem("              发现音乐");
    item1->setTextColor(Qt::white);
    QTableWidgetItem *item2=new QTableWidgetItem("              私人FM");
    item2->setTextColor(Qt::white);
    QTableWidgetItem *item3=new QTableWidgetItem("              MV");
    item3->setTextColor(Qt::white);
    QTableWidgetItem *item4=new QTableWidgetItem("              朋友");
    item4->setTextColor(Qt::white);
    this->setItem(1,1,item1);
    this->setItem(2,1,item2);
    this->setItem(3,1,item3);
    this->setItem(4,1,item4);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    verticalHeader()->setVisible(false);
    horizontalHeader()->setVisible(false);
    setCellWidget(0,1,recommendMusicLabel);
    setCellWidget(1,1,label0);
    setCellWidget(2,1,label1);
    setCellWidget(3,1,label2);
    setCellWidget(4,1,label3);
    show();
}

