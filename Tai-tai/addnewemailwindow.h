#ifndef ADDNEWEMAILWINDOW_H
#define ADDNEWEMAILWINDOW_H

#include <QFrame>
#include <QLineEdit>
#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPropertyAnimation>
#include <QGroupBox>
#include <QRegExpValidator>
#include <QRegExp>
#include <QValidator>
#include <QFile>

#include "exbutton.h"
#include "exlabel.h"
#include "groupexbuttons.h"
#include "profile.h"
#include "account.h"
#include "pop3.h"

class AddNewEmailWindow : public QFrame
{
    Q_OBJECT
public:
    explicit AddNewEmailWindow(QWidget *parent = 0);
    void StartHideAnim();
    void StartShowAnim(int left, int top, int width, int height);
    bool isCorrectLineEdit(QLineEdit *lineEdit);
signals:
    void hide_();
    void show_();
    void addedNewEmailAccount();

public slots:
    void onSaveAndExitEBClicked();
    void onBackEBClicked();
    void onDefaultEBClicked();
    bool onApproveEBClicked();
    bool onCheckEmailEBClicked();
    void setCurrentProfile(Profile *profile);
    void autoFillProtocol();
    void setDefaults();
    void setDefaultSSLogin();
    void setDefaultSSPassword();
private:
    void initExButtons();
    void initLayouts();
    void initCaptionLay();
    void initButtonLay();
    void initEmailLay();
    void initValidator();

    QBoxLayout *mainLay;
    QBoxLayout *buttonLay;
    QBoxLayout *emailLay;
    QLabel *windowCaptionLabel;

    ExButton *saveAndExitEB;
    ExButton *backEB;
    ExButton *approveEB;
    ExButton *defaultEB;
    ExButton *checkEmail;
    GroupExButtons *controllGroup;

    QPropertyAnimation *animation;
    /*profile*/
    Profile *currentProfile;
    Account *tempAccount;
    QValidator *validator;

    /*inner gridlay*/
    QLineEdit *loginLE;
    QLineEdit *passwordLE;
    QLineEdit *pop3hostLE;
    QLineEdit *pop3portLE;
    QLineEdit *imapHostLE;
    QLineEdit *imapPortLE;
    QLineEdit *smtpHostLE;
    QLineEdit *smtpPortLE;
    QCheckBox *additionalSettings;

};

#endif // ADDNEWEMAILWINDOW_H
