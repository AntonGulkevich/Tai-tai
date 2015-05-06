#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QFrame(parent)
{
    mpos=pos();
    canMove=false;
    //temporary settings//
    mainWindowStartSize.setHeight(600);
    mainWindowStartSize.setWidth(800);
    mainWindownStartPoint.setX(400);
    mainWindownStartPoint.setY(100);
    mainWindowMinSize.setHeight(550);
    mainWindowMinSize.setWidth(500);
    //temporary settings//

    /*style of main window*/
    initDefaultStyle();
    /*********************/

    MainProfileWindow = new ProfileWindow(this);

    /*layouts setup and init*/
    initLayouts();
    /************************/

    /*setup top controll layout*/
    initTopControllLayout();
    /**************************/

    /*scroll areal example
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollWidget = new QWidget(scrollArea);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);
    for (int j=0; j<100; j++)
    {
        scrollLayout->addWidget(new QLabel("This is a test"),0, Qt::AlignLeft );  // adding your widgets to scrolllayout
    }
    scrollArea->setWidget(scrollWidget);
    leftTopLay->addWidget(scrollArea, 0);

    centrallLay->addWidget(new QLabel("This is a test"), 1);
    */

    /*menu of ExButtons*/
    initMenuExButtons();
    /********************/

    /*sentrall layout*/
    QWidget * centrallBackWidget =  new QWidget();
    centrallBackWidget->setStyleSheet("background-color:white; border: 0px");
    centrallLay->addWidget(centrallBackWidget);
    this->installEventFilter(this);
    /*****************/

    /*overLay*/
    initOverLay();
    /*********/

    /*profiles init*/
    initProfiles();
    /***************/
}

void MainWindow::initControllExButtons(){
    int margin =5;
    int radius=25;

    settingsGenegal = new ExButton(this,  "S", radius, 0);
    settingsGenegal->setImage(":/resourses/icons/gear_def.png");
    settingsGenegal->setImageMargin(margin);
    settingsGenegal->setToolTip("Settings and managment.");
    settingsGenegal->setFixedSize(radius, radius);

    closeProgramm = new ExButton(this,  "C", radius, 0);
    closeProgramm->setImage(":/resourses/icons/cancel_nb.png");
    closeProgramm->setImageMargin(margin+1);
    closeProgramm->setToolTip("Close.");
    closeProgramm->setFixedSize(radius, radius);


    hideToTray = new ExButton(this,  "H", radius, 0);
    hideToTray->setImage(":/resourses/icons/minimize.png");
    hideToTray->setImageMargin(margin);
    hideToTray->setToolTip("Hide to tray.");
    hideToTray->setFixedSize(radius, radius);


    expandToWindow = new ExButton(this,  "M", radius, 0);
    expandToWindow->setImage(":/resourses/icons/maximizeWindow.png");
    expandToWindow->setImageMargin(margin);
    expandToWindow->setToolTip("Maximize to window.");
    expandToWindow->setFixedSize(radius, radius);


    collapseToWindow = new ExButton(this,  "C", radius, 0);
    collapseToWindow->setImage(":/resourses/icons/minimize2.png");
    collapseToWindow->setImageMargin(margin);
    collapseToWindow->setToolTip("Collapse to window.");
    collapseToWindow->setFixedSize(radius, radius);
    collapseToWindow->hide();


    profileNameExLabel = new ExLabel("Default profile");

}

void MainWindow::initDefaultStyle(){
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    resize(mainWindowStartSize);
    move(mainWindownStartPoint);
    setMinimumSize(mainWindowMinSize);
    initColors();
    setStyleSheet("border: 1px solid lightgrey; background: white");

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
}

void MainWindow::initProfiles(){

    openAllProfilesInf();
    openAllprofiles();

    MainProfileWindow->setProfileList(profileList);
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
        QFile file(*profilesSaveWays.at(i));
        if (!file.open(QIODevice::ReadOnly)) {
            //"Unable to open file");
            file.close();
            return false;
        }
        QDataStream in(&file);

        in>> *tempProfile;
        profileList.append(tempProfile);
        file.close();
    }
    return true;
}

void MainWindow::showProfileWindow(){
    MainProfileWindow->StartShowAnim(0, 0, mainWindowStartSize.width()/2-100, mainWindowStartSize.height());
    overLay->raise();
    MainProfileWindow->raise();
}

void MainWindow::hideProfileWindow(){
    MainProfileWindow->StartHideAnim(0, 0, mainWindowStartSize.width()/2-100, mainWindowStartSize.height());
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key()==Qt::Key_Control){
            showMenu();
            return true;
        }
    }
    if (event->type() == QEvent::KeyRelease){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key()==Qt::Key_Control){
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
