#include "lrc_mainwindow.h"
/*目前无法寻找到歌词，而且网络模块还没就绪，只能空着。
歌词显示模块的控件部分已经写好，但解析部分还没有写好
解析部分的读取和显示已经在100.pro工程文件中写出了例子，但是
歌词时间与歌曲时间之间的通信部分还为就绪。据说网易云的API不能提供相应的歌词下载
加密的歌词无法解析----2016.12.25*/

lrc_mainwindow::lrc_mainwindow(QWidget *parent) : QMainWindow(parent)
{
    setGeometry(310,20,1300,100);
    setMaximumSize(1300,100);
    setMinimumSize(1300,100);
    lrcLabel=new QLabel(this);
    lrcLabel->setGeometry(0,0,1300,70);
    QPalette pal0;
    pal0.setColor(QPalette::WindowText,QColor(255,0,0));
    QFont font0("微软雅黑",25);
    lrcLabel->setFont(font0);
    lrcLabel->setPalette(pal0);
    lrcLabel->setText(tr("网易云音乐"));
    lrcLabel->setCursor(Qt::PointingHandCursor);
    lrcLabel->setAlignment(Qt::AlignCenter);
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    setAttribute(Qt::WA_TranslucentBackground,true);
}
void lrc_mainwindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_pressed=true;
        m_point=event->pos();
    }
}
void lrc_mainwindow::mouseMoveEvent(QMouseEvent *event)
{

    if(m_pressed)
    {
        move(event->pos()-m_point+pos());
    }
}
void lrc_mainwindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
     m_pressed=false;
}
