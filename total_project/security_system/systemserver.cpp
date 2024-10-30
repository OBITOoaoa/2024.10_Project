#include "systemserver.h"
#include "ui_systemserver.h"
#include <QDebug>
#include <QDir>

#include <QBuffer>
#include <QImageReader>

SystemServer::SystemServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemServer)
{
    ui->setupUi(this);

    this->setWindowTitle("安防管理系统"); // 设置窗口标题


    this->initValue();
}

SystemServer::~SystemServer()
{
    delete ui;
}

void SystemServer::initValue()
{
    picPath.clear();
    vidPath.clear();
    pvPath.clear();

    // 设置窗口尺寸
    font.setPointSize(12);
    IMAGE_SIZE.setWidth(240);
    IMAGE_SIZE.setHeight(200);
    ITEM_SIZE.setWidth(240);
    ITEM_SIZE.setHeight(225);

    // 图片列表基本设置
    ui->picWidget->setIconSize(IMAGE_SIZE);
    ui->picWidget->clear();

    ui->picWidget->setResizeMode(QListView::Adjust);
    ui->picWidget->setViewMode(QListView::IconMode);
    ui->picWidget->setMovement(QListView::Static);
    //ui->picWidget->setMovement(QListView::Free);

    ui->picWidget->setSpacing(5);
    ui->picWidget->clear();
    ui->picWidget->setStyleSheet(
        "QListWidget::Item{padding-top:1px; }"
        "QListWidget::Item:hover{background:skyblue; }"
        "QListWidget::item:selected{background:rgb(0, 24, 58); color:white;}"
        "QListWidget{background:rgba(0, 33, 68,200); }"
    );

    // 视频列表基本设置
    ui->vidWidget->setIconSize(IMAGE_SIZE);
    ui->vidWidget->clear();

    ui->vidWidget->setResizeMode(QListView::Adjust);
    ui->vidWidget->setViewMode(QListView::IconMode);
    ui->vidWidget->setMovement(QListView::Static);
    //ui->vidWidget->setMovement(QListView::Free);

    ui->vidWidget->setSpacing(5);
    ui->vidWidget->clear();
    ui->vidWidget->setStyleSheet(
        "QListWidget::Item{padding-top:1px; }"
        "QListWidget::Item:hover{background:skyblue; }"
        "QListWidget::item:selected{background:rgb(0, 24, 58); color:white;}"
        "QListWidget{background:rgba(0, 33, 68,200);}"
    );

    updatePicData("./photo");
    updataVidData("./video/photo", "./video");
    ui->vidWidget->show();
    ui->picWidget->hide();

    // 双击图片放大图示
    connect(ui->picWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,
            SLOT(slot_itemClicked(QListWidgetItem*)));

    // 双击视频图标播放
    connect(ui->vidWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,
            SLOT(slot_itemClicked(QListWidgetItem*)));

    msg = new fullShow(this);
    connect(msg, SIGNAL(requestReturnToFileIndex()), this, SLOT(slot_onReturnToFileIndexRequested()));


    which_widget_index = 0; // vidWidget

    // mqtt
    SUBclient = new QMQTT::Client;

    // 设置ip和端口
    SUBclient->setHostName("172.20.10.3");
    //SUBclient->setHostName("192.168.1.128");
    SUBclient->setPort(1883);

    connect(SUBclient,SIGNAL(connected()),this,SLOT(Subclient_Hanlder()));

    SUBclient->connectToHost();
}


void SystemServer::on_monitor_lbl_hover()
{
    qDebug() << "hover";
    // ...

    ui->monitor_lbl->setStyleSheet("border-width:0px 0px 3px 0px;   \
                                   border-style: solid;             \
                                   border-color: rgb(36, 144, 243); \
                                   padding-bottom: 0px;             \
                                   color: rgb(36, 144, 243) ");
    //

}

void SystemServer::on_monitor_lbl_leave()
{
    qDebug() << "leave";
    // ...

    //ui->monitor_lbl->setStyleSheet("background-color: rgb(164, 167, 243);");
}

void SystemServer::on_monitor_lbl_clicked()
{
    qDebug() << "click";
    // ...

    ui->monitor_lbl->setStyleSheet("border-width:0px 0px 3px 0px;   \
                                   border-style: solid;             \
                                   border-color: rgb(36, 144, 243); \
                                   padding-bottom: 0px;             \
                                   color: rgb(36, 144, 243) ");
    ui->photo_lbl->setStyleSheet("border-width:0px 0px 0px 0px;   \
                                  color: rgb(255, 255, 255) ");

    ui->stackedWidget->setCurrentIndex(0);

}

void SystemServer::on_photo_lbl_clicked()
{
    qDebug() << "click";
    // ...

    ui->photo_lbl->setStyleSheet("border-width:0px 0px 3px 0px;   \
                                   border-style: solid;             \
                                   border-color: rgb(36, 144, 243); \
                                   padding-bottom: 0px;             \
                                   color: rgb(36, 144, 243) ");

    ui->monitor_lbl->setStyleSheet("border-width:0px 0px 0px 0px;   \
                                 color: rgb(255, 255, 255) ");


    ui->stackedWidget->setCurrentIndex(2);

}

void SystemServer::on_photo_lbl_hover()
{
    qDebug() << "hover";
    // ...

    ui->photo_lbl->setStyleSheet("border-width:0px 0px 3px 0px;   \
                                   border-style: solid;             \
                                   border-color: rgb(36, 144, 243); \
                                   padding-bottom: 0px;             \
                                   color: rgb(36, 144, 243) ");

}

void SystemServer::on_photo_lbl_leave()
{
    qDebug() << "leave";
    // ...

    //ui->photo_lbl->setStyleSheet("background-color: rgb(164, 167, 243);");

}

void SystemServer::on_monitor_1_doubleclicked()
{
    qDebug() << "on_monitor_1_doubleclicked";
    // ...

    ui->stackedWidget->setCurrentIndex(1);
}

void SystemServer::on_monitor_2_doubleclicked()
{
    qDebug() << "on_monitor_2_doubleclicked";
    // ...

    ui->stackedWidget->setCurrentIndex(1);
}

void SystemServer::on_monitor_3_doubleclicked()
{
    qDebug() << "on_monitor_3_doubleclicked";
    // ...

    ui->stackedWidget->setCurrentIndex(1);
}

void SystemServer::on_monitor_4_doubleclicked()
{
    qDebug() << "on_monitor_4_doubleclicked";
    // ...

    ui->stackedWidget->setCurrentIndex(1);
}

void SystemServer::on_backToMonitorAll_btn_clicked()
{
    qDebug() << "on_backToMonitorAll_btn_clicked";
    // ...

    ui->stackedWidget->setCurrentIndex(0);
}

// 加载显示图片数据
void SystemServer::updatePicData(QString p_name)
{
    picPath = p_name;
    QDir dir(picPath);
    if(!dir.exists()){
        return ;
    }
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    filters << "*.png" << "*.jpg";
    dir.setNameFilters(filters);

    picList = dir.entryList();
    if(picList.count() <= 0){
        return ;
    }

    qDebug() << "picList.count:" << picList.count();

    for(int i = 0; i < picList.count(); ++i){
        QPixmap pixmap(picPath + "/" + picList.at(i));
        QListWidgetItem *listWidgetItem = new QListWidgetItem(QIcon(pixmap.scaled(IMAGE_SIZE)), picList.at(i));

        listWidgetItem->setFont(QFont(font));
        listWidgetItem->setTextColor(QColor(255,255,255));
        listWidgetItem->setSizeHint(ITEM_SIZE);
        ui->picWidget->insertItem(i, listWidgetItem);
    }
}

//加载显示视频数据
void SystemServer::updataVidData(QString vp_name,QString v_name)
{
    pvPath = vp_name;
    vidPath = v_name;
    qDebug() << "vp_name:" <<vp_name;   // ./photo
    qDebug() << "v_name:" <<v_name;     // ./video

    QDir v_dir(pvPath);
    if(!v_dir.exists()){
        return ;
    }

    // set filters 缩略图
    v_dir.setFilter(QDir::Files | QDir::NoSymLinks);
    QStringList v_filters;
    v_filters << "*.png" << "*.jpg";
    v_dir.setNameFilters(v_filters);

    vidList = v_dir.entryList();

    qDebug() << "vidList.count:" << vidList.count();

    for(int i = 0; i < vidList.count(); ++i){
        QString vidFile = vidList.at(i).split(".").at(0) + ".avi";
        QPixmap pixmap(pvPath + "/" + vidList.at(i));

        QListWidgetItem *listWidgetItem = new QListWidgetItem(QIcon(pixmap.scaled(IMAGE_SIZE)), vidFile);
        listWidgetItem->setFont(QFont(font));
        listWidgetItem->setTextColor(QColor(255,255,255));
        listWidgetItem->setSizeHint(ITEM_SIZE);

        ui->vidWidget->insertItem(i, listWidgetItem);
    }
}

void SystemServer::on_video_btn_clicked()
{
    qDebug() << "on_video_btn_clicked";

    ui->vidWidget->show();
    ui->picWidget->hide();
    which_widget_index = 0;
}

void SystemServer::on_photo_btn_clicked()
{
    qDebug() << "on_video_btn_clicked";
    ui->picWidget->show();
    ui->vidWidget->hide();
    which_widget_index = 1;
}

// 双击全屏显示或播放
void SystemServer::slot_itemClicked(QListWidgetItem * item)
{
    QString fileName = item->text();

    if(fileName.split(".").at(1) == "jpg" || fileName.split(".").at(1) == "png"){
        QSize picSize(1024, 600);
        QPixmap pixmap;
        pixmap.load(picPath + "/" + picList.at(ui->picWidget->row(item)));
        QPixmap scaledPixmap = QPixmap(pixmap.scaled(picSize));
        //msg = new fullShow(this);

        connect(this, SIGNAL(give_message(QPixmap)), msg, SLOT(show_picture(QPixmap)));
        msg->show();

        emit give_message(scaledPixmap);
        this->hide();
    }
    else if(fileName.split(".").at(1) == "avi" || fileName.split(".").at(1) == "mp4"){
        //msg = new fullShow(this);
        connect(this, SIGNAL(give_vedname(QString)), msg, SLOT(show_video(QString)));
        msg->show();
        this->hide();
        emit give_vedname(vidPath + "/" + fileName);
    }
}

// 退出全屏显示
void SystemServer::slot_onReturnToFileIndexRequested()
{
    this->show();
    msg->hide();
}

void SystemServer::on_picWidget_itemClicked(QListWidgetItem *item)
{
    ui->rename_edt->setText(picList.at(ui->picWidget->currentRow()));
}

void SystemServer::on_vidWidget_itemClicked(QListWidgetItem *item)
{
    QString vidFile = vidList.at(ui->vidWidget->currentRow()).split(".").at(0) + ".avi";
    ui->rename_edt->setText(vidFile);
}

// 刷新显示列表的函数
void SystemServer::updateDisplay()
{
    ui->rename_edt->clear();
    ui->search_edt->clear();
    ui->picWidget->clear(); // 清除照片列表
    ui->vidWidget->clear(); // 清除视频列表

    updatePicData("./photo");
    updataVidData("./video/photo", "./video");
}

void SystemServer::on_rename_btn_clicked()
{
    QString newName = ui->rename_edt->text();
    qDebug() << "newName:" << newName;
    // 根据当前标签页索引决定刷新哪个列表
    if(which_widget_index == 1){  // photo
        QFile file(picPath + "/" + picList.at(ui->picWidget->currentRow()));
        if(!newName.isEmpty()){
//            bool ok = file.rename(picPath + "/" + newName);
//            qDebug() << ok;
//            qDebug() << picPath;
//            qDebug() << picList.at(ui->picWidget->currentRow());
            if(file.rename(picPath + "/" + newName)){
                qDebug() << "yes 1";
            }
        }
    }
    else if(which_widget_index == 0){ // video
        QString vidFile = vidList.at(ui->vidWidget->currentRow()).split(".").at(0) + ".avi";
        QFile file_video(vidPath + "/" + vidFile);
        QFile file_photo(pvPath + "/" + vidList.at(ui->vidWidget->currentRow()));

//        qDebug() << "vidFile:" << vidFile;
//        qDebug() << "file_video:" << vidPath + "/" + vidFile;
//        qDebug() << "file_photo:" << pvPath + "/" + vidList.at(ui->vidWidget->currentRow());

        if(!newName.isEmpty()){
            if(file_video.rename(vidPath + "/" + newName) && file_photo.rename(pvPath + "/" + newName.split(".").at(0) + ".jpg")){
                qDebug() << "yes 2";
            }
        }
    }

    updateDisplay();
}

void SystemServer::on_del_btn_clicked()
{
    if(which_widget_index == 1){ // photo
       QListWidgetItem* item = ui->picWidget->currentItem();
       if(item){
           int index = ui->picWidget->row(item);
           QString filePath = picPath + "/" + picList.at(index);
           QFile file(filePath);
           if(file.exists() && file.remove()){
               picList.removeAt(index); // 更新列表数据
               ui->picWidget->takeItem(index); // 从列表中移除项
           }
       }
    }
    else if(which_widget_index == 0){ // video
       QListWidgetItem* item = ui->vidWidget->currentItem();
       if(item){
           int index = ui->vidWidget->row(item);
           QString vidFile = vidList.at(ui->vidWidget->currentRow()).split(".").at(0) + ".avi";
           QString filePath = vidPath + "/" + vidFile;

           QFile file_video(filePath);
           QFile file_image(pvPath + "/" + vidList.at(ui->vidWidget->currentRow()));
           qDebug() << "file_video:" << filePath;
           qDebug() << "file_image:" << pvPath + "/" + vidList.at(ui->vidWidget->currentRow());
           if(file_image.exists() && file_image.remove() && file_video.remove()){
               vidList.removeAt(index); // 更新列表数据
               ui->vidWidget->takeItem(index); // 从列表中移除项
           }
       }
    }
       // 刷新显示列表
       updateDisplay();
}

void SystemServer::on_search_btn_clicked()
{
    // 根据当前标签页索引决定刷新哪个列表
    if(which_widget_index == 1){ // photo
        // clear display
        ui->picWidget->clear(); // 清除照片列表

        // 按照前缀搜索
        QString fileName = ui->search_edt->text();
        QDir currentDir = QDir("./photo");
        QStringList files;
        QStringList filters;
        filters << "*.jpg" << "*.png";
        files = currentDir.entryList(filters, QDir::Files | QDir::NoSymLinks);

        QStringList foundFiles;
        if(!fileName.isEmpty()){
            for(int i = 0; i < files.size(); ++i){
                if(files[i].contains(fileName)){
                    foundFiles << files[i];
                }
            }
            qDebug() << foundFiles;
        }

        // 显示搜索到的图片
        for(int i = 0; i < foundFiles.count(); ++i){
            QPixmap pixmap(picPath + "/" + foundFiles.at(i));
            QListWidgetItem *listWidgetItem = new QListWidgetItem(QIcon(pixmap.scaled(IMAGE_SIZE)), foundFiles.at(i));

            listWidgetItem->setFont(QFont(font));
            listWidgetItem->setTextColor(QColor(255,255,255));
            listWidgetItem->setSizeHint(ITEM_SIZE);
            ui->picWidget->insertItem(i, listWidgetItem);
        }
    }
    else if(which_widget_index == 0){ // video
        // clear display
        ui->vidWidget->clear(); // 清除视频列表

        // 按照前缀搜索
        QString fileName = ui->search_edt->text();
        QDir currentDir = QDir("./video");
        QStringList files;
        QStringList filters;
        filters << "*.avi";
        files = currentDir.entryList(filters, QDir::Files | QDir::NoSymLinks);

        QStringList foundFiles;
        if(!fileName.isEmpty()){
            for(int i = 0; i < files.size(); ++i){
                if(files[i].contains(fileName)){
                    foundFiles << files[i];
                }
            }
            qDebug() << "foundFiles:" << foundFiles;
        }

        // 显示搜索到的
        for(int i = 0; i < foundFiles.count(); ++i){
            QString jpg = foundFiles.at(i).split(".").at(0) + ".jpg";

            QPixmap pixmap(pvPath + "/" + jpg);
            qDebug() << "jpg:" << jpg;
            qDebug() << "pixmap:" << pvPath + "/" + jpg;

            QListWidgetItem *listWidgetItem = new QListWidgetItem(QIcon(pixmap.scaled(IMAGE_SIZE)), foundFiles.at(i));
            listWidgetItem->setFont(QFont(font));
            listWidgetItem->setTextColor(QColor(255,255,255));
            listWidgetItem->setSizeHint(ITEM_SIZE);
            ui->vidWidget->insertItem(i, listWidgetItem);
        }
    }
}

void SystemServer::Subclient_Hanlder()
{

    qDebug()<<"connect MQTT server success,begin to subscribe."<<endl;

    SubTopic = "/VIDEO";
    SUBclient->subscribe(SubTopic);
    SUBclient->setKeepAlive(30);

    qDebug()<<"subscribe /VIDEO."<<endl;

    connect(SUBclient, SIGNAL(received(QMQTT::Message)), this, SLOT(DataRecvParse(QMQTT::Message)));
}

void SystemServer::DataRecvParse(QMQTT::Message recv_mes)
{
    qDebug()<<"receive data...";
    QByteArray array = recv_mes.payload();

//    while(client->waitForReadyRead(100))
//    {
//        array.append((QByteArray)client->readAll());
//    }
    QBuffer buffer(&array);
    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"JPG");
    QImage img = reader.read();
     if(!img.isNull()){
        QPixmap pix = QPixmap::fromImage(img);
         ui->video_lbl->setPixmap(pix.scaled(ui->video_lbl->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
}

void SystemServer::on_get_photo_bt_clicked()
{
    qDebug() << "take photo";

    // 获取当前时间并格式化为字符串
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyyMMdd_hhmmss");

    // 生成文件名
    QString filename = "photo/screenshot_" + dateTimeString + ".jpg";

    QImage image = ui->video_lbl->pixmap()->toImage();
    image.save(filename);
}

void SystemServer::on_get_video_bt_clicked()
{

}

void SystemServer::on_auto_model_bt_clicked()
{

}

void SystemServer::mqtt_ctl_PTZ(const QString &topic, const QString &message)
{
    qDebug() << "publish";

    quint16 messageID = 2; // 消息ID，可以根据需要生成
    QByteArray bytes = message.toUtf8();
    QMQTT::Message msg(messageID, topic, bytes);
    SUBclient->publish(msg);
}

void SystemServer::on_turn_up_bt_clicked()
{
    if(SUBclient->connectionState() == QMQTT::ConnectionState::STATE_CONNECTED){
        mqtt_ctl_PTZ("/PTZCTL", "{\"cmd\":\"{\\\"PTZ_UP\\\":\\\"MOVE\\\"}\"}");
    }
}

void SystemServer::on_turn_left_bt_clicked()
{
    if(SUBclient->connectionState() == QMQTT::ConnectionState::STATE_CONNECTED){
        mqtt_ctl_PTZ("/PTZCTL", "{\"cmd\":\"{\\\"PTZ_LEFT\\\":\\\"MOVE\\\"}\"}");
    }
}

void SystemServer::on_turn_reset_bt_clicked()
{
    if(SUBclient->connectionState() == QMQTT::ConnectionState::STATE_CONNECTED){
        mqtt_ctl_PTZ("/PTZCTL", "{\"cmd\":\"{\\\"PTZ_RESET\\\":\\\"MOVE\\\"}\"}");
    }
}

void SystemServer::on_turn_right_bt_clicked()
{
    if(SUBclient->connectionState() == QMQTT::ConnectionState::STATE_CONNECTED){
        mqtt_ctl_PTZ("/PTZCTL", "{\"cmd\":\"{\\\"PTZ_RIGHT\\\":\\\"MOVE\\\"}\"}");
    }
}

void SystemServer::on_turn_down_bt_clicked()
{
    if(SUBclient->connectionState() == QMQTT::ConnectionState::STATE_CONNECTED){
        mqtt_ctl_PTZ("/PTZCTL", "{\"cmd\":\"{\\\"PTZ_DOWN\\\":\\\"MOVE\\\"}\"}");
    }

}
