#ifndef FOPS_H
#define FOPS_H

#include <QWidget>
#include <fullShow.h>
#include <QFile>
#include <QListWidget>

namespace Ui {
class fops;
}

class fops : public QWidget
{
    Q_OBJECT

public:
    explicit fops(QWidget *parent = 0);
    ~fops();


private slots:
    void on_back_menu_bt_clicked();

    void on_video_btn_clicked();

    void on_photo_btn_clicked();

    void on_del_btn_clicked();

    void on_rename_btn_clicked();

    void on_search_btn_clicked();

    void slot_onReturnToFileIndexRequested();

    void on_vidWidget_itemClicked(QListWidgetItem *item);

    void on_picWidget_itemClicked(QListWidgetItem *item);

    void slot_itemClicked(QListWidgetItem * item);


signals:
    void give_message(QPixmap message);
    void give_vedname(QString ved_name);

private:
    Ui::fops *ui;

    void initValue();

    void updatePicData(QString p_name);

    void updataVidData(QString vp_name,QString v_name);

    void updateDisplay();

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

};

#endif // FOPS_H








