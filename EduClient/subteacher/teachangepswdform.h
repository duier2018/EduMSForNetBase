#ifndef TEACHANGEPSWDFORM_H
#define TEACHANGEPSWDFORM_H

#include <QWidget>

namespace Ui {
class TeaChangePswdForm;
}

class TeaChangePswdForm : public QWidget
{
    Q_OBJECT

public:
    explicit TeaChangePswdForm(QWidget *parent = 0);
    ~TeaChangePswdForm();

private:
    Ui::TeaChangePswdForm *ui;
};

#endif // TEACHANGEPSWDFORM_H
