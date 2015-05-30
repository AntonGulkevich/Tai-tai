#include "profileeditwindow.h"

ProfileEditWindow::ProfileEditWindow(QWidget *parent) :
    QFrame(parent)
{
    resize(0, parent->height());
    move(0, 0);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QFrame{background-color: white }");

    /*Layouts*/
    initLayouts();
    /*Ex buttons*/
    initExButtons();

    hide();
}
void ProfileEditWindow::StartShowAnim(int left, int top, int width, int height){
    show();
    raise();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, 0, height));
    animation->setEndValue(QRect(left, top, width, height));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    controllGroup->moveToPoints(150 - controllGroup->getBigRadius()/2, buttonsLay->geometry().top()+70);
    emit show_();
}

void ProfileEditWindow::StartHideAnim(){
    int left =0;
    int top =0;
    int height_ = height();
    int width_ = width();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width_, height_));
    animation->setEndValue(QRect(left, top, 1, height_));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect (animation, SIGNAL(finished()), this, SLOT(close()));
    controllGroup->closeGroup();
    emit hide_();
}
bool ProfileEditWindow::isCorrectLineEdit(QLineEdit *lineEdit){
    if (lineEdit->text().isEmpty()){
        lineEdit->setStyleSheet("QLineEdit { border: 1px solid red}");
        return false;
    }
    else{
        lineEdit->setStyleSheet("");
        return true;
    }
}

void ProfileEditWindow::setEmailEditWindow(EmailEditWindow *window){
    emailEditWindow = window;
}

void ProfileEditWindow::initLayouts(){
    int margin = 0;
    int spacing = 0;
    mainLay= new QBoxLayout(QBoxLayout::TopToBottom);
    settingsGUILay = new QBoxLayout (QBoxLayout::TopToBottom);
    passwordLay = new QBoxLayout (QBoxLayout::TopToBottom);
    emailLay = new QBoxLayout (QBoxLayout::TopToBottom);
    buttonsLay = new QBoxLayout(QBoxLayout::TopToBottom);

    settingsGUILay->setSpacing(spacing);
    settingsGUILay->setMargin(10);

    passwordLay->setSpacing(spacing);
    passwordLay->setMargin(10);

    emailLay->setSpacing(spacing);
    emailLay->setMargin(10);

    buttonsLay->setSpacing(spacing);
    buttonsLay->setMargin(margin);

    mainLay->setSpacing(spacing);
    mainLay->setMargin(margin);

    initCaptionLay();

    mainLay->addLayout(passwordLay,0);
    mainLay->addLayout(settingsGUILay, 0);
    mainLay->addLayout(emailLay, 0);
    mainLay->addLayout(buttonsLay, 0);

    initPasswordLay();
    initSettingsGuiLay();
    initEmailslay();


    setLayout(mainLay);
}

void ProfileEditWindow::initPasswordLay(){
    int margin = 10;
    int spacing = 10;
    QGroupBox *passwordGB = new QGroupBox("Password");
    passwordGB->setStyleSheet("QLabel {border:0px} \
                              QGroupBox{margin-top: 5px;} \
                              QGroupBox::title {subcontrol-origin: margin; \
                                                subcontrol-position: top left;\
                                                left:10 px;bottom:2px}\
                              QGroupBox::title {color: #8B6969}");
    QGridLayout *passwordInnerLay = new QGridLayout;
    passwordLay->addWidget(passwordGB, 0);
    passwordInnerLay->setSpacing(spacing);
    passwordInnerLay->setMargin(margin);

    QLabel *oldPasswordLabel= new QLabel("Old password:");
    QLabel *newPasswordLabel = new QLabel("New password:");
    QLabel *repeatNewPasswordLabel = new QLabel("Repeat new password:");

    oldPasswordLE= new QLineEdit();
    newPasswordLE = new QLineEdit();
    repeatNewPasswordLE = new QLineEdit();

    oldPasswordLE->setEchoMode(QLineEdit::Password);
    newPasswordLE->setEchoMode(QLineEdit::Password);
    repeatNewPasswordLE->setEchoMode(QLineEdit::Password);

    passwordInnerLay->addWidget(oldPasswordLabel, 0, 0);
    passwordInnerLay->addWidget(oldPasswordLE, 0, 1);
    passwordInnerLay->addWidget(newPasswordLabel, 1, 0);
    passwordInnerLay->addWidget(newPasswordLE, 1, 1);
    passwordInnerLay->addWidget(repeatNewPasswordLabel, 2, 0);
    passwordInnerLay->addWidget(repeatNewPasswordLE, 2, 1);

    passwordGB->setLayout(passwordInnerLay);
}

void ProfileEditWindow::initSettingsGuiLay(){
    QGroupBox *settingsGB = new QGroupBox("GUI settings");
    settingsGB->setStyleSheet("QLabel {border:0px} \
                                QGroupBox{margin-top: 5px;} \
                                QGroupBox::title {subcontrol-origin: margin; \
                                                  subcontrol-position: top left;\
                                                  left:10 px; bottom:2px}\
                                QCheckBox{border: 0px}\
                                QGroupBox::title {color: #8B6969}");
    QGridLayout *settingsGuiInnerLay = new QGridLayout;
    settingsGUILay->addWidget(settingsGB, 0);

    QLabel *dinamicGuiLabel = new QLabel ("Enable dinamic GUI:");
    QLabel *stopStatLabel = new QLabel ("Enable update statistic:");

    dinamicGUICB = new QCheckBox();
    stopStatCB = new QCheckBox();

    settingsGuiInnerLay->addWidget(dinamicGuiLabel, 0, 0);
    settingsGuiInnerLay->addWidget(dinamicGUICB, 0, 1);
    settingsGuiInnerLay->addWidget(stopStatLabel, 1, 0);
    settingsGuiInnerLay->addWidget(stopStatCB, 1, 1);

    settingsGB->setLayout(settingsGuiInnerLay);
}

void ProfileEditWindow::initEmailslay(){
    int margin = 10;
    int spacing = 10;
    QGroupBox *emailGB = new QGroupBox("Emails");
    emailGB->setStyleSheet("QLabel {border:0px} \
                                QGroupBox{margin-top: 5px;} \
                                QGroupBox::title {subcontrol-origin: margin; \
                                                  subcontrol-position: top left;\
                                                  left:10 px; bottom:2px}\
                                QCheckBox{border: 0px;}\
                                QGroupBox::title {color: #8B6969}");
    emailLay->addWidget(emailGB);
    /*
    QScrollArea *scrollArea = new QScrollArea(emailGB);
    emailGB->setMinimumHeight(110);
    scrollArea->setStyleSheet("QScrollArea{margin-top:15px;margin-left:5 px; border: 0px}\
                              QScrollBar {background: white; width: 7px; border:0 px}\
                              QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {width:5 px; height: 5px}\
                              QScrollBar::handle:vertical {background: gray; min-width: 7px; min-height:25px}");
    scrollArea->setFixedHeight(105);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QWidget *scrollWidget = new QWidget(scrollArea);
    scrollWidget->setStyleSheet("border:0px");
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);
    scrollLayout->setSpacing(spacing);
    scrollLayout->setMargin(margin);


    for (int j=0; j<100; j++)
    {
        scrollLayout->addWidget(new QLabel("This is a test"));  // adding your widgets to scrolllayout
    }

    scrollArea->setWidget(scrollWidget);
    */
    QVBoxLayout *emailInnerLay = new QVBoxLayout(emailGB);
    emailInnerLay->setMargin(margin);
    emailInnerLay->setSpacing(spacing);
    emailsEL = new ExLabel("Manage emails accounts.");
    emailsEL->setFonts(11, 11, 11);
    emailsEL->setStyleSheet("color: #436EEE");
    emailInnerLay->addWidget(emailsEL);
    connect(emailsEL, SIGNAL(clicked()), this, SLOT(onEmailELClicked()));
    buttonsLay->addStretch(1);
}

void ProfileEditWindow::initCaptionLay(){

    QWidget *labelCaptionBack = new QWidget();
    labelCaptionBack->setStyleSheet("background-color:rgba(250, 250, 250);border:0px; border-bottom: 1px solid lightgray");
    QBoxLayout *labelcaptionLay = new QBoxLayout(QBoxLayout::TopToBottom);
    labelCaptionBack->setMaximumHeight(32);
    labelCaptionBack->setMinimumHeight(32);
    labelcaptionLay->setSpacing(0);
    labelcaptionLay->setMargin(0);

    windowCaptionLabel = new QLabel("Edit profile.");
    windowCaptionLabel->setStyleSheet("font: 14px; border:0px");

    labelcaptionLay->addWidget(windowCaptionLabel, 0, Qt::AlignCenter);
    labelCaptionBack->setLayout(labelcaptionLay);
    mainLay->addWidget(labelCaptionBack);
}

void ProfileEditWindow::initExButtons(){
    int margin = 10;
    int radius = 50;

    saveAndExitEB = new ExButton(this,  "Save", radius, 0);
    saveAndExitEB->move(800/4-100+50/2, 600/2+50/2+150);
    saveAndExitEB->setRotation(273);
    saveAndExitEB->setImage(":/resourses/icons/check_nb.png");
    saveAndExitEB->setImageMargin(margin);
    saveAndExitEB->setToolTip("Save profile and exit setup.");

    backEB = new ExButton(this,  "Back", radius, 1);
    backEB->setImage(":/resourses/icons/back_nb.png");
    backEB->setImageMargin(margin);
    backEB->setToolTip("Exit without saving.");

    defaultEB = new ExButton(this,  "Restore", radius, 1);
    defaultEB->setImage(":/resourses/icons/restore_nb.png");
    defaultEB->setImageMargin(margin);
    defaultEB->setToolTip("Restore previous settings.");

    approveEB = new ExButton(this, "Approve", radius, 1);
    approveEB->setImage(":/resourses/icons/approve.png");
    approveEB->setImageMargin(margin);
    approveEB->setToolTip("Save profile.");

    controllGroup= new GroupExButtons();

    controllGroup->addButton(saveAndExitEB);
    controllGroup->addButton(backEB);
    controllGroup->addButton(defaultEB);
    controllGroup->addButton(approveEB);

    controllGroup->setDefaultButton("Save");

    connect(saveAndExitEB, SIGNAL(leftClicked()), this, SLOT(onSaveAndExitEBClicked()));
    connect(backEB, SIGNAL(leftClicked()), this, SLOT(onBackEBClicked()));
    connect(defaultEB, SIGNAL(leftClicked()), this, SLOT(onDefaultEBClicked()));
    connect(approveEB, SIGNAL(leftClicked()), this, SLOT(onApproveEBClicked()));

}
void ProfileEditWindow::clearAllContent(){
    oldPasswordLE->setText("");
    newPasswordLE->setText("");
    repeatNewPasswordLE->setText("");
}

void ProfileEditWindow::onSaveAndExitEBClicked(){

}

void ProfileEditWindow::onBackEBClicked(){
   StartHideAnim();
}

void ProfileEditWindow::onDefaultEBClicked(){

}

void ProfileEditWindow::onApproveEBClicked(){

}

void ProfileEditWindow::onEmailELClicked(){
    emailEditWindow->setCurrentProfile(currentProfile);
    emailEditWindow->StartShowAnim(0, 0,  300, height());

}

void ProfileEditWindow::setCurrentProfile(Profile *profile){
    currentProfile = profile;
    windowCaptionLabel->setText("Edit profile: "+ currentProfile->getLogin());
    dinamicGUICB->setChecked(currentProfile->getDGuiMode());
    stopStatCB->setChecked(currentProfile->getStatisticMode());
}
