#ifndef ADDGRADEFORM_H
#define ADDGRADEFORM_H

#include <QWidget>

namespace Ui {
class AddGradeForm;
}

class AddGradeForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddGradeForm(QWidget *parent = 0);
    ~AddGradeForm();

private:
    Ui::AddGradeForm *ui;
};

#endif // ADDGRADEFORM_H
