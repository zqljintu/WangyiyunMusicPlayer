#include "down_voicewidget.h"

down_voicewidget::down_voicewidget(QWidget *parent) : QWidget(parent)
{
    voiceButton=new QPushButton(this);
    voiceButton->setGeometry(20,25,20,20);
    voiceButton->setToolTip(QString("音量"));
    voiceButton->setCursor(Qt::PointingHandCursor);
    voiceButton->setCheckable(true);
    voiceButton->setChecked(false);
    voiceButton->setStyleSheet("QPushButton:checked{border-image:url(:/image/image/voice_unclicked.png)}\
                                QPushButton:!checked{border-image:url(:/image/image/voice_clicked.png)}");
}
void down_voicewidget::paintEvent(QPaintEvent *event)//绘制接收参数改变后更新
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor baseColor(0,20,20);
    QColor intColor(255,0,0);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(baseColor);
    QRectF rect=QRectF(60,32,100,6);
    painter.drawRoundedRect(rect,3,3);
    painter.restore();
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(intColor);
    QRectF voicerect=QRectF(60,32,X-60,6);
    painter.drawRoundedRect(voicerect,3,3);
    painter.restore();
}
void down_voicewidget::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y()>30&&event->pos().y()<40)
    {
            int value;
            value=event->pos().x();
            if(value<60)
            {
                X=60;
            }
            else if(value>160)
            {
                X=160;
            }
            else
            {
                X=value;
            }
            if(voiceButton->isChecked())
            {
                X=60;
                update();
            }
            if(X<90||X>90)
           {
               emit changeX();
           }
            update();
            setCursor(Qt::PointingHandCursor);
    }
    else
    {
        event->ignore();
    }
}










