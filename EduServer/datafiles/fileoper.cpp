#include "fileoper.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "globalvars.h"

FileOper::FileOper()
{
    m_classFilePath = "../EduMSForDB/datafiles/class.txt";
    m_courseFilePath = "../EduMSForDB/datafiles/course.txt";
    m_teacherFilePath = "../EduMSForDB/datafiles/teacher.txt";
    m_studentFilePath = "../EduMSForDB/datafiles/student.txt";
}

void FileOper::readAndInitBuffers(void)
{
    readClassFile();
    readCourseFile();
    readTeacherFile();
    readStudentFile();
}

void FileOper::saveAndCloseBuffers(void)
{
    saveClassFile();
    saveCourseFile();
    saveTeacherFile();
    saveStudentFile();
}

void FileOper::readClassFile()
{
    qDebug() << "FileOper::readClassFile()";
    QFile f(m_classFilePath);
    if(f.open(QIODevice::ReadOnly))
    {
        ClassInfo info;
        QString id, name, room, count;
        QTextStream ts(&f);
        while(!ts.atEnd())
        {
            ts >> id >> name >> room >> count;
            if(!id.isEmpty())
            {
                info = ClassInfo(id, name, room, count);
                GlobalVars::g_classInfoList->append(info);
            }
        }
        f.close();
    }
}

void FileOper::saveClassFile()
{
    qDebug() << "FileOper::saveClassFile()";
    QFile f(m_classFilePath);
    if(f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream ts(&f);
        for(int i = 0; i < GlobalVars::g_classInfoList->length(); i++)
        {
            ts << GlobalVars::g_classInfoList->at(i).getID() << "\t\t"
               << GlobalVars::g_classInfoList->at(i).getName() << "\t\t"
               << GlobalVars::g_classInfoList->at(i).getRoom() << "\t\t"
               << GlobalVars::g_classInfoList->at(i).getCount() <<'\n';
        }
        f.close();
    }
}

void FileOper::readCourseFile()
{
    qDebug() << "FileOper::readCourseFile()";
    QFile f(m_courseFilePath);
    if(f.open(QIODevice::ReadOnly))
    {
        CourseInfo info;
        QString id, name, room, count;
        QTextStream ts(&f);
        while(!ts.atEnd())
        {
            ts >> id >> name >> room >> count;
            if(!id.isEmpty())
            {
                info = CourseInfo(id, name, room, count);
                GlobalVars::g_courseInfoList->append(info);
            }
        }
        f.close();
    }
}

void FileOper::saveCourseFile()
{
    qDebug() << "FileOper::saveCourseFile()";
    QFile f(m_courseFilePath);
    if(f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream ts(&f);
        for(int i = 0; i < GlobalVars::g_courseInfoList->length(); i++)
        {
            ts << GlobalVars::g_courseInfoList->at(i).getID() << "\t\t"
               << GlobalVars::g_courseInfoList->at(i).getName() << "\t\t"
               << GlobalVars::g_courseInfoList->at(i).getType() << "\t\t"
               << GlobalVars::g_courseInfoList->at(i).getLesson() <<'\n';
        }
        f.close();
    }
}

void FileOper::readTeacherFile()
{
    qDebug() << "FileOper::readTeacherFile()";
    QFile f(m_teacherFilePath);
    if(f.open(QIODevice::ReadOnly))
    {
        TeacherInfo info;
        QString id, name, dept, post;
        QTextStream ts(&f);
        while(!ts.atEnd())
        {
            ts >> id >> name >> dept >> post;
            if(!id.isEmpty())
            {
                info = TeacherInfo(id, name, dept, post);
                GlobalVars::g_teacherInfoList->append(info);
            }

        }
        f.close();
    }
}

void FileOper::saveTeacherFile()
{
    qDebug() << "FileOper::saveTeacherFile()";
    QFile f(m_teacherFilePath);
    if(f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream ts(&f);
        for(int i = 0; i < GlobalVars::g_teacherInfoList->length(); i++)
        {
            ts << GlobalVars::g_teacherInfoList->at(i).getID() << "\t\t"
               << GlobalVars::g_teacherInfoList->at(i).getName() << "\t\t"
               << GlobalVars::g_teacherInfoList->at(i).getDept() << "\t\t"
               << GlobalVars::g_teacherInfoList->at(i).getPost() <<'\n';
        }
        f.close();
    }
}

void FileOper::readStudentFile()
{
    qDebug() << "FileOper::readStudentFile()";
    QFile f(m_studentFilePath);
    if(f.open(QIODevice::ReadOnly))
    {
        StudentInfo info;
        QString id, name, degree, major;
        QTextStream ts(&f);
        while(!ts.atEnd())
        {
            ts >> id >> name >> degree >> major;
            if(!id.isEmpty())
            {
                info = StudentInfo(id, name, degree, major);
                GlobalVars::g_studentInfoList->append(info);
            }
        }
        f.close();
    }
}

void FileOper::saveStudentFile()
{
    qDebug() << "FileOper::saveStudentFile()";
    QFile f(m_studentFilePath);
    if(f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream ts(&f);
        for(int i = 0; i < GlobalVars::g_studentInfoList->length(); i++)
        {
            ts << GlobalVars::g_studentInfoList->at(i).getID() << "\t\t"
               << GlobalVars::g_studentInfoList->at(i).getName() << "\t\t"
               << GlobalVars::g_studentInfoList->at(i).getDegree() << "\t\t"
               << GlobalVars::g_studentInfoList->at(i).getMajor() <<'\n';
        }
        f.close();
    }
}

