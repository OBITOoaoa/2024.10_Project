#include "menu.h"
#include <QApplication>
#include <login.h>

int main(int argc, char *argv[])
{
    // 软键盘
    qputenv("QT_IM_MODULE", QByteArray("tgtsml"));

    QApplication a(argc, argv);
//    menu w;
//    w.show();

    Login l;
    l.show();

    return a.exec();
}
