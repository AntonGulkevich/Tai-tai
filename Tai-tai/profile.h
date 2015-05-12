#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
#include <QPixmap>
#include <QFile>
#include <QDataStream>

class Profile
{
public:
    Profile();
    void setLogin(const QString &login_);
    void setPasswordText(const QString &password);
    void setSaveWay(const QString &way);
    void setAvatar(const QString &ava);

    QString getAvatar();
    QString getLogin();
    int getEmailCount();
    QString getSaveWay();
    QString getAllProfilesSaveWay();

    bool verification(const QString &password);
    bool saveprofile();
    bool addNewEmail(const QString &loginEmail, const QString &passEmail);
    bool addToAllProfiles();

    friend QDataStream & operator <<(QDataStream & out, const Profile& profile_);
    friend QDataStream & operator >>(QDataStream & in, Profile& profile_ );

private:
    QString login;
    QString passwordText;
    QString avatar;
    QString saveWay;

    QString allProfilesSaveWay;
    int emailCount;

};

#endif // PROFILE_H
