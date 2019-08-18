#ifndef GLOBALVARS_H
#define GLOBALVARS_H

#include "userinfo.h"
#include "classinfo.h"
#include "courseinfo.h"
#include "studentinfo.h"
#include "teacherinfo.h"

#include "msgsocket.h"

#include <QQueue>

#define USE_DATABASE 1

enum Oper_Data{
    Oper_None,
    Oper_Add,
    Oper_Del,
    Oper_Mdy
};

enum RESPONSE{
    RES_Down = '!',
    RES_Fail = '?'
};

enum COMMAND{
    ///通用请求命令
    CMD_UserLogin_L = 'L',          //用户登录
    CMD_UserInfo_I = 'I',           //获取个人信息
    CMD_ChangePswd_H = 'H',         //修改密码
    CMD_UserExit_X = 'X',           //用户退出
    ///学生请求命令
    CMD_StudentSchedule_U = 'U',    //学生课表
    CMD_OptionzCourse_O = 'O',      //可选课程
    CMD_SelectedCourse_S = 'S',     //已选课程
    CMD_PickCourse_P = 'P',         //选择课程
    CMD_QueryGrade_Q = 'Q',         //查询成绩
    ///老师请求命令
    CMD_TeacherSchedule_T = 'T',    //老师课表
    CMD_GrantCourse_G = 'G',        //可授课程
    CMD_ExistClass_E = 'E',         //现有班级信息
    CMD_NewClass_N = 'N',           //新建班级信息
    CMD_AddTeaches_A = 'A',         //添加授课
    CMD_PickResult_R = 'R',         //学生选课结果
    CMD_EntryGrade_Y = 'Y'          //录入学生成绩
};

class GlobalVars
{
public:
    static UserInfo g_localUser;
    static TeacherInfo g_localTeacher;
    static StudentInfo g_localStudent;

//    static QQueue<QString> g_msgQueue;

    static ClassInfoList *g_classInfoList;
    static CourseInfoList *g_courseInfoList;
    static TeacherInfoList *g_teacherInfoList;
    static StudentInfoList *g_studentInfoList;
};

#endif // GLOBALVARS_H
