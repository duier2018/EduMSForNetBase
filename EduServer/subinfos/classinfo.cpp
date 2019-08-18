#include "classinfo.h"

#include <QDebug>

ClassInfo::ClassInfo()
{
    m_id.clear();
    m_name.clear();
    m_room.clear();
    m_count.clear();
}

ClassInfo::ClassInfo(const QString &id, const QString &name,
           const QString &room, const QString &count)
{
    m_id = id;
    m_name = name;
    m_room = room;
    m_count = count;
}

void ClassInfo::display(void) const
{
    qDebug() << "ID: " << m_id;
    qDebug() << "Name: " << m_name;
    qDebug() << "Room: " << m_room;
    qDebug() << "Count: " << m_count;
}

void ClassInfo::setID(const QString &id)
{
    m_id = id;
}

void ClassInfo::setName(const QString &name)
{
    m_name = name;
}

void ClassInfo::setRoom(const QString &room)
{
    m_room = room;
}

void ClassInfo::setCount(const QString &count)
{
    m_count = count;
}

const QString &ClassInfo::getID() const
{
    return m_id;
}
const QString &ClassInfo::getName() const
{
    return m_name;
}
const QString &ClassInfo::getRoom() const
{
    return m_room;
}
const QString &ClassInfo::getCount() const
{
    return m_count;
}

bool operator==(const ClassInfo &one, const ClassInfo &other)
{
    return one.m_id == other.m_id;
}

