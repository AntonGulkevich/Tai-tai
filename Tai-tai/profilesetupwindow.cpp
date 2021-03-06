#include "profilesetupwindow.h"

ProfileSetupWindow::ProfileSetupWindow(QWidget *parent) :
    QFrame(parent)
{

    resize(0, parent->height());
    move(0, 0);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QFrame{background-color: white }");
    defaultAva = ":/resourses/icons/ava_def.jpg";
    /*Layouts*/
    mainLay=new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLay->setSpacing(0);
    mainLay->setMargin(0);

    topLay = new QBoxLayout(QBoxLayout::TopToBottom);
    topLay->setSpacing(0);
    topLay->setMargin(0);

    botLayl = new QBoxLayout(QBoxLayout::TopToBottom);

    gridLay = new QGridLayout();
    gridLay->setSpacing(5);
    gridLay->setMargin(10);

    mainLay->addLayout(topLay);
    mainLay->addLayout(botLayl);
    setStyleSheet("QLabel { border: 0 px}");
    /**********/
    QWidget *labelCaptionBack = new QWidget();
    labelCaptionBack->setStyleSheet("background-color:rgba(250, 250, 250); border: 0px");
    QBoxLayout *labelcaptionLay = new QBoxLayout(QBoxLayout::TopToBottom);
    labelCaptionBack->setMaximumHeight(31);
    labelCaptionBack->setMinimumHeight(31);
    labelcaptionLay->setSpacing(0);
    labelcaptionLay->setMargin(0);

    windowCaption = new QLabel("Create new profile.");
    windowCaption->setStyleSheet("font: 14px");

    labelcaptionLay->addWidget(windowCaption, 0, Qt::AlignCenter);
    labelCaptionBack->setLayout(labelcaptionLay);

    QFrame *h_line = new QFrame();
    h_line->setFrameStyle(QFrame::HLine| QFrame::Raised);
    h_line->setStyleSheet("border: 0px; border-top: 1px solid lightgray");

    QLabel * profileCaptionLabel = new QLabel("Name of the new profile:");
    profileNameLE = new QLineEdit();

    profileAvaLabel = new ExLabel("AVA");
    profileAvaLabel->setMaximumSize(200, 220);
    QPixmap avadef(defaultAva);
    profileAvaLabel->setPixmap(avadef);
    QString actSS, inActSS;
    actSS="QLabel{ border: 1px solid gray;}";
    inActSS ="QLabel{ border: 1px solid lightgray;}";
    profileAvaLabel->setStyleSheet(inActSS);
    profileAvaLabel->setActiveStyleSheet(actSS);
    profileAvaLabel->setInActiveStyleSheet(inActSS);
    profileAvaLabel->setScaledContents(true);

    QLabel *profilePasswordLabel = new QLabel("New password:");
    profilePasswordFirstLE =  new QLineEdit();
    profilePasswordFirstLE->setEchoMode(QLineEdit::Password);

    QLabel *profilePasswordVerificationLabel = new QLabel ("Repeat password:");
    profilePasswordSecondLE = new QLineEdit();
    profilePasswordSecondLE->setEchoMode(QLineEdit::Password);

    errorMessage =  new QLabel("");
    errorMessage->setStyleSheet("color:red");
    errorMessage->hide();

    topLay->addWidget(labelCaptionBack, 1);
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
    topLay->addWidget(errorMessage, 0, Qt::AlignHCenter);

    botLayl->addStretch(1);

    /*exbuttons*/

    int margin =10;
    int radius=50;

    cancel = new ExButton(this,  "Cancel", radius, 0);
    cancel->setRotation(273);
    cancel->setImage(":/resourses/icons/back_nb.png");
    cancel->setImageMargin(margin);
    cancel->setToolTip("Close this window.");

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
    connect(this, SIGNAL(hide_()), this, SLOT(clearAllContent()));
    connect (profileAvaLabel, SIGNAL(clicked()), this, SLOT(onAvatarCliked()));
    connect (this, SIGNAL(show_()), this , SLOT(createTempProfile()));
    /*************/

    hide();
}

void ProfileSetupWindow::StartShowAnim(int left, int top, int width, int height){
    show();
    raise();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, 0, height));
    animation->setEndValue(QRect(left, top, width, height));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    controllGroup->moveToPoints(150 - controllGroup->getBigRadius()/2, botLayl->geometry().top()+70);
    emit show_();
}

void ProfileSetupWindow::StartHideAnim(int left, int top, int width, int height){

    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width, height));
    animation->setEndValue(QRect(left, top, 1, height));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect (animation, SIGNAL(finished()), this, SLOT(close()));
    emit hide_();
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

void ProfileSetupWindow::addNewProfile(){
    QString login;
    QString password1;
    login = profileNameLE->text();
    password1 = profilePasswordFirstLE->text();
    if (currentProfile->getAvatar()==""){
        currentProfile->setAvatar(defaultAva);
    }

    currentProfile->setSaveWay(currentProfile->getSaveWay()+login+".txt");
    currentProfile->setLogin(profileNameLE->text());
    currentProfile->setPasswordText(password1);
    currentProfile->saveprofile();
    currentProfile->addToAllProfiles();

    delete(currentProfile);
    animatedHide();
    emit profileAdded();
}

void ProfileSetupWindow::setEmailEditWindow(EmailEditWindow *window){
    emailEditWindow= window;
}

void ProfileSetupWindow::onCancelExButtonclicked(){
    animatedHide();

}
void ProfileSetupWindow::animatedHide(){
    StartHideAnim(0, 0, width(), height());
}

void ProfileSetupWindow::onAvatarCliked(){
    QString fileName =QFileDialog::getOpenFileName(this,
                                                   tr("Open avatar"), "C:\\Users\\Mera\\Documents\\GitHub\\Tai-tai\\Accounts",
                                                   tr("pmg (*.png);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        currentProfile->setAvatar(fileName);
        QPixmap ava(fileName);
        profileAvaLabel->setPixmap(ava);
    }
}

bool ProfileSetupWindow::onSaveAndContinueExButtonClicked(){
    QString login;
    QString password1;
    QString password2;
    login = profileNameLE->text();
    password1 = profilePasswordFirstLE->text();
    password2 = profilePasswordSecondLE->text();

    bool correctInput=true;
    bool similarPasswords=false;
    if (!isCorrectLineEdit(profileNameLE)){
        correctInput=false;
    }
    if(!isCorrectLineEdit(profilePasswordFirstLE)){
        correctInput=false;
    }
    if (!isCorrectLineEdit(profilePasswordSecondLE)){
        correctInput=false;
    }
    if (password1==password2){
        similarPasswords=true;
    }
    if (!similarPasswords){
        profilePasswordFirstLE->setText("");
        profilePasswordSecondLE->setText("");
        isCorrectLineEdit(profilePasswordFirstLE);
        isCorrectLineEdit(profilePasswordSecondLE);
        errorMessage->setText("Different passwords.");
        errorMessage->show();
        return false;
    }
    if (!correctInput){
        errorMessage->setText("All fields must be filled.");
        errorMessage->show();
        return false;
    }
    errorMessage->hide();
    addNewProfile();
    return true;
}

void ProfileSetupWindow::onExtendedSetupExButtonClicked(){
    if (onSaveAndContinueExButtonClicked())
        emit setupLastProfile();
}

void ProfileSetupWindow::onAddEmailExButtonClicked(){
    if (onSaveAndContinueExButtonClicked())
        emit addEmailLastProfile();
}

void ProfileSetupWindow::clearAllContent(){
    profileNameLE->setStyleSheet("");
    profilePasswordFirstLE->setStyleSheet("");
    profilePasswordSecondLE->setStyleSheet("");
    errorMessage->hide();
    profileNameLE->clear();
    profilePasswordFirstLE->clear();
    profilePasswordSecondLE->clear();
    QPixmap avadef(":/resourses/icons/ava_def.jpg");
    profileAvaLabel->setPixmap(avadef);
}

void ProfileSetupWindow::setCurrentProfile(Profile *profile){
    currentProfile = profile;
}

void ProfileSetupWindow::createTempProfile(){
    currentProfile = new Profile();
}
