#include "seting_showmusiclistwidget.h"

seting_showmusiclistWidget::seting_showmusiclistWidget(QWidget *parent) : QWidget(parent)
{
    this->hide();
    file0.setFileName("filenamebase.txt");
    file0.open(QIODevice::WriteOnly|QIODevice::Append);
    file0.close();
    songlist=new QTableView(this);//添加音乐列表
   //  songlist->setFrameShape(QFrame::NoFrame);
    //songlist->setFocusPolicy(Qt::NoFocus);
    songlist->setGeometry(500,220,800,490);
    songlistmodel=new QStandardItemModel;
    musicplaylist=new QMediaPlaylist(this);
    songlistmodel->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("歌曲列表")));
    songlist->setModel(songlistmodel);
    songlist->verticalHeader()->hide();
    songlist->setColumnWidth(0,800);
    songlist->setEditTriggers(QAbstractItemView::NoEditTriggers);
    songlist->setSelectionBehavior(QAbstractItemView::SelectRows);
    songlist->setAlternatingRowColors(true);
    songlist->setStyleSheet("QTableView{background-color:rgb(102,111,117);alternate-background-color: rgb(150,164,163);border:0px;}\
                                            QTableView::item{border:none;padding-left:10px;padding-right:10px;border-bottom:0px;}\
                                            QHeaderView::section{background:rgb(60,66,66);border:0px;min-height:40px;}\
                                            QScrollBar:vertical{width:10px;background:transparent;padding-top:20px;padding-bottom:20px;}\
                                            QScrollBar::handle:vertical{width:10px;min-height:30px;background:rgba(68,69,73,25%);border-radius:5px;}\
                                            QScrollBar::sub-line:vertical{height:15px;background:transparent;subcontrol-position:top;}}\
                                            QScrollBar::add-line:vertical{height:15px;background:transparent;subcontrol-position:bottom;}}\
                                            QScrollBar::add-page:vertical{background:transparent}");
    setPushbutton();
}
void seting_showmusiclistWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor color(52,53,44);
    color.setAlphaF(0.8);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    QRectF rect=QRectF(500,200,800,530);
    painter.drawRoundedRect(rect,10,10);
    painter.restore();
}
void seting_showmusiclistWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().x()<500)
    {
        this->hide();
        setGeometry(0,0,0,0);
    }
    if((event->pos().y()>730)||(event->pos().y()<200))
    {
        this->hide();
        setGeometry(0,0,0,0);
    }
}
void seting_showmusiclistWidget::getmusicList()//绘制背景颜色边框
{
    path=QFileDialog::getOpenFileNames(this,"get Many","/","(*.mp3)");
    if(!path.isEmpty())
    {
        musicplaylist->clear();
        QString addSongs;
        QListIterator<QString>mylist(path);
        while(mylist.hasNext())//加载音乐列表
        {
            addSongs=mylist.next();
            QTextStream stream0(&file0);
            file0.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text);
            stream0<<addSongs;
            stream0<<"\n";
            file0.close();
        }
    }
    if(!file0.open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream stream2(&file0);
    int i=0;
    while(!stream2.atEnd())
    {
        QString line0;
        line0=stream2.readLine();
        QFileInfo fileinfo;
        fileinfo=QFileInfo(line0);
        QString filename=fileinfo.fileName();
        QString filepath=fileinfo.absoluteFilePath();
        songlistmodel->setItem(i,0,new QStandardItem(filename));
        musicplaylist->addMedia(QUrl::fromLocalFile(filepath));
        musicbaseList<<line0;
        i++;
    }
    file0.close();
}
void seting_showmusiclistWidget::setPushbutton()
{
    addButton=new QPushButton(this);
    deleteButon=new QPushButton(this);
    addButton->setGeometry(520,220,40,40);
    addButton->setStyleSheet("QPushButton{border-image:url(:/image/image/add.png)}\
                                                 QPushButton:pressed{background:rgb(0,20,20)}");
    addButton->setCursor(Qt::PointingHandCursor);
    deleteButon->setGeometry(1240,220,35,35);
    deleteButon->setStyleSheet("QPushButton{border-image:url(:/image/image/delete.png)}\
                                                    QPushButton:pressed{background:rgb(0,20,20)}");
    deleteButon->setCursor(Qt::PointingHandCursor);
}
void seting_showmusiclistWidget::updateMusiclist()
{
   if(!file0.open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream stream2(&file0);
    int i=0;
    while(!stream2.atEnd())
    {
        QString line0;
        line0=stream2.readLine();
        QFileInfo fileinfo;
        fileinfo=QFileInfo(line0);
        QString filename=fileinfo.fileName();
        QString filepath=fileinfo.absoluteFilePath();
        songlistmodel->setItem(i,0,new QStandardItem(filename));
        musicplaylist->addMedia(QUrl::fromLocalFile(filepath));
        musicbaseList<<line0;
        i++;
    }
    file0.close();
}










