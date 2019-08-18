#ifndef COURSEFORM_H
#define COURSEFORM_H

#include <QWidget>
#include "courseinfo.h"

namespace Ui {
class CourseForm;
}

class CourseForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseForm(QWidget *parent = 0);
    ~CourseForm();

    enum Search_Condition{
        Search_None = 0,
        Search_ID,
        Search_Name,
        Search_Type
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
    Ui::CourseForm *ui;

    int m_operData;
    int m_searchCond;

    void updateTableInfos(void);
    void initWidgetUnits(void);
};

#endif // COURSEFORM_H
