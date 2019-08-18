#ifndef USERINFO_H
#define USERINFO_H

#include <QString>
#include <QList>

class UserInfo
{
public:
    UserInfo();
    UserInfo(const QString &id, const QString &pswd,
               const QString &role, const QString &date);

    void display(void) const;

    void setID(const QString &id);
    void setPswd(const QString &pswd);
    void setRole(const QString &role);
    void setDate(const QString &date);

    const QString &getID() const;
    const QString &getPswd() const;
    const QString &getRole() const;
    const QString &getDate() const;

private:
    QString m_id;
    QString m_pswd;
    QString m_role;
    QString m_date;
};

#endif // USERINFO_H
