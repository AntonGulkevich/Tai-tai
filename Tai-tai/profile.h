#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
#include <QPixmap>

class profile
{
public:
    profile();
    void setLogin(const QString &login_);
    void setPasswordText(const QString &password);
    void setSaveWay(const QString &way);
    void setAvatar(const QPixmap &ava);

    QPixmap getAvatar();
    QString getLogin();
    int getEmailCount();

    bool verification(const QString &password);
    bool saveprofile();
    bool addNewEmail(const QString &loginEmail, const QString &passEmail);

private:
    QString login;
    QString passwordText;
    QPixmap avatar;
    QString saveWay;
    int emailCount;

};

#endif // PROFILE_H
