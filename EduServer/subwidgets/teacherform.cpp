#include "teacherform.h"
#include "ui_teacherform.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "globalvars.h"
#include "execsql.h"

TeacherForm::TeacherForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherForm)
{
    ui->setupUi(this);

    m_operData = Oper_None;
    m_searchCond = Search_None;

    initWidgetUnits();
    on_pb_search_clicked();
}

TeacherForm::~TeacherForm()
{
    delete ui;
}

void TeacherForm::updateTableInfos(void)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);

    // set header lables
    QStringList headers;
    headers << "工号" << "姓名"  << "部门" << "职务";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
#if USE_DATABASE
    ui->tableWidget->setRowCount(GlobalVars::g_teacherInfoList->length());
    for(int i=0; i < GlobalVars::g_teacherInfoList->length(); i++)
    {
        QTableWidgetItem *item = new  QTableWidgetItem(GlobalVars::g_teacherInfoList->at(i).getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new  QTableWidgetItem(GlobalVars::g_teacherInfoList->at(i).getName());
        ui->tableWidget->setItem(i, 1, item);
        item = new  QTableWidgetItem(GlobalVars::g_teacherInfoList->at(i).getDept());
        ui->tableWidget->setItem(i, 2, item);
        item = new  QTableWidgetItem(GlobalVars::g_teacherInfoList->at(i).getPost());
        ui->tableWidget->setItem(i, 3, item);
    }
#else
    ui->tableWidget->setRowCount(DataProc::d_teacherInfoPtrList.length());
    for(int i=0; i < DataProc::d_teacherInfoPtrList.count(); i++)
    {
        QTableWidgetItem *item = new  QTableWidgetItem(DataProc::d_teacherInfoPtrList.at(i)->getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new  QTableWidgetItem(DataProc::d_teacherInfoPtrList.at(i)->getName());
        ui->tableWidget->setItem(i, 1, item);
        item = new  QTableWidgetItem(DataProc::d_teacherInfoPtrList.at(i)->getPswd());
        ui->tableWidget->setItem(i, 2, item);
        item = new  QTableWidgetItem(DataProc::d_teacherInfoPtrList.at(i)->getPost());
        ui->tableWidget->setItem(i, 3, item);
    }
#endif //USE_DATABASE
}

void TeacherForm::on_tableWidget_clicked(const QModelIndex &index)
{
#if USE_DATABASE
    const TeacherInfo &info = GlobalVars::g_teacherInfoList->at(index.row());

    ui->le_id->setText(info.getID());
    ui->le_name->setText(info.getName());
    ui->le_dept->setText(info.getDept());
    ui->le_post->setText(info.getPost());
#else
    TeacherInfo *info = DataProc::d_teacherInfoPtrList.at(index.row());
    DataProc::d_teacherInfoIter = qFind(GlobalVars::g_teacherInfoList->begin(),
                                      GlobalVars::g_teacherInfoList->end(), *info);
    ui->le_id->setText(DataProc::d_teacherInfoIter->getID());
    ui->le_name->setText(DataProc::d_teacherInfoIter->getName());
    ui->le_dept->setText(DataProc::d_teacherInfoIter->getPswd());
    ui->le_post->setText(DataProc::d_teacherInfoIter->getPost());
#endif //USE_DATABASE
}

void TeacherForm::on_pb_search_clicked()
{
#if USE_DATABASE
    if(m_searchCond == Search_ID)
    {
        ExecSQL::searchTeacherInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Name)
    {
        ExecSQL::searchTeacherInfoForName(ui->le_condition->text());
    }else if(m_searchCond == Search_Post)
    {
        ExecSQL::searchTeacherInfoForPost(ui->le_condition->text());
    }else
    {
        ExecSQL::searchAllTeacherInfos();
    }
#else
    if(m_searchCond == Search_ID)
    {
        DataProc::searchTeacherInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Name)
    {
        DataProc::searchTeacherInfoForName(ui->le_condition->text());
    }else if(m_searchCond == Search_Post)
    {
        DataProc::searchTeacherInfoForPost(ui->le_condition->text());
    }else
    {
        DataProc::searchAllTeacherInfos();
    }
#endif //USE_DATABASE

    updateTableInfos();
}

void TeacherForm::on_cb_condition_currentIndexChanged(int index)
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

void TeacherForm::initWidgetUnits(void)
{
    ui->le_condition->setEnabled(false);
    ui->le_id->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_dept->setEnabled(false);
    ui->le_post->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void TeacherForm::on_pb_cancel_clicked()
{
    ui->le_id->clear();
    ui->le_name->clear();
    ui->le_dept->clear();
    ui->le_post->clear();

    ui->le_id->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_dept->setEnabled(false);
    ui->le_post->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void TeacherForm::on_pb_modify_clicked()
{
    m_operData = Oper_Mdy;
    ui->le_name->setEnabled(true);
    ui->le_dept->setEnabled(true);
    ui->le_post->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void TeacherForm::on_pb_delete_clicked()
{
    m_operData = Oper_Del;
    ui->le_name->setEnabled(true);
    ui->le_dept->setEnabled(true);
    ui->le_post->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void TeacherForm::on_pb_add_clicked()
{
    m_operData = Oper_Add;
    ui->le_id->setEnabled(true);
    ui->le_name->setEnabled(true);
    ui->le_dept->setEnabled(true);
    ui->le_post->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void TeacherForm::on_pb_save_clicked()
{
#if USE_DATABASE
    if(m_operData == Oper_Mdy)
    {
        ExecSQL::modifyTeacherInfoForName(ui->le_id->text(), ui->le_name->text());
        ExecSQL::modifyTeacherInfoForDept(ui->le_id->text(), ui->le_dept->text());
        ExecSQL::modifyTeacherInfoForPost(ui->le_id->text(), ui->le_post->text());
    }else if(m_operData == Oper_Del)
    {
        ExecSQL::removeTeacherInfo(ui->le_id->text());
    }else if(m_operData == Oper_Add)
    {
        TeacherInfo info(ui->le_id->text(),
                         ui->le_name->text(),
                         ui->le_dept->text(),
                         ui->le_post->text());
        ExecSQL::addNewTeacherInfo(info);
    }
#else
    if(m_operData == Oper_Mdy)
    {
        DataProc::modifyTeacherInfoForName(ui->le_name->text());
        DataProc::modifyTeacherInfoForPswd(ui->le_dept->text());
        DataProc::modifyTeacherInfoForPost(ui->le_post->text());
    }else if(m_operData == Oper_Del)
    {
        DataProc::removeTeacherInfo();
    }else if(m_operData == Oper_Add)
    {
        TeacherInfo info(ui->le_id->text(),
                         ui->le_name->text(),
                         ui->le_dept->text(),
                         ui->le_post->text());
        DataProc::addNewTeacherInfo(info);
    }
#endif //USE_DATABASE

    on_pb_cancel_clicked();
    on_pb_search_clicked();
}
