#include "globalvars.h"

UserInfo GlobalVars::g_localUser;
TeacherInfo GlobalVars::g_localTeacher;
StudentInfo GlobalVars::g_localStudent;

//QQueue<QString> GlobalVars::g_msgQueue;

ClassInfoList *GlobalVars::g_classInfoList = new ClassInfoList;
CourseInfoList *GlobalVars::g_courseInfoList = new CourseInfoList;
TeacherInfoList *GlobalVars::g_teacherInfoList = new TeacherInfoList;
StudentInfoList *GlobalVars::g_studentInfoList = new StudentInfoList;
