#ifndef NO_FOCUS_DELEGATE_H
#define NO_FOCUS_DELEGATE_H
#include <QFocusFrame>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QStyle>
#include <QStyledItemDelegate>

class no_focus_delegate
{
public:
    no_focus_delegate();
    void NoFocusDelegate::paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const;
};

#endif // NO_FOCUS_DELEGATE_H
