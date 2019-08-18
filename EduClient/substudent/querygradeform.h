#ifndef QUERYGRADEFORM_H
#define QUERYGRADEFORM_H

#include <QWidget>

namespace Ui {
class QueryGradeForm;
}

class QueryGradeForm : public QWidget
{
    Q_OBJECT

public:
    explicit QueryGradeForm(QWidget *parent = 0);
    ~QueryGradeForm();

private:
    Ui::QueryGradeForm *ui;
};

#endif // QUERYGRADEFORM_H
