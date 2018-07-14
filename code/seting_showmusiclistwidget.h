#ifndef SETING_SHOWMUSICLISTWIDGET_H
#define SETING_SHOWMUSICLISTWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QStandardItemModel>
#include <QTableView>
#include <QStringListIterator>
#include <QFileDialog>
#include <QDir>
#include <QDirModel>
#include <QMediaPlaylist>
#include <QHeaderView>
#include <QPushButton>
#include <QSqlQuery>
#include <QFile>
#include <QIODevice>

class seting_showmusiclistWidget : public QWidget
{
    Q_OBJECT
public:
    explicit seting_showmusiclistWidget(QWidget *parent = 0);
    QStandardItemModel *songlistmodel;
    QStringList path;//文件目录
    QTableView *songlist;//播放表格
   QMediaPlaylist *musicplaylist;//媒体播放列表
    QPushButton *addButton;//添加
    QPushButton *deleteButon;//删除
    void setPushbutton();//设置按钮
    QFile file0;//播放路径
    void updateMusiclist();
    QStringList musicbaseList;//播放路径的Stringlist


private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:


public slots:
    void getmusicList();


};

#endif // SETING_SHOWMUSICLISTWIDGET_H
