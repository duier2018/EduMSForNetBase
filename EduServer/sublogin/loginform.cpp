#include "loginform.h"
#include "ui_loginform.h"

#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>

#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPixmap pix(":/images/back.jpg");
    p.drawPixmap(0,0,pix);
}

void LoginForm::on_pb_login_clicked()
{
    emit signalUserLogin(ui->le_uid->text(),
                         ui->le_pswd->text());
}

void LoginForm::userLoginFail(void)
{
    QMessageBox msgBox(this);
    msgBox.setStyleSheet("background-color: rgb(172, 88, 42);");
    msgBox.setText("登录失败!");
    msgBox.setInformativeText("用户名或者密码错误，请重新输入!");
    msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
    msgBox.setDefaultButton(QMessageBox::Retry);
    msgBox.exec();
}
