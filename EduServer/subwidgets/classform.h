#ifndef CLASSFORM_H
#define CLASSFORM_H

#include <QWidget>
#include "classinfo.h"

namespace Ui {
class ClassForm;
}

class ClassForm : public QWidget
{
    Q_OBJECT

    enum Search_Condition{
        Search_None = 0,
        Search_ID,
        Search_Name,
        Search_Room
    };

public:
    explicit ClassForm(QWidget *parent = 0);
    ~ClassForm();

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
    Ui::ClassForm *ui;

    int m_operData;
    int m_searchCond;

    void updateTableInfos(void);
    void initWidgetUnits(void);
};

#endif // CLASSFORM_H
