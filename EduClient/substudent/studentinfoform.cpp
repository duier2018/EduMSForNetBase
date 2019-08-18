#include "studentinfoform.h"
#include "ui_studentinfoform.h"

#include "globalvars.h"

StudentInfoForm::StudentInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentInfoForm)
{
    ui->setupUi(this);
}

StudentInfoForm::~StudentInfoForm()
{
    delete ui;
}

void StudentInfoForm::slotGainStudentInfo(bool res)
{
    if(res)
    {
        ui->le_id->setText(GlobalVars::g_localStudent.getID());
        ui->le_name->setText(GlobalVars::g_localStudent.getName());
        ui->le_degree->setText(GlobalVars::g_localStudent.getDegree());
        ui->le_major->setText(GlobalVars::g_localStudent.getMajor());
        ui->le_date->setText(GlobalVars::g_localUser.getDate());
    }
}
