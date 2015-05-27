#include "profile.h"

Profile::Profile(){
    saveWay= "C:\\Users\\Mera\\Documents\\GitHub\\Tai-tai\\Accounts\\";
    allProfilesSaveWay = "C:\\Users\\Mera\\Documents\\GitHub\\Tai-tai\\Accounts\\AllProfiles.txt";
    dGuiMode =true;
    statisticMode =true;
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

void Profile::setDGuiMode(bool mode){
    dGuiMode=mode;
}

void Profile::setStatisticMode(bool mode){
    statisticMode = mode;
}

QString Profile::getAvatar(){
    return avatar;
}

QString Profile::getLogin(){
    return login;
}

int Profile::getEmailCount(){
    return accountList.count();
}

QString Profile::getSaveWay(){
    return saveWay;
}

QString Profile::getAllProfilesSaveWay(){
    return allProfilesSaveWay;
}

bool Profile::getDGuiMode(){
    return dGuiMode;
}

bool Profile::getStatisticMode(){
    return statisticMode;
}

Account *Profile::getAccount(int pos){
    return accountList.at(pos);
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

bool Profile::addNewEmail(Account *account){
    QString accountLogin;
    accountLogin =account->GetLogin();
    QListIterator <Account*> listIter(accountList);
    while(listIter.hasNext()){
        if (listIter.next()->GetLogin()==accountLogin)
            return false;//login is not unic
    }
    accountList.append(account);
    return true;// is new email is correct and unic
}

bool Profile::deleteEmail(Account *account){
    QString accountLogin;
    accountLogin =account->GetLogin();
    QList<Account*>::iterator it = accountList.begin();
    while (it != accountList.end()) {
      if ((*it)->GetLogin()==accountLogin){
          accountList.erase(it);
          return true;
      }
    }
    return false;
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

QDataStream & operator<<(QDataStream & out, const Profile& profile_){
    int count;
    count = profile_.accountList.count();

    out<<profile_.login
       <<profile_.passwordText
       <<profile_.avatar
       <<profile_.statisticMode
       <<profile_.dGuiMode
       <<count;
    while(count--){
        out<<*(profile_.accountList.at(count));
    }

    return out;
}
QDataStream & operator >>(QDataStream & in, Profile& profile_ ){
    int count;
    Account *tempAccount;
    in>>profile_.login
      >>profile_.passwordText
      >>profile_.avatar
      >>profile_.statisticMode
      >>profile_.dGuiMode
      >>count;
    while(count--){
        tempAccount = new Account();
        in>>*tempAccount;
        profile_.accountList.append(tempAccount);
    }
    return in;
}
