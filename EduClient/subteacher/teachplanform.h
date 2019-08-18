#ifndef TEACHPLANFORM_H
#define TEACHPLANFORM_H

#include <QWidget>

namespace Ui {
class TeachPlanForm;
}

class TeachPlanForm : public QWidget
{
    Q_OBJECT

public:
    explicit TeachPlanForm(QWidget *parent = 0);
    ~TeachPlanForm();

private:
    Ui::TeachPlanForm *ui;
};

#endif // TEACHPLANFORM_H
