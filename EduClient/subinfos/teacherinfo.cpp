#include "teacherinfo.h"

#include <QDebug>

TeacherInfo::TeacherInfo()
{
    m_id.clear();
    m_name.clear();
    m_dept.clear();
    m_post.clear();
}

TeacherInfo::TeacherInfo(const QString &id, const QString &name,
            const QString &dept, const QString &post)
{
    m_id = id;
    m_name = name;
    m_dept = dept;
    m_post = post;
}

void TeacherInfo::display(void) const
{
    qDebug() << "ID: " << m_id;
    qDebug() << "Name: " << m_name;
    qDebug() << "Dept: " << m_dept;
    qDebug() << "Post: " << m_post;
}

void TeacherInfo::setID(const QString &id)
{
    m_id = id;
}

void TeacherInfo::setName(const QString &name)
{
    m_name = name;
}

void TeacherInfo::setDept(const QString &dept)
{
    m_dept = dept;
}

void TeacherInfo::setPost(const QString &post)
{
    m_post = post;
}

const QString &TeacherInfo::getID() const
{
    return m_id;
}
const QString &TeacherInfo::getName() const
{
    return m_name;
}
const QString &TeacherInfo::getDept() const
{
    return m_dept;
}
const QString &TeacherInfo::getPost() const
{
    return m_post;
}

bool operator==(const TeacherInfo &one, const TeacherInfo &other)
{
    return one.m_id == other.m_id;
}
