#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
#include <QPixmap>
#include <QFile>
#include <QDataStream>
#include <QDebug>

#include "account.h"


class Profile
{
public:
    Profile();
    /*functions*/
    bool verification(const QString &password);
    bool saveprofile();
    bool addNewEmail(Account *account);
    bool deleteEmail(Account *account);
    bool addToAllProfiles();
    /*set*/
    void setLogin(const QString &login_);
    void setPasswordText(const QString &password);
    void setSaveWay(const QString &way);
    void setAvatar(const QString &ava);
    void setDGuiMode(bool mode);
    void setStatisticMode(bool mode);
    /*get*/
    int getEmailCount();
    QString getAvatar();
    QString getLogin();
    QString getSaveWay();
    QString getAllProfilesSaveWay();
    bool getDGuiMode();
    bool getStatisticMode();
    Account *getAccount(int pos);
    /*inner*/
    friend QDataStream & operator <<(QDataStream & out, const Profile& profile_);
    friend QDataStream & operator >>(QDataStream & in, Profile& profile_ );

private:
    /*parametrs*/
    QString login;
    QString passwordText;
    QString avatar;
    QString saveWay;    
    bool dGuiMode;
    bool statisticMode;
    QList <Account*> accountList;

    QString allProfilesSaveWay;

};

#endif // PROFILE_H
