#include "fops.h"
#include "ui_fops.h"
#include <QDir>

fops::fops(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fops)
{
    ui->setupUi(this);

    this->initValue();
}

fops::~fops()
{
    delete ui;
}

void fops::initValue()
{
    this->setWindowTitle("安防管理系统-文件管理"); // 设置窗口标题

    picPath.clear();
    vidPath.clear();
    pvPath.clear();

    // 设置窗口尺寸
    font.setPointSize(6);
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
        "QListWidget::item:selected{background:lightgreen; color:red; }"
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
        "QListWidget::item:selected{background:lightgreen; color:red; }"
        "QListWidget{background:rgba(0, 33, 68,200);}"
    );

    updatePicData("./photo");
    updataVidData("./video/photo", "./video");

    // 双击图片放大图示
    connect(ui->picWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,
            SLOT(slot_itemClicked(QListWidgetItem*)));

    // 双击视频图标播放
    connect(ui->vidWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,
            SLOT(slot_itemClicked(QListWidgetItem*)));

    msg = new fullShow(this);
    connect(msg, SIGNAL(requestReturnToFileIndex()), this, SLOT(slot_onReturnToFileIndexRequested()));


    which_widget_index = 0; // vidWidget

    QPixmap pixmap(":/images/menu1.jpg");
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
}


void fops::on_back_menu_bt_clicked()
{
    this->close();
}

// 加载显示图片数据
void fops::updatePicData(QString p_name)
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
void fops::updataVidData(QString vp_name,QString v_name)
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

void fops::on_video_btn_clicked()
{
    qDebug() << "on_video_btn_clicked";

    ui->stackedWidget->setCurrentIndex(0);
    which_widget_index = 0;

}

void fops::on_photo_btn_clicked()
{
    qDebug() << "on_photo_btn_clicked";

    ui->stackedWidget->setCurrentIndex(1);
    which_widget_index = 1;
}

// 双击全屏显示或播放
void fops::slot_itemClicked(QListWidgetItem * item)
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
void fops::slot_onReturnToFileIndexRequested()
{
    this->show();
    msg->hide();
}

void fops::on_picWidget_itemClicked(QListWidgetItem *item)
{
    ui->rename_edt->setText(picList.at(ui->picWidget->currentRow()));
}

void fops::on_vidWidget_itemClicked(QListWidgetItem *item)
{
    QString vidFile = vidList.at(ui->vidWidget->currentRow()).split(".").at(0) + ".avi";
    ui->rename_edt->setText(vidFile);
}

// 刷新显示列表的函数
void fops::updateDisplay()
{
    ui->rename_edt->clear();
    ui->search_edt->clear();

    ui->vidWidget->clear(); // 清除视频列表
    ui->picWidget->clear(); // 清除照片列表

    updatePicData("./photo");
    updataVidData("./video/photo", "./video");
}

void fops::on_rename_btn_clicked()
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

void fops::on_del_btn_clicked()
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

void fops::on_search_btn_clicked()
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

