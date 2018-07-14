#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QIODevice>
#include <QPoint>
#include <QEvent>
#include <QMouseEvent>
#include "qt_windows.h"
#include <QWindow>
#include <QPalette>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation>
#include <QCloseEvent>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QTableView>
#include <QStandardItemModel>
#include <QDir>
#include <QDirModel>
#include <QTimer>
#include <QDebug>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMap>
#include <QApplication>
#include "searchwidget.h"
#include "dowidget.h"
#include "qbjectwidget.h"
#include "qbject_showuserwidget.h"
#include "qbject_showmessagewidget.h"
#include "down_playwidget.h"
#include "down_progressbarwidget.h"
#include "down_voicewidget.h"
#include "down_setingwidget.h"
#include "seting_showmusiclistwidget.h"
#include "left_musicbutton.h"
#include "left_musicshowwidget.h"
#include "left_tablewidget.h"
#include "center_tagshow.h"
#include "lrc_mainwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool m_pressed;
    QPoint m_point;//可移动的点
    QWidget *topwidget;
    QWidget *downwidget;
    QWidget *redwidget;
    QWidget *leftwidget;
    searchwidget *searchWidget;
    dowidget *doWidgwt;//向前操作向后操作
    Qbjectwidget *objectWidget;//关闭等

    left_musicshowWidget *musicshowwidget;//音乐show
    qbject_showUserWidget *usershowWidget;//用户框
    qbject_showmessageWidget *messageshowWidget;//信息框
    seting_showmusiclistWidget *musiclistshowWidget;//列表框
    left_tablewidget *lefttableWidget;//推荐框

    down_playWidget *downplaywidget;//播放框
    down_progressbarWidget *progressbarWidget;//进度条
    down_voicewidget *voicebarWidget;//音量条
    down_setingWidget *downsetingWidget;//控制

    center_tagshow *musictagshowWidget;//音乐tag展示

    left_musicButton *musicbigerButton;//音乐展示
    QTimer *timer4;//刷新

    QLabel *wangyi_labe;

    QSystemTrayIcon *trayIcon;//迷你模式
    QMenu *menu;//托盘菜单
    QAction *showMainAction;//显示界面
    QAction *closeMainAction;//关闭程序

    lrc_mainwindow *lrcshowwidget;//歌词显示框

private:
    void closeEvent(QCloseEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);//设置窗体可移动
    void paintEvent(QPaintEvent *event);//从新绘制界面
    void settopWidget(QWidget* widget);//绘制上方界面
    void setdownWidget(QWidget* widget);//绘制下方界面
    void setleftWidget(QWidget* widget);//绘制左方界面
    void settoplightIcon(QLabel *label,QPixmap pix);//绘制icon
    void setSearchEdit(QWidget *widget);//绘制搜索框
    void setredWidget(QWidget *widget);//绘制红色线条
    int T;//控

private slots:
    void closeMainwindow();//关闭程序
    void minMainwindow();//最小化程序
    void showUserWidget();//显示用户信息
    void showMessageWidget();//显示信息
    void showMusiclistWidget();//显示播放列表
    void showMusicWidget();//显示播放界面
    void updatemusicWidget();//更新播放进度条
    void doubleclcklistwidget(QModelIndex  index);//双击列表播放歌曲
    void getTableWidgetItem(QTableWidgetItem *item);
    void removeItemMusic();//移除选中歌曲
    void getMusictime();//获取歌曲播放时长
    void playnextmusic();//播放下一首歌曲
    void playbeforemusic();//播放上一首歌曲
    void updatemusicbutton(int n);//更新播放按钮
    void updatemusiicon();//更新歌曲图标
    void changevoice();//声音改变
    void closevoice();//关闭声音
    void begainMinistyle();//迷你到托盘
    void changeMusicposition();//改变音乐播放时态。kao....大长腿啊。。。。挣扎ing
    void creativeTrayivon(QSystemTrayIcon::ActivationReason reason);//小菜单的显示
    void showLrcMainwidget();//歌词显示框

};

#endif // MAINWINDOW_H
