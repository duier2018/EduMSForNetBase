#ifndef FILEPROC_H
#define FILEPROC_H

#include <QString>

class FileOper
{
public:
    FileOper();

    void readAndInitBuffers(void);
    void saveAndCloseBuffers(void);

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

#endif // FILEPROC_H
