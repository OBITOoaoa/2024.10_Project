#ifndef SYSTEMSERVER_H
#define SYSTEMSERVER_H

#include <QMainWindow>
#include <QListWidget>
#include <QTableWidget>
#include <fullShow.h>
#include <QFile>

#include "mqtt/qmqtt.h"

namespace Ui {
class SystemServer;
}

class SystemServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemServer(QWidget *parent = 0);
    ~SystemServer();

    void initValue();

    void updatePicData(QString p_name);

    void updataVidData(QString vp_name,QString v_name);

    void updateDisplay();

    void mqtt_ctl_PTZ(const QString &topic, const QString &message);

signals:
    void give_message(QPixmap message);
    void give_vedname(QString ved_name);

private slots:
    void on_monitor_lbl_hover();

    void on_monitor_lbl_leave();

    void on_monitor_lbl_clicked();

    void on_photo_lbl_clicked();

    void on_photo_lbl_hover();

    void on_photo_lbl_leave();


    void on_monitor_1_doubleclicked();

    void on_monitor_2_doubleclicked();

    void on_monitor_3_doubleclicked();

    void on_monitor_4_doubleclicked();

    void on_backToMonitorAll_btn_clicked();



    void on_video_btn_clicked();

    void on_photo_btn_clicked();

    void slot_itemClicked(QListWidgetItem * item);

    void slot_onReturnToFileIndexRequested();



    void on_picWidget_itemClicked(QListWidgetItem *item);

    void on_vidWidget_itemClicked(QListWidgetItem *item);

    void on_rename_btn_clicked();

    void on_del_btn_clicked();

    void on_search_btn_clicked();

    void Subclient_Hanlder();

    void DataRecvParse(QMQTT::Message);

    void on_get_photo_bt_clicked();

    void on_get_video_bt_clicked();

    void on_auto_model_bt_clicked();

    void on_turn_up_bt_clicked();

    void on_turn_left_bt_clicked();

    void on_turn_reset_bt_clicked();

    void on_turn_right_bt_clicked();

    void on_turn_down_bt_clicked();

private:
    Ui::SystemServer *ui;

    QString picPath,pvPath,vidPath;
    QStringList picList;      // 文件目录下所有的图像文件名
    QStringList vidList;      // 文件目录下所有的视频文件名
    fullShow *msg;
    QStringList filters;

    QFont font;
    QSize IMAGE_SIZE;
    QSize ITEM_SIZE;

    QString m_fileName;
    QFile *m_localFile;

    int which_widget_index; // 0:vidWidget 1:picWidget

    // mqtt
    QMQTT::Client* SUBclient;

    QString SubTopic,message;

};

#endif // SYSTEMSERVER_H
