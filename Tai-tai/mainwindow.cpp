#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QFrame(parent)
{    
    /*temporary settings*/
    initDefSettings();

    /*style of main window*/
    initDefaultStyle();

    /*Profile Windows*/
    initProfileSetupWindow();
    initProfileEditWindow();
    initProfileWindow();
    initEmailEditWindow();
    initNewEmailWindow();

    /*layouts setup and init*/
    initLayouts();

    /*setup top controll layout*/
    initTopControllLayout();

    /*menu of ExButtons*/
    initMenuExButtons();

    /*sentrall layout*/
    initCentrallWidget();

    /*overLay*/
    initOverLay();

    /*profiles init*/
    initProfiles();

    /* TEST*/
    addNewEmailWindow->StartShowAnim(0, 0, 300, height());
}

void MainWindow::initDefSettings(){
    mpos=pos();
    canMove=false;
    subWindows=0;
    //temporary settings//
    mainWindowStartSize.setHeight(600);
    mainWindowStartSize.setWidth(800);
    mainWindownStartPoint.setX(400);
    mainWindownStartPoint.setY(100);
    mainWindowMinSize.setHeight(550);
    mainWindowMinSize.setWidth(500);
    currentProfile= NULL;
    this->installEventFilter(this);
}

void MainWindow::initControllExButtons(){
    int margin =5;
    int radius=25;

    settingsGenegal = new ExButton(this,  "S", radius, 0);
    settingsGenegal->setImage(":/resourses/icons/gear_def.png");
    settingsGenegal->setImageMargin(margin);
    settingsGenegal->setToolTip("Settings and managment.");
    settingsGenegal->setFixedSize(radius, radius);
    settingsGenegal->setOnlyPicture(true);

    closeProgramm = new ExButton(this,  "C", radius, 0);
    closeProgramm->setImage(":/resourses/icons/cancel_nb.png");
    closeProgramm->setImageMargin(margin+1);
    closeProgramm->setToolTip("Close.");
    closeProgramm->setFixedSize(radius, radius);
    closeProgramm->setOnlyPicture(true);


    hideToTray = new ExButton(this,  "H", radius, 0);
    hideToTray->setImage(":/resourses/icons/minimize.png");
    hideToTray->setImageMargin(margin);
    hideToTray->setToolTip("Hide to tray.");
    hideToTray->setFixedSize(radius, radius);
    hideToTray->setOnlyPicture(true);


    expandToWindow = new ExButton(this,  "M", radius, 0);
    expandToWindow->setImage(":/resourses/icons/maximizeWindow.png");
    expandToWindow->setImageMargin(margin);
    expandToWindow->setToolTip("Maximize to window.");
    expandToWindow->setFixedSize(radius, radius);
    expandToWindow->setOnlyPicture(true);


    collapseToWindow = new ExButton(this,  "C", radius, 0);
    collapseToWindow->setImage(":/resourses/icons/restore.png");
    collapseToWindow->setImageMargin(margin);
    collapseToWindow->setToolTip("Collapse to window.");
    collapseToWindow->setFixedSize(radius, radius);
    collapseToWindow->setOnlyPicture(true);
    collapseToWindow->hide();

    connect(closeProgramm, SIGNAL(leftClicked()), this, SLOT(onCloseButtonClicked()));
    connect (hideToTray, SIGNAL(leftClicked()), this, SLOT(showMinimized()));
    connect(expandToWindow, SIGNAL(leftClicked()), this, SLOT(showFullScreen()));
    connect(expandToWindow, SIGNAL(leftClicked()), expandToWindow, SLOT(hide()));
    connect(expandToWindow, SIGNAL(leftClicked()), collapseToWindow, SLOT(show()));
    connect(collapseToWindow, SIGNAL(leftClicked()), this, SLOT(showNormal()));
    connect(collapseToWindow, SIGNAL(leftClicked()), collapseToWindow, SLOT(hide()));
    connect(collapseToWindow, SIGNAL(leftClicked()), expandToWindow, SLOT(show()));

}

void MainWindow::initDefaultStyle(){
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    resize(mainWindowStartSize);
    move(mainWindownStartPoint);
    setMinimumSize(mainWindowMinSize);
    initColors();


    profileNameExLabel = new ExLabel("Profile");
    profileNameExLabel->setStyleSheet("color: #436EEE");

}

void MainWindow::initLayouts(){
    mainLay = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLay->setMargin(0);
    mainLay->setSpacing(0);
    topControllLay = new QBoxLayout(QBoxLayout::LeftToRight);
    topControllLay->setMargin(0);
    topControllLay->setSpacing(0);
    centrallLay = new QBoxLayout(QBoxLayout::LeftToRight);
    centrallLay->setMargin(0);
    centrallLay->setSpacing(0);

    QFrame *h_line = new QFrame();
    h_line->setFrameStyle(QFrame::HLine| QFrame::Raised);
    h_line->setStyleSheet("border: 0px; border-top: 1px solid lightgray");

    mainLay->addLayout(topControllLay);
    mainLay->addWidget(h_line);
    mainLay->addLayout(centrallLay);

    setLayout(mainLay);
}

void MainWindow::initTopControllLayout(){
    int margin =3;
    int spacing=5;
    int maximumHeightTopLabel =31;

    QWidget * topback = new QWidget();
    topback->setStyleSheet("background-color:"+additionBackGroundColor+";border: 0px");
    topback->setMaximumHeight(maximumHeightTopLabel);
    QBoxLayout * controllLay = new QBoxLayout(QBoxLayout::LeftToRight);
    controllLay->setMargin(margin);
    controllLay->setSpacing(spacing);

    topControllLay->addWidget(topback);
    topback->setLayout(controllLay);

    initControllExButtons();

    controllLay->addWidget(settingsGenegal, 0, Qt::AlignLeft|Qt::AlignHCenter);
    controllLay->addStretch(1);
    controllLay->addWidget(profileNameExLabel, 0, Qt::AlignHCenter|Qt::AlignHCenter);
    controllLay->addStretch(1);
    controllLay->addWidget(hideToTray, 0, Qt::AlignRight|Qt::AlignHCenter);
    controllLay->addWidget(expandToWindow, 0, Qt::AlignRight|Qt::AlignHCenter);
    controllLay->addWidget(collapseToWindow, 0, Qt::AlignRight|Qt::AlignHCenter);
    controllLay->addWidget(closeProgramm, 0, Qt::AlignRight|Qt::AlignHCenter);

    connect(profileNameExLabel, SIGNAL(clicked()), this, SLOT(showProfileWindow()));

}

void MainWindow::initOverLay(){
    overLay = new QWidget(this);
    overLay->setWindowFlags(Qt::FramelessWindowHint);
    overLay->setGeometry(0, 0, width(), height());
    overLay->setStyleSheet("background-color:"+overlayBackGroundColor);
    overLay->hide();
    connect (MainProfileWindow, SIGNAL(hide_()), overLay, SLOT(hide()));
    connect (MainProfileWindow, SIGNAL(show_()), overLay, SLOT(show()));
    connect (MainProfileWindow, SIGNAL(show_()), this, SLOT(resizeOverlay()));
}

void MainWindow::initMenuExButtons(){
    int radius= 50;
    int margin = 6;

    writeNewMail = new ExButton(this,  "Write", radius, 0);
    writeNewMail->setRotation(120);
    writeNewMail->setImage(":/resourses/icons/write_nb.png");
    writeNewMail->setImageMargin(margin);
    writeNewMail->setToolTip("Write new e-mail.");

    refreshMail = new ExButton(this,  "Refresh", radius, 1);
    refreshMail->setImage(":/resourses/icons/refresh_def.png");
    refreshMail->setImageMargin(margin);
    refreshMail->setToolTip("Refresh email.");

    deleteMail = new ExButton(this,  "Delete", radius, 1);
    deleteMail->setImage(":/resourses/icons/deleteMail.png");
    deleteMail->setImageMargin(margin);
    deleteMail->setToolTip("Delete selected emails.");

    saveMail = new ExButton(this,  "Save", radius, 1);
    saveMail->setImage(":/resourses/icons/save-file.png");
    saveMail->setImageMargin(margin+3);
    saveMail->setToolTip("Save selected emails.");

    selectAllAsReaded = new ExButton(this,  "Read all", radius, 1);
    selectAllAsReaded->setImage(":/resourses/icons/openMail.png");
    selectAllAsReaded->setImageMargin(margin+1);
    selectAllAsReaded->setToolTip("Mark selected emails as readed.");

    contactList = new ExButton(this,  "Contacts", radius, 1);
    contactList->setImage(":/resourses/icons/contacts.png");
    contactList->setImageMargin(margin);
    contactList->setToolTip("Open contact list.");

    toHome = new ExButton(this,  "Home", radius, 1);
    toHome->setImage(":/resourses/icons/home_def.png");
    toHome->setImageMargin(margin+1);
    toHome->setToolTip("Go back to home page.");

    findList = new ExButton(this,  "Find", radius, 1);
    findList->setImage(":/resourses/icons/search_nb.png");
    findList->setImageMargin(margin-3);
    findList->setToolTip("Find text in emails.");

    groupMenu = new GroupExButtons();

    groupMenu->addButton(writeNewMail);
    groupMenu->addButton(refreshMail);
    groupMenu->addButton(deleteMail);
    groupMenu->addButton(saveMail);
    groupMenu->addButton(selectAllAsReaded);
    groupMenu->addButton(contactList);
    groupMenu->addButton(toHome);
    groupMenu->addButton(findList);

    groupMenu->setScaleKoef(1.3);
    groupMenu->hideGroup();
}

void MainWindow::initColors(){
    mainBackGroudColor ="white";
    additionBackGroundColor="rgb(250, 250, 250)";
    overlayBackGroundColor ="rgba(130, 130, 130, 50%)";
    frameStyleSheet ="      QFrame{border: 1px solid lightgrey;\
                                    background: white}";
    groupBoxStyleSheet ="   QGroupBox{margin-top: 5px;} \
                            QGroupBox::title {subcontrol-origin: margin; \
                                           subcontrol-position: top left;\
                                           left:10 px;\
                                           bottom:2px\
                                           color: #8B6969}\
                            QCheckBox{border: 0px}";

    lineEditStyleSheet ="   QLineEdit{ border-style: solid;\
                                    border-width: 1px;\
                                    border-color: #BEBEBE;} \
                            QLineEdit:hover{ border-style: solid;\
                                    border-width: 1px;\
                                    border-color: #8B8989;}\
                            QLineEdit:focus{ border-style: solid;\
                                    border-width: 1px;\
                                    border-color: #4ea6ea;}\
                            QLineEdit:disabled{ border-style: solid;\
                                    border-width: 1px;\
                                    border-color: #D3D3D3;}";

    labelStyleSheet = "     QLabel {border:0px}";

    setStyleSheet(frameStyleSheet+groupBoxStyleSheet+lineEditStyleSheet+labelStyleSheet);

}

void MainWindow::initProfiles(){

    openAllProfilesInf();
    openAllprofiles();

    MainProfileWindow->setProfileList(&profileList);
    MainProfileWindow->setProfileSaveWays(&profilesSaveWays);
}

void MainWindow::initProfileWindow(){
    MainProfileWindow = new ProfileWindow(this);
    MainProfileWindow->setProfileEditWindow(profileEditWindow);
    MainProfileWindow->setProfileSetupWindow(profileSetupWindow);

    connect(MainProfileWindow, SIGNAL(profileAdded()), this, SLOT(updateProfiles()));
    connect (MainProfileWindow, SIGNAL(profileDeleted()), this, SLOT(updateProfiles()));
    connect(MainProfileWindow, SIGNAL(profileLogged(Profile*)), this , SLOT(loginProfile(Profile*)));
    connect(MainProfileWindow, SIGNAL(profileLogout()), this, SLOT(logoutProfile()));
    connect(MainProfileWindow, SIGNAL(profileEditing(Profile*)), profileEditWindow, SLOT(setCurrentProfile(Profile*)));

    connect (MainProfileWindow, SIGNAL(show_()), this, SLOT(subwindowsOn()));
    connect (MainProfileWindow, SIGNAL(hide_()), this, SLOT(subwindowsOff()));
}

void MainWindow::initCentrallWidget(){
    QWidget * centrallBackWidget =  new QWidget();
    centrallBackWidget->setStyleSheet("background-color:white; border: 0px");
    centrallLay->addWidget(centrallBackWidget);
}

void MainWindow::initProfileSetupWindow(){
    profileSetupWindow = new ProfileSetupWindow(this);
    connect (profileSetupWindow, SIGNAL(show_()), this, SLOT(subwindowsOn()));
    connect (profileSetupWindow, SIGNAL(hide_()), this, SLOT(subwindowsOff()));

}

void MainWindow::initProfileEditWindow(){
    profileEditWindow = new ProfileEditWindow(this);
    connect (profileEditWindow, SIGNAL(show_()), this, SLOT(subwindowsOn()));
    connect (profileEditWindow, SIGNAL(hide_()), this, SLOT(subwindowsOff()));
}

void MainWindow::initEmailEditWindow(){
    emailEditWindow = new EmailEditWindow(this);
    connect (emailEditWindow, SIGNAL(show_()), this, SLOT(subwindowsOn()));
    connect (emailEditWindow, SIGNAL(hide_()), this, SLOT(subwindowsOff()));
    profileEditWindow->setEmailEditWindow(emailEditWindow);
    MainProfileWindow->setEmailEditWindow(emailEditWindow);
}

void MainWindow::initNewEmailWindow(){
    addNewEmailWindow= new AddNewEmailWindow(this);
    connect (addNewEmailWindow, SIGNAL(show_()), this, SLOT(subwindowsOn()));
    connect (addNewEmailWindow, SIGNAL(hide_()), this, SLOT(subwindowsOff()));
    emailEditWindow->setAddNewEmailWindow(addNewEmailWindow);
}

MainWindow::~MainWindow(){

}

void MainWindow::showMenu(){
    int h = height();
    int w = width();
    int halfRadius = groupMenu->getBigRadius()/2;

    groupMenu->moveToPoints(w/2-halfRadius, h/2-halfRadius);
    overLay->resize(w, h);
    overLay->raise();
    overLay->show();
    groupMenu->showGroup();
    groupMenu->raiseToTop();
}

void MainWindow::hideMenu(){
    groupMenu->hideGroup();
    overLay->hide();
}

QString MainWindow::getMainBackGroudColor(){
    return mainBackGroudColor;
}

QString MainWindow::getAdditionBackGroundColor(){
    return additionBackGroundColor;

}

QString MainWindow::getOverlayBackGroundColor(){
    return overlayBackGroundColor;
}

bool MainWindow::openAllProfilesInf(){
    QString allProfiles = "C:\\Users\\Mera\\Documents\\GitHub\\Tai-tai\\Accounts\\AllProfiles.txt";

    QFile file(allProfiles);
    if (file.open(QFile::ReadOnly)==(-1)){
        return false;
    }
    if(!file.isOpen())
        return false;

    QDataStream in(&file);

    while (!in.atEnd()){
        QString *temp = new QString();
        in>>*temp;
        profilesSaveWays.append(temp);
        qDebug()<<*temp;
    }
    file.close();
    return true;
}

bool MainWindow::openAllprofiles(){
    QString tempProfileSaveWay;

    if (profilesSaveWays.count()==0)
        return false;
    int count = profilesSaveWays.count();

    for (int i=0;i<count;++i){
        Profile *tempProfile = new Profile();
        QString curWay;
        curWay =*profilesSaveWays.at(i);
        QFile file (curWay);
        if (!file.open(QIODevice::ReadOnly)) {
            //"Unable to open file");
            file.close();
            return false;
        }
        QDataStream in(&file);

        in>> *tempProfile;
        tempProfile->setSaveWay(curWay);
        profileList.append(tempProfile);
        file.close();
    }
    return true;
}

void MainWindow::showProfileWindow(){
    MainProfileWindow->StartShowAnim(0, 0, 300, height());
    overLay->raise();
    MainProfileWindow->raise();
}

void MainWindow::hideProfileWindow(){
    MainProfileWindow->StartHideAnim(0, 0, 300, height());
}

void MainWindow::updateProfiles(){
    profileList.clear();
    profilesSaveWays.clear();
    initProfiles();

}

void MainWindow::loginProfile(Profile *profile){
    currentProfile = profile;
    profileNameExLabel->setText(currentProfile->getLogin());
}

void MainWindow::logoutProfile(){
    currentProfile = NULL;
    profileNameExLabel->setText("Profiles");
}

void MainWindow::subwindowsOn(){
    ++subWindows;
}

void MainWindow::subwindowsOff(){
    --subWindows;
}

void MainWindow::onCloseButtonClicked(){
    exit(0);
}

void MainWindow::resizeOverlay(){
    overLay->resize(width(), height());
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if (subWindows)
        return QObject::eventFilter(obj,event);

    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key()==Qt::Key_Shift){
            showMenu();
            return true;
        }
    }
    if (event->type() == QEvent::KeyRelease){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key()==Qt::Key_Shift){
            hideMenu();
            return true;
        }
    }
    return QObject::eventFilter(obj,event);
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)    {
        mpos = event->pos();
        canMove = true;
    }
    if(subWindows>0){
        if (mpos.x()>300){
            profileEditWindow->StartHideAnim();
            profileSetupWindow->animatedHide();
            MainProfileWindow->animatedHide();
            emailEditWindow->StartHideAnim();
            addNewEmailWindow->StartHideAnim();
            subWindows=0;
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && canMove) {
        canMove = false;
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if((event->buttons() & Qt::LeftButton) && canMove){
        move(event->globalPos()-mpos);
    }
}
