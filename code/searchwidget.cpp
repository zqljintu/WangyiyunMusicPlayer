#include "searchwidget.h"

searchwidget::searchwidget(QWidget *parent) : QWidget(parent)
{
    QPalette pal;
    pal.setColor(QPalette::Text,QColor(100,100,100));
    searchEdit=new QLineEdit(this);
    searchEdit->setGeometry(15,0,300,30);
    searchEdit->setStyleSheet("QLineEdit {border-radius: 4px;border: 0px solid rgb(100, 100, 100); background: rgb(0,20,20);}");
    searchEdit->setPlaceholderText(QString("搜索音乐,歌手,歌词,用户"));

    searchEdit->setPalette(pal);
    searchButton=new QPushButton(this);
    searchButton->setGeometry(315,0,30,30);
    searchButton->setToolTip(QString("搜索"));
    searchButton->setStyleSheet("QPushButton{background:rgb(0,20,20);border:0px;}\
                                                      QPushButton{image:url(:/image/image/search_normal.png)}\
                                                      QPushButton:hover{image:url(:/image/image/search_press.png)}\
                                                      QPushButton:pressed{image:url(:/image/image/search_normal.png)}");
    searchButton->setCursor(Qt::PointingHandCursor);
}
void searchwidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor color(0,20,20);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    QRectF rect=QRectF(0,0,360,30);
    painter.drawRoundedRect(rect,15,15);
    painter.restore();
}
void searchwidget::search()
{

}
