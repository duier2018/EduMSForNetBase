#include "globalvars.h"

QQueue<QString> GlobalVars::g_msgQueue;

UserInfoMap GlobalVars::g_userInfoMap;
TeacherInfoMap GlobalVars::g_teacherInfoMap;
StudentInfoMap GlobalVars::g_studentInfoMap;
ClassInfoMap GlobalVars::g_classInfoMap;
CourseInfoMap GlobalVars::g_courseInfoMap;

UserInfoList *GlobalVars::g_userInfoList = new UserInfoList;
ClassInfoList *GlobalVars::g_classInfoList = new ClassInfoList;
CourseInfoList *GlobalVars::g_courseInfoList = new CourseInfoList;
TeacherInfoList *GlobalVars::g_teacherInfoList = new TeacherInfoList;
StudentInfoList *GlobalVars::g_studentInfoList = new StudentInfoList;
