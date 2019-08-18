#include "teacherinfoform.h"
#include "ui_teacherinfoform.h"

#include "globalvars.h"

TeacherInfoForm::TeacherInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherInfoForm)
{
    ui->setupUi(this);
}

TeacherInfoForm::~TeacherInfoForm()
{
    delete ui;
}

void TeacherInfoForm::slotGainTeacherInfo(bool res)
{
    if(res)
    {
        ui->le_id->setText(GlobalVars::g_localTeacher.getID());
        ui->le_name->setText(GlobalVars::g_localTeacher.getName());
        ui->le_dept->setText(GlobalVars::g_localTeacher.getDept());
        ui->le_post->setText(GlobalVars::g_localTeacher.getPost());
        ui->le_date->setText(GlobalVars::g_localUser.getDate());
    }
}
