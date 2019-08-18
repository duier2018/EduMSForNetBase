#include "addgradeform.h"
#include "ui_addgradeform.h"

AddGradeForm::AddGradeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddGradeForm)
{
    ui->setupUi(this);
}

AddGradeForm::~AddGradeForm()
{
    delete ui;
}
