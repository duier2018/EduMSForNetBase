#ifndef PICKCOURSEFORM_H
#define PICKCOURSEFORM_H

#include <QWidget>

namespace Ui {
class PickCourseForm;
}

class PickCourseForm : public QWidget
{
    Q_OBJECT

public:
    explicit PickCourseForm(QWidget *parent = 0);
    ~PickCourseForm();

private:
    Ui::PickCourseForm *ui;
};

#endif // PICKCOURSEFORM_H
