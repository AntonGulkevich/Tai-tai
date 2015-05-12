#ifndef PROFILESETUPWINDOW_H
#define PROFILESETUPWINDOW_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPropertyAnimation>
#include <QGridLayout>
#include <QFileDialog>

#include "exlabel.h"
#include "exbutton.h"
#include "groupexbuttons.h"
#include "profile.h"

class ProfileSetupWindow : public QFrame
{
    Q_OBJECT
public:
    explicit ProfileSetupWindow(QWidget *parent = 0);
    void StartHideAnim(int left, int top, int width, int height);
    void StartShowAnim(int left, int top, int width, int height);
    bool isCorrectLineEdit(QLineEdit *lineEdit);
    void addNewProfile();
signals:
    void hide_();
    void show_();
    void profileAdded();

private:
    QPropertyAnimation * animation;
    QBoxLayout *mainLay;
    QBoxLayout *topLay;
    QBoxLayout *botLayl;
    QGridLayout *gridLay;

    QLabel *windowCaption;
    QLabel *errorMessage;

    ExLabel *profileAvaLabel;

    ExButton *cancel;
    ExButton *saveAndContinue;
    ExButton *extendedSetup;
    ExButton *addEmail;

    GroupExButtons *controllGroup;

    QLineEdit *profileNameLE;
    QLineEdit *profilePasswordFirstLE;
    QLineEdit *profilePasswordSecondLE;
    Profile *currentProfile;

    QString defaultAva;


public slots:
    void animatedHide();
    void onAvatarCliked();
    void onCancelExButtonclicked();
    void onSaveAndContinueExButtonClicked();
    void onExtendedSetupExButtonClicked();
    void onAddEmailExButtonClicked();
    void clearAllContent();

private slots:
    void createTempProfile();

};

#endif // PROFILESETUPWINDOW_H
