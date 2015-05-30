#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QSize>
#include <QPoint>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include <QScrollArea>
#include <QComboBox>

#include "profilewindow.h"
#include "profilesetupwindow.h"
#include "profileeditwindow.h"
#include "exbutton.h"
#include "trackwidget.h"
#include "emaileditwindow.h"
#include "addnewemailwindow.h"
#include "directwindow.h"
#include "account.h"


class MainWindow : public QFrame
{
    Q_OBJECT
private:
    QPoint mpos;
    bool canMove;
    int subWindows;
    QSize mainWindowStartSize;
    QSize mainWindowMinSize;
    QPoint mainWindownStartPoint;

    /*layouts*/
    QBoxLayout *mainLay;
    QBoxLayout *topControllLay;
    QBoxLayout *centrallLay;

    /*exbuttons of top lay*/
    ExButton *settingsGenegal;
    ExButton *closeProgramm;
    ExButton *hideToTray;
    ExButton *expandToWindow;
    ExButton *collapseToWindow;
    /*exlabels of top lay*/
    ExLabel *profileNameExLabel;

    /*exbuttos of menu*/
    ExButton *writeNewMail;
    ExButton *refreshMail;
    ExButton *deleteMail;
    ExButton *saveMail;
    ExButton *selectAllAsReaded;
    ExButton *contactList;
    ExButton *toHome;
    ExButton *findList;
    GroupExButtons * groupMenu;
    /*colors and styles*/
    QString mainBackGroudColor;
    QString additionBackGroundColor;
    QString overlayBackGroundColor;
    QString groupBoxStyleSheet;
    QString lineEditStyleSheet;
    QString labelStyleSheet;
    QString frameStyleSheet;
    QString comboBoxStyleSheet;
    /*overlay*/
    QWidget *overLay;
    TrackWidget *trackBar;

    /*initialization*/
    void initDefSettings();
    void initControllExButtons();
    void initDefaultStyle();
    void initLayouts();
    void initTopControllLayout();
    void initOverLay();
    void initMenuExButtons();
    void initColorsStyles();
    void initProfiles();
    void initProfileWindow();
    void initCentrallWidget();
    void initProfileSetupWindow();
    void initProfileEditWindow();
    void initEmailEditWindow();
    void initNewEmailWindow();
    void initProfileDirectWindow();

    /*profiles*/
    QList <Profile*> profileList;
    QList <QString*> profilesSaveWays;
    Profile *currentProfile;
    Account *currentAccount;

    /*windows*/
    ProfileWindow *MainProfileWindow;
    ProfileSetupWindow *profileSetupWindow;
    ProfileEditWindow *profileEditWindow;
    EmailEditWindow *emailEditWindow;
    AddNewEmailWindow *addNewEmailWindow;
    DirectWindow *profileDirectWindow;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showMenu();
    void hideMenu();
    /*colors*/
    QString getMainBackGroudColor();
    QString getAdditionBackGroundColor();
    QString getOverlayBackGroundColor();
    void setMainBackGroudColor(const QString &color);
    void setAdditionBackGroundColor(const QString &color);
    void setOverlayBackGroundColor(const QString &color);
    /*profiles*/
    bool openAllProfilesInf();
    bool openAllprofiles();
    void setCurrentAccount(Account *account);
    /********/

private slots:
    void updateProfiles();
    void loginProfile(Profile *profile);
    void logoutProfile();
    void subwindowsOn();
    void subwindowsOff();
    void onCloseButtonClicked();
    void resizeOverlay();
    void onProfileLabelClicked();
    void accountChanged(int pos);
    void reLogin();
    void overLayShow();
    void overLayClose();
    void editProfile();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void someWindowOpened();
    void someWindowClosed();
};

#endif // MAINWINDOW_H
