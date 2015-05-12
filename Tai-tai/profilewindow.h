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
#include "profileeditwindow.h"

class ProfileWindow : public QFrame
{
    Q_OBJECT
public:
    explicit ProfileWindow(QWidget *parent = 0);
    ~ProfileWindow();
    void StartHideAnim(int left, int top, int width, int height);
    void StartShowAnim(int left, int top, int width, int height);
    void setProfileList(QList <Profile*> *list);
    void setProfileSaveWays(QList <QString*> *list);
    void setCurrentProfile(Profile *profile);
    void setCurrentProfile(int pos);
    void updateAllProfilesSaveWays();
    void setProfileSetupWindow (ProfileSetupWindow * window);
    void setProfileEditWindow (ProfileEditWindow *window);

signals:
    void hide_();
    void show_();
    void profileAdded();
    void profileDeleted();
    void profileLogged(Profile * profile);
    void profileLogout();

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
    void onProfileAdded();
    void setDefaultProfile();

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
    QList <Profile*> *profileList;
    QList <QString*> *profilesSaveWays;
    Profile *currentProfile;
    int currentProfileNumber;    
    QLabel *errorMessageLabel;

    ProfileSetupWindow * profileSetWin;
    ProfileEditWindow *profileEditWin;

    void initLayouts();
    void setupProfileLayout();
    void setupExButtons();
    void setupNextPrevExButtons();
    void deleteProfile();
protected:
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // PROFILEWINDOW_H
