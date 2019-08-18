#ifndef USERFORM_H
#define USERFORM_H

#include <QWidget>

namespace Ui {
class UserForm;
}

class UserForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserForm(QWidget *parent = 0);
    ~UserForm();

    enum Search_Condition{
        Search_None = 0,
        Search_ID,
        Search_Role,
        Search_Date
    };

private slots:
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_pb_search_clicked();
    void on_cb_condition_currentIndexChanged(int index);

    void on_pb_cancel_clicked();
    void on_pb_modify_clicked();
    void on_pb_delete_clicked();
    void on_pb_add_clicked();
    void on_pb_save_clicked();

private:
    Ui::UserForm *ui;

    int m_operData;
    int m_searchCond;

    void updateTableInfos(void);
    void initWidgetUnits(void);
};

#endif // USERFORM_H
