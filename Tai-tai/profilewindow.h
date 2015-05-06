#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QFrame>
#include <QBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QLineEdit>

#include "exlabel.h"
#include "exbutton.h"
#include "groupexbuttons.h"
#include "profilesetupwindow.h"

class ProfileWindow : public QFrame
{
    Q_OBJECT
public:
    explicit ProfileWindow(QWidget *parent = 0);
    ~ProfileWindow();
    void StartHideAnim(int left, int top, int width, int height);
    void StartShowAnim(int left, int top, int width, int height);
    void setProfileList(const QList <Profile*> list);
    void setCurrentProfile(Profile *profile);
    void setCurrentProfile(int pos);


signals:
    void hide_();
    void show_();

public slots:
    void drawButton();
    void animatedHide();

    void loginExButtonLeftClicked();
    void createExButtonLeftClicked();
    void deleteExButtonLeftClicked();
    void editExButtonLeftClicked();
    void exitExButtonLeftClicked();
    void backExButtonLeftClicked();
    void onNextProfileButttonClicked();
    void onPreviousProfileButtonClicked();


private:
    QPropertyAnimation * animation;
    QBoxLayout * bigLay;
    QBoxLayout * topLay;
    QBoxLayout * botLay;
    QBoxLayout * profileLay;
    QBoxLayout * profileHorLay;

    GroupExButtons* groupEx;

    ExButton *loginExButton;
    ExButton *createExButton;
    ExButton *deleteExButton;
    ExButton *editExButton;
    ExButton *exitExButton;
    ExButton *backExButton;

    ExButton *nextProfileButtton;
    ExButton *previousProfileButton;

    QWidget *profileFrame;
    ExLabel *profileNameLabel;
    ExLabel *profileAvaLabel;
    QLineEdit * profilePasswordEdit;
    ProfileSetupWindow * profileSetWin;
    QList <Profile*> profileList;
    Profile *currentProfile;
    int currentProfileNumber;
protected:
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // PROFILEWINDOW_H
