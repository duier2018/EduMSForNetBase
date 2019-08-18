#include "courseform.h"
#include "ui_courseform.h"

#include <QFile>
#include <QTextStream>

#include "globalvars.h"
#include "execsql.h"

CourseForm::CourseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CourseForm)
{
    ui->setupUi(this);

    m_operData = Oper_None;
    m_searchCond = Search_None;

    initWidgetUnits();
    on_pb_search_clicked();
}

CourseForm::~CourseForm()
{
    delete ui;
}

void CourseForm::updateTableInfos(void)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);

    // set header lables
    QStringList headers;
    headers << "课程号" << "名称"  << "类别" << "课时";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
#if USE_DATABASE
    ui->tableWidget->setRowCount(GlobalVars::g_courseInfoList->length());
    for(int i=0; i < GlobalVars::g_courseInfoList->length(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(GlobalVars::g_courseInfoList->at(i).getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new  QTableWidgetItem(GlobalVars::g_courseInfoList->at(i).getName());
        ui->tableWidget->setItem(i, 1, item);
        item = new  QTableWidgetItem(GlobalVars::g_courseInfoList->at(i).getType());
        ui->tableWidget->setItem(i, 2, item);
        item = new  QTableWidgetItem(GlobalVars::g_courseInfoList->at(i).getLesson());
        ui->tableWidget->setItem(i, 3, item);
    }
#else
    ui->tableWidget->setRowCount(DataProc::d_courseInfoPtrList.length());
    for(int i=0; i < DataProc::d_courseInfoPtrList.count(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(DataProc::d_courseInfoPtrList.at(i)->getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new  QTableWidgetItem(DataProc::d_courseInfoPtrList.at(i)->getName());
        ui->tableWidget->setItem(i, 1, item);
        item = new  QTableWidgetItem(DataProc::d_courseInfoPtrList.at(i)->getType());
        ui->tableWidget->setItem(i, 2, item);
        item = new  QTableWidgetItem(DataProc::d_courseInfoPtrList.at(i)->getLesson());
        ui->tableWidget->setItem(i, 3, item);
    }
#endif //USE_DATABASE
}

void CourseForm::on_tableWidget_clicked(const QModelIndex &index)
{
#if USE_DATABASE
    const CourseInfo &info = GlobalVars::g_courseInfoList->at(index.row());
    ui->le_id->setText(info.getID());
    ui->le_name->setText(info.getName());
    ui->le_pswd->setText(info.getType());
    ui->le_major->setText(info.getLesson());
#else
    CourseInfo *info = DataProc::d_courseInfoPtrList.at(index.row());
    DataProc::d_courseInfoIter = qFind(GlobalVars::g_courseInfoList->begin(),
                                      GlobalVars::g_courseInfoList->end(), *info);
    ui->le_id->setText(DataProc::d_courseInfoIter->getID());
    ui->le_name->setText(DataProc::d_courseInfoIter->getName());
    ui->le_pswd->setText(DataProc::d_courseInfoIter->getType());
    ui->le_major->setText(DataProc::d_courseInfoIter->getLesson());
#endif //USE_DATABASE
}

void CourseForm::on_pb_search_clicked()
{
#if USE_DATABASE
    if(m_searchCond == Search_ID)
    {
        ExecSQL::searchCourseInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Name)
    {
        ExecSQL::searchCourseInfoForName(ui->le_condition->text());
    }else if(m_searchCond == Search_Type)
    {
        ExecSQL::searchCourseInfoForType(ui->le_condition->text());
    }else
    {
        ExecSQL::searchAllCourseInfos();
    }
#else
    if(m_searchCond == Search_ID)
    {
        DataProc::searchCourseInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Name)
    {
        DataProc::searchCourseInfoForName(ui->le_condition->text());
    }else if(m_searchCond == Search_Type)
    {
        DataProc::searchCourseInfoForType(ui->le_condition->text());
    }else
    {
        DataProc::searchAllCourseInfos();
    }
#endif //USE_DATABASE

    updateTableInfos();
}
void CourseForm::on_cb_condition_currentIndexChanged(int index)
{
    m_searchCond = index;
    if(m_searchCond == Search_None)
    {
        ui->le_condition->setEnabled(false);
    }else
    {
        ui->le_condition->setEnabled(true);
    }
}

void CourseForm::initWidgetUnits(void)
{
    ui->le_condition->setEnabled(false);
    ui->le_id->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_pswd->setEnabled(false);
    ui->le_major->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void CourseForm::on_pb_cancel_clicked()
{
    ui->le_id->clear();
    ui->le_name->clear();
    ui->le_pswd->clear();
    ui->le_major->clear();

    ui->le_id->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_pswd->setEnabled(false);
    ui->le_major->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void CourseForm::on_pb_modify_clicked()
{
    m_operData = Oper_Mdy;
    ui->le_name->setEnabled(true);
    ui->le_pswd->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void CourseForm::on_pb_delete_clicked()
{
    m_operData = Oper_Del;
    ui->le_name->setEnabled(true);
    ui->le_pswd->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void CourseForm::on_pb_add_clicked()
{
    m_operData = Oper_Add;
    ui->le_id->setEnabled(true);
    ui->le_name->setEnabled(true);
    ui->le_pswd->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void CourseForm::on_pb_save_clicked()
{
#if USE_DATABASE
    if(m_operData == Oper_Mdy)
    {
        ExecSQL::modifyCourseInfoForName(ui->le_id->text(), ui->le_name->text());
        ExecSQL::modifyCourseInfoForType(ui->le_id->text(), ui->le_pswd->text());
        ExecSQL::modifyCourseInfoForLesson(ui->le_id->text(), ui->le_major->text());
    }else if(m_operData == Oper_Del)
    {
        ExecSQL::removeCourseInfo(ui->le_id->text());
    }else if(m_operData == Oper_Add)
    {
        CourseInfo info(ui->le_id->text(),
                         ui->le_name->text(),
                         ui->le_pswd->text(),
                         ui->le_major->text());
        ExecSQL::addNewCourseInfo(info);
    }
#else
    if(m_operData == Oper_Mdy)
    {
        DataProc::modifyCourseInfoForName(ui->le_name->text());
        DataProc::modifyCourseInfoForType(ui->le_pswd->text());
        DataProc::modifyCourseInfoForLesson(ui->le_major->text());
    }else if(m_operData == Oper_Del)
    {
        DataProc::removeCourseInfo();
    }else if(m_operData == Oper_Add)
    {
        CourseInfo info(ui->le_id->text(),
                         ui->le_name->text(),
                         ui->le_pswd->text(),
                         ui->le_major->text());
        DataProc::addNewCourseInfo(info);
    }
#endif //USE_DATABASE

    on_pb_cancel_clicked();
    on_pb_search_clicked();
}
