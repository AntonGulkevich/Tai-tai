#ifndef PROFILESETUPWINDOW_H
#define PROFILESETUPWINDOW_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPropertyAnimation>
#include <QGridLayout>

#include "exlabel.h"
#include "exbutton.h"
#include "groupexbuttons.h"

class ProfileSetupWindow : public QFrame
{
    Q_OBJECT
public:
    explicit ProfileSetupWindow(QWidget *parent = 0);
    void StartHideAnim(int left, int top, int width, int height);
    void StartShowAnim(int left, int top, int width, int height);
    bool isCorrectLineEdit(QLineEdit *lineEdit);
signals:
    void hide_();
    void show_();

private:
    QPropertyAnimation * animation;
    QBoxLayout *mainLay;
    QBoxLayout *topLay;
    QBoxLayout *botLayl;
    QGridLayout *gridLay;

    QLabel *windowCaption;

    ExLabel *profileAvaLabel;

    ExButton *cancel;
    ExButton *saveAndContinue;
    ExButton *extendedSetup;
    ExButton *addEmail;

    GroupExButtons *controllGroup;

    QLineEdit *profileNameLE;
    QLineEdit *profilePasswordFirstLE;
    QLineEdit *profilePasswordSecondLE;


public slots:
    void animatedHide();

private slots:
    void onCancelExButtonclicked();
    void onSaveAndContinueExButtonClicked();
    void onExtendedSetupExButtonClicked();
    void onAddEmailExButtonClicked();
    void clearAllContent();

};

#endif // PROFILESETUPWINDOW_H
