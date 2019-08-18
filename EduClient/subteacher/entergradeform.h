#ifndef ENTERGRADEFORM_H
#define ENTERGRADEFORM_H

#include <QWidget>

namespace Ui {
class EnterGradeForm;
}

class EnterGradeForm : public QWidget
{
    Q_OBJECT

signals:
    void signalEnterGrade(QString,QString,QString,QString);

public:
    explicit EnterGradeForm(QWidget *parent = 0);
    ~EnterGradeForm();

private slots:
    void on_pb_sure_clicked();

private:
    Ui::EnterGradeForm *ui;
};

#endif // ENTERGRADEFORM_H
