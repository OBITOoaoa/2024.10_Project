#include "steng.h"

//初始化云台设备
setEng::setEng()
{
    angfd = open(dev, O_RDWR);
    if(angfd < 0){
        qDebug() << "open steng dev fail";
    }
}

//设置云台初始角度
void setEng::backLrpos()
{
    angLR = 75;
    ioctl(angfd, angLR, TURN_LR_CTL);
}


void setEng::backUdpos()
{
    angUD = 67;
    ioctl(angfd, angUD, TURN_UD_CTL);
}


//控制左右偏转角度
void setEng::turnLeft()
{
    angLR--;
    if(angLR <= 25)
        angLR = 25;

    ioctl(angfd, angLR, TURN_LR_CTL);
}

void setEng::turnRight()
{
    angLR++;
    if(angLR >= 125)
        angLR = 125;

    ioctl(angfd, angLR, TURN_LR_CTL);
}

void setEng::setLrAngle(int angle)
{
    angLR = angle + 25;
    if(angLR <= 25)
        angLR = 25;
    if(angLR >= 125)
        angLR = 125;

    ioctl(angfd, angLR, TURN_LR_CTL);
}

int setEng::getLrAngle()
{
    return angLR - 25;
}

//控制上下偏转角度
void setEng::turnUp()
{
    angUD++;
    if(angUD >= 117)
        angUD = 117;

    ioctl(angfd, angUD, TURN_UD_CTL);
}

void setEng::turnDown()
{
    angUD--;
    if(angUD <= 17)
        angUD = 17;

    ioctl(angfd, angUD, TURN_UD_CTL);
}

void setEng::setUdAngle(int angle)
{
    angUD = angle + 17;
    if(angUD <= 17)
        angUD = 17;
    if(angUD >= 117)
        angUD = 117;

    ioctl(angfd, angUD, TURN_UD_CTL);
}

int setEng::getUdAngle()
{
    return angUD - 17;
}

void setEng::auto_turn(int angle)
{
    static bool increasing = true;
    if(increasing){
        angLR += angle;
        if(angLR >= 125){
            increasing = false;
            angLR = 125;
        }
    }
    else{
        angLR -= angle;
        if(angLR <= 0){
            increasing = true;
            angLR = 0;
        }
    }
    qDebug() << "angLR:" << angLR;
    ioctl(angfd, angLR, TURN_LR_CTL);
}



