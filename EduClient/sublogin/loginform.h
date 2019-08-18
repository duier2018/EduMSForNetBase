#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

signals:
    void signalUserLogin(QString id, QString pswd);
    void signalUserLogout(void);

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

    void userLoginFail(void);

protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *ev);

private slots:
    void on_pb_login_clicked();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
