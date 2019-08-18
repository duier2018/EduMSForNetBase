#ifndef STUCHANGEPSWDFORM_H
#define STUCHANGEPSWDFORM_H

#include <QWidget>

namespace Ui {
class StuChangePswdForm;
}

class StuChangePswdForm : public QWidget
{
    Q_OBJECT
signals:
    void signalChangePswd(QString pswd);
public:
    explicit StuChangePswdForm(QWidget *parent = 0);
    ~StuChangePswdForm();

private slots:
    void on_pb_changePswd_clicked();

private:
    Ui::StuChangePswdForm *ui;
};

#endif // STUCHANGEPSWDFORM_H
