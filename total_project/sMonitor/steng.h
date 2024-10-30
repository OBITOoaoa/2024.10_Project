#ifndef ENG_H
#define ENG_H
#include <QObject>
#include <QTimer>
#include <QDebug>

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>


#define dev "/dev/sm_stENG"
#define TURN_LR_CTL 0x2
#define TURN_UD_CTL 0x3



class setEng : public QObject
{
    Q_OBJECT
public:
    setEng();
    void turnLeft();
    void turnRight();
    void setLrAngle(int ang);
    int getLrAngle();

    void turnUp();
    void turnDown();
    void setUdAngle(int ang);
    int getUdAngle();

    void backLrpos();
    void backUdpos();

    void auto_turn(int angle);


public slots:

private:
    int angLR;
    int angUD;
    int angfd;

};

#endif // ENG_H





























