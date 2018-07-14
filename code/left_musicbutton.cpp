#include "left_musicbutton.h"

left_musicButton::left_musicButton(QWidget *parent):QPushButton(parent)
{
    musictitleLabel=new QLabel(this);
    QPalette pal1;
    pal1.setColor(QPalette::ButtonText,QColor(255,255,255));
    QFont font("Courier",12);
    setCursor(Qt::PointingHandCursor);
    pix=QPixmap(":/image/image/music3.png");
    musictitleLabel->setGeometry(70,10,150,40);
    musictitleLabel->setFont(font);
    musictitleLabel->setText(tr("网易云音乐"));
    musictitleLabel->setPalette(pal1);
    setPalette(pal1);
}
void left_musicButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();
    QRectF rect=QRectF(0,0,250,64);
    QColor color(73,90,128);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.drawRect(rect);
    painter.restore();
    painter.save();
    painter.drawPixmap(0,0,64,64,pix);
    painter.restore();
}

