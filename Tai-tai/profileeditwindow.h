#ifndef PROFILEEDITWINDOW_H
#define PROFILEEDITWINDOW_H

#include <QFrame>
#include <QLineEdit>
#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPropertyAnimation>
#include <QGroupBox>
#include <QScrollArea>

#include "exbutton.h"
#include "exlabel.h"
#include "groupexbuttons.h"
#include "profile.h"

class ProfileEditWindow : public QFrame
{
    Q_OBJECT
public:
    explicit ProfileEditWindow(QWidget *parent = 0);
    void StartHideAnim();
    void StartShowAnim(int left, int top, int width, int height);
    bool isCorrectLineEdit(QLineEdit *lineEdit);
private:
    QBoxLayout *mainLay;
    QBoxLayout *passwordLay;
    QBoxLayout *settingsGUILay;
    QBoxLayout *emailLay;
    QBoxLayout *buttonsLay;
    QVBoxLayout *scrollLayout;

    QLabel *windowCaptionLabel;
    void initLayouts();

    QPropertyAnimation *animation;

    QLineEdit *oldPasswordLE;
    QLineEdit *newPasswordLE;
    QLineEdit *repeatNewPasswordLE;

    QCheckBox *dinamicGUICB;
    QCheckBox *stopStatCB;

    ExLabel *setupEmails;

    ExButton *saveAndExitEB;
    ExButton *backEB;
    ExButton *defaultEB;
    ExButton *approveEB;
    GroupExButtons *controllGroup;

    void initPasswordLay();
    void initSettingsGuiLay();
    void initEmailslay();
    void initCaptionLay();
    void initExButtons();


signals:
    void hide_();
    void show_();

public slots:
    void clearAllContent();
    void onSaveAndExitEBClicked();
    void onBackEBClicked();
    void onDefaultEBClicked();
    void onApproveEBClicked();

};


#endif // PROFILEEDITWINDOW_H
