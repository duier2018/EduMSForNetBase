#include "userform.h"
#include "ui_userform.h"

#include "execsql.h"

UserForm::UserForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);

    m_operData = Oper_None;
    m_searchCond = Search_None;

    initWidgetUnits();
    on_pb_search_clicked();
}

UserForm::~UserForm()
{
    delete ui;
}

void UserForm::updateTableInfos(void)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);

    // set header lables
    QStringList headers;
    headers << "账号" << "密码"  << "角色" << "注册时间";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(GlobalVars::g_userInfoList->length());
    for(int i=0; i < GlobalVars::g_userInfoList->length(); i++)
    {
        QTableWidgetItem *item = new  QTableWidgetItem(GlobalVars::g_userInfoList->at(i).getID());
        ui->tableWidget->setItem(i, 0, item);
        item = new  QTableWidgetItem(GlobalVars::g_userInfoList->at(i).getPswd());
        ui->tableWidget->setItem(i, 1, item);
        item = new  QTableWidgetItem(GlobalVars::g_userInfoList->at(i).getRole());
        ui->tableWidget->setItem(i, 2, item);
        item = new  QTableWidgetItem(GlobalVars::g_userInfoList->at(i).getDate());
        ui->tableWidget->setItem(i, 3, item);
    }
}

void UserForm::on_tableWidget_clicked(const QModelIndex &index)
{
    const UserInfo &info = GlobalVars::g_userInfoList->at(index.row());

    ui->le_id->setText(info.getID());
    ui->le_pswd->setText(info.getPswd());
    ui->le_role->setText(info.getRole());
    ui->le_date->setText(info.getDate());
}

void UserForm::on_pb_search_clicked()
{
    if(m_searchCond == Search_ID)
    {
        ExecSQL::searchUserInfoForID(ui->le_condition->text());
    }else if(m_searchCond == Search_Role)
    {
        ExecSQL::searchUserInfoForRole(ui->le_condition->text());
    }else if(m_searchCond == Search_Date)
    {
        ExecSQL::searchUserInfoForDate(ui->le_condition->text());
    }else
    {
        ExecSQL::searchAllUserInfos();
    }

    updateTableInfos();
}

void UserForm::on_cb_condition_currentIndexChanged(int index)
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

void UserForm::initWidgetUnits(void)
{
    ui->le_condition->setEnabled(false);
    ui->le_id->setEnabled(false);
    ui->le_pswd->setEnabled(false);
    ui->le_role->setEnabled(false);
    ui->le_date->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void UserForm::on_pb_cancel_clicked()
{
    ui->le_id->clear();
    ui->le_pswd->clear();
    ui->le_role->clear();
    ui->le_date->clear();

    ui->le_id->setEnabled(false);
    ui->le_pswd->setEnabled(false);
    ui->le_role->setEnabled(false);
    ui->le_date->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void UserForm::on_pb_modify_clicked()
{
    m_operData = Oper_Mdy;
    ui->le_pswd->setEnabled(true);
    ui->le_role->setEnabled(true);
    ui->le_date->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void UserForm::on_pb_delete_clicked()
{
    m_operData = Oper_Del;
    ui->le_pswd->setEnabled(true);
    ui->le_role->setEnabled(true);
    ui->le_date->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void UserForm::on_pb_add_clicked()
{
    m_operData = Oper_Add;
    ui->le_id->setEnabled(true);
    ui->le_pswd->setEnabled(true);
    ui->le_role->setEnabled(true);
    ui->le_date->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void UserForm::on_pb_save_clicked()
{
    if(m_operData == Oper_Mdy)
    {
        ExecSQL::modifyUserInfoForPswd(ui->le_id->text(), ui->le_pswd->text());
        ExecSQL::modifyUserInfoForRole(ui->le_id->text(), ui->le_role->text());
        ExecSQL::modifyUserInfoForDate(ui->le_id->text(), ui->le_date->text());
    }else if(m_operData == Oper_Del)
    {
        ExecSQL::removeUserInfo(ui->le_id->text());
    }else if(m_operData == Oper_Add)
    {
        UserInfo info(ui->le_id->text(),
                         ui->le_pswd->text(),
                         ui->le_role->text(),
                         ui->le_date->text());
        ExecSQL::addNewUserInfo(info);
    }

    on_pb_cancel_clicked();
    on_pb_search_clicked();
}


