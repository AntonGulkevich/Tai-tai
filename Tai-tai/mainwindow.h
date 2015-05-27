#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QSize>
#include <QPoint>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include <QScrollArea>

#include "profilewindow.h"
#include "profilesetupwindow.h"
#include "profileeditwindow.h"
#include "exbutton.h"
#include "trackwidget.h"
#include "emaileditwindow.h"
#include "addnewemailwindow.h"

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
    QBoxLayout * mainLay;
    QBoxLayout * topControllLay;
    QBoxLayout * centrallLay;

    /*exbuttons of top lay*/
    ExButton * settingsGenegal;
    ExButton * closeProgramm;
    ExButton * hideToTray;
    ExButton * expandToWindow;
    ExButton * collapseToWindow;
    /*exlabels of top lay*/
    ExLabel * profileNameExLabel;

    /*exbuttos of menu*/
    ExButton * writeNewMail;
    ExButton * refreshMail;
    ExButton * deleteMail;
    ExButton * saveMail;
    ExButton * selectAllAsReaded;
    ExButton * contactList;
    ExButton * toHome;
    ExButton * findList;
    GroupExButtons * groupMenu;
    /*colors and styles*/
    QString mainBackGroudColor;
    QString additionBackGroundColor;
    QString overlayBackGroundColor;
    QString groupBoxStyleSheet;
    QString lineEditStyleSheet;
    QString labelStyleSheet;
    QString frameStyleSheet;
    /*overlay*/
    QWidget * overLay;
    TrackWidget *trackBar;

    /*initialization*/
    void initDefSettings();
    void initControllExButtons();
    void initDefaultStyle();
    void initLayouts();
    void initTopControllLayout();
    void initOverLay();
    void initMenuExButtons();
    void initColors();
    void initProfiles();
    void initProfileWindow();
    void initCentrallWidget();
    void initProfileSetupWindow();
    void initProfileEditWindow();
    void initEmailEditWindow();
    void initNewEmailWindow();

    /*profiles*/
    QList <Profile*> profileList;
    QList <QString*> profilesSaveWays;
    Profile * currentProfile;

    /*windows*/
    ProfileWindow * MainProfileWindow;
    ProfileSetupWindow *profileSetupWindow;
    ProfileEditWindow *profileEditWindow;
    EmailEditWindow *emailEditWindow;
    AddNewEmailWindow *addNewEmailWindow;

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
    bool openAllProfilesInf();
    bool openAllprofiles();
    /********/

private slots:
    void showProfileWindow();
    void hideProfileWindow();
    void updateProfiles();
    void loginProfile(Profile *profile);
    void logoutProfile();
    void subwindowsOn();
    void subwindowsOff();
    void onCloseButtonClicked();
    void resizeOverlay();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
