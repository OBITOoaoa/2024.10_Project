/********************************************************************************
** Form generated from reading UI file 'fops.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOPS_H
#define UI_FOPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fops
{
public:
    QPushButton *back_menu_bt;
    QWidget *widget;
    QPushButton *video_btn;
    QPushButton *photo_btn;
    QPushButton *del_btn;
    QLineEdit *search_edt;
    QPushButton *next_btn;
    QPushButton *rename_btn;
    QPushButton *previous_btn;
    QLineEdit *rename_edt;
    QPushButton *search_btn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QListWidget *vidWidget;
    QWidget *page_2;
    QListWidget *picWidget;

    void setupUi(QWidget *fops)
    {
        if (fops->objectName().isEmpty())
            fops->setObjectName(QStringLiteral("fops"));
        fops->resize(1024, 600);
        fops->setStyleSheet(QLatin1String("#fops{border-image: url(:/images/menu1.jpg);}\n"
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
        back_menu_bt = new QPushButton(fops);
        back_menu_bt->setObjectName(QStringLiteral("back_menu_bt"));
        back_menu_bt->setGeometry(QRect(940, 0, 81, 41));
        QFont font;
        font.setPointSize(11);
        back_menu_bt->setFont(font);
        back_menu_bt->setFocusPolicy(Qt::NoFocus);
        widget = new QWidget(fops);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 50, 191, 541));
        widget->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,200);"));
        video_btn = new QPushButton(widget);
        video_btn->setObjectName(QStringLiteral("video_btn"));
        video_btn->setGeometry(QRect(10, 20, 171, 41));
        video_btn->setFocusPolicy(Qt::NoFocus);
        video_btn->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        video_btn->setIcon(icon);
        video_btn->setIconSize(QSize(30, 29));
        photo_btn = new QPushButton(widget);
        photo_btn->setObjectName(QStringLiteral("photo_btn"));
        photo_btn->setGeometry(QRect(10, 80, 171, 41));
        photo_btn->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/photo.png"), QSize(), QIcon::Normal, QIcon::Off);
        photo_btn->setIcon(icon1);
        photo_btn->setIconSize(QSize(30, 30));
        del_btn = new QPushButton(fops);
        del_btn->setObjectName(QStringLiteral("del_btn"));
        del_btn->setGeometry(QRect(430, 550, 99, 33));
        QFont font1;
        font1.setPointSize(9);
        del_btn->setFont(font1);
        del_btn->setFocusPolicy(Qt::NoFocus);
        search_edt = new QLineEdit(fops);
        search_edt->setObjectName(QStringLiteral("search_edt"));
        search_edt->setGeometry(QRect(790, 550, 113, 33));
        QFont font2;
        font2.setPointSize(5);
        search_edt->setFont(font2);
        next_btn = new QPushButton(fops);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        next_btn->setGeometry(QRect(320, 550, 99, 33));
        next_btn->setFont(font1);
        next_btn->setFocusPolicy(Qt::NoFocus);
        rename_btn = new QPushButton(fops);
        rename_btn->setObjectName(QStringLiteral("rename_btn"));
        rename_btn->setGeometry(QRect(670, 550, 99, 33));
        rename_btn->setFont(font1);
        rename_btn->setFocusPolicy(Qt::NoFocus);
        previous_btn = new QPushButton(fops);
        previous_btn->setObjectName(QStringLiteral("previous_btn"));
        previous_btn->setGeometry(QRect(210, 550, 99, 33));
        previous_btn->setFont(font1);
        previous_btn->setFocusPolicy(Qt::NoFocus);
        rename_edt = new QLineEdit(fops);
        rename_edt->setObjectName(QStringLiteral("rename_edt"));
        rename_edt->setGeometry(QRect(550, 550, 113, 33));
        rename_edt->setFont(font2);
        search_btn = new QPushButton(fops);
        search_btn->setObjectName(QStringLiteral("search_btn"));
        search_btn->setGeometry(QRect(910, 550, 99, 33));
        search_btn->setFont(font1);
        search_btn->setFocusPolicy(Qt::NoFocus);
        stackedWidget = new QStackedWidget(fops);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(210, 50, 800, 490));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,200);"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        vidWidget = new QListWidget(page);
        vidWidget->setObjectName(QStringLiteral("vidWidget"));
        vidWidget->setGeometry(QRect(0, 0, 800, 490));
        vidWidget->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,200);"));
        vidWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        picWidget = new QListWidget(page_2);
        picWidget->setObjectName(QStringLiteral("picWidget"));
        picWidget->setGeometry(QRect(0, 0, 800, 490));
        picWidget->setStyleSheet(QStringLiteral("background-color: rgba(0, 33, 68,200);"));
        picWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->addWidget(page_2);

        retranslateUi(fops);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fops);
    } // setupUi

    void retranslateUi(QWidget *fops)
    {
        fops->setWindowTitle(QApplication::translate("fops", "Form", 0));
        back_menu_bt->setText(QApplication::translate("fops", "\350\277\224\345\233\236", 0));
        video_btn->setText(QApplication::translate("fops", "\345\275\225\345\203\217", 0));
        photo_btn->setText(QApplication::translate("fops", "\345\233\276\347\211\207", 0));
        del_btn->setText(QApplication::translate("fops", "\345\210\240\351\231\244", 0));
        next_btn->setText(QApplication::translate("fops", "\344\270\213\344\270\200\351\241\265", 0));
        rename_btn->setText(QApplication::translate("fops", "\351\207\215\345\221\275\345\220\215", 0));
        previous_btn->setText(QApplication::translate("fops", "\344\270\212\344\270\200\351\241\265", 0));
        search_btn->setText(QApplication::translate("fops", " \346\220\234\347\264\242", 0));
    } // retranslateUi

};

namespace Ui {
    class fops: public Ui_fops {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOPS_H
