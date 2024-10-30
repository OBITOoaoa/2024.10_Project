#include "menu.h"
#include "ui_menu.h"

#include <QDateTime>
#include <QPainter>

#include <QDir>
#include <QProcess>
#include <QStringList>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QBuffer>

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

    this->initValue();
}

menu::~menu()
{
    delete ui;
}

void menu::initValue()
{
    this->setWindowTitle("安防管理系统-控制"); // 设置窗口标题

    // ui界面设置
    QPixmap pixmap(":/images/menu1.jpg");
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    ui->ctl_Panel_sw->setCurrentIndex(0);
    ui->get_photo_bt->setEnabled(false);
    ui->get_video_bt->setEnabled(false);

    // display time
    currentTimer = new QTimer(this);
    connect(currentTimer, SIGNAL(timeout()), this, SLOT(slot_updateCurrentTime()));
    currentTimer->start(1000);

    //调整初始化角度
    sEng.backLrpos();
    sEng.backUdpos();

    ui->angle_slider->setMaximum(100);
    ui->angle_slider->setMinimum(0);
    ui->angle_slider->setValue(0);

    ui->speed_slider->setMaximum(270);
    ui->speed_slider->setMinimum(0);
    ui->speed_slider->setValue(0);

    // timer
    auto_timer = new QTimer();
    connect(auto_timer, SIGNAL(timeout()), this, SLOT(slot_autoTimer_timeout()));
    speed = 100;

    // video
    capTimer = new QTimer(this);
    connect(capTimer, SIGNAL(timeout()), this, SLOT(CaptureOpen()));

    // cal fps
    fpsTimer = new QTimer(this);
    connect(fpsTimer, SIGNAL(timeout()), this, SLOT(slot_fpsTimer()));
    fpsCount = 0;
    fpsTimer->start(1000);

#ifdef __x86
    if(!cap.open(0)){
        qDebug() << "open camera error";
    }
#else
    if(!cap.open("/dev/video0")){
        qDebug() << "open camera error";
    }
//    if(!cap.open(video_path.toStdString())){
//        qDebug() << "open camera error";
//    }
#endif

    // 设置捕获视频的分辨率
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640); // 设置宽度为640像素
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480); // 设置高度为480像素

    // 检查是否设置成功
    double width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    double height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "Frame Width: " << width << ", Frame Height: " << height << std::endl;

    // 添加分类器
    cascade1.load("./haarcascade_frontalface_alt.xml");
    nestedCascade1.load("./haarcascade_eye_tree_eyeglasses.xml");

    // mqtt
    SUBclient = new QMQTT::Client;

    // 设置ip和端口
    SUBclient->setHostName("172.20.10.3");
    SUBclient->setPort(1883);

    connect(SUBclient,SIGNAL(connected()),this,SLOT(Subclient_Hanlder()));

    SUBclient->connectToHost();
}

void menu::on_swt_Control_bt_clicked()
{
    if(swt_Control_flag){
        swt_Control_flag = false;
        ui->swt_Control_bt->setText("切换手动");
        ui->ctl_Panel_sw->setCurrentIndex(1);
    }
    else{
        swt_Control_flag = true;
        ui->swt_Control_bt->setText("切换自动");
        ui->ctl_Panel_sw->setCurrentIndex(0);
    }
}

void menu::on_file_Manage_bt_clicked()
{
    fops* fo = new fops();
    fo->show();
    this->hide();
    //currentTimer->stop();
}

void menu::on_turn_up_bt_pressed()
{
    qDebug() << "turn up --->";
    sEng.turnUp();
}

void menu::on_turn_left_bt_pressed()
{
    qDebug() << "turn left --->";
    sEng.turnLeft();
}

void menu::on_turn_down_bt_pressed()
{
    qDebug() << "turn down --->";
    sEng.turnDown();
}

void menu::on_turn_right_bt_pressed()
{
    qDebug() << "turn right --->";
    sEng.turnRight();
}

void menu::on_turn_reset_bt_clicked()
{
    sEng.backLrpos();
    sEng.backUdpos();
}

void menu::slot_autoTimer_timeout()
{
    sEng.auto_turn(1);
}

void menu::on_auto_btn_clicked()
{
    if(ui->auto_btn->text() == "自动旋转"){
        ui->auto_btn->setText("暂停");
        auto_timer->start(300 - speed);
    }
    else if(ui->auto_btn->text() == "暂停"){
        ui->auto_btn->setText("自动旋转");
        auto_timer->stop();
    }
}

void menu::on_angle_slider_valueChanged(int value)
{
    qDebug() << "angle value:" << value;

    sEng.setLrAngle(value);
}

void menu::on_speed_slider_valueChanged(int value)
{
    qDebug() << "speed value:" << value;
    speed = value;

    auto_timer->stop();
    auto_timer->start(300 - speed);
}

void menu::CaptureOpen()
{
//    double start_t, end_t;
//    start_t = (double)cvGetTickCount();

    cap >> frame;
    if(!frame.empty()){

        // 目标检测
        face_tracking();     // 320 240 or 640 480
        //cv::resize(frame, frame, Size(640, 480));

        // 添加中文水印
        //addChineseWatermark(frame);

        // 添加英文水印
        addEnglishWatermark(frame); // frame to qImage

        Mat frameRGB;
        cvtColor(frame, frameRGB, CV_BGR2RGB);
        frame_to_qimage = QImage((const unsigned char *)(frameRGB.data), frameRGB.cols, frameRGB.rows, frameRGB.step, QImage::Format_RGB888);

        // 显示图像
        ui->ctl_Frame_sw->setPixmap(QPixmap::fromImage(frame_to_qimage));
        ui->ctl_Frame_sw->resize(frame_to_qimage.size());
        ui->ctl_Frame_sw->show();

        // 开启mqtt图传
        if(isVideoTransfer){
            // mqtt图传
            QString topic = "/VIDEO";
            publishImage(frame_to_qimage, topic);
        }

        // 开启录制
        if(isRecording){
            qDebug() << "isRecording";
            // 次数可以调整视频的帧数
            videoWriter.write(frame);
            videoWriter.write(frame);
            //videoWriter.write(frame);
        }

        // fps
        ++fpsCount;

//        end_t = (double)cvGetTickCount();
//        cout << "show photo time:" << (end_t - start_t)*1000/(getTickFrequency()) << "ms" <<endl;
//        ui->fps_lb->setText("fps:" + QString::number(1000.0 / ((end_t - start_t)*1000/(getTickFrequency()))));
    }
}

void menu::slot_fpsTimer()
{
    if(fpsCount != 0){
        qDebug() << "fps:" << fpsCount;
        ui->fps_lbl->setText("FPS:" + QString::number(fpsCount));
        fpsCount = 0;
    }
}

void menu::on_get_video_bt_clicked()
{
    qDebug() << "take video";

    if(!isRecording){
            // 获取当前时间并格式化为字符串
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString dateTimeString = currentDateTime.toString("yyyyMMdd_hhmmss");

            // 生成文件名
            saveVideoFileName = "video/video_" + dateTimeString + ".avi";
            thumbnailFilename = "video/photo/video_" + dateTimeString + ".jpg";

            std::string filename = saveVideoFileName.toStdString();
            videoWriter.open(filename, CV_FOURCC('M','J','P','G'), 10, frame.size());

            // 取第一帧作为缩略图
//            QString firstFrame = "video/photo/video_" + dateTimeString + ".jpg";
//            QImage image = ui->ctl_Frame_sw->pixmap()->toImage();
//            image.save(firstFrame);

            isRecording = true;
            ui->get_video_bt->setStyleSheet("border-image: url(:/images/recording.png);");
    }
    else if(isRecording) {
            videoWriter.release();
            isRecording = false;
            ui->get_video_bt->setStyleSheet("border-image: url(:/images/capture.png);");
            // 使用 FFmpeg 获取第一帧作为缩略图
            ffmpeg_process = new QProcess(this);
            ffmpeg_process->start("ffmpeg", QStringList() << "-i" << saveVideoFileName << "-ss" << "00:00:00"
                                                     << "-vframes" << "1" << "-s" << "200x160" << "-y" << thumbnailFilename);
            connect(ffmpeg_process, SIGNAL(finished(int)), this, SLOT(onThumbnailGenerated(int)));
    }
}

void menu::onThumbnailGenerated(int exitCode)
{
    if (exitCode == 0) {
       qDebug() << "Thumbnail created successfully";
    } else {
       qDebug() << "Failed to create thumbnail";
    }
    ffmpeg_process->deleteLater();
}

void menu::on_get_photo_bt_clicked()
{
    qDebug() << "take photo";

    // 获取当前时间并格式化为字符串
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyyMMdd_hhmmss");

    // 生成文件名
    QString filename = "photo/screenshot_" + dateTimeString + ".jpg";

    QImage image = ui->ctl_Frame_sw->pixmap()->toImage();
    image.save(filename);
}

void menu::on_capture_bt_clicked()
{
    if(ui->capture_bt->text() == "开始"){
        ui->capture_bt->setText("捕获中");
        capTimer->start(30);

        ui->get_photo_bt->setEnabled(true);
        ui->get_video_bt->setEnabled(true);
    }
    else if(ui->capture_bt->text() == "捕获中"){
        ui->capture_bt->setText("开始");
        capTimer->stop();
        ui->get_photo_bt->setEnabled(false);
        ui->get_video_bt->setEnabled(false);
    }
}

void menu::slot_updateCurrentTime()
{
    //qDebug() << "1";
    QDateTime time = QDateTime::currentDateTime();//获取当前日期和时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");//格式为年-月-日 小时-分钟-秒 星期
    ui->currentTime_lb->setText(str);
    ui->currentTime_lb->setStyleSheet("color:white");
    ui->currentTime_lb->setAlignment(Qt::AlignRight);
}

void menu::addChineseWatermark(cv::Mat &frame)
{
    // 获取当前时间并格式化为字符串
    QDateTime currentDateTime = QDateTime::currentDateTime();
    // 将星期转换为中文
    QString weekString = currentDateTime.toString("dddd");
    QString chineseWeek[7] = {"星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期日"};
    // 星期的中文映射
    QMap<QString, QString> chineseWeekMap;
    chineseWeekMap["Monday"] = "星期一";
    chineseWeekMap["Tuesday"] = "星期二";
    chineseWeekMap["Wednesday"] = "星期三";
    chineseWeekMap["Thursday"] = "星期四";
    chineseWeekMap["Friday"] = "星期五";
    chineseWeekMap["Saturday"] = "星期六";
    chineseWeekMap["Sunday"] = "星期日";

    // 将英文缩写转换为中文
    QString chineseWeekString = chineseWeekMap.value(weekString);

    // 完整的时间字符串，包括中文星期
    QString dateTimeString = chineseWeekString + currentDateTime.toString(" yyyy-MM-dd HH:mm:ss");

    // 将cv::Mat转换为QImage
    Mat tmpFrame;
    cvtColor(frame, tmpFrame, CV_BGR2RGB);
    QImage image((const uchar*) tmpFrame.data, tmpFrame.cols, tmpFrame.rows, tmpFrame.step, QImage::Format_RGB888);
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);

    // 设置字体和颜色
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(15);
    painter.setFont(font);
    painter.setPen(QColor(255, 0, 0)); // 设置字体颜色为红色

    // 绘制中文时间水印
    QRect rect = painter.boundingRect(0, 0, tmpFrame.cols, tmpFrame.rows, Qt::TextWordWrap, dateTimeString);
    painter.drawText(rect, Qt::AlignTop | Qt::AlignLeft, dateTimeString);

    // 将QImage转回cv::Mat error????
//    frame = cv::Mat(image.height(), image.width(), CV_8UC3, const_cast<uchar*>(image.constBits()), image.bytesPerLine());
//    cvtColor(frame, frame, CV_RGB2BGR);

    ui->ctl_Frame_sw->setPixmap(QPixmap::fromImage(image));
    ui->ctl_Frame_sw->resize(image.size());
    ui->ctl_Frame_sw->show();
}

void menu::addEnglishWatermark(cv::Mat &frame)
{
    // 获取当前时间并格式化为字符串
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd HH:mm:ss dddd");
    // 画面添加时间戳
    putText(frame, dateTimeString.toStdString(), Point(20, 50), FONT_HERSHEY_COMPLEX, 1, // font face and scale
               Scalar(242, 130, 21), 1, LINE_AA); // line thickness and type
//    Mat frameRGB;
//    cvtColor(frame, frameRGB, CV_BGR2RGB);

//    frame_to_qimage = QImage((const unsigned char *)(frameRGB.data), frameRGB.cols, frameRGB.rows, frameRGB.step, QImage::Format_RGB888);

//    ui->ctl_Frame_sw->setPixmap(QPixmap::fromImage(frame_to_qimage));
//    ui->ctl_Frame_sw->resize(frame_to_qimage.size());
//    ui->ctl_Frame_sw->show();
}

QString menu::scanVideoDevices()
{
    QDir dir("/dev");
    const QStringList filters; // 不使用过滤条件
    const QStringList files = dir.entryList(QDir::System | QDir::AllEntries, QDir::Name);

    qDebug() << "file:" << files.size();
    foreach (const QString &fileName, files) {

        // 检查文件名是否以"video"开头，并且后面跟着数字
        if (fileName.startsWith("video") && fileName.length() > 5) {
            qDebug() << "fileName:" << fileName;

            bool isNumber;
            int number = fileName.mid(5).toInt(&isNumber); // 尝试将文件名中"video"后的字符转换为整数
            if (isNumber) {
                QString devicePath = "/dev/" + fileName;
                qDebug() << "Checking video device:" << devicePath;

                // 使用QProcess执行cat命令来检查设备是否有输出
                QProcess process;
                process.start("cat", QStringList() << devicePath);
                if (process.waitForFinished() && !process.exitStatus()) {
                    QByteArray output = process.readAllStandardOutput();
                    if (!output.isEmpty()) {
                        qDebug() << "Device" << devicePath << "is usable.";
                        process.close();
                        return devicePath;
                    } else {
                        qDebug() << "Device" << devicePath << "has no output.";
                    }
                } else {
                    qDebug() << "Failed to execute cat command on" << devicePath;
                }
            }
        }
    }
}

void menu::face_tracking()
{
//    double t = 0;
//    t = (double)cvGetTickCount();
    vector<Rect> faces;
    const static Scalar colors[] = {
        CV_RGB(0, 0, 255), CV_RGB(0, 128, 255),
        CV_RGB(0, 255, 255), CV_RGB(0, 255, 0),
        CV_RGB(255, 128, 0), CV_RGB(255, 255, 0),
        CV_RGB(255, 0, 0), CV_RGB(255, 0, 255)
    };

    // 缩小图像
    Mat gray1, smallImg(frame.rows/(int)scale1, frame.cols/(int)scale1, CV_8UC1);
    cvtColor(frame, gray1, CV_BGR2GRAY);
    cv::resize(gray1, smallImg, Size(frame.cols/(int)scale1, frame.rows/(int)scale1));

    // 直方图均衡化，以提高图像的对比度。
    equalizeHist(smallImg, smallImg);

    // 尺度因子（scaleFactor）：减少这个值可以提高检测的灵敏度，但会增加误检率和处理时间。
    // 最小领域个数（minNeighbors）：减少这个值可以提高灵敏度，但同样会增加误检率。
    // 最小检测窗口的大小（minSize）：减小这个值可以提高检测小目标的灵敏度。

    cascade1.detectMultiScale(smallImg, faces,
                              face_scaleFactor,  // 尺度因子
                              face_minNeighbors,    //  最小领域个数
                              0,
                              Size(30, 30));    //  表示最小检测窗口的大小


    // 人脸的宽高比，如果宽高比在0.75到1.3之间，则认为是一个有效的人脸。
    for(vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++){
        static Point center;
        int radius;

        double aspect_ratio = (double)r->width / r->height;
        if(aspect_ratio > 0.75 && aspect_ratio < 1.3){
            center.x = cvRound((r->x + r->width * 0.5) * scale1);
            center.y = cvRound((r->y + r->height * 0.5) * scale1);
            radius = cvRound((r->width + r->height) * 0.25 * scale1);

            // 测距安防
            qDebug() << "radius:" << radius;
            if(radius > 120){
                ui->get_photo_bt->click(); // 自动拍照
                if(isFirstVideo){
                    qDebug() << "first";
                    ui->get_video_bt->click();    // 自动录像
                    isFirstVideo = false;
                }
            }
            else{
                if(!isFirstVideo){
                    ui->get_video_bt->click();
                    isFirstVideo = true;
                }
            }

            circle(frame, center, radius, Scalar(0, 0, 255), 2, 8);

            // 检测人脸中心位置并控制摄像头移动
            trackFace(center.x, center.y);  // 根据人脸中心位置调整摄像头

            if(isOpenEyesDetect){
                // 人脸区域:检测到人脸再检测眼睛
                Mat faceROI = smallImg(*r);
                vector<Rect> eyes;
                // 眼睛检测，调整灵敏度
                if (!nestedCascade1.empty()) {
                   nestedCascade1.detectMultiScale(faceROI, eyes, 1.05, 2, 0 | CASCADE_SCALE_IMAGE, Size(10, 10)); // 1.05 2
                   for (size_t j = 0; j < eyes.size(); j++) {
                       Rect eye = eyes[j];
                       Point eye_center(cvRound((r->x + eye.x + eye.width * 0.5) * scale1),
                                        cvRound((r->y + eye.y + eye.height * 0.5) * scale1));
                       int eye_radius = cvRound((eye.width + eye.height) * 0.25 * scale1);
                       circle(frame, eye_center, eye_radius, Scalar(0, 255, 0), 2, 8);
                   }
                }
            }
        }
        else
            cout << "no face" << endl;
    }

//    cv::resize(frame, frame, Size(640, 480));
//    t = (double)cvGetTickCount() - t;
//    cout << "time:" << t*1000/(getTickFrequency()) << "ms" <<endl;
}

void menu::trackFace(int faceX, int faceY)
{
    // 计算人脸中心与图像中心的偏移量
       int frameCenterX = frame.cols / 2;
       int frameCenterY = frame.rows / 2;
       int offsetX = faceX - frameCenterX;
       int offsetY = faceY - frameCenterY;

       // 如果人脸偏移量大于某个阈值，就调整摄像头
       int threshold = 20;

       if (offsetX > threshold) {
           // 人脸在图像右侧，向左移动摄像头
           qDebug() << "Move camera left";
           sEng.turnLeft();
       } else if (offsetX < -threshold) {
           // 人脸在图像左侧，向右移动摄像头
           qDebug() << "Move camera right";
           sEng.turnRight();
       }

       if (offsetY > threshold) {
           // 人脸在图像下方，向上移动摄像头
           qDebug() << "Move camera up";
           sEng.turnUp();
       } else if (offsetY < -threshold) {
           // 人脸在图像上方，向下移动摄像头
           qDebug() << "Move camera down";
           sEng.turnDown();
       }
}

void menu::Subclient_Hanlder()
{

    qDebug()<<"connect MQTT server success,begin to subscribe."<<endl;

    SubTopic = "/PTZCTL";
    SUBclient->subscribe(SubTopic);
    SUBclient->setKeepAlive(30);

    qDebug()<<"subscribe /PTZCTL."<<endl;

    connect(SUBclient,SIGNAL(received(QMQTT::Message)),this,SLOT(DataRecvParse(QMQTT::Message)));
}

void menu::DataRecvParse(QMQTT::Message recv_mes)
{
    qDebug()<<"receive data...";
    QString mes = recv_mes.payload();
    qDebug()<<mes.toUtf8()<<endl;

    // 解析消息
    QJsonDocument doc = QJsonDocument::fromJson(mes.toUtf8());
    if (!doc.isNull()) {
        QJsonObject obj = doc.object();
        QJsonValue cmdValue = obj.value("cmd");
        if (!cmdValue.isUndefined()) {
            QJsonDocument cmdDoc = QJsonDocument::fromJson(cmdValue.toString().toUtf8());
            QJsonObject cmdObj = cmdDoc.object();

            // 根据接收到的命令执行操作
            if (cmdObj.contains("PTZ_UP") && cmdObj.value("PTZ_UP").toString() == "MOVE") {
                qDebug() << "turn up.";
                sEng.turnUp();
            } else if (cmdObj.contains("PTZ_DOWN") && cmdObj.value("PTZ_DOWN").toString() == "MOVE") {
                qDebug() << "turn down.";
                sEng.turnDown();
            } else if (cmdObj.contains("PTZ_LEFT") && cmdObj.value("PTZ_LEFT").toString() == "MOVE") {
                qDebug() << "turn left.";
                sEng.turnLeft();
            } else if (cmdObj.contains("PTZ_RIGHT") && cmdObj.value("PTZ_RIGHT").toString() == "MOVE") {
                qDebug() << "turn right.";
                sEng.turnRight();
            } else if (cmdObj.contains("PTZ_RESET") && cmdObj.value("PTZ_RESET").toString() == "MOVE"){
                qDebug() << "reset..";
                sEng.backLrpos();
                sEng.backUdpos();
            }
        }
    }
}

void menu::publishImage(QImage image, const QString &topic)
{
    // qImage to QByteArray
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);//pixmap不能为空，必须先将图片加载到pixmap中
    image.save(&buffer,"jpg");
    QByteArray pixArray;
    pixArray.append(buffer.data());

    quint16 messageID = 1; // 消息ID，可以根据需要生成
    QMQTT::Message message(messageID, topic, pixArray);

    SUBclient->publish(message);

    qDebug() << "publish";
}

void menu::on_mqtt_transfer_bt_clicked()
{
    isVideoTransfer = !isVideoTransfer;
    if(isVideoTransfer){
        ui->mqtt_transfer_bt->setText("图传中");
    }
    else{
        ui->mqtt_transfer_bt->setText("图传");
    }
}
