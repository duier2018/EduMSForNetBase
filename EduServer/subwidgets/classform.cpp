#include "classform.h"
#include "ui_classform.h"

#include <QDebug>

#include "globalvars.h"
#include "execsql.h"

ClassForm::ClassForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassForm)
{
    ui->setupUi(this);

    m_operData = Oper_None;
    m_searchCond = Search_None;

    initWidgetUnits();
    on_pb_search_clicked();
}

ClassForm::~ClassForm()
{
    delete ui;
}

void ClassForm::updateTableInfos(void)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);


    // set header lables
    QStringList headers;
    headers << "班级号" << "名称"  << "教室" << "人数";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

#if USE_DATABASE
    ui->tableWidget->setRowCount(GlobalVars::g_classInfoList->length());
    for(int i=0; i < GlobalVars::g_classInfoList->count(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(GlobalVars::g_classInfoList->at(i).getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new QTableWidgetItem(GlobalVars::g_classInfoList->at(i).getName());
        ui->tableWidget->setItem(i, 1, item);
        item = new QTableWidgetItem(GlobalVars::g_classInfoList->at(i).getRoom());
        ui->tableWidget->setItem(i, 2, item);
        item = new QTableWidgetItem(GlobalVars::g_classInfoList->at(i).getCount());
        ui->tableWidget->setItem(i, 3, item);
    }
#else
    ui->tableWidget->setRowCount(DataProc::d_classInfoPtrList.length());
    for(int i=0; i < DataProc::d_classInfoPtrList.count(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(DataProc::d_classInfoPtrList.at(i)->getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new  QTableWidgetItem(DataProc::d_classInfoPtrList.at(i)->getName());
        ui->tableWidget->setItem(i, 1, item);
        item = new  QTableWidgetItem(DataProc::d_classInfoPtrList.at(i)->getRoom());
        ui->tableWidget->setItem(i, 2, item);
        item = new  QTableWidgetItem(DataProc::d_classInfoPtrList.at(i)->getCount());
        ui->tableWidget->setItem(i, 3, item);
    }
#endif //USE_DATABASE
}
void ClassForm::on_tableWidget_clicked(const QModelIndex &index)
{
#if USE_DATABASE
    const ClassInfo &info = GlobalVars::g_classInfoList->at(index.row());

    ui->le_id->setText(info.getID());
    ui->le_name->setText(info.getName());
    ui->le_pswd->setText(info.getRoom());
    ui->le_major->setText(info.getCount());
#else
    ClassInfo *info = DataProc::d_classInfoPtrList.at(index.row());
    DataProc::d_classInfoIter = qFind(GlobalVars::g_classInfoList->begin(),
                                      GlobalVars::g_classInfoList->end(), *info);
    ui->le_id->setText(DataProc::d_classInfoIter->getID());
    ui->le_name->setText(DataProc::d_classInfoIter->getName());
    ui->le_pswd->setText(DataProc::d_classInfoIter->getRoom());
    ui->le_major->setText(DataProc::d_classInfoIter->getCount());
#endif //USE_DATABASE
}

void ClassForm::on_pb_search_clicked()
{
#if USE_DATABASE
    if(m_searchCond == Search_ID)
    {
        ExecSQL::searchClassInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Name)
    {
        ExecSQL::searchClassInfoForName(ui->le_condition->text());
    }else if(m_searchCond == Search_Room)
    {
        ExecSQL::searchClassInfoForRoom(ui->le_condition->text());
    }else
    {
        ExecSQL::searchAllClassInfos();
    }

#else
    if(m_searchCond == Search_ID)
    {
        DataProc::searchClassInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Name)
    {
        DataProc::searchClassInfoForName(ui->le_condition->text());
    }else if(m_searchCond == Search_Room)
    {
        DataProc::searchClassInfoForRoom(ui->le_condition->text());
    }else
    {
        DataProc::searchAllClassInfos();
    }    
#endif //USE_DATABASE

    updateTableInfos();
}

void ClassForm::on_cb_condition_currentIndexChanged(int index)
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

void ClassForm::initWidgetUnits(void)
{
    ui->le_condition->setEnabled(false);
    ui->le_id->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_pswd->setEnabled(false);
    ui->le_major->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void ClassForm::on_pb_cancel_clicked()
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

void ClassForm::on_pb_modify_clicked()
{
    m_operData = Oper_Mdy;
    ui->le_name->setEnabled(true);
    ui->le_pswd->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void ClassForm::on_pb_delete_clicked()
{
    m_operData = Oper_Del;
    ui->le_name->setEnabled(true);
    ui->le_pswd->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void ClassForm::on_pb_add_clicked()
{
    m_operData = Oper_Add;
    ui->le_id->setEnabled(true);
    ui->le_name->setEnabled(true);
    ui->le_pswd->setEnabled(true);
    ui->le_major->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void ClassForm::on_pb_save_clicked()
{
#if USE_DATABASE
    if(m_operData == Oper_Mdy)
    {
        ExecSQL::modifyClassInfoForName(ui->le_id->text(), ui->le_name->text());
        ExecSQL::modifyClassInfoForRoom(ui->le_id->text(), ui->le_pswd->text());
        ExecSQL::modifyClassInfoForCount(ui->le_id->text(), ui->le_major->text());
    }else if(m_operData == Oper_Del)
    {
        ExecSQL::removeClassInfo(ui->le_id->text());
    }else if(m_operData == Oper_Add)
    {
        ClassInfo info(ui->le_id->text(),
                         ui->le_name->text(),
                         ui->le_pswd->text(),
                         ui->le_major->text());
        ExecSQL::addNewClassInfo(info);
    }
#else
    if(m_operData == Oper_Mdy)
    {
        DataProc::modifyClassInfoForName(ui->le_name->text());
        DataProc::modifyClassInfoForRoom(ui->le_pswd->text());
        DataProc::modifyClassInfoForCount(ui->le_major->text());
    }else if(m_operData == Oper_Del)
    {
        DataProc::removeClassInfo();
    }else if(m_operData == Oper_Add)
    {
        ClassInfo info(ui->le_id->text(),
                         ui->le_name->text(),
                         ui->le_pswd->text(),
                         ui->le_major->text());
        DataProc::addNewClassInfo(info);
    }
#endif //USE_DATABASE

    on_pb_cancel_clicked();
    on_pb_search_clicked();
}
