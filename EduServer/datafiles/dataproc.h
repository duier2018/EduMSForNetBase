#ifndef DATAPROC_H
#define DATAPROC_H

#include "globalvars.h"

class DataProc
{
public:
    ///////////////////////ClassInfo/////////////////////////////
    static ClassInfoList::iterator d_classInfoIter;
    static ClassInfoPtrList d_classInfoPtrList;

    static void searchAllClassInfos();
    static void searchClassInfoForID(const QString &value);
    static void searchClassInfoForName(const QString &value);
    static void searchClassInfoForRoom(const QString &value);

    static void addNewClassInfo(const ClassInfo &info);
    static void removeClassInfo();
    static void modifyClassInfoForName(const QString &value);
    static void modifyClassInfoForRoom(const QString &value);
    static void modifyClassInfoForCount(const QString &value);

    ///////////////////////CourseInfo/////////////////////////////
    static CourseInfoList::iterator d_courseInfoIter;
    static CourseInfoPtrList d_courseInfoPtrList;

    static void searchAllCourseInfos();
    static void searchCourseInfoForID(const QString &value);
    static void searchCourseInfoForName(const QString &value);
    static void searchCourseInfoForType(const QString &value);

    static void addNewCourseInfo(const CourseInfo &info);
    static void removeCourseInfo();
    static void modifyCourseInfoForName(const QString &value);
    static void modifyCourseInfoForType(const QString &value);
    static void modifyCourseInfoForLesson(const QString &value);

    ///////////////////////StudentInfo/////////////////////////////
    static StudentInfoList::iterator d_studentInfoIter;
    static StudentInfoPtrList d_studentInfoPtrList;

    static void searchAllStudentInfos();
    static void searchStudentInfoForID(const QString &value);
    static void searchStudentInfoForName(const QString &value);
    static void searchStudentInfoForDegree(const QString &value);
    static void searchStudentInfoForMajor(const QString &value);

    static void addNewStudentInfo(const StudentInfo &info);
    static void removeStudentInfo();
    static void modifyStudentInfoForName(const QString &value);
    static void modifyStudentInfoForDegree(const QString &value);
    static void modifyStudentInfoForMajor(const QString &value);

    ///////////////////////TeacherInfo/////////////////////////////
    static TeacherInfoList::iterator d_teacherInfoIter;
    static TeacherInfoPtrList d_teacherInfoPtrList;

    static void searchAllTeacherInfos();
    static void searchTeacherInfoForID(const QString &value);
    static void searchTeacherInfoForName(const QString &value);
    static void searchTeacherInfoForDept(const QString &value);
    static void searchTeacherInfoForPost(const QString &value);

    static void addNewTeacherInfo(const TeacherInfo &info);
    static void removeTeacherInfo();
    static void modifyTeacherInfoForName(const QString &value);
    static void modifyTeacherInfoForDept(const QString &value);
    static void modifyTeacherInfoForPost(const QString &value);
};

#endif // DATAPROC_H
