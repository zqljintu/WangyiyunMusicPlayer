#include "no_focus_delegate.h"

no_focus_delegate::no_focus_delegate()
{

}
void no_focus_delegate::NoFocusDelegate::paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const
  {
     QStyleOptionViewItem itemOption(option);
     if (itemOption.state & QStyle::State_HasFocus)
     {
        itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
     }
     QStyledItemDelegate::paint(painter, itemOption, index);
  }
