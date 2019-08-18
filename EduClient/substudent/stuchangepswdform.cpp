#include "stuchangepswdform.h"
#include "ui_stuchangepswdform.h"
#include "globalvars.h"

StuChangePswdForm::StuChangePswdForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StuChangePswdForm)
{
    ui->setupUi(this);
}

StuChangePswdForm::~StuChangePswdForm()
{
    delete ui;
}

void StuChangePswdForm::on_pb_changePswd_clicked()
{
    qDebug() << "1";
    if (ui->le_oldpswd->text() == GlobalVars::g_localUser.getPswd())
    {
        qDebug() << "2";
        if(ui->le_newpswd->text() == ui->le_cmppswd->text())
        {
            qDebug() << "3";
            emit signalChangePswd(ui->le_newpswd->text());
        }
    }
}
