#include "pickcourseform.h"
#include "ui_pickcourseform.h"

PickCourseForm::PickCourseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PickCourseForm)
{
    ui->setupUi(this);
}

PickCourseForm::~PickCourseForm()
{
    delete ui;
}
