#include "scheduleform.h"
#include "ui_scheduleform.h"

ScheduleForm::ScheduleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleForm)
{
    ui->setupUi(this);
}

ScheduleForm::~ScheduleForm()
{
    delete ui;
}
