#include "teachplanform.h"
#include "ui_teachplanform.h"

TeachPlanForm::TeachPlanForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachPlanForm)
{
    ui->setupUi(this);
}

TeachPlanForm::~TeachPlanForm()
{
    delete ui;
}
