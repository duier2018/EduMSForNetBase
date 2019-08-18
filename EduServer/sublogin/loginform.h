#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

signals:
    void signalUserLogin(QString id, QString pswd);

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

    void userLoginFail(void);

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_pb_login_clicked();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
