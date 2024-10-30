#include "login.h"
#include "ui_login.h"
#include <QAction>

#include <QDebug>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowTitle("安防管理系统-登录"); // 设置窗口标题
    //this->setObjectName("dialog");


    QAction *usr_action = new QAction(this);

    usr_action->setIcon(QIcon(":/new/prefix1/ui_image/login.png"));
    ui->account_edt->addAction(usr_action,QLineEdit::LeadingPosition);
    QAction *pas_action=new QAction(this);
    pas_action->setIcon(QIcon(":/new/prefix1/ui_image/password.png"));
    ui->password_edt->addAction(pas_action,QLineEdit::LeadingPosition);


}

Login::~Login()
{
    delete ui;
}


void Login::on_login_btn_clicked()
{
    // 登录

    // login
    if(ui->account_edt->text() == "admin"){
        if(ui->password_edt->text() == "123456"){
            qDebug() << "login successfully";

            server = new SystemServer(this);
            this->hide();
            server->show();
        }
        else{
            QMessageBox::warning(NULL, "warning", "password error");
            //qDebug() << "password error";
        }

    }
    else{
        QMessageBox::warning(NULL, "warning", "can not find this user");
        //qDebug() << "no this user";
    }

}

void Login::on_register_btn_clicked()
{
    // 注册
}
