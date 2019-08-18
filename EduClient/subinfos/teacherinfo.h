#ifndef __TEACHER_INFO_H
#define __TEACHER_INFO_H

#include <QString>
#include <QList>

class TeacherInfo
{
public:
    TeacherInfo();
    TeacherInfo(const QString &id, const QString &name,
                const QString &dept, const QString &post);

    void display(void) const;

    void setID(const QString &id);
    void setName(const QString &name);
    void setDept(const QString &dept);
    void setPost(const QString &post);

    const QString &getID() const;
    const QString &getName() const;
    const QString &getDept() const;
    const QString &getPost() const;

    friend bool operator==(const TeacherInfo &one, const TeacherInfo &other);

private:
    QString m_id;
    QString m_name;
    QString m_dept;
    QString m_post;
};

typedef QList<TeacherInfo> TeacherInfoList;
typedef QList<TeacherInfo*> TeacherInfoPtrList;

#endif // __TEACHER_INFO_H
