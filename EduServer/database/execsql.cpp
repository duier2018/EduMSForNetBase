#include "execsql.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>

#include <QDebug>

void ExecSQL::searchAllUserInfos()
{
    QString queryString = QString("select * from user_info");
    qDebug() << queryString;

    updateUserInfoList(queryString);
}

void ExecSQL::searchUserInfoForID(const QString &value)
{
    QString queryString = QString("select * from user_info where id = '%1'").arg(value);
    qDebug() << queryString;

    updateUserInfoList(queryString);
}

void ExecSQL::searchUserInfoForRole(const QString &value)
{
    QString queryString = QString("select * from user_info where role = '%1'").arg(value);
    qDebug() << queryString;

    updateUserInfoList(queryString);
}

void ExecSQL::searchUserInfoForDate(const QString &value)
{
    QString queryString = QString("select * from user_info where date = '%1'").arg(value);
    qDebug() << queryString;

    updateUserInfoList(queryString);
}

void ExecSQL::updateUserInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_userInfoList->clear();
    GlobalVars::g_userInfoMap.clear();
    if(query.exec(sql))
    {
         int id_idx = query.record().indexOf("id");
         int pswd_idx = query.record().indexOf("pswd");
         int role_idx = query.record().indexOf("role");
         int date_idx = query.record().indexOf("date");

         while(query.next())
         {
            QString id = query.value(id_idx).toString();
            QString pswd = query.value(pswd_idx).toString();
            QString role = query.value(role_idx).toString();
            QString date = query.value(date_idx).toString();

            UserInfo info(id, pswd, role, date);
            GlobalVars::g_userInfoList->append(info);
         }

         for(UserInfoList::iterator it = GlobalVars::g_userInfoList->begin();
             it != GlobalVars::g_userInfoList->end(); it++)
         {
            GlobalVars::g_userInfoMap.insert(it->getID(), it);
         }
    }
}

bool ExecSQL::addNewUserInfo(const UserInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into user_info values('%1', '%2', '%3', %4)")
            .arg(info.getID()).arg(info.getPswd()).arg(info.getRole()).arg(info.getRole());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeUserInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from user_info where id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyUserInfoForPswd(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update user_info set pswd = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyUserInfoForRole(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update user_info set role = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyUserInfoForDate(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update user_info set date = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

///////////////////////TeacherInfo/////////////////////////////
void ExecSQL::searchAllTeacherInfos()
{
    QString queryString = QString("select * from teacher_info");
    qDebug() << queryString;

    updateTeacherInfoList(queryString);
}

void ExecSQL::searchTeacherInfoForID(const QString &value)
{
    QString queryString = QString("select * from teacher_info where id = '%1'").arg(value);
    qDebug() << queryString;

    updateTeacherInfoList(queryString);
}

void ExecSQL::searchTeacherInfoForName(const QString &value)
{
    QString queryString = QString("select * from teacher_info where pswd = '%1'").arg(value);
    qDebug() << queryString;

    updateTeacherInfoList(queryString);
}

void ExecSQL::searchTeacherInfoForDept(const QString &value)
{
    QString queryString = QString("select * from teacher_info where dept = '%1'").arg(value);
    qDebug() << queryString;

    updateTeacherInfoList(queryString);
}

void ExecSQL::searchTeacherInfoForPost(const QString &value)
{
    QString queryString = QString("select * from teacher_info where post = '%1'").arg(value);
    qDebug() << queryString;

    updateTeacherInfoList(queryString);
}

void ExecSQL::updateTeacherInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_teacherInfoList->clear();
    if(query.exec(sql))
    {
         int id_idx = query.record().indexOf("id");
         int name_idx = query.record().indexOf("name");
         int dept_idx = query.record().indexOf("dept");
         int post_idx = query.record().indexOf("post");

         while(query.next())
         {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx).toString();
            QString dept = query.value(dept_idx).toString();
            QString post = query.value(post_idx).toString();

            TeacherInfo info(id, name, dept, post);
            GlobalVars::g_teacherInfoList->append(info);
         }

         for(TeacherInfoList::iterator it = GlobalVars::g_teacherInfoList->begin();
             it != GlobalVars::g_teacherInfoList->end(); it++)
         {
            GlobalVars::g_teacherInfoMap.insert(it->getID(), it);
         }
    }
}

bool ExecSQL::addNewTeacherInfo(const TeacherInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into teacher_info values('%1', '%2', '%3', %4)")
            .arg(info.getID()).arg(info.getName()).arg(info.getDept()).arg(info.getPost());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeTeacherInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from teacher_info where id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyTeacherInfoForName(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update teacher_info set name = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyTeacherInfoForDept(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update teacher_info set dept = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyTeacherInfoForPost(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update teacher_info set post = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

///////////////////////StudentInfo/////////////////////////////
void ExecSQL::searchAllStudentInfos()
{
    QString queryString = QString("select * from student_info");
    qDebug() << queryString;

    updateStudentInfoList(queryString);
}

void ExecSQL::searchStudentInfoForID(const QString &value)
{
    QString queryString = QString("select * from student_info where id = '%1'").arg(value);
    qDebug() << queryString;

    updateStudentInfoList(queryString);
}

void ExecSQL::searchStudentInfoForName(const QString &value)
{
    QString queryString = QString("select * from student_info where name = '%1'").arg(value);
    qDebug() << queryString;

    updateStudentInfoList(queryString);
}

void ExecSQL::searchStudentInfoForDegree(const QString &value)
{
    QString queryString = QString("select * from student_info where degree = '%1'").arg(value);
    qDebug() << queryString;

    updateStudentInfoList(queryString);
}

void ExecSQL::searchStudentInfoForMajor(const QString &value)
{
    QString queryString = QString("select * from student_info where major = '%1'").arg(value);
    qDebug() << queryString;

    updateStudentInfoList(queryString);
}

void ExecSQL::updateStudentInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_studentInfoList->clear();
    if(query.exec(sql))
    {
         int id_idx = query.record().indexOf("id");
         int name_idx = query.record().indexOf("name");
         int degree_idx = query.record().indexOf("degree");
         int major_idx = query.record().indexOf("major");

         while(query.next())
         {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx).toString();
            QString degree = query.value(degree_idx).toString();
            QString major = query.value(major_idx).toString();

            StudentInfo info(id, name, degree, major);
            GlobalVars::g_studentInfoList->append(info);
         }

         for(StudentInfoList::iterator it = GlobalVars::g_studentInfoList->begin();
                      it != GlobalVars::g_studentInfoList->end(); it++)
         {
            GlobalVars::g_studentInfoMap.insert(it->getID(), it);
         }
    }
}
bool ExecSQL::addNewStudentInfo(const StudentInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into student_info values('%1', '%2', '%3', %4)")
            .arg(info.getID()).arg(info.getName()).arg(info.getDegree()).arg(info.getMajor());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeStudentInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from student_info where id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyStudentInfoForName(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update student_info set name = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyStudentInfoForDegree(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update student_info set degree = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyStudentInfoForMajor(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update student_info set major = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::EntryGrade(const QString &stuid, const QString &classid, const QString &crouseid, const QString &grade)
{
    QSqlQuery query;
    QString queryString = QString("insert into elect_info values('%1', '%2', '%3', %4)")
            .arg(stuid).arg(classid).arg(crouseid).arg(grade);
    qDebug() << queryString;
    return query.exec(queryString);
}

///////////////////////ClassInfo/////////////////////////////
void ExecSQL::searchAllClassInfos()
{
    QString queryString = QString("select * from class_info");
    qDebug() << queryString;

    updateClassInfoList(queryString);
}

void ExecSQL::searchClassInfoForID(const QString &value)
{
    QString queryString = QString("select * from class_info where id = '%1'").arg(value);
    qDebug() << queryString;

    updateClassInfoList(queryString);
}

void ExecSQL::searchClassInfoForName(const QString &value)
{
    QString queryString = QString("select * from class_info where name = '%1'").arg(value);
    qDebug() << queryString;

    updateClassInfoList(queryString);
}

void ExecSQL::searchClassInfoForRoom(const QString &value)
{
    QString queryString = QString("select * from class_info where room = '%1'").arg(value);
    qDebug() << queryString;

    updateClassInfoList(queryString);
}

void ExecSQL::updateClassInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_classInfoList->clear();
    GlobalVars::g_classInfoMap.clear();
    if(query.exec(sql))
    {
         int id_idx = query.record().indexOf("id");
         int name_idx = query.record().indexOf("name");
         int room_idx = query.record().indexOf("room");
         int count_idx = query.record().indexOf("count");

         while(query.next())
         {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx).toString();
            QString room = query.value(room_idx).toString();
            QString count = query.value(count_idx).toString();

            ClassInfo info(id, name, room, count);
            GlobalVars::g_classInfoList->append(info);
         }

         for(ClassInfoList::iterator it = GlobalVars::g_classInfoList->begin();
             it != GlobalVars::g_classInfoList->end(); it++)
         {
            GlobalVars::g_classInfoMap.insert(it->getID(), it);
         }
    }
}

bool ExecSQL::addNewClassInfo(const ClassInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into class_info values('%1', '%2', '%3', %4)")
            .arg(info.getID()).arg(info.getName()).arg(info.getRoom()).arg(info.getCount());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeClassInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from class_info where id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyClassInfoForName(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update class_info set name = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyClassInfoForRoom(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update class_info set room = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyClassInfoForCount(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update class_info set count = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

/////////////////////CourseInfo//////////////////////////
void ExecSQL::searchAllCourseInfos()
{
    QString queryString = QString("select * from course_info");
    qDebug() << queryString;

    updateCourseInfoList(queryString);
}

void ExecSQL::searchCourseInfoForID(const QString &value)
{
    QString queryString = QString("select * from course_info where id = '%1'").arg(value);
    qDebug() << queryString;

    updateCourseInfoList(queryString);
}

void ExecSQL::searchCourseInfoForName(const QString &value)
{
    QString queryString = QString("select * from course_info where name = '%1'").arg(value);
    qDebug() << queryString;

    updateCourseInfoList(queryString);
}

void ExecSQL::searchCourseInfoForType(const QString &value)
{
    QString queryString = QString("select * from course_info where type = '%1'").arg(value);
    qDebug() << queryString;

    updateTeacherInfoList(queryString);
}

void ExecSQL::updateCourseInfoList(const QString &sql)
{
    QSqlQuery query;
    GlobalVars::g_courseInfoList->clear();
    GlobalVars::g_courseInfoMap.clear();
    if(query.exec(sql))
    {
         int id_idx = query.record().indexOf("id");
         int name_idx = query.record().indexOf("name");
         int type_idx = query.record().indexOf("type");
         int lesson_idx = query.record().indexOf("lesson");

         while(query.next())
         {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx).toString();
            QString type = query.value(type_idx).toString();
            QString lesson = query.value(lesson_idx).toString();

            CourseInfo info(id, name, type, lesson);
            GlobalVars::g_courseInfoList->append(info);
         }

         for(CourseInfoList::iterator it = GlobalVars::g_courseInfoList->begin();
             it != GlobalVars::g_courseInfoList->end(); it++)
         {
            GlobalVars::g_courseInfoMap.insert(it->getID(), it);
         }
    }
}

bool ExecSQL::addNewCourseInfo(const CourseInfo &info)
{
    QSqlQuery query;
    QString queryString = QString("insert into course_info values('%1', '%2', '%3', %4)")
            .arg(info.getID()).arg(info.getName()).arg(info.getType()).arg(info.getLesson());
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::removeCourseInfo(QString value)
{
    QSqlQuery query;
    QString queryString = QString("delete from course_info where id = '%1'").arg(value);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyCourseInfoForName(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update course_info set name = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyCourseInfoForType(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update course_info set type = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}

bool ExecSQL::modifyCourseInfoForLesson(const QString &id, const QString &value)
{
    QSqlQuery query;
    QString queryString = QString("update course_info set lesson = '%1' where id = '%2'").arg(value).arg(id);
    qDebug() << queryString;
    return query.exec(queryString);
}
