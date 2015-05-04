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
#include "exbutton.h"


class MainWindow : public QFrame
{
    Q_OBJECT
private:
    ProfileWindow * MainProfileWindow;
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
    /*colors*/
    QString mainBackGroudColor;
    QString additionBackGroundColor;
    QString overlayBackGroundColor;

    /*overlay*/
    QWidget * overLay;

    /*initialization*/
    void initControllExButtons();
    void initDefaultStyle();
    void initLayouts();
    void initTopControllLayout();
    void initOverLay();
    void initMenuExButtons();
    void initColors();

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
    /********/

private slots:
    void showProfileWindow();
    void hideProfileWindow();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H
