/********************************************************************************
** Form generated from reading UI file 'systemserver.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSERVER_H
#define UI_SYSTEMSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <click_label.h>

QT_BEGIN_NAMESPACE

class Ui_SystemServer
{
public:
    QWidget *centralWidget;
    QLabel *title_lbl;
    click_label *monitor_lbl;
    click_label *photo_lbl;
    click_label *log_lbl;
    click_label *manager_lbl;
    QStackedWidget *stackedWidget;
    QWidget *monitorAll_widget;
    click_label *monitor_1;
    click_label *monitor_2;
    click_label *monitor_4;
    click_label *monitor_3;
    QWidget *monitorOne_widget;
    QPushButton *get_photo_bt;
    QPushButton *auto_model_bt;
    QPushButton *backToMonitorAll_btn;
    QPushButton *get_video_bt;
    QPushButton *turn_left_bt;
    QPushButton *turn_down_bt;
    QPushButton *turn_right_bt;
    QPushButton *turn_up_bt;
    QPushButton *turn_reset_bt;
    QLabel *video_lbl;
    QWidget *photo_widget;
    QPushButton *previous_btn;
    QPushButton *next_btn;
    QPushButton *search_btn;
    QWidget *widget;
    QPushButton *video_btn;
    QPushButton *photo_btn;
    QPushButton *search_btn_2;
    QListWidget *vidWidget;
    QListWidget *picWidget;
    QPushButton *del_btn;
    QPushButton *rename_btn;
    QLineEdit *rename_edt;
    QLineEdit *search_edt;
    QWidget *log_widget;
    QWidget *manager_widget;

    void setupUi(QMainWindow *SystemServer)
    {
        if (SystemServer->objectName().isEmpty())
            SystemServer->setObjectName(QStringLiteral("SystemServer"));
        SystemServer->resize(1024, 600);
        SystemServer->setStyleSheet(QLatin1String("#SystemServer{background-image: url(:/new/prefix1/ui_image/menu.jpg);}\n"
"\n"
"QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        centralWidget = new QWidget(SystemServer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        title_lbl = new QLabel(centralWidget);
        title_lbl->setObjectName(QStringLiteral("title_lbl"));
        title_lbl->setGeometry(QRect(20, 20, 151, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        title_lbl->setFont(font);
        title_lbl->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        monitor_lbl = new click_label(centralWidget);
        monitor_lbl->setObjectName(QStringLiteral("monitor_lbl"));
        monitor_lbl->setGeometry(QRect(220, 20, 84, 32));
        QFont font1;
        font1.setPointSize(16);
        monitor_lbl->setFont(font1);
        monitor_lbl->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        monitor_lbl->setAlignment(Qt::AlignCenter);
        monitor_lbl->setMargin(0);
        photo_lbl = new click_label(centralWidget);
        photo_lbl->setObjectName(QStringLiteral("photo_lbl"));
        photo_lbl->setGeometry(QRect(347, 20, 84, 32));
        photo_lbl->setFont(font1);
        photo_lbl->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        log_lbl = new click_label(centralWidget);
        log_lbl->setObjectName(QStringLiteral("log_lbl"));
        log_lbl->setGeometry(QRect(484, 20, 84, 32));
        log_lbl->setFont(font1);
        log_lbl->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        manager_lbl = new click_label(centralWidget);
        manager_lbl->setObjectName(QStringLiteral("manager_lbl"));
        manager_lbl->setGeometry(QRect(620, 20, 84, 32));
        manager_lbl->setFont(font1);
        manager_lbl->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-1, 70, 1020, 530));
        stackedWidget->setStyleSheet(QLatin1String("background-color: rgba(0, 33, 68,10);\n"
""));
        monitorAll_widget = new QWidget();
        monitorAll_widget->setObjectName(QStringLiteral("monitorAll_widget"));
        monitor_1 = new click_label(monitorAll_widget);
        monitor_1->setObjectName(QStringLiteral("monitor_1"));
        monitor_1->setGeometry(QRect(10, 20, 500, 250));
        monitor_1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/ui_image/menu2.jpg);"));
        monitor_2 = new click_label(monitorAll_widget);
        monitor_2->setObjectName(QStringLiteral("monitor_2"));
        monitor_2->setGeometry(QRect(510, 20, 500, 250));
        monitor_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/ui_image/menu1.jpg);"));
        monitor_4 = new click_label(monitorAll_widget);
        monitor_4->setObjectName(QStringLiteral("monitor_4"));
        monitor_4->setGeometry(QRect(510, 270, 500, 250));
        monitor_4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/ui_image/menu2.jpg);"));
        monitor_3 = new click_label(monitorAll_widget);
        monitor_3->setObjectName(QStringLiteral("monitor_3"));
        monitor_3->setGeometry(QRect(10, 270, 500, 250));
        monitor_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/ui_image/menu1.jpg);"));
        stackedWidget->addWidget(monitorAll_widget);
        monitorOne_widget = new QWidget();
        monitorOne_widget->setObjectName(QStringLiteral("monitorOne_widget"));
        get_photo_bt = new QPushButton(monitorOne_widget);
        get_photo_bt->setObjectName(QStringLiteral("get_photo_bt"));
        get_photo_bt->setGeometry(QRect(710, 310, 101, 61));
        get_photo_bt->setFocusPolicy(Qt::NoFocus);
        get_photo_bt->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        auto_model_bt = new QPushButton(monitorOne_widget);
        auto_model_bt->setObjectName(QStringLiteral("auto_model_bt"));
        auto_model_bt->setGeometry(QRect(710, 420, 101, 61));
        auto_model_bt->setFocusPolicy(Qt::NoFocus);
        auto_model_bt->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        backToMonitorAll_btn = new QPushButton(monitorOne_widget);
        backToMonitorAll_btn->setObjectName(QStringLiteral("backToMonitorAll_btn"));
        backToMonitorAll_btn->setGeometry(QRect(890, 420, 101, 61));
        backToMonitorAll_btn->setFocusPolicy(Qt::NoFocus);
        backToMonitorAll_btn->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        get_video_bt = new QPushButton(monitorOne_widget);
        get_video_bt->setObjectName(QStringLiteral("get_video_bt"));
        get_video_bt->setGeometry(QRect(890, 310, 101, 61));
        get_video_bt->setFocusPolicy(Qt::NoFocus);
        get_video_bt->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        turn_left_bt = new QPushButton(monitorOne_widget);
        turn_left_bt->setObjectName(QStringLiteral("turn_left_bt"));
        turn_left_bt->setGeometry(QRect(710, 90, 81, 81));
        turn_left_bt->setFocusPolicy(Qt::NoFocus);
        turn_left_bt->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/ui_image/left.png);\n"
""));
        turn_left_bt->setAutoRepeat(true);
        turn_left_bt->setAutoRepeatDelay(30);
        turn_left_bt->setAutoRepeatInterval(30);
        turn_down_bt = new QPushButton(monitorOne_widget);
        turn_down_bt->setObjectName(QStringLiteral("turn_down_bt"));
        turn_down_bt->setGeometry(QRect(810, 180, 81, 81));
        turn_down_bt->setFocusPolicy(Qt::NoFocus);
        turn_down_bt->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/ui_image/down.png);\n"
""));
        turn_down_bt->setAutoRepeat(true);
        turn_down_bt->setAutoRepeatDelay(30);
        turn_down_bt->setAutoRepeatInterval(30);
        turn_right_bt = new QPushButton(monitorOne_widget);
        turn_right_bt->setObjectName(QStringLiteral("turn_right_bt"));
        turn_right_bt->setGeometry(QRect(910, 90, 81, 81));
        turn_right_bt->setFocusPolicy(Qt::NoFocus);
        turn_right_bt->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/ui_image/right.png);\n"
"\n"
""));
        turn_right_bt->setAutoRepeat(true);
        turn_right_bt->setAutoRepeatDelay(30);
        turn_right_bt->setAutoRepeatInterval(30);
        turn_up_bt = new QPushButton(monitorOne_widget);
        turn_up_bt->setObjectName(QStringLiteral("turn_up_bt"));
        turn_up_bt->setGeometry(QRect(810, 0, 81, 81));
        turn_up_bt->setFocusPolicy(Qt::NoFocus);
        turn_up_bt->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/ui_image/up.png);\n"
""));
        turn_up_bt->setAutoRepeat(true);
        turn_up_bt->setAutoRepeatDelay(30);
        turn_up_bt->setAutoRepeatInterval(30);
        turn_reset_bt = new QPushButton(monitorOne_widget);
        turn_reset_bt->setObjectName(QStringLiteral("turn_reset_bt"));
        turn_reset_bt->setGeometry(QRect(820, 100, 61, 61));
        turn_reset_bt->setFocusPolicy(Qt::NoFocus);
        turn_reset_bt->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/ui_image/reset.png);\n"
""));
        video_lbl = new QLabel(monitorOne_widget);
        video_lbl->setObjectName(QStringLiteral("video_lbl"));
        video_lbl->setGeometry(QRect(10, 10, 640, 480));
        video_lbl->setStyleSheet(QLatin1String("background-color: rgba(0, 33, 68,150);\n"
""));
        stackedWidget->addWidget(monitorOne_widget);
        photo_widget = new QWidget();
        photo_widget->setObjectName(QStringLiteral("photo_widget"));
        photo_widget->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,200);"));
        previous_btn = new QPushButton(photo_widget);
        previous_btn->setObjectName(QStringLiteral("previous_btn"));
        previous_btn->setGeometry(QRect(210, 490, 99, 33));
        previous_btn->setFocusPolicy(Qt::NoFocus);
        previous_btn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        next_btn = new QPushButton(photo_widget);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        next_btn->setGeometry(QRect(320, 490, 99, 33));
        next_btn->setFocusPolicy(Qt::NoFocus);
        next_btn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        search_btn = new QPushButton(photo_widget);
        search_btn->setObjectName(QStringLiteral("search_btn"));
        search_btn->setGeometry(QRect(910, 490, 99, 33));
        search_btn->setFocusPolicy(Qt::NoFocus);
        search_btn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        widget = new QWidget(photo_widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 190, 531));
        widget->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,10);"));
        video_btn = new QPushButton(widget);
        video_btn->setObjectName(QStringLiteral("video_btn"));
        video_btn->setGeometry(QRect(10, 10, 171, 41));
        video_btn->setFocusPolicy(Qt::NoFocus);
        video_btn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        photo_btn = new QPushButton(widget);
        photo_btn->setObjectName(QStringLiteral("photo_btn"));
        photo_btn->setGeometry(QRect(10, 60, 171, 41));
        photo_btn->setFocusPolicy(Qt::NoFocus);
        photo_btn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        search_btn_2 = new QPushButton(widget);
        search_btn_2->setObjectName(QStringLiteral("search_btn_2"));
        search_btn_2->setGeometry(QRect(10, 110, 171, 41));
        search_btn_2->setFocusPolicy(Qt::NoFocus);
        search_btn_2->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        vidWidget = new QListWidget(photo_widget);
        vidWidget->setObjectName(QStringLiteral("vidWidget"));
        vidWidget->setGeometry(QRect(200, 0, 820, 480));
        vidWidget->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,10);"));
        vidWidget->setFrameShape(QFrame::NoFrame);
        picWidget = new QListWidget(photo_widget);
        picWidget->setObjectName(QStringLiteral("picWidget"));
        picWidget->setGeometry(QRect(200, 0, 820, 480));
        picWidget->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,10);"));
        picWidget->setFrameShape(QFrame::NoFrame);
        del_btn = new QPushButton(photo_widget);
        del_btn->setObjectName(QStringLiteral("del_btn"));
        del_btn->setGeometry(QRect(430, 490, 99, 33));
        del_btn->setFocusPolicy(Qt::NoFocus);
        del_btn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        rename_btn = new QPushButton(photo_widget);
        rename_btn->setObjectName(QStringLiteral("rename_btn"));
        rename_btn->setGeometry(QRect(670, 490, 99, 33));
        rename_btn->setFocusPolicy(Qt::NoFocus);
        rename_btn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #68ACF9;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);background-color: rgba(0, 33, 68,50);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        rename_edt = new QLineEdit(photo_widget);
        rename_edt->setObjectName(QStringLiteral("rename_edt"));
        rename_edt->setGeometry(QRect(550, 490, 113, 33));
        rename_edt->setFocusPolicy(Qt::NoFocus);
        rename_edt->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border:0px;"));
        rename_edt->setFrame(true);
        search_edt = new QLineEdit(photo_widget);
        search_edt->setObjectName(QStringLiteral("search_edt"));
        search_edt->setGeometry(QRect(790, 490, 113, 33));
        search_edt->setFocusPolicy(Qt::NoFocus);
        search_edt->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border:0px;"));
        stackedWidget->addWidget(photo_widget);
        log_widget = new QWidget();
        log_widget->setObjectName(QStringLiteral("log_widget"));
        stackedWidget->addWidget(log_widget);
        manager_widget = new QWidget();
        manager_widget->setObjectName(QStringLiteral("manager_widget"));
        stackedWidget->addWidget(manager_widget);
        SystemServer->setCentralWidget(centralWidget);

        retranslateUi(SystemServer);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemServer);
    } // setupUi

    void retranslateUi(QMainWindow *SystemServer)
    {
        SystemServer->setWindowTitle(QApplication::translate("SystemServer", "SystemServer", 0));
        title_lbl->setText(QApplication::translate("SystemServer", "\345\256\211\351\230\262\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        monitor_lbl->setText(QApplication::translate("SystemServer", "\345\256\236\346\227\266\347\233\221\346\216\247", 0));
        photo_lbl->setText(QApplication::translate("SystemServer", "\345\275\225\345\203\217\347\205\247\347\211\207", 0));
        log_lbl->setText(QApplication::translate("SystemServer", "\346\212\245\350\255\246\344\277\241\346\201\257", 0));
        manager_lbl->setText(QApplication::translate("SystemServer", "\347\263\273\347\273\237\347\256\241\347\220\206", 0));
        monitor_1->setText(QString());
        monitor_2->setText(QString());
        monitor_4->setText(QString());
        monitor_3->setText(QString());
        get_photo_bt->setText(QApplication::translate("SystemServer", "\346\213\215\347\205\247", 0));
        auto_model_bt->setText(QApplication::translate("SystemServer", "\350\207\252\345\212\250\346\250\241\345\274\217", 0));
        backToMonitorAll_btn->setText(QApplication::translate("SystemServer", "\350\277\224\345\233\236\345\205\250\347\233\221", 0));
        get_video_bt->setText(QApplication::translate("SystemServer", "\345\275\225\345\203\217", 0));
        turn_left_bt->setText(QString());
        turn_down_bt->setText(QString());
        turn_right_bt->setText(QString());
        turn_up_bt->setText(QString());
        turn_reset_bt->setText(QString());
        video_lbl->setText(QString());
        previous_btn->setText(QApplication::translate("SystemServer", "\344\270\212\344\270\200\351\241\265", 0));
        next_btn->setText(QApplication::translate("SystemServer", "\344\270\213\344\270\200\351\241\265", 0));
        search_btn->setText(QApplication::translate("SystemServer", " \346\220\234\347\264\242", 0));
        video_btn->setText(QApplication::translate("SystemServer", "\345\275\225\345\203\217", 0));
        photo_btn->setText(QApplication::translate("SystemServer", "\345\233\276\347\211\207", 0));
        search_btn_2->setText(QApplication::translate("SystemServer", "\346\220\234\347\264\242", 0));
        del_btn->setText(QApplication::translate("SystemServer", "\345\210\240\351\231\244", 0));
        rename_btn->setText(QApplication::translate("SystemServer", "\351\207\215\345\221\275\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class SystemServer: public Ui_SystemServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSERVER_H
