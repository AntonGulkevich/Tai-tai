#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
private:
    QString email;
    QString password;
    QString pop3Host;
    int pop3Port;
    QString imapHost;
    int imapPort;
    QString smtpHost;
    int smtpPort;
    bool enable;
    enum state{
        good,
        bad,
        error,
    };

public:
    Account();
    Account (const QString &_email,const QString &_password);
    ~Account();
    QString GetLogin();
    QString GetPassword();

    QString GetPop3Host();
    QString GetImapHost();
    QString GetSmtpHost();
    int GetPop3Port();
    int GetImapPort();
    int GetSmtpPort();
    bool enabled();

    void setPop3Host(const QString &host);
    void setImapHost(const QString &host);
    void setSmtpHost(const QString &host);
    void setPop3Port(int port);
    void setImapPort(int port);
    void setSmtpPort(int port);
    void setEnabled(bool mode);

    friend QDataStream & operator <<(QDataStream & out, const Account& account);
    friend QDataStream & operator >>(QDataStream & in, Account& account );

};

#endif // ACCOUNT_H
