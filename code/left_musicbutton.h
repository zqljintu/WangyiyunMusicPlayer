#ifndef LEFT_MUSICBUTTON_H
#define LEFT_MUSICBUTTON_H
#include <QPushButton>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QTimer>
#include <QFont>
#include <QPalette>
#include <QColor>


class left_musicButton : public QPushButton
{
    Q_OBJECT
public:
    explicit left_musicButton(QWidget *parent=0);
    QLabel *musiciconLabel;//歌曲封面
    QPixmap pix;
    QLabel *musictitleLabel;//歌曲名称
private:
    void paintEvent(QPaintEvent *event);
};

#endif // LEFT_MUSICBUTTON_H
