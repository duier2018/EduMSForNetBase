#ifndef STUSCHEDULEFORM_H
#define STUSCHEDULEFORM_H

#include <QWidget>

namespace Ui {
class StuScheduleForm;
}

class StuScheduleForm : public QWidget
{
    Q_OBJECT

public:
    explicit StuScheduleForm(QWidget *parent = 0);
    ~StuScheduleForm();

private:
    Ui::StuScheduleForm *ui;
};

#endif // STUSCHEDULEFORM_H
