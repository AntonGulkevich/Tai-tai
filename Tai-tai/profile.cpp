#include "profile.h"

profile::profile(){
}

void profile::setLogin(const QString &login_){
    login=login_;
}

void profile::setPasswordText(const QString &password){
    passwordText=password;
}

void profile::setSaveWay(const QString &way){
    saveWay=way;
}

void profile::setAvatar(const QPixmap &ava){
    avatar=ava;
}

QPixmap profile::getAvatar(){
    return avatar;
}

QString profile::getLogin(){
    return login;
}

int profile::getEmailCount(){
    return emailCount;
}

bool profile::verification(const QString &password){
    if (password==passwordText){
        return true;
    }
    else
        return false;
}

bool profile::saveprofile(){
    return true; //is save is ok
}

bool profile::addNewEmail(const QString &loginEmail, const QString &passEmail){
    return true;// is new email is correct and unic
}
