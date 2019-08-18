#include "studentinfo.h"

#include <QDebug>

StudentInfo::StudentInfo()
{
    m_id.clear();
    m_name.clear();
    m_degree.clear();
    m_major.clear();
}

StudentInfo::StudentInfo(const QString &id, const QString &name,
                         const QString &degree, const QString &major)
{
    m_id = id;
    m_name = name;
    m_degree = degree;
    m_major = major;
}

void StudentInfo::display(void)const
{
    qDebug() << "ID: " << m_id;
    qDebug() << "Name: " << m_name;
    qDebug() << "Degree: " << m_degree;
    qDebug() << "Major: " << m_major;
}

void StudentInfo::setID(const QString &id)
{
    m_id = id;
}

void StudentInfo::setName(const QString &name)
{
    m_name = name;
}

void StudentInfo::setDegree(const QString &degree)
{
    m_degree = degree;
}

void StudentInfo::setMajor(const QString &major)
{
    m_major = major;
}

const QString &StudentInfo::getID() const
{
    return m_id;
}
const QString &StudentInfo::getName() const
{
    return m_name;
}
const QString &StudentInfo::getDegree() const
{
    return m_degree;
}
const QString &StudentInfo::getMajor() const
{
    return m_major;
}

bool operator==(const StudentInfo &one, const StudentInfo &other)
{
    return one.m_id == other.m_id;
}
