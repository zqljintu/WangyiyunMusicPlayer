#include "down_setingwidget.h"


down_setingWidget::down_setingWidget(QWidget *parent) : QWidget(parent)
{
    patternCombox=new QComboBox(this);
    patternCombox->setGeometry(0,18,50,32);
    patternCombox->setToolTip(QString("播放模式"));
    patternCombox->setCursor(Qt::PointingHandCursor);
    QIcon icon1(":/image/image/comboxitem1.png");
    QIcon icon2(":/image/image/comboxitem2.png");
    QIcon icon3(":/image/image/comboxitem3.png");
    patternCombox->addItem(icon1,"");
    patternCombox->addItem(icon2,"");
    patternCombox->addItem(icon3,"");
    patternCombox->setStyleSheet("QComboBox{background:rgb(50,50,50);border:0px;}\
                                 QComboBox::drop-down{border:0px;}\
                                 QComboBox QAbstractItemView{height:25px;background:rgb(50,50,50);border:0px;}");
    musicwordButton=new QPushButton(this);
    musicwordButton->setCheckable(true);
    musicwordButton->setChecked(false);
    musicwordButton->setGeometry(60,19,32,32);
    musicwordButton->setToolTip(QString("打开歌词"));
    musicwordButton->setCursor(Qt::PointingHandCursor);
    musicwordButton->setStyleSheet("QPushButton:checked{image:url(:/image/image/music_word.png);background:rgb(100,100,100);border:0px}\
                                QPushButton:!checked{image:url(:/image/image/music_word.png);background:rgb(50,50,50);border:0px}");
    musiclistButton=new QPushButton(this);
    musiclistButton->setGeometry(122,22,25,25);
    musiclistButton->setCursor(Qt::PointingHandCursor);
    musiclistButton->setToolTip(QString("打开播放列表"));
    musiclistButton->setStyleSheet("QPushButton{border:0px;border-image:url(:/image/image/list_normal.png)}\
                                QPushButton:hover{border-image:url(:/image/image/list_pressed.png)}");
}
void down_setingWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor color(0,20,20);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    QRectF rect=QRectF(110,19,50,32);
    painter.drawRoundedRect(rect,16,16);
    painter.restore();

}

















