#ifndef CENTER_TAGSHOW_H
#define CENTER_TAGSHOW_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QPalette>
#include <QRectF>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QtQuick/QQuickView>
#include <QtQuickWidgets/QQuickWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include <QListWidget>
#include <QListWidgetItem>
class center_tagshow : public QWidget
{
    Q_OBJECT
public:
    explicit center_tagshow(QWidget *parent = 0);
    QString text;//搜索歌曲名称
    void readJson(QString musicjson);//解析数据
    QListWidget *replysong;
    QLabel *imagelabel;

signals:

public slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // CENTER_TAGSHOW_H
