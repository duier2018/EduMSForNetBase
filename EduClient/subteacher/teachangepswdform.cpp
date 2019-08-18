#include "teachangepswdform.h"
#include "ui_teachangepswdform.h"

TeaChangePswdForm::TeaChangePswdForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeaChangePswdForm)
{
    ui->setupUi(this);
}

TeaChangePswdForm::~TeaChangePswdForm()
{
    delete ui;
}
