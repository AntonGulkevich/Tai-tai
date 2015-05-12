#include "profilewindow.h"

ProfileWindow::ProfileWindow(QWidget *parent) :
    QFrame(parent)
{

    resize(0, parent->height());
    move(0, 0);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QFrame{background-color: white }");
    currentProfileNumber =0;

    /*LAYOUTS*/
    initLayouts();

    /*Profile layout*/
    setupProfileLayout();

    /*profile button's rose*/
    setupExButtons();

    /*next prev buttons*/
    setupNextPrevExButtons();


    profileHorLay->addWidget(previousProfileButton, 0, Qt::AlignRight);
    profileHorLay->addLayout(topLay);
    profileHorLay->addWidget(nextProfileButtton, 0, Qt::AlignLeft);
    profileHorLay->setMargin(0);
    profileHorLay->setSpacing(0);

    hide();
}
ProfileWindow::~ProfileWindow(){

}
void ProfileWindow::StartShowAnim(int left, int top, int width, int height){
    show();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, 0, height));
    animation->setEndValue(QRect(left, top, width, height));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
    emit show_();
}

void ProfileWindow::drawButton(){


}

void ProfileWindow::animatedHide(){
    StartHideAnim(0, 0, width(), height());
    emit hide_();
}

void ProfileWindow::loginExButtonLeftClicked(){
    if (!groupEx->isDefaultButton(loginExButton)){
        //  groupEx->setDefaultButton("Login");
        groupEx->startAnimation();
    }
    if (profilesSaveWays->isEmpty()){
        return;
    }
    QString password = profilePasswordEdit->text();
    if (currentProfile->verification(password)){
        emit profileLogged(currentProfile);
        profilePasswordEdit->setText("");
        animatedHide();
    }
    else{
        errorMessageLabel->setText("Wrong password.");
        errorMessageLabel->show();
    }
}

void ProfileWindow::createExButtonLeftClicked(){
    if (!groupEx->isDefaultButton(createExButton)){
        // groupEx->setDefaultButton("Create");
        groupEx->startAnimation();
    }
    profileSetWin->StartShowAnim(0, 0, width(), height());
}

void ProfileWindow::deleteExButtonLeftClicked(){
    if (!groupEx->isDefaultButton(deleteExButton)){
        //   groupEx->setDefaultButton("Delete");
        groupEx->startAnimation();
    }
    if (profilesSaveWays->isEmpty()){
        return;
    }
    deleteProfile();
}

void ProfileWindow::editExButtonLeftClicked(){
    if (!groupEx->isDefaultButton(editExButton)){
        //    groupEx->setDefaultButton("Edit");
        groupEx->startAnimation();
    }
    if (profilesSaveWays->isEmpty()){
        return;
    }
    profileEditWin->StartShowAnim(0,0,width(), height());
}

void ProfileWindow::exitExButtonLeftClicked(){
    if (!groupEx->isDefaultButton(exitExButton)){
        //    groupEx->setDefaultButton("Logout");
        groupEx->startAnimation();
    }
    if (profilesSaveWays->isEmpty()){
        return;
    }
    emit profileLogout();
}

void ProfileWindow::backExButtonLeftClicked(){
    if (!groupEx->isDefaultButton(backExButton)){
        //    groupEx->setDefaultButton("Back");
        groupEx->startAnimation();
    }
    animatedHide();
}

void ProfileWindow::onNextProfileButttonClicked(){
    if (profilesSaveWays->isEmpty())
        return;
    int count = profileList->count();
    if ((++currentProfileNumber)>=count){
        currentProfileNumber=0;
    }
    setCurrentProfile(currentProfileNumber);
}

void ProfileWindow::onPreviousProfileButtonClicked(){
    if (profilesSaveWays->isEmpty())
        return;
    int count = profileList->count();
    if ((--currentProfileNumber)<0){
        currentProfileNumber=count-1;
    }
    setCurrentProfile(currentProfileNumber);
}

void ProfileWindow::onProfileAdded(){
    emit profileAdded();
}

void ProfileWindow::setDefaultProfile(){
    QPixmap avadef(":/resourses/icons/ava_def.jpg");
    profileAvaLabel->setPixmap(avadef);
    profileNameLabel->setText("Default Profile");
}

void ProfileWindow::initLayouts(){
    bigLay = new QBoxLayout(QBoxLayout::TopToBottom, this);
    topLay = new QBoxLayout(QBoxLayout::TopToBottom);
    botLay = new QBoxLayout(QBoxLayout::TopToBottom);
    profileHorLay = new QBoxLayout(QBoxLayout::LeftToRight);

    bigLay->setMargin(0);
    bigLay->setSpacing(0);

    bigLay->addLayout(profileHorLay, 1);
    bigLay->addLayout(botLay, 1);
}

void ProfileWindow::setupProfileLayout(){
    profileFrame = new QWidget();
    profileLay= new QBoxLayout(QBoxLayout::TopToBottom);
    profileLay->setMargin(1);
    profileLay->setSpacing(0);
    profileFrame->setStyleSheet("QWidget {border: 1px solid black}");
    profileFrame->setLayout(profileLay);

    profileNameLabel = new ExLabel("DEFAULT PROFILE");

    QFont fnt2;
    fnt2.setPixelSize(13);
    fnt2.setItalic(false);
    fnt2.setUnderline(false);
    fnt2.setBold(false);

    profileNameLabel->setFont(fnt2);
    profileNameLabel->setFonts(14, 13, 13);

    profileAvaLabel = new ExLabel("AVA");

    profilePasswordEdit = new QLineEdit();
    profilePasswordEdit->setStyleSheet("border: 0 px");
    profilePasswordEdit->setEchoMode(QLineEdit::Password);
    profilePasswordEdit->setPlaceholderText("Password");

    profileAvaLabel->setStyleSheet("QLabel{border: 1px solid gray;}");

    profileNameLabel->setMaximumSize(200, 20);
    profilePasswordEdit->setFixedSize(200, 20);

    profileAvaLabel->setMaximumSize(200, 220);
    QPixmap avadef(":/resourses/icons/ava_def.jpg");
    profileAvaLabel->setPixmap(avadef);
    // profileAvaLabel->setMask(avadef.mask());


    QWidget *labelNameBack = new QWidget();
    labelNameBack->setStyleSheet("background-color:rgba(250, 250, 250); border: 0px");
    QBoxLayout *topNameLay = new QBoxLayout(QBoxLayout::TopToBottom);
    topNameLay->addSpacing(2);
    topNameLay->addWidget(profileNameLabel, 0, Qt::AlignHCenter);
    topNameLay->addSpacing(2);
    labelNameBack->setLayout(topNameLay);
    profileLay->addWidget(labelNameBack);
    profileLay->addWidget(profileAvaLabel, 1, Qt::AlignHCenter);
    profileLay->addWidget(profilePasswordEdit, 0, Qt::AlignHCenter);
    profileFrame->setMaximumSize(profileNameLabel->width()+2,
                                 profileNameLabel->height()+profileAvaLabel->height()+profilePasswordEdit->height()+2);

    errorMessageLabel = new QLabel();
    errorMessageLabel->setStyleSheet("color:red; border: 0px");
    errorMessageLabel->hide();

    topLay->addStretch(1);
    topLay->addWidget(profileFrame, 1,  Qt::AlignHCenter);
    topLay->addWidget(errorMessageLabel);
    topLay->addStretch(1);

    topLay->setSpacing(0);
    topLay->setMargin(10);

    botLay->addStretch(1);

    connect(profilePasswordEdit, SIGNAL(textEdited(QString)), errorMessageLabel, SLOT(hide()));

}

void ProfileWindow::setupExButtons(){
    int margin =5;
    int radius=50;
    loginExButton = new ExButton(this,  "Login", radius, 0);
    loginExButton->move(800/4-100+50/2, 600/2+50/2+50);
    loginExButton->setRotation(201);
    loginExButton->setImage(":/resourses/icons/logout_acc3.png");
    loginExButton->setImageMargin(margin);
    loginExButton->setToolTip("Login in current account.");

    createExButton = new ExButton(this,  "Create", radius, 1);
    createExButton->setImage(":/resourses/icons/create_acc.png");
    createExButton->setImageMargin(margin);

    deleteExButton = new ExButton(this,  "Delete", radius, 1);
    deleteExButton->setImage(":/resourses/icons/delete_acc.png");
    deleteExButton->setImageMargin(margin);

    editExButton = new ExButton(this,  "Edit", radius, 1);
    editExButton->setImage(":/resourses/icons/edit_acc.png");
    editExButton->setImageMargin(margin);

    exitExButton = new ExButton(this,  "Logout", radius, 1);
    exitExButton->setImage(":/resourses/icons/login_acc.png");
    exitExButton->setImageMargin(margin);

    backExButton = new ExButton(this,  "Back", radius, 1);
    backExButton->setImage(":/resourses/icons/back_nb.png");
    backExButton->setImageMargin(10);

    groupEx = new GroupExButtons();

    groupEx->addButton(loginExButton);
    groupEx->addButton(createExButton);
    groupEx->addButton(deleteExButton);
    groupEx->addButton(editExButton);
    groupEx->addButton(exitExButton);
    groupEx->addButton(backExButton);

    connect(loginExButton, SIGNAL(leftClicked()), SLOT(loginExButtonLeftClicked()));
    connect(createExButton, SIGNAL(leftClicked()), SLOT(createExButtonLeftClicked()));
    connect(deleteExButton, SIGNAL(leftClicked()), SLOT(deleteExButtonLeftClicked()));
    connect(editExButton, SIGNAL(leftClicked()), SLOT(editExButtonLeftClicked()));
    connect(exitExButton, SIGNAL(leftClicked()), SLOT(exitExButtonLeftClicked()));
    connect(backExButton, SIGNAL(leftClicked()), SLOT(backExButtonLeftClicked()));

}

void ProfileWindow::setupNextPrevExButtons(){
    int radiusNextPrev =30;
    int margin =5;

    nextProfileButtton= new ExButton(this, "Next", radiusNextPrev, 0);
    nextProfileButtton->setImage(":/resourses/icons/ch_right.png");
    nextProfileButtton->setImageMargin(margin);
    nextProfileButtton->setToolTip("Select next profile.");
    nextProfileButtton->setFixedSize(radiusNextPrev, radiusNextPrev);

    previousProfileButton = new ExButton(this, "Prev.",radiusNextPrev, 0);
    previousProfileButton->setImage(":/resourses/icons/ch_left.png");
    previousProfileButton->setImageMargin(margin);
    previousProfileButton->setToolTip("Select previous profile.");
    previousProfileButton->setFixedSize(radiusNextPrev, radiusNextPrev);

    connect(nextProfileButtton, SIGNAL(leftClicked()), this , SLOT(onNextProfileButttonClicked()));
    connect(previousProfileButton, SIGNAL(leftClicked()), this, SLOT(onPreviousProfileButtonClicked()));
}

void ProfileWindow::deleteProfile(){
    setCurrentProfile(currentProfileNumber);
    QFile::remove(currentProfile->getSaveWay());
    QFile::resize(currentProfile->getAllProfilesSaveWay(), 0);

    profileList->removeAt(currentProfileNumber);
    profilesSaveWays->removeAt(currentProfileNumber);
    updateAllProfilesSaveWays();
    currentProfileNumber=0;

    if(profileList->isEmpty()){
        setDefaultProfile();
    }

    emit profileDeleted();
}

void ProfileWindow::setProfileList(QList <Profile*> *list){
    if (list->isEmpty()){
        /*WARNING*/
    }
    else{
        profileList=list;
        setCurrentProfile(0);
    }
}

void ProfileWindow::setProfileSaveWays(QList<QString *> *list){
    profilesSaveWays = list;
}

void ProfileWindow::setCurrentProfile(Profile *profile){
    currentProfile = profile;
}

void ProfileWindow::setCurrentProfile(int pos){
    currentProfile = profileList->at(pos);

    profileNameLabel->setText(currentProfile->getLogin());
    QPixmap avadef(currentProfile->getAvatar());
    profileAvaLabel->setPixmap(avadef);
}

void ProfileWindow::updateAllProfilesSaveWays(){
    int count = profileList->count();
    for (int i =0; i<count; ++i){
        profileList->at(i)->addToAllProfiles();
    }
}

void ProfileWindow::setProfileSetupWindow(ProfileSetupWindow *window){
    profileSetWin = window;
    connect(profileSetWin, SIGNAL(profileAdded()), this, SLOT(onProfileAdded()));
}

void ProfileWindow::setProfileEditWindow(ProfileEditWindow *window){
    profileEditWin = window;
}
void ProfileWindow::mouseReleaseEvent(QMouseEvent *event){

}

void ProfileWindow::StartHideAnim(int left, int top, int width, int height){

    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width, height));
    animation->setEndValue(QRect(left, top, 1, height));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect (animation, SIGNAL(finished()), this, SLOT(hide()));
    groupEx->closeGroup();
    emit hide_();
}

