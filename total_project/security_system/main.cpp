#include "systemserver.h"
#include <QApplication>

#include <login.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    SystemServer w;
//    w.show();

    Login l;
    l.show();


    return a.exec();
}
