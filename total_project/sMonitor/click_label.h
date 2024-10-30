#ifndef CLICK_LABLE_H
#define CLICK_LABLE_H


#include <QLabel>
#include <QEvent>
class click_label : public QLabel
{
    Q_OBJECT
public:
        explicit click_label(QWidget *parent=0);

        bool eventFilter(QObject *obj, QEvent *event);

protected:
    /*!
      由Qt自己调用的鼠标事件处理函数,在此发射clicked信号
    */
    virtual void mouseReleaseEvent(QMouseEvent * ev);
      void mouseDoubleClickEvent(QMouseEvent *event);


signals:
    void  hover(void);
    void  clicked(void);
    void  leave(void);
    void  doubleclicked(void);


};

#endif // CLICK_LABLE_H
