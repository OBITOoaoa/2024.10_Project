#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <systemserver.h>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_login_btn_clicked();

    void on_register_btn_clicked();

private:
    Ui::Login *ui;

    SystemServer *server;

};

#endif // LOGIN_H
