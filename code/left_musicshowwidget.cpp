#include "left_musicshowwidget.h"

left_musicshowWidget::left_musicshowWidget(QWidget *parent) : QWidget(parent)
{
    this->hide();
    pix2=QPixmap(":/image/image/music3.png");
    QPalette pal;
    color=QColor(30,30,40);
    color.setAlphaF(1);
    pal.setColor(QPalette::Background,color);
    setAutoFillBackground(true);
    setPalette(pal);
    show();
    lessButton=new QPushButton(this);
    lessButton->setGeometry(1220,20,30,30);
    lessButton->setStyleSheet("QPushButton{border:0px;border-image:url(:/image/image/less.png)}\
                                                 QPushButton:hover{background:rgb(100,100,100)}");
    connect(lessButton,SIGNAL(clicked(bool)),this,SLOT(changemusicWidget()));
    updateTimer=new QTimer(this);
    updateTimer->setInterval(25);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(updateheijiaopian()));
    updateTimer1=new QTimer(this);
    updateTimer1->setInterval(15);
    connect(updateTimer1,SIGNAL(timeout()),this,SLOT(updatechangegan()));

    musictitelLabel=new QLabel(this);
    musicerLabel=new QLabel(this);
    specialLabel=new QLabel(this);
    QPalette pal0;
    pal0.setColor(QPalette::WindowText,QColor(255,250,200));
    QFont font0("微软雅黑",20);
    QFont font1("微软雅黑",12);
    musictitelLabel->setFont(font0);
    musictitelLabel->setPalette(pal0);
    musicerLabel->setFont(font1);
    musicerLabel->setPalette(pal0);
    specialLabel->setFont(font1);
    specialLabel->setPalette(pal0);
    musictitelLabel->setText("网易云音乐");
    musictitelLabel->setGeometry(650,75,300,35);
    musicerLabel->setText("歌手");
    musicerLabel->setGeometry(650,130,80,25);
    musictitelLabel->show();
    specialLabel->setText("专辑");
    specialLabel->setGeometry(780,130,300,25);
    specialLabel->show();

}
void left_musicshowWidget::changemusicWidget()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(0,69,1300,661));
    animation->setEndValue(QRect(0,730,1300,0));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    if(!animation->duration())
    {
        this->hide();
    }
}
void left_musicshowWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();
    painter.drawPixmap(0,0,1300,661,pix2);
    painter.restore();
    painter.save();
    QRectF rect=QRectF(0,0,1300,661);
    QColor color1(30,30,40);
    color1.setAlphaF(0.9);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color1);
    painter.drawRect(rect);
    painter.restore();
    painter.save();
    QColor color(100,100,100);
    painter.translate(85,110);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.drawEllipse(-5,-5,400,400);
    painter.restore();
    QPixmap pix1;
    pix1.load(":/image/image/heijiaopian.png");
    painter.save();
    painter.translate(85,110);
    painter.translate(195,195);
    painter.rotate(i);
    painter.translate(-195,-195);
    painter.drawPixmap(0,0,390,390,pix1);
    painter.restore();
    QPixmap pix;
    pix.load(":/image/image/changegan.png");
    painter.save();
    painter.translate(30,-200);
    painter.translate(250,250);
    painter.rotate(j);
    painter.translate(-250,-250);
    painter.drawPixmap(0,0,500,500,pix);
    painter.restore();

}
void left_musicshowWidget::updateheijiaopian()
{
    i+=1;
    if(i>360)
    {
        i=0;
    }
    update();
}
void left_musicshowWidget::updatechangegan()
{
    j+=1;
    if(j>30)
    {
        updateTimer1->stop();
    }
    update();
}
void left_musicshowWidget::updatechangegan1()
{
    j=0;
    update();
}














