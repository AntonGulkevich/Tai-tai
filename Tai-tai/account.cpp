#include "account.h"

#include <QDebug>

Account::Account(const QString &_email, const QString &_password) :
    email(_email), password (_password)
{
    //domain_name=email.right(email.length()-email.indexOf("@")-1);
    //domain_name=domain_name.left(domain_name.length()-domain_name.indexOf(".")+1);
    enable = true;

}
Account::~Account(){
    enable = true;
}
Account::Account(){

}
QString Account::GetLogin(){
    return email;
}

QString Account::GetPassword(){
    return password;
}
QString Account::GetPop3Host(){
    return pop3Host;
}

QString Account::GetImapHost(){
    return imapHost;
}

QString Account::GetSmtpHost(){
    return smtpHost;
}

int Account::GetPop3Port(){
    return pop3Port;
}

int Account::GetImapPort(){
    return imapPort;
}

int Account::GetSmtpPort(){
    return smtpPort;
}

bool Account::enabled(){
    return enable;
}

void Account::setPop3Host(const QString &host){
    pop3Host=host;
}

void Account::setImapHost(const QString &host){
    imapHost=host;
}

void Account::setSmtpHost(const QString &host){
    smtpHost=host;
}

void Account::setPop3Port(int port){
    pop3Port= port;
}

void Account::setImapPort(int port){
    imapPort=port;
}

void Account::setSmtpPort(int port){
    smtpPort=port;
}

void Account::setEnabled(bool mode){
    enable=mode;
}
QDataStream & operator<<(QDataStream & out, const Account& account)
{
    out << account.email
        << account.password
        << account.pop3Host
        << account.pop3Port
        << account.imapHost
        << account.imapPort
        << account.smtpHost
        << account.smtpPort
        << account.enable;

    return out;
}
QDataStream & operator >>(QDataStream & in, Account& account ){
    in  >> account.email
        >> account.password
        >> account.pop3Host
        >> account.pop3Port
        >> account.imapHost
        >> account.imapPort
        >> account.smtpHost
        >> account.smtpPort
        >> account.enable;

    return in;
}


