#include "changepswdform.h"
#include "ui_changepswdform.h"

ChangePswdForm::ChangePswdForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePswdForm)
{
    ui->setupUi(this);
}

ChangePswdForm::~ChangePswdForm()
{
    delete ui;
}
