#include "center_tagshow.h"

center_tagshow::center_tagshow(QWidget *parent) : QWidget(parent)
{
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background,QColor(255,230,250));
    setAutoFillBackground(true);
    setPalette(pal);
    show();
    QPixmap pix;
    pix.load(":/image/image/mmmmm.jpg");
    imagelabel=new QLabel(this);
    imagelabel->setPixmap(pix);
    imagelabel->setGeometry(0,0,1050,661);

    /*QQuickWidget *m_quickWidget=new QQuickWidget(this);
    QUrl source("qrc:/image/tagQml.qml");
    m_quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView );
    m_quickWidget->setSource(source);
    m_quickWidget->setGeometry(0,0,360,360);
    m_quickWidget->show();
    replysong=new QListWidget(this);
    replysong->setGeometry(0,0,800,600);//能显示QML写的界面，但无法实现对鼠标操作的交互。放弃使用这种模式

    QByteArray byte_array;
    byte_array.append("tn=getinfo");
    byte_array.append("&ct=0");
    byte_array.append("&ie=utf-8");
    byte_array.append("&word=" + text);  //text指歌曲名称、歌手名称
    byte_array.append("&format=json");

    QString url="http://music.163.com/api/search/pc"+QString(byte_array);
    QNetworkAccessManager *network_manager=new QNetworkAccessManager();
    QNetworkRequest *network_request=new QNetworkRequest();

    connect(network_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    network_request->setUrl(QUrl(url));
    network_manager->get(network_request);*/
}
void center_tagshow::replyFinished(QNetworkReply *reply)
{
   /* QVariant status_code=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(reply->error()==QNetworkReply::NoError)
    {
        QByteArray bytes=reply->readAll();
        QString result(bytes);
        readJson(result);
    }
    else
    {
        return;
    }*/
}
void center_tagshow::readJson(QString musicjson)
{
    /*QByteArray byte_array;
    QJsonParseError json_error;
    QJsonDocument parseDocument=QJsonDocument::fromJson(byte_array.append(musicjson),&json_error);
    if(json_error==QJsonParseError::NoError)
    {
        if(parseDocument.isArray())
        {
            QJsonArray array=parseDocument.array();
            int size=array.size();
            for(int i=0;i<size;i++)
            {
                QJsonValue value=array.at[i];
                if(value.isObject());
                {
                    QJsonObject object=value.toObject();
                    if(object.contains("song"))
                    {
                        QJsonValue namevalue=object.take("song");
                        if(namevalue.isString())
                        {
                            QString name=namevalue.toString();
                            QString name2=name;
                            QListWidgetItem *list_item=new QListWidgetItem();
                            list_item->setText(name);
                            replysong->addItem(list_item);
                        }
                        if(so)
                    }
                }
            }
        }
    }*/
}









