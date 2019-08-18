#ifndef __CLASSINFO_H
#define __CLASSINFO_H

#include <QString>
#include <QList>
#include <QMap>

class ClassInfo
{
public:
    ClassInfo();
    ClassInfo(const QString &id, const QString &name,
               const QString &room, const QString &count);
    void display(void) const;

    void setID(const QString &id);
    void setName(const QString &name);
    void setRoom(const QString &room);
    void setCount(const QString &count);

    const QString &getID() const;
    const QString &getName() const;
    const QString &getRoom() const;
    const QString &getCount() const;

    friend bool operator==(const ClassInfo &one, const ClassInfo &other);

private:
    QString m_id;
    QString m_name;
    QString m_room;
    QString m_count;
};

typedef QList<ClassInfo> ClassInfoList;
typedef QList<ClassInfo*> ClassInfoPtrList;    //文件操作使用
typedef QMap<QString, ClassInfoList::iterator> ClassInfoMap;  //网络操作使用

#endif // __CLASSINFO_H
