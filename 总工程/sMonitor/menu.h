#ifndef MENU_H
#define MENU_H

#include <QWidget>

#include "fops.h"
#include "steng.h"

#include "mqtt/qmqtt.h"

#include <iostream>
#include <QTimer>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/face.hpp>

using namespace std;
using namespace cv;

//#define __x86
#define __arm


namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

    void face_tracking();

    void trackFace(int faceX, int faceY);

    QString scanVideoDevices();

    void addChineseWatermark(cv::Mat &frame);

    void addEnglishWatermark(cv::Mat &frame);

    void publishImage(QImage image, const QString &topic);

private slots:
    void on_swt_Control_bt_clicked();

    void on_file_Manage_bt_clicked();

    void on_turn_up_bt_pressed();

    void on_turn_left_bt_pressed();

    void on_turn_down_bt_pressed();

    void on_turn_right_bt_pressed();

    void on_turn_reset_bt_clicked();

    void on_auto_btn_clicked();

    void slot_autoTimer_timeout();

    void on_angle_slider_valueChanged(int value);

    void on_speed_slider_valueChanged(int value);

    void on_get_video_bt_clicked();

    void on_get_photo_bt_clicked();

    void on_capture_bt_clicked();

    void CaptureOpen();

    void slot_fpsTimer();

    void slot_updateCurrentTime();

    void Subclient_Hanlder();

    void DataRecvParse(QMQTT::Message);

    void on_mqtt_transfer_bt_clicked();

    void onThumbnailGenerated(int exitCode); // 声明槽函数

private:
    Ui::menu *ui;

    // yun ping tai
    bool swt_Control_flag = true;
    setEng sEng;
    QTimer *auto_timer;
    int speed;

    // video
    QTimer *capTimer;
    VideoCapture cap;
    Mat frame;
    QImage frame_to_qimage;

    VideoWriter videoWriter;
    bool isRecording = false;
    bool isFirstVideo = true;

    QString saveVideoFileName;
    QString thumbnailFilename;

    QTimer *fpsTimer;
    int fpsCount;

    // display time
    QTimer *currentTimer;

    // 目标检测
    CascadeClassifier cascade1, nestedCascade1;
    double scale1 = 3.0;

    double face_scaleFactor = 1.1;
    int face_minNeighbors = 3;

    bool isOpenEyesDetect = false;

    // mqtt
    QMQTT::Client* SUBclient;
    QString SubTopic,message;
    bool isVideoTransfer = false;



    QProcess *ffmpeg_process;
    void initValue();
};

#endif // MENU_H
