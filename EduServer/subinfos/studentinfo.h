#ifndef __STUDENT_H
#define __STUDENT_H

#include <QString>
#include <QList>
#include <QMap>

class StudentInfo
{
public:
    StudentInfo();
    StudentInfo(const QString &id, const QString &name,
                const QString &degree, const QString &major);

    void display(void) const;

    void setID(const QString &id);
    void setName(const QString &name);
    void setDegree(const QString &degree);
    void setMajor(const QString &major);

    const QString &getID() const;
    const QString &getName() const;
    const QString &getDegree() const;
    const QString &getMajor() const;

    friend bool operator==(const StudentInfo &one, const StudentInfo &other);

private:
    QString m_id;
    QString m_name;
    QString m_degree;
    QString m_major;
};

typedef QList<StudentInfo> StudentInfoList;
typedef QList<StudentInfo*> StudentInfoPtrList;    //文件操作使用
typedef QMap<QString, StudentInfoList::iterator> StudentInfoMap;  //网络操作使用

#endif // __STUDENT_H
