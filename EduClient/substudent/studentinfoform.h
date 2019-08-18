#ifndef STUDENTINFOFORM_H
#define STUDENTINFOFORM_H

#include <QWidget>

namespace Ui {
class StudentInfoForm;
}

class StudentInfoForm : public QWidget
{
    Q_OBJECT
public slots:
    void slotGainStudentInfo(bool res);

public:
    explicit StudentInfoForm(QWidget *parent = 0);
    ~StudentInfoForm();

private:
    Ui::StudentInfoForm *ui;
};

#endif // STUDENTINFOFORM_H
