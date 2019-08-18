#ifndef TEASCHEDULEFORM_H
#define TEASCHEDULEFORM_H

#include <QWidget>

namespace Ui {
class TeaScheduleForm;
}

class TeaScheduleForm : public QWidget
{
    Q_OBJECT

public:
    explicit TeaScheduleForm(QWidget *parent = 0);
    ~TeaScheduleForm();

private:
    Ui::TeaScheduleForm *ui;
};

#endif // TEASCHEDULEFORM_H
