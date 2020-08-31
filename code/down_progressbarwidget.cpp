#include "down_progressbarwidget.h"

down_progressbarWidget::down_progressbarWidget(QWidget *parent) : QWidget(parent)
{
    QPalette pal;
    pal.setColor(QPalette::WindowText,QColor(255,255,255));
    QFont font("Courier",10);
    liftLabel=new QLabel(this);
    rightLabel=new QLabel(this);
    liftLabel->setAlignment(Qt::AlignCenter);
    rightLabel->setAlignment(Qt::AlignCenter);
    liftLabel->setGeometry(0,10,50,50);
    rightLabel->setGeometry(640,10,50,50);
    rightLabel->setFont(font);
    liftLabel->setFont(font);
    liftLabel->setPalette(pal);
    rightLabel->setPalette(pal);
    timer3=new QTimer(this);
    timer3->setInterval(1000);
    connect(timer3,SIGNAL(timeout()),this,SLOT(updatepos()));
}
void down_progressbarWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor baseColor(0,20,20);
    QColor inColor(255,0,0);
    QColor outColor(255,255,255);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(baseColor);
    QRectF rect=QRectF(55,32,580,6);
    painter.drawRoundedRect(rect,3,3);
    painter.restore();
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(inColor);
    QRectF playrect=QRectF(55,32,X-63,6);
    painter.drawRoundedRect(playrect,3,3);
    painter.restore();
    painter.setPen(Qt::NoPen);
    painter.setBrush(outColor);
    painter.drawEllipse(X-7,25,20,20);
    painter.restore();
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(inColor);
    painter.drawEllipse(X,32,6,6);
    painter.restore();
}
void down_progressbarWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y()>30&&event->pos().y()<50)
    {
            int value;
            value=event->pos().x();
            if(value<55)
            {
                X=56;
            }
            else if(value>635)
            {
                X=620;
            }
            else
            {
                X=value;
            }
            if(X<=620)
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
void down_progressbarWidget::mouseMoveEvent(QMouseEvent *event)
{
        int value;
        value=event->pos().x();
        if(value<55)
        {
            X=56;
        }
        else if(value>635)
        {
            X=620;
        }
        else
        {
            X=event->pos().x();
        }
        if(X<=620)
        {
            emit changeX();
        }
       update();
       setCursor(Qt::PointingHandCursor);
}
void down_progressbarWidget::updatepos()
{
    float a;
    a=(float)positontime/(float)druntime;
    X=a*580+56;
    qint64 time=druntime;
    double secondDouble=time/1000;
    int minint=secondDouble/60;
    int secondint=secondDouble-minint*60;
    double secondtime1=positontime/1000;
    int minint1=secondtime1/60;
    int secondint1=secondtime1-minint1*60;
    t=QString("%0:%1").arg(QString::number(minint1),QString::number(secondint1));
    s=QString("%0:%1").arg(QString::number(minint),QString::number(secondint));
    rightLabel->setText(s);
    liftLabel->setText(t);
    update();
}
