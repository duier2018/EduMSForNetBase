#ifndef GLOBALBUFFERS_H
#define GLOBALBUFFERS_H

#include "classinfo.h"
#include "courseinfo.h"
#include "studentinfo.h"
#include "teacherinfo.h"

class InfoBuffers
{
public:
    InfoBuffers();

    void readAndInitBuffers(void);
    void saveAndCloseBuffers(void);

    static ClassInfoList g_classInfoList;
    static CourseInfoList g_courseInfoList;
    static TeacherInfoList g_teacherInfoList;
    static StudentInfoList g_studentInfoList;

private:
    QString m_classFilePath;
    QString m_courseFilePath;
    QString m_teacherFilePath;
    QString m_studentFilePath;

    void readClassFile();
    void saveClassFile();

    void readCourseFile();
    void saveCourseFile();

    void readTeacherFile();
    void saveTeacherFile();

    void readStudentFile();
    void saveStudentFile();
};

#endif // GLOBALBUFFERS_H
