#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include <QWidget>
#include "studentinfo.h"

namespace Ui {
class StudentForm;
}

class StudentForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentForm(QWidget *parent = 0);
    ~StudentForm();

    enum Search_Condition{
        Search_None = 0,
        Search_ID,
        Search_Name,
        Search_Degree,
        Search_Major
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
    Ui::StudentForm *ui;

    int m_operData;
    int m_searchCond;

    void updateTableInfos(void);
    void initWidgetUnits(void);
};

#endif // STUDENTFORM_H
