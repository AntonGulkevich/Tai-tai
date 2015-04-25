#include "profilesetupwindow.h"

ProfileSetupWindow::ProfileSetupWindow(QWidget *parent) :
    QFrame(parent)
{
    resize(0, parent->height());
    move(0, 0);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QFrame{background-color: white }");
    /*Layouts*/
    mainLay=new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLay->setSpacing(0);
    mainLay->setMargin(0);

    topLay = new QBoxLayout(QBoxLayout::TopToBottom);
    topLay->setSpacing(5);
    topLay->setMargin(10);

    botLayl = new QBoxLayout(QBoxLayout::TopToBottom);

    gridLay = new QGridLayout();

    mainLay->addLayout(topLay);
    mainLay->addLayout(botLayl);
    setStyleSheet("QLabel { border: 0 px}");
    /**********/
    windowCaption = new QLabel("Create new profile.");
    windowCaption->setStyleSheet("font: 20px");

    QLabel * profileCaptionLabel = new QLabel("Input name of the new profile:");
    profileNameLE = new QLineEdit();

    profileAvaLabel = new ExLabel("AVA");
    profileAvaLabel->setMaximumSize(200, 220);
    QPixmap avadef(":/resourses/icons/ava_def.jpg");
    profileAvaLabel->setPixmap(avadef);
    profileAvaLabel->setStyleSheet("QLabel{border: 1px solid gray;}");

    QLabel *profilePasswordLabel = new QLabel("Input new password:");
    profilePasswordFirstLE =  new QLineEdit();

    QLabel *profilePasswordVerificationLabel = new QLabel ("Repeat password:");
    profilePasswordSecondLE = new QLineEdit();


    topLay->addWidget(windowCaption, 0, Qt::AlignHCenter);
    topLay->addWidget(profileAvaLabel, 1, Qt::AlignHCenter);
    topLay->addSpacing(20);

    gridLay->addWidget(profileCaptionLabel,0, 0, Qt::AlignLeft);
    gridLay->addWidget(profileNameLE,0, 1, Qt::AlignLeft);
    gridLay->addWidget(profilePasswordLabel,1, 0, Qt::AlignLeft);
    gridLay->addWidget(profilePasswordFirstLE,1, 1, Qt::AlignLeft);
    gridLay->addWidget(profilePasswordVerificationLabel,2, 0, Qt::AlignLeft);
    gridLay->addWidget(profilePasswordSecondLE,2, 1, Qt::AlignLeft);

    topLay->addLayout(gridLay);

    botLayl->addStretch(1);

    /*exbuttons*/

    int margin =5;
    int radius=50;

    cancel = new ExButton(this,  "Cancel", radius, 0);
    cancel->move(800/4-100+50/2, 600/2+50/2+100);
    cancel->setRotation(201);
    cancel->setImage(":/resourses/icons/logout_acc3.png");
    cancel->setImageMargin(margin);
    cancel->setToolTip("Login in current account.");

    saveAndContinue = new ExButton(this,  "Save", radius, 1);
    saveAndContinue->setImage(":/resourses/icons/create_acc.png");
    saveAndContinue->setImageMargin(margin);
    saveAndContinue->setToolTip("Save new profile.");

    extendedSetup = new ExButton(this,  "Continue", radius, 1);
    extendedSetup->setImage(":/resourses/icons/create_acc.png");
    extendedSetup->setImageMargin(margin);
    extendedSetup->setToolTip("Save profile and continue setup.");

    controllGroup= new GroupExButtons();

    controllGroup->addButton(cancel);
    controllGroup->addButton(saveAndContinue);
    controllGroup->addButton(extendedSetup);

    /***********/
}

void ProfileSetupWindow::StartShowAnim(int left, int top, int width, int height){
    show();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, 0, height));
    animation->setEndValue(QRect(left, top, width, height));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void ProfileSetupWindow::StartHideAnim(int left, int top, int width, int height){

    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width, height));
    animation->setEndValue(QRect(left, top, 1, height));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect (animation, SIGNAL(finished()), this, SLOT(hide()));
}
