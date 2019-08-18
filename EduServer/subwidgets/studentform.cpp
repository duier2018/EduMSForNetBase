#include "studentform.h"
#include "ui_studentform.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "globalvars.h"
#include "execsql.h"

StudentForm::StudentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentForm)
{
    ui->setupUi(this);

    m_operData = Oper_None;
    m_searchCond = Search_None;

    initWidgetUnits();
    on_pb_search_clicked();
}

StudentForm::~StudentForm()
{
    delete ui;
}

void StudentForm::updateTableInfos(void)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);

    // set header lables
    QStringList headers;
    headers << "工号" << "姓名"  << "年级" << "专业";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
#if USE_DATABASE
    ui->tableWidget->setRowCount(GlobalVars::g_studentInfoList->length());

    for(int i=0; i < GlobalVars::g_studentInfoList->length(); i++)
    {
        QTableWidgetItem *item = new  QTableWidgetItem(GlobalVars::g_studentInfoList->at(i).getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new  QTableWidgetItem(GlobalVars::g_studentInfoList->at(i).getName());
        ui->tableWidget->setItem(i, 1, item);
        item = new  QTableWidgetItem(GlobalVars::g_studentInfoList->at(i).getDegree());
        ui->tableWidget->setItem(i, 2, item);
        item = new  QTableWidgetItem(GlobalVars::g_studentInfoList->at(i).getMajor());
        ui->tableWidget->setItem(i, 3, item);
    }
#else
    ui->tableWidget->setRowCount(DataProc::d_studentInfoPtrList.length());

    for(int i=0; i < DataProc::d_studentInfoPtrList.count(); i++)
    {
        QTableWidgetItem *item = new  QTableWidgetItem(DataProc::d_studentInfoPtrList.at(i)->getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new  QTableWidgetItem(DataProc::d_studentInfoPtrList.at(i)->getName());
        ui->tableWidget->setItem(i, 1, item);
        item = new  QTableWidgetItem(DataProc::d_studentInfoPtrList.at(i)->getDegree());
        ui->tableWidget->setItem(i, 2, item);
        item = new  QTableWidgetItem(DataProc::d_studentInfoPtrList.at(i)->getMajor());
        ui->tableWidget->setItem(i, 3, item);
    }
#endif //USE_DATABASE
}

void StudentForm::on_tableWidget_clicked(const QModelIndex &index)
{
#if USE_DATABASE
    const StudentInfo &info = GlobalVars::g_studentInfoList->at(index.row());

    ui->le_id->setText(info.getID());
    ui->le_name->setText(info.getName());
    ui->le_degree->setText(info.getDegree());
    ui->le_major->setText(info.getMajor());
#else
    StudentInfo *info = DataProc::d_studentInfoPtrList.at(index.row());
    DataProc::d_studentInfoIter = qFind(GlobalVars::g_studentInfoList->begin(),
                                      GlobalVars::g_studentInfoList->end(), *info);
    ui->le_id->setText(DataProc::d_studentInfoIter->getID());
    ui->le_name->setText(DataProc::d_studentInfoIter->getName());
    ui->le_degree->setText(DataProc::d_studentInfoIter->getDegree());
    ui->le_major->setText(DataProc::d_studentInfoIter->getMajor());
#endif //USE_DATABASE
}

void StudentForm::on_pb_search_clicked()
{
#if USE_DATABASE
    if(m_searchCond == Search_ID)
    {
        ExecSQL::searchStudentInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Name)
    {
        ExecSQL::searchStudentInfoForName(ui->le_condition->text());
    }else if(m_searchCond == Search_Degree)
    {
        ExecSQL::searchStudentInfoForDegree(ui->le_condition->text());
    }else if(m_searchCond == Search_Major)
    {
        ExecSQL::searchStudentInfoForMajor(ui->le_condition->text());
    }else
    {
        ExecSQL::searchAllStudentInfos();
    }
#else
    if(m_searchCond == Search_ID)
    {
        DataProc::searchStudentInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Name)
    {
        DataProc::searchStudentInfoForName(ui->le_condition->text());
    }else if(m_searchCond == Search_Degree)
    {
        DataProc::searchStudentInfoForDegree(ui->le_condition->text());
    }else if(m_searchCond == Search_Major)
    {
        DataProc::searchStudentInfoForMajor(ui->le_condition->text());
    }else
    {
        DataProc::searchAllStudentInfos();
    }
#endif //USE_DATABASE

    updateTableInfos();
}

void StudentForm::on_cb_condition_currentIndexChanged(int index)
{
    m_searchCond = index;
    if(m_searchCond == 0)
    {
        ui->le_condition->setEnabled(false);
    }else
    {
        ui->le_condition->setEnabled(true);
    }
}

void StudentForm::initWidgetUnits(void)
{
    ui->le_condition->setEnabled(false);
    ui->le_id->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_degree->setEnabled(false);
    ui->le_major->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void StudentForm::on_pb_cancel_clicked()
{
    ui->le_id->clear();
    ui->le_name->clear();
    ui->le_degree->clear();
    ui->le_major->clear();

    ui->le_id->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_degree->setEnabled(false);
    ui->le_major->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void StudentForm::on_pb_modify_clicked()
{
    m_operData = Oper_Mdy;
    ui->le_name->setEnabled(true);
    ui->le_degree->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void StudentForm::on_pb_delete_clicked()
{
    m_operData = Oper_Del;
    ui->le_name->setEnabled(true);
    ui->le_degree->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void StudentForm::on_pb_add_clicked()
{
    m_operData = Oper_Add;
    ui->le_id->setEnabled(true);
    ui->le_name->setEnabled(true);
    ui->le_degree->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void StudentForm::on_pb_save_clicked()
{
#if USE_DATABASE
    if(m_operData == Oper_Mdy)
    {
        ExecSQL::modifyStudentInfoForName(ui->le_id->text(), ui->le_name->text());
        ExecSQL::modifyStudentInfoForDegree(ui->le_id->text(), ui->le_degree->text());
        ExecSQL::modifyStudentInfoForMajor(ui->le_id->text(), ui->le_major->text());
    }else if(m_operData == Oper_Del)
    {
        ExecSQL::removeStudentInfo(ui->le_id->text());
    }else if(m_operData == Oper_Add)
    {
        StudentInfo info(ui->le_id->text(),
                         ui->le_name->text(),
                         ui->le_degree->text(),
                         ui->le_major->text());
        ExecSQL::addNewStudentInfo(info);
    }
#else
    if(m_operData == Oper_Mdy)
    {
        DataProc::modifyStudentInfoForName(ui->le_name->text());
        DataProc::modifyStudentInfoForDegree(ui->le_degree->text());
        DataProc::modifyStudentInfoForMajor(ui->le_major->text());
    }else if(m_operData == Oper_Del)
    {
        DataProc::removeStudentInfo();
    }else if(m_operData == Oper_Add)
    {
        StudentInfo info(ui->le_id->text(),
                         ui->le_name->text(),
                         ui->le_degree->text(),
                         ui->le_major->text());
        DataProc::addNewStudentInfo(info);
    }
#endif //USE_DATABASE
    on_pb_cancel_clicked();
    on_pb_search_clicked();
}

