/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *swt_Control_bt;
    QLabel *ctl_Frame_sw;
    QStackedWidget *ctl_Panel_sw;
    QWidget *page;
    QPushButton *turn_up_bt;
    QPushButton *turn_reset_bt;
    QPushButton *turn_left_bt;
    QPushButton *turn_right_bt;
    QPushButton *turn_down_bt;
    QPushButton *get_photo_bt;
    QPushButton *get_video_bt;
    QPushButton *capture_bt;
    QPushButton *mqtt_transfer_bt;
    QWidget *page_2;
    QSlider *angle_slider;
    QSlider *speed_slider;
    QPushButton *auto_btn;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *exp_Check_bt;
    QPushButton *file_Manage_bt;
    QPushButton *mode_Setup_bt;
    QLabel *currentTime_lb;
    QLabel *fps_lbl;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(1024, 600);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        menu->setFont(font);
        menu->setStyleSheet(QLatin1String("#menu{border-image: url(:/images/menu1.jpg);}\n"
"\n"
"QPushButton {\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);\n"
"	background-color: rgba(0, 33, 68,220);\n"
"	border:none; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: #2F42B5;\n"
"}"));
        swt_Control_bt = new QPushButton(menu);
        swt_Control_bt->setObjectName(QStringLiteral("swt_Control_bt"));
        swt_Control_bt->setGeometry(QRect(50, 540, 161, 61));
        QFont font1;
        font1.setPointSize(10);
        swt_Control_bt->setFont(font1);
        swt_Control_bt->setFocusPolicy(Qt::NoFocus);
        swt_Control_bt->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/auto_model.png"), QSize(), QIcon::Normal, QIcon::Off);
        swt_Control_bt->setIcon(icon);
        swt_Control_bt->setIconSize(QSize(40, 40));
        ctl_Frame_sw = new QLabel(menu);
        ctl_Frame_sw->setObjectName(QStringLiteral("ctl_Frame_sw"));
        ctl_Frame_sw->setGeometry(QRect(40, 53, 640, 480));
        ctl_Frame_sw->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,200);"));
        ctl_Panel_sw = new QStackedWidget(menu);
        ctl_Panel_sw->setObjectName(QStringLiteral("ctl_Panel_sw"));
        ctl_Panel_sw->setGeometry(QRect(750, 53, 221, 481));
        ctl_Panel_sw->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,120);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        turn_up_bt = new QPushButton(page);
        turn_up_bt->setObjectName(QStringLiteral("turn_up_bt"));
        turn_up_bt->setGeometry(QRect(70, 40, 81, 81));
        turn_up_bt->setFocusPolicy(Qt::NoFocus);
        turn_up_bt->setStyleSheet(QStringLiteral("border-image: url(:/images/up.png);"));
        turn_up_bt->setAutoRepeat(true);
        turn_up_bt->setAutoRepeatDelay(30);
        turn_up_bt->setAutoRepeatInterval(30);
        turn_reset_bt = new QPushButton(page);
        turn_reset_bt->setObjectName(QStringLiteral("turn_reset_bt"));
        turn_reset_bt->setGeometry(QRect(90, 130, 41, 41));
        turn_reset_bt->setFocusPolicy(Qt::NoFocus);
        turn_reset_bt->setStyleSheet(QStringLiteral("border-image: url(:/images/reset.png);"));
        turn_left_bt = new QPushButton(page);
        turn_left_bt->setObjectName(QStringLiteral("turn_left_bt"));
        turn_left_bt->setGeometry(QRect(0, 110, 81, 81));
        turn_left_bt->setFocusPolicy(Qt::NoFocus);
        turn_left_bt->setStyleSheet(QStringLiteral("border-image: url(:/images/left.png);"));
        turn_left_bt->setAutoRepeat(true);
        turn_left_bt->setAutoRepeatDelay(30);
        turn_left_bt->setAutoRepeatInterval(30);
        turn_right_bt = new QPushButton(page);
        turn_right_bt->setObjectName(QStringLiteral("turn_right_bt"));
        turn_right_bt->setGeometry(QRect(140, 110, 81, 81));
        turn_right_bt->setFocusPolicy(Qt::NoFocus);
        turn_right_bt->setStyleSheet(QStringLiteral("border-image: url(:/images/right.png);"));
        turn_right_bt->setAutoRepeat(true);
        turn_right_bt->setAutoRepeatDelay(30);
        turn_right_bt->setAutoRepeatInterval(30);
        turn_down_bt = new QPushButton(page);
        turn_down_bt->setObjectName(QStringLiteral("turn_down_bt"));
        turn_down_bt->setGeometry(QRect(70, 180, 81, 81));
        turn_down_bt->setFocusPolicy(Qt::NoFocus);
        turn_down_bt->setStyleSheet(QStringLiteral("border-image: url(:/images/down.png);"));
        turn_down_bt->setAutoRepeat(true);
        turn_down_bt->setAutoRepeatDelay(30);
        turn_down_bt->setAutoRepeatInterval(30);
        get_photo_bt = new QPushButton(page);
        get_photo_bt->setObjectName(QStringLiteral("get_photo_bt"));
        get_photo_bt->setGeometry(QRect(0, 420, 71, 61));
        get_photo_bt->setFocusPolicy(Qt::NoFocus);
        get_photo_bt->setStyleSheet(QStringLiteral("border-image: url(:/images/camera.png);"));
        get_video_bt = new QPushButton(page);
        get_video_bt->setObjectName(QStringLiteral("get_video_bt"));
        get_video_bt->setGeometry(QRect(150, 420, 71, 61));
        get_video_bt->setFocusPolicy(Qt::NoFocus);
        get_video_bt->setStyleSheet(QStringLiteral("border-image: url(:/images/capture.png);"));
        capture_bt = new QPushButton(page);
        capture_bt->setObjectName(QStringLiteral("capture_bt"));
        capture_bt->setGeometry(QRect(0, 330, 81, 61));
        QFont font2;
        font2.setPointSize(8);
        capture_bt->setFont(font2);
        capture_bt->setFocusPolicy(Qt::NoFocus);
        capture_bt->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);\n"
"	background-color: rgba(0, 33, 68,250);\n"
"	border:none; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    color: #2F42B5;\n"
"}"));
        mqtt_transfer_bt = new QPushButton(page);
        mqtt_transfer_bt->setObjectName(QStringLiteral("mqtt_transfer_bt"));
        mqtt_transfer_bt->setGeometry(QRect(140, 330, 81, 61));
        mqtt_transfer_bt->setFont(font2);
        mqtt_transfer_bt->setFocusPolicy(Qt::NoFocus);
        mqtt_transfer_bt->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border-radius: 15px;\n"
"	color: rgba(255, 255,255, 250);\n"
"	background-color: rgba(0, 33, 68,250);\n"
"	border:none; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2F42B5;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    color: #2F42B5;\n"
"}"));
        ctl_Panel_sw->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        angle_slider = new QSlider(page_2);
        angle_slider->setObjectName(QStringLiteral("angle_slider"));
        angle_slider->setGeometry(QRect(40, 140, 29, 271));
        angle_slider->setFocusPolicy(Qt::NoFocus);
        angle_slider->setStyleSheet(QLatin1String("background-color: rgba(0, 33, 68,10);\n"
"\n"
"\n"
""));
        angle_slider->setOrientation(Qt::Vertical);
        angle_slider->setInvertedAppearance(true);
        speed_slider = new QSlider(page_2);
        speed_slider->setObjectName(QStringLiteral("speed_slider"));
        speed_slider->setGeometry(QRect(150, 140, 29, 271));
        speed_slider->setFocusPolicy(Qt::NoFocus);
        speed_slider->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,10);"));
        speed_slider->setOrientation(Qt::Vertical);
        speed_slider->setInvertedAppearance(true);
        auto_btn = new QPushButton(page_2);
        auto_btn->setObjectName(QStringLiteral("auto_btn"));
        auto_btn->setGeometry(QRect(60, 0, 91, 71));
        auto_btn->setFont(font2);
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 91, 71));
        label_2->setFont(font2);
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 33, 68,10);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 70, 91, 71));
        label_3->setFont(font2);
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 33, 68,10);"));
        label_3->setAlignment(Qt::AlignCenter);
        ctl_Panel_sw->addWidget(page_2);
        exp_Check_bt = new QPushButton(menu);
        exp_Check_bt->setObjectName(QStringLiteral("exp_Check_bt"));
        exp_Check_bt->setGeometry(QRect(280, 540, 161, 61));
        exp_Check_bt->setFont(font1);
        exp_Check_bt->setFocusPolicy(Qt::NoFocus);
        exp_Check_bt->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/exception.png"), QSize(), QIcon::Normal, QIcon::Off);
        exp_Check_bt->setIcon(icon1);
        exp_Check_bt->setIconSize(QSize(40, 40));
        file_Manage_bt = new QPushButton(menu);
        file_Manage_bt->setObjectName(QStringLiteral("file_Manage_bt"));
        file_Manage_bt->setGeometry(QRect(520, 540, 161, 61));
        file_Manage_bt->setFont(font1);
        file_Manage_bt->setFocusPolicy(Qt::NoFocus);
        file_Manage_bt->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/file_manager.png"), QSize(), QIcon::Normal, QIcon::Off);
        file_Manage_bt->setIcon(icon2);
        file_Manage_bt->setIconSize(QSize(40, 40));
        mode_Setup_bt = new QPushButton(menu);
        mode_Setup_bt->setObjectName(QStringLiteral("mode_Setup_bt"));
        mode_Setup_bt->setGeometry(QRect(750, 540, 161, 61));
        mode_Setup_bt->setFont(font1);
        mode_Setup_bt->setFocusPolicy(Qt::NoFocus);
        mode_Setup_bt->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        mode_Setup_bt->setIcon(icon3);
        mode_Setup_bt->setIconSize(QSize(40, 40));
        currentTime_lb = new QLabel(menu);
        currentTime_lb->setObjectName(QStringLiteral("currentTime_lb"));
        currentTime_lb->setGeometry(QRect(540, 10, 451, 41));
        currentTime_lb->setStyleSheet(QStringLiteral(""));
        currentTime_lb->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fps_lbl = new QLabel(menu);
        fps_lbl->setObjectName(QStringLiteral("fps_lbl"));
        fps_lbl->setGeometry(QRect(50, 120, 81, 41));
        fps_lbl->setStyleSheet(QStringLiteral("color: rgb(224, 18, 18);"));

        retranslateUi(menu);

        ctl_Panel_sw->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "menu", 0));
        swt_Control_bt->setText(QApplication::translate("menu", "\345\210\207\346\215\242\350\207\252\345\212\250", 0));
        ctl_Frame_sw->setText(QString());
        turn_up_bt->setText(QString());
        turn_reset_bt->setText(QString());
        turn_left_bt->setText(QString());
        turn_right_bt->setText(QString());
        turn_down_bt->setText(QString());
        get_photo_bt->setText(QString());
        get_video_bt->setText(QString());
        capture_bt->setText(QApplication::translate("menu", "\345\274\200\345\247\213", 0));
        mqtt_transfer_bt->setText(QApplication::translate("menu", "\345\233\276\344\274\240", 0));
        auto_btn->setText(QApplication::translate("menu", "\350\207\252\345\212\250\346\227\213\350\275\254", 0));
        label_2->setText(QApplication::translate("menu", "\350\247\222\345\272\246\346\216\247\345\210\266", 0));
        label_3->setText(QApplication::translate("menu", "\351\200\237\345\272\246\346\216\247\345\210\266", 0));
        exp_Check_bt->setText(QApplication::translate("menu", "\345\274\202\345\270\270\346\237\245\347\234\213", 0));
        file_Manage_bt->setText(QApplication::translate("menu", "\346\226\207\344\273\266\347\256\241\347\220\206", 0));
        mode_Setup_bt->setText(QApplication::translate("menu", "\346\250\241\345\274\217\350\256\276\347\275\256", 0));
        currentTime_lb->setText(QString());
        fps_lbl->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
