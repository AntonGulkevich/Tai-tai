#ifndef EMAILEDITWINDOW_H
#define EMAILEDITWINDOW_H

#include <QFrame>
#include <QLineEdit>
#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPropertyAnimation>
#include <QGroupBox>
#include <QScrollArea>
#include <QList>

#include "exbutton.h"
#include "exlabel.h"
#include "groupexbuttons.h"
#include "profile.h"
#include "account.h"
#include "addnewemailwindow.h"

class EmailEditWindow : public QFrame
{
    Q_OBJECT
public:
    explicit EmailEditWindow(QWidget *parent = 0);
    void StartHideAnim();
    void StartShowAnim(int left, int top, int width, int height);
    bool isCorrectLineEdit(QLineEdit *lineEdit);
    void restoreProfile();
private:
    QBoxLayout *mainLay;
    QBoxLayout *buttonsLay;
    QVBoxLayout *scrollLayout;
    QLabel *windowCaptionLabel;
    QVBoxLayout *scrollLayout1;
    QWidget *scrollWidget;

    QPropertyAnimation *animation;

    ExButton *saveAndExitEB;
    ExButton *backEB;    
    ExButton *approveEB;
    ExButton *addEmail;
    ExButton *deleteEmail;
    ExButton *editEmail;
    GroupExButtons *controllGroup;

    QScrollArea *scrollArea;
    Profile *currentProfile;
    Profile *reservProfile;
    QGroupBox *emailGB;

    AddNewEmailWindow *addNewEmailWindow;
    void initLayouts();
    void initCaptionLay();
    void initButtonsLay();
    void initExButtons();
    void initScrollLay();

    QList <QWidget *> emailList;

signals:
    void hide_();
    void show_();

public slots:
    void clearAllContent();    
    void setCurrentProfile(Profile *profile);
    void setAddNewEmailWindow(AddNewEmailWindow *window);
    void addNewEmailAccount(const QString &name);
    /*buttons*/
    void onSaveAndExitEBClicked();//completed
    void onBackEBClicked();//completed
    void onAddEmailEBClicked();//completed
    void onApproveEBClicked();//completed
    void onDeleteEBClicked();//completed
    void onEditEBClicked();
    /*fc*/
    void animatedShow();
    void clearEmailTable();
    void fillEmailsTable();
protected:

};

#endif // EMAILEDITWINDOW_H
