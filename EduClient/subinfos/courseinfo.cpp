#include "courseinfo.h"

#include <QDebug>

CourseInfo::CourseInfo()
{
    m_id.clear();
    m_name.clear();
    m_type.clear();
    m_lesson.clear();
}

CourseInfo::CourseInfo(const QString &id, const QString &name,
                         const QString &type, const QString &lesson)
{
    m_id = id;
    m_name = name;
    m_type = type;
    m_lesson = lesson;
}

void CourseInfo::display(void)const
{
    qDebug() << "ID: " << m_id;
    qDebug() << "Name: " << m_name;
    qDebug() << "Type: " << m_type;
    qDebug() << "Lesson: " << m_lesson;
}

void CourseInfo::setID(const QString &id)
{
    m_id = id;
}

void CourseInfo::setName(const QString &name)
{
    m_name = name;
}

void CourseInfo::setType(const QString &type)
{
    m_type = type;
}

void CourseInfo::setLesson(const QString &lesson)
{
    m_lesson = lesson;
}

const QString &CourseInfo::getID() const
{
    return m_id;
}
const QString &CourseInfo::getName() const
{
    return m_name;
}
const QString &CourseInfo::getType() const
{
    return m_type;
}
const QString &CourseInfo::getLesson() const
{
    return m_lesson;
}

bool operator==(const CourseInfo &one, const CourseInfo &other)
{
    return one.m_id == other.m_id;
}


