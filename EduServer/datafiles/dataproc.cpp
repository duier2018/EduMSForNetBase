#include "dataproc.h"

#include <QDebug>

ClassInfoList::iterator DataProc::d_classInfoIter;
ClassInfoPtrList DataProc::d_classInfoPtrList;

CourseInfoList::iterator DataProc::d_courseInfoIter;
CourseInfoPtrList DataProc::d_courseInfoPtrList;

StudentInfoList::iterator DataProc::d_studentInfoIter;
StudentInfoPtrList DataProc::d_studentInfoPtrList;

TeacherInfoList::iterator DataProc::d_teacherInfoIter;
TeacherInfoPtrList DataProc::d_teacherInfoPtrList;

//////////////////////////////ClassInfo//////////////////////////
void DataProc::searchAllClassInfos()
{
    d_classInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_classInfoList->length(); i++)
    {
        d_classInfoPtrList.append(&((*GlobalVars::g_classInfoList)[i]));
    }
}

void DataProc::searchClassInfoForID(const QString &value)
{
    d_classInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_classInfoList->length(); i++)
    {
        if(value == GlobalVars::g_classInfoList->at(i).getID())
        {
            d_classInfoPtrList.append(&((*GlobalVars::g_classInfoList)[i]));
        }
    }
}

void DataProc::searchClassInfoForName(const QString &value)
{
    d_classInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_classInfoList->length(); i++)
    {
        if(value == GlobalVars::g_classInfoList->at(i).getName())
        {
            d_classInfoPtrList.append(&((*GlobalVars::g_classInfoList)[i]));
        }
    }
}

void DataProc::searchClassInfoForRoom(const QString &value)
{
    d_classInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_classInfoList->length(); i++)
    {
        if(value == GlobalVars::g_classInfoList->at(i).getRoom())
        {
            d_classInfoPtrList.append(&((*GlobalVars::g_classInfoList)[i]));
        }
    }
}

void DataProc::addNewClassInfo(const ClassInfo &info)
{
    GlobalVars::g_classInfoList->append(info);
}

void DataProc::removeClassInfo()
{
    GlobalVars::g_classInfoList->removeOne(*d_classInfoIter);
}

void DataProc::modifyClassInfoForName(const QString &value)
{
    d_classInfoIter->setName(value);
}

void DataProc::modifyClassInfoForRoom(const QString &value)
{
    d_classInfoIter->setRoom(value);
}

void DataProc::modifyClassInfoForCount(const QString &value)
{
    d_classInfoIter->setCount(value);
}

//////////////////////////////CourseInfo//////////////////////////
void DataProc::searchAllCourseInfos()
{
    d_courseInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_courseInfoList->length(); i++)
    {
        d_courseInfoPtrList.append(&((*GlobalVars::g_courseInfoList)[i]));
    }
}

void DataProc::searchCourseInfoForID(const QString &value)
{
    d_courseInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_courseInfoList->length(); i++)
    {
        if(value == GlobalVars::g_courseInfoList->at(i).getID())
        {
            d_courseInfoPtrList.append(&((*GlobalVars::g_courseInfoList)[i]));
        }
    }
}

void DataProc::searchCourseInfoForName(const QString &value)
{
    d_courseInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_courseInfoList->length(); i++)
    {
        if(value == GlobalVars::g_courseInfoList->at(i).getName())
        {
            d_courseInfoPtrList.append(&((*GlobalVars::g_courseInfoList)[i]));
        }
    }
}

void DataProc::searchCourseInfoForType(const QString &value)
{
    d_courseInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_courseInfoList->length(); i++)
    {
        if(value == GlobalVars::g_courseInfoList->at(i).getType())
        {
            d_courseInfoPtrList.append(&((*GlobalVars::g_courseInfoList)[i]));
        }
    }
}

void DataProc::addNewCourseInfo(const CourseInfo &info)
{
    GlobalVars::g_courseInfoList->append(info);
}

void DataProc::removeCourseInfo()
{
    GlobalVars::g_courseInfoList->removeOne(*d_courseInfoIter);
}

void DataProc::modifyCourseInfoForName(const QString &value)
{
    d_courseInfoIter->setName(value);
}

void DataProc::modifyCourseInfoForType(const QString &value)
{
    d_courseInfoIter->setType(value);
}

void DataProc::modifyCourseInfoForLesson(const QString &value)
{
    d_courseInfoIter->setLesson(value);
}

/////////////////////////////StudentInfo////////////////////////////////////
void DataProc::searchAllStudentInfos()
{
    d_studentInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_studentInfoList->length(); i++)
    {
        d_studentInfoPtrList.append(&((*GlobalVars::g_studentInfoList)[i]));
    }
}

void DataProc::searchStudentInfoForID(const QString &value)
{
    d_studentInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_studentInfoList->length(); i++)
    {
        if(value == GlobalVars::g_studentInfoList->at(i).getID())
        {
            d_studentInfoPtrList.append(&((*GlobalVars::g_studentInfoList)[i]));
        }
    }
}

void DataProc::searchStudentInfoForName(const QString &value)
{
    d_studentInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_studentInfoList->length(); i++)
    {
        if(value == GlobalVars::g_studentInfoList->at(i).getName())
        {
            d_studentInfoPtrList.append(&((*GlobalVars::g_studentInfoList)[i]));
        }
    }
}

void DataProc::searchStudentInfoForDegree(const QString &value)
{
    d_studentInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_studentInfoList->length(); i++)
    {
        if(value == GlobalVars::g_studentInfoList->at(i).getDegree())
        {
            d_studentInfoPtrList.append(&((*GlobalVars::g_studentInfoList)[i]));
        }
    }
}

void DataProc::searchStudentInfoForMajor(const QString &value)
{
    d_studentInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_studentInfoList->length(); i++)
    {
        if(value == GlobalVars::g_studentInfoList->at(i).getMajor())
        {
            d_studentInfoPtrList.append(&((*GlobalVars::g_studentInfoList)[i]));
        }
    }
}

void DataProc::addNewStudentInfo(const StudentInfo &info)
{
    GlobalVars::g_studentInfoList->append(info);
}

void DataProc::removeStudentInfo()
{
    GlobalVars::g_studentInfoList->removeOne(*d_studentInfoIter);
}

void DataProc::modifyStudentInfoForName(const QString &value)
{
    d_studentInfoIter->setName(value);
}

void DataProc::modifyStudentInfoForDegree(const QString &value)
{
    d_studentInfoIter->setDegree(value);
}

void DataProc::modifyStudentInfoForMajor(const QString &value)
{
    d_studentInfoIter->setMajor(value);
}

/////////////////////////////TeacherInfo////////////////////////////////////
void DataProc::searchAllTeacherInfos()
{
    d_teacherInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_teacherInfoList->length(); i++)
    {
        d_teacherInfoPtrList.append(&((*GlobalVars::g_teacherInfoList)[i]));
    }
}

void DataProc::searchTeacherInfoForID(const QString &value)
{
    d_teacherInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_teacherInfoList->length(); i++)
    {
        if(value == GlobalVars::g_teacherInfoList->at(i).getID())
        {
            d_teacherInfoPtrList.append(&((*GlobalVars::g_teacherInfoList)[i]));
        }
    }
}

void DataProc::searchTeacherInfoForName(const QString &value)
{
    d_teacherInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_teacherInfoList->length(); i++)
    {
        if(value == GlobalVars::g_teacherInfoList->at(i).getName())
        {
            d_teacherInfoPtrList.append(&((*GlobalVars::g_teacherInfoList)[i]));
        }
    }
}

void DataProc::searchTeacherInfoForDept(const QString &value)
{
    d_teacherInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_teacherInfoList->length(); i++)
    {
        if(value == GlobalVars::g_teacherInfoList->at(i).getDept())
        {
            d_teacherInfoPtrList.append(&((*GlobalVars::g_teacherInfoList)[i]));
        }
    }
}

void DataProc::searchTeacherInfoForPost(const QString &value)
{
    d_teacherInfoPtrList.clear();
    for(int i = 0; i < GlobalVars::g_teacherInfoList->length(); i++)
    {
        if(value == GlobalVars::g_teacherInfoList->at(i).getPost())
        {
            d_teacherInfoPtrList.append(&((*GlobalVars::g_teacherInfoList)[i]));
        }
    }
}

void DataProc::addNewTeacherInfo(const TeacherInfo &info)
{
    GlobalVars::g_teacherInfoList->append(info);
}

void DataProc::removeTeacherInfo()
{
    GlobalVars::g_teacherInfoList->removeOne(*d_teacherInfoIter);
}

void DataProc::modifyTeacherInfoForName(const QString &value)
{
    d_teacherInfoIter->setName(value);
}

void DataProc::modifyTeacherInfoForDept(const QString &value)
{
    d_teacherInfoIter->setDept(value);
}

void DataProc::modifyTeacherInfoForPost(const QString &value)
{
    d_teacherInfoIter->setPost(value);
}


