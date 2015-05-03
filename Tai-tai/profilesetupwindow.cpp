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

    QFrame *h_line = new QFrame();
    h_line->setFrameStyle(QFrame::HLine| QFrame::Raised);
    h_line->setStyleSheet("border: 0px; border-top: 1px solid gray");

    QLabel * profileCaptionLabel = new QLabel("Name of the new profile:");
    profileNameLE = new QLineEdit();

    profileAvaLabel = new ExLabel("AVA");
    profileAvaLabel->setMaximumSize(200, 220);
    QPixmap avadef(":/resourses/icons/ava_def.jpg");
    profileAvaLabel->setPixmap(avadef);
    profileAvaLabel->setStyleSheet("QLabel{border: 1px solid gray;}");

    QLabel *profilePasswordLabel = new QLabel("New password:");
    profilePasswordFirstLE =  new QLineEdit();

    QLabel *profilePasswordVerificationLabel = new QLabel ("Repeat password:");
    profilePasswordSecondLE = new QLineEdit();


    topLay->addWidget(windowCaption, 0, Qt::AlignHCenter);
    topLay->addWidget(h_line, 1);
    topLay->addSpacing(5);
    topLay->addWidget(profileAvaLabel, 1, Qt::AlignHCenter);
    topLay->addSpacing(5);

    gridLay->addWidget(profileCaptionLabel,0, 0, Qt::AlignLeft);
    gridLay->addWidget(profileNameLE,0, 1, Qt::AlignLeft);
    gridLay->addWidget(profilePasswordLabel,1, 0, Qt::AlignLeft);
    gridLay->addWidget(profilePasswordFirstLE,1, 1, Qt::AlignLeft);
    gridLay->addWidget(profilePasswordVerificationLabel,2, 0, Qt::AlignLeft);
    gridLay->addWidget(profilePasswordSecondLE,2, 1, Qt::AlignLeft);

    topLay->addLayout(gridLay);

    botLayl->addStretch(1);

    /*exbuttons*/

    int margin =10;
    int radius=50;

    cancel = new ExButton(this,  "Cancel", radius, 0);
    cancel->move(800/4-100+50/2, 600/2+50/2+150);
    cancel->setRotation(273);
    cancel->setImage(":/resourses/icons/cancel_nb.png");
    cancel->setImageMargin(margin);
    cancel->setToolTip("Login in current account.");

    saveAndContinue = new ExButton(this,  "Save", radius, 1);
    saveAndContinue->setImage(":/resourses/icons/check_nb.png");
    saveAndContinue->setImageMargin(margin);
    saveAndContinue->setToolTip("Save new profile.");

    extendedSetup = new ExButton(this,  "Continue", radius, 1);
    extendedSetup->setImage(":/resourses/icons/more_nb.png");
    extendedSetup->setImageMargin(margin);
    extendedSetup->setToolTip("Save profile and continue setup.");

    addEmail = new ExButton(this, "Emails", radius, 1);
    addEmail->setImage(":/resourses/icons/email_gears_nb.png");
    addEmail->setImageMargin(margin);
    addEmail->setToolTip("Manage email in this profile.");

    controllGroup= new GroupExButtons();

    controllGroup->addButton(cancel);
    controllGroup->addButton(saveAndContinue);
    controllGroup->addButton(extendedSetup);
    controllGroup->addButton(addEmail);

    controllGroup->setDefaultButton("Save");

    /***********/

    /*connections*/
    connect(cancel, SIGNAL(leftClicked()), this , SLOT(onCancelExButtonclicked()));
    connect(saveAndContinue, SIGNAL(leftClicked()), this, SLOT(onSaveAndContinueExButtonClicked()));
    connect(extendedSetup, SIGNAL(leftClicked()), this, SLOT(onExtendedSetupExButtonClicked()));
    connect(addEmail, SIGNAL(leftClicked()), this, SLOT(onAddEmailExButtonClicked()));
    /*************/
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
    controllGroup->closeGroup();
}
bool ProfileSetupWindow::isCorrectLineEdit(QLineEdit *lineEdit){
    if (lineEdit->text().isEmpty()){
        lineEdit->setStyleSheet("QLineEdit { border: 1px solid red}");
        return false;
    }
    else{
        lineEdit->setStyleSheet("");
        return true;
    }
}

void ProfileSetupWindow::onCancelExButtonclicked(){
    animatedHide();

}
void ProfileSetupWindow::animatedHide(){
    StartHideAnim(0, 0, width(), height());
    emit hide_();
}

void ProfileSetupWindow::onSaveAndContinueExButtonClicked(){

}

void ProfileSetupWindow::onExtendedSetupExButtonClicked(){

}

void ProfileSetupWindow::onAddEmailExButtonClicked(){

}
