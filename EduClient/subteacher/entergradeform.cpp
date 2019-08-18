#include "entergradeform.h"
#include "ui_entergradeform.h"

#include <QMessageBox>
#include <QDebug>

EnterGradeForm::EnterGradeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterGradeForm)
{
    ui->setupUi(this);
}

EnterGradeForm::~EnterGradeForm()
{
    delete ui;
}

void EnterGradeForm::on_pb_sure_clicked()
{
    if(ui->le_stuid->text().isEmpty())
    {
        QMessageBox::warning(this, "警告", "学号不能为空!",
                             QMessageBox::Retry|QMessageBox::Close);
    }
    else if(ui->le_classid->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","班号不能为空",
                             QMessageBox::Retry|QMessageBox::Close);
    }
    else if(ui->le_courseid->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","课号不能为空",
                             QMessageBox::Retry|QMessageBox::Close);
    }
    else if(ui->le_grade->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","成绩不能为空",
                             QMessageBox::Retry|QMessageBox::Close);
    }
    else
    {
        emit signalEnterGrade(ui->le_stuid->text(),ui->le_classid->text(),
                              ui->le_courseid->text(),ui->le_grade->text());
        qDebug() << "录入成绩";
    }
}
