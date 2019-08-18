#ifndef EXECSQL_H
#define EXECSQL_H

#include "globalvars.h"

class ExecSQL
{
public:
    ///////////////////////UserInfo/////////////////////////////
    static void searchAllUserInfos();
    static void searchUserInfoForID(const QString &value);
    static void searchUserInfoForRole(const QString &value);
    static void searchUserInfoForDate(const QString &value);
    static void updateUserInfoList(const QString &sql);

    static bool addNewUserInfo(const UserInfo &info);
    static bool removeUserInfo(QString value);
    static bool modifyUserInfoForPswd(const QString &id, const QString &value);
    static bool modifyUserInfoForRole(const QString &id, const QString &value);
    static bool modifyUserInfoForDate(const QString &id, const QString &value);

    ///////////////////////TeacherInfo/////////////////////////////
    static void searchAllTeacherInfos();
    static void searchTeacherInfoForID(const QString &value);
    static void searchTeacherInfoForName(const QString &value);
    static void searchTeacherInfoForDept(const QString &value);
    static void searchTeacherInfoForPost(const QString &value);
    static void updateTeacherInfoList(const QString &sql);

    static bool addNewTeacherInfo(const TeacherInfo &info);
    static bool removeTeacherInfo(QString value);
    static bool modifyTeacherInfoForName(const QString &id, const QString &value);
    static bool modifyTeacherInfoForDept(const QString &id, const QString &value);
    static bool modifyTeacherInfoForPost(const QString &id, const QString &value);

    ///////////////////////StudentInfo/////////////////////////////
    static void searchAllStudentInfos();
    static void searchStudentInfoForID(const QString &value);
    static void searchStudentInfoForName(const QString &value);
    static void searchStudentInfoForDegree(const QString &value);
    static void searchStudentInfoForMajor(const QString &value);
    static void updateStudentInfoList(const QString &sql);

    static bool addNewStudentInfo(const StudentInfo &info);
    static bool removeStudentInfo(QString value);
    static bool modifyStudentInfoForName(const QString &id, const QString &value);
    static bool modifyStudentInfoForDegree(const QString &id, const QString &value);
    static bool modifyStudentInfoForMajor(const QString &id, const QString &value);
    static bool EntryGrade(const QString &stuid, const QString &classid, const QString &crouseid, const QString &grade);

    ///////////////////////ClassInfo/////////////////////////////
    static void searchAllClassInfos();
    static void searchClassInfoForID(const QString &value);
    static void searchClassInfoForName(const QString &value);
    static void searchClassInfoForRoom(const QString &value);
    static void updateClassInfoList(const QString &sql);

    static bool addNewClassInfo(const ClassInfo &info);
    static bool removeClassInfo(QString value);
    static bool modifyClassInfoForName(const QString &id, const QString &value);
    static bool modifyClassInfoForRoom(const QString &id, const QString &value);
    static bool modifyClassInfoForCount(const QString &id, const QString &value);

    ///////////////////////CourseInfo/////////////////////////////
    static void searchAllCourseInfos();
    static void searchCourseInfoForID(const QString &value);
    static void searchCourseInfoForName(const QString &value);
    static void searchCourseInfoForType(const QString &value);
    static void updateCourseInfoList(const QString &sql);

    static bool addNewCourseInfo(const CourseInfo &info);
    static bool removeCourseInfo(QString value);
    static bool modifyCourseInfoForName(const QString &id, const QString &value);
    static bool modifyCourseInfoForType(const QString &id, const QString &value);
    static bool modifyCourseInfoForLesson(const QString &id, const QString &value);
};

#endif // EXECSQL_H
