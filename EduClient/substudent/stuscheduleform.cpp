#include "stuscheduleform.h"
#include "ui_stuscheduleform.h"

StuScheduleForm::StuScheduleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StuScheduleForm)
{
    ui->setupUi(this);
}

StuScheduleForm::~StuScheduleForm()
{
    delete ui;
}
