#include "querygradeform.h"
#include "ui_querygradeform.h"

QueryGradeForm::QueryGradeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryGradeForm)
{
    ui->setupUi(this);
}

QueryGradeForm::~QueryGradeForm()
{
    delete ui;
}
