#ifndef TEACHERFORM_H
#define TEACHERFORM_H

#include <QWidget>
#include "teacherinfo.h"

#include <QTableWidgetItem>

namespace Ui {
class TeacherForm;
}

class TeacherForm : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherForm(QWidget *parent = 0);
    ~TeacherForm();

    enum Search_Condition{
        Search_None = 0,
        Search_ID,
        Search_Name,
        Search_Post
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
    Ui::TeacherForm *ui;

    int m_operData;
    int m_searchCond;

    void updateTableInfos(void);
    void initWidgetUnits(void);
};

#endif // TEACHERFORM_H
