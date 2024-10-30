/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QCheckBox *checkBox_2;
    QLineEdit *account_edt;
    QLineEdit *password_edt;
    QPushButton *register_btn;
    QCheckBox *checkBox;
    QPushButton *login_btn;
    QLabel *label;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(1024, 600);
        Login->setStyleSheet(QLatin1String("#Login{background-image: url(:/images/menu1.jpg);}\n"
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
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(212, 125, 600, 350));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(350, 260, 141, 81));
        QFont font;
        font.setPointSize(10);
        checkBox_2->setFont(font);
        checkBox_2->setFocusPolicy(Qt::NoFocus);
        account_edt = new QLineEdit(frame);
        account_edt->setObjectName(QStringLiteral("account_edt"));
        account_edt->setGeometry(QRect(190, 120, 231, 31));
        password_edt = new QLineEdit(frame);
        password_edt->setObjectName(QStringLiteral("password_edt"));
        password_edt->setGeometry(QRect(190, 160, 231, 31));
        password_edt->setEchoMode(QLineEdit::Password);
        register_btn = new QPushButton(frame);
        register_btn->setObjectName(QStringLiteral("register_btn"));
        register_btn->setGeometry(QRect(330, 210, 91, 51));
        QFont font1;
        font1.setPointSize(11);
        register_btn->setFont(font1);
        register_btn->setFocusPolicy(Qt::NoFocus);
        register_btn->setStyleSheet(QStringLiteral(""));
        register_btn->setFlat(false);
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(190, 260, 131, 81));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        checkBox->setFont(font2);
        checkBox->setFocusPolicy(Qt::NoFocus);
        checkBox->setStyleSheet(QStringLiteral(""));
        login_btn = new QPushButton(frame);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(200, 210, 91, 51));
        login_btn->setFont(font1);
        login_btn->setMouseTracking(false);
        login_btn->setFocusPolicy(Qt::NoFocus);
        login_btn->setStyleSheet(QStringLiteral(""));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 20, 261, 101));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("color: rgba(255, 255,255, 250);"));
        label->setAlignment(Qt::AlignCenter);
        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "MainWindow", 0));
        checkBox_2->setText(QApplication::translate("Login", "\345\277\230\350\256\260\345\257\206\347\240\201", 0));
        account_edt->setText(QApplication::translate("Login", "admin", 0));
        account_edt->setPlaceholderText(QApplication::translate("Login", "User Name", 0));
        password_edt->setText(QApplication::translate("Login", "123456", 0));
        password_edt->setPlaceholderText(QApplication::translate("Login", "Password", 0));
        register_btn->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0));
        checkBox->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        login_btn->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("Login", "\345\256\211\351\230\262\347\263\273\347\273\237\346\254\242\350\277\216\344\275\240", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
