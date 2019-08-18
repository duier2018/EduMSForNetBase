#ifndef SCHEDULEFORM_H
#define SCHEDULEFORM_H

#include <QWidget>

namespace Ui {
class ScheduleForm;
}

class ScheduleForm : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleForm(QWidget *parent = 0);
    ~ScheduleForm();

private:
    Ui::ScheduleForm *ui;
};

#endif // SCHEDULEFORM_H
