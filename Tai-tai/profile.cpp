#include "profile.h"

Profile::Profile(){
    saveWay= "C:\\Users\\Mera\\Documents\\GitHub\\Tai-tai\\Accounts\\";
    allProfilesSaveWay = "C:\\Users\\Mera\\Documents\\GitHub\\Tai-tai\\Accounts\\AllProfiles.txt";
}

void Profile::setLogin(const QString &login_){
    login=login_;
}

void Profile::setPasswordText(const QString &password){
    passwordText=password;
}

void Profile::setSaveWay(const QString &way){
    saveWay=way;
}

void Profile::setAvatar(const QString &ava){
    avatar=ava;
}

QString Profile::getAvatar(){
    return avatar;
}

QString Profile::getLogin(){
    return login;
}

int Profile::getEmailCount(){
    return emailCount;
}

QString Profile::getSaveWay(){
    return saveWay;
}

bool Profile::verification(const QString &password){
    if (password==passwordText){
        return true;
    }
    else
        return false;
}

bool Profile::saveprofile(){
    QFile file(saveWay);
    if (!file.open(QIODevice::WriteOnly)) {
        //"Unable to open file"
        file.close();
        return false;
    }
    QDataStream out(&file);
    out<<*this;
    file.close();
    return true;
}

bool Profile::addNewEmail(const QString &loginEmail, const QString &passEmail){
    return true;// is new email is correct and unic
}

bool Profile::addToAllProfiles(){
    QFile file(allProfilesSaveWay);
    if (!file.open(QIODevice::Append)) {
        //"Unable to open file"
        file.close();
        return false;
    }
    QDataStream out(&file);
    out<<saveWay;
    file.close();
    return true;
}

bool Profile::openProfile(const QString &way){

}

QDataStream & operator<<(QDataStream & out, const Profile& profile_){
    out <<profile_.login<<profile_.passwordText<<profile_.avatar;

    return out;
}
QDataStream & operator >>(QDataStream & in, Profile& profile_ ){
    in >>profile_.login>>profile_.passwordText>>profile_.avatar;

    return in;


}
