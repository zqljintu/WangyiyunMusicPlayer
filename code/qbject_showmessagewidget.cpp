#include "qbject_showmessagewidget.h"

qbject_showmessageWidget::qbject_showmessageWidget(QWidget *parent) : QWidget(parent)
{
    this->hide();

}
void qbject_showmessageWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.save();
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor color(52,53,44);
    painter.setPen(Qt::black);
    painter.setBrush(color);
    QRectF rect=QRectF(940,69,358,650);
    painter.drawRoundedRect(rect,15,15);
    QPolygonF polygon;
    polygon<<QPointF(1077,45)<<QPointF(1067,69)<<QPointF(1087,69)<<QPointF(1077,45);
    painter.drawPolygon(polygon,Qt::WindingFill);
    painter.restore();
}
void qbject_showmessageWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().x()<940)
    {
        setGeometry(0,0,0,0);
    }
    if((event->pos().y()>669)||(event->pos().y()<69))
    {
        setGeometry(0,0,0,0);
    }
}
