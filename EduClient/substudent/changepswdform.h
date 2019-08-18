#ifndef CHANGEPSWDFORM_H
#define CHANGEPSWDFORM_H

#include <QWidget>

namespace Ui {
class ChangePswdForm;
}

class ChangePswdForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePswdForm(QWidget *parent = 0);
    ~ChangePswdForm();

private:
    Ui::ChangePswdForm *ui;
};

#endif // CHANGEPSWDFORM_H
