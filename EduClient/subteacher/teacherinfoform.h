#ifndef TEACHERINFOFORM_H
#define TEACHERINFOFORM_H

#include <QWidget>

namespace Ui {
class TeacherInfoForm;
}

class TeacherInfoForm : public QWidget
{
    Q_OBJECT

public slots:
    void slotGainTeacherInfo(bool res);

public:
    explicit TeacherInfoForm(QWidget *parent = 0);
    ~TeacherInfoForm();

private:
    Ui::TeacherInfoForm *ui;
};

#endif // TEACHERINFOFORM_H
