#include "click_label.h"

click_label::click_label(QWidget *parent):

    QLabel(parent)
{

    installEventFilter(this); // 安装事件过滤器

}


void click_label::mouseReleaseEvent(QMouseEvent * ev)
{

    Q_UNUSED(ev)
    emit clicked();

}

void click_label::mouseDoubleClickEvent(QMouseEvent *event){
    Q_UNUSED(event)
    emit doubleclicked();
}


bool click_label::eventFilter(QObject *obj, QEvent *event)
   {
       if (obj == this)
       {
           if (event->type() == QEvent::Enter)
           {
                emit hover();

           }
           else if (event->type() == QEvent::Leave)
           {
                emit leave();

           }
       }

      return QLabel::eventFilter(obj, event);
   }





