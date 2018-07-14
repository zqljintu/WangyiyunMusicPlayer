#include "qbject_showuserwidget.h"

qbject_showUserWidget::qbject_showUserWidget(QWidget *parent) : QWidget(parent)
{
    this->hide();
}
void qbject_showUserWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.save();
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor color(52,53,44);
    painter.setPen(Qt::black);
    painter.setBrush(color);
    QRectF rect=QRectF(855,69,200,300);
    painter.drawRoundedRect(rect,15,15);
    QPolygonF polygon;
    polygon<<QPointF(955,52)<<QPointF(945,69)<<QPointF(965,69)<<QPointF(955,52);
    painter.drawPolygon(polygon,Qt::WindingFill);
    painter.restore();

}
void qbject_showUserWidget::mousePressEvent(QMouseEvent *event)
{
    if((event->pos().x()>1055)||(event->pos().x()<855))
    {
        this->hide();
        setGeometry(0,0,0,0);
    }
    if((event->pos().y()<69)||(event->pos().y()>369))
    {
        this->hide();
        setGeometry(0,0,0,0);
    }
}
