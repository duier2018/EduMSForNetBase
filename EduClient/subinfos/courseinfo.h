#ifndef __COURSEINFO_H
#define __COURSEINFO_H

#include <QString>
#include <QList>

class CourseInfo
{
public:
    CourseInfo();
    CourseInfo(const QString &id, const QString &name,
               const QString &type, const QString &lesson);

    void display(void) const;

    void setID(const QString &id);
    void setName(const QString &name);
    void setType(const QString &type);
    void setLesson(const QString &lesson);

    const QString &getID() const;
    const QString &getName() const;
    const QString &getType() const;
    const QString &getLesson() const;

    friend bool operator==(const CourseInfo &one, const CourseInfo &other);

private:
    QString m_id;
    QString m_name;
    QString m_type;
    QString m_lesson;
};

typedef QList<CourseInfo> CourseInfoList;
typedef QList<CourseInfo*> CourseInfoPtrList;

#endif // __COURSEINFO_H
