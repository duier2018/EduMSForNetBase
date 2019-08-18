#include "teascheduleform.h"
#include "ui_teascheduleform.h"

TeaScheduleForm::TeaScheduleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeaScheduleForm)
{
    ui->setupUi(this);
}

TeaScheduleForm::~TeaScheduleForm()
{
    delete ui;
}
