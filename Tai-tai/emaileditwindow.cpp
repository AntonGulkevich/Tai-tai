#include "emaileditwindow.h"

EmailEditWindow::EmailEditWindow(QWidget *parent) :
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
}
void EmailEditWindow::StartHideAnim(){
    int left =0;
    int top =0;
    int height_ = height();
    int width_ = width();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width_, height_));
    animation->setEndValue(QRect(left, top, 1, height_));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect (animation, SIGNAL(finished()), this, SLOT(hide()));
    controllGroup->closeGroup();
    emit hide_();
}
void EmailEditWindow::StartShowAnim(int left, int top, int width, int height){
    show();
    raise();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, 0, height));
    animation->setEndValue(QRect(left, top, width, height));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    controllGroup->moveToPoints(150 - controllGroup->getBigRadius()/2, this->height()-105);
    emailGB->setMinimumHeight(this->height()-220);
    scrollArea->setFixedHeight(this->height()-225);
    fillEmailsTable();
    emit show_();
}
bool EmailEditWindow::isCorrectLineEdit(QLineEdit *lineEdit){
    if (lineEdit->text().isEmpty()){
        lineEdit->setStyleSheet("QLineEdit { border: 1px solid red}");
        return false;
    }
    else{
        lineEdit->setStyleSheet("");
        return true;
    }
}

void EmailEditWindow::initLayouts(){
    int margin = 0;
    int spacing = 0;


    mainLay= new QBoxLayout(QBoxLayout::TopToBottom);
    mainLay->setSpacing(spacing);
    mainLay->setMargin(margin);

    initCaptionLay();
    initButtonsLay();
    initScrollLay();

    mainLay->addLayout(scrollLayout, 0);
    mainLay->addLayout(buttonsLay, 0);

    setLayout(mainLay);
}

void EmailEditWindow::initCaptionLay(){
    QWidget *labelCaptionBack = new QWidget();
    labelCaptionBack->setStyleSheet("background-color:rgba(250, 250, 250);border:0px; border-bottom: 1px solid lightgray");
    QBoxLayout *labelcaptionLay = new QBoxLayout(QBoxLayout::TopToBottom);
    labelCaptionBack->setMaximumHeight(32);
    labelCaptionBack->setMinimumHeight(32);
    labelcaptionLay->setSpacing(0);
    labelcaptionLay->setMargin(0);

    windowCaptionLabel = new QLabel("Manage emails.");
    windowCaptionLabel->setStyleSheet("font: 14px; border:0px");

    labelcaptionLay->addWidget(windowCaptionLabel, 0, Qt::AlignCenter);
    labelCaptionBack->setLayout(labelcaptionLay);
    mainLay->addWidget(labelCaptionBack);
}

void EmailEditWindow::initButtonsLay(){
    int margin = 10;
    int spacing = 10;

    buttonsLay = new QBoxLayout(QBoxLayout::TopToBottom);
    buttonsLay->addStretch(1);

    buttonsLay->setSpacing(spacing);
    buttonsLay->setMargin(margin);

}

void EmailEditWindow::initExButtons(){
    int margin = 10;
    int radius = 50;

    saveAndExitEB = new ExButton(this,  "Save", radius, 0);
    saveAndExitEB->move(800/4-100+50/2, 600/2+50/2+150);
    saveAndExitEB->setRotation(273);
    saveAndExitEB->setImage(":/resourses/icons/check_nb.png");
    saveAndExitEB->setImageMargin(margin);
    saveAndExitEB->setToolTip("Save changes and exit.");

    backEB = new ExButton(this,  "Back", radius, 1);
    backEB->setImage(":/resourses/icons/back_nb.png");
    backEB->setImageMargin(margin);
    backEB->setToolTip("Exit without saving.");

    addEmail = new ExButton(this,  "Add", radius, 1);
    addEmail->setImage(":/resourses/icons/add_nb.png");
    addEmail->setImageMargin(margin);
    addEmail->setToolTip("Add new email account.");

    approveEB = new ExButton(this, "Approve", radius, 1);
    approveEB->setImage(":/resourses/icons/approve.png");
    approveEB->setImageMargin(margin);
    approveEB->setToolTip("Save all changes.");

    deleteEmail = new ExButton(this, "Delete", radius, 1);
    deleteEmail->setImage(":/resourses/icons/cancel_nb.png");
    deleteEmail->setImageMargin(margin+2);
    deleteEmail->setToolTip("Delete selected emails.");

    editEmail = new ExButton(this, "Edit", radius, 1);
    editEmail->setImage(":/resourses/icons/write_nb.png");
    editEmail->setImageMargin(2);
    editEmail->setToolTip("Edit selected emails.");

    controllGroup= new GroupExButtons();

    controllGroup->addButton(saveAndExitEB);
    controllGroup->addButton(backEB);
    controllGroup->addButton(addEmail);
    controllGroup->addButton(approveEB);
    controllGroup->addButton(deleteEmail);
    controllGroup->addButton(editEmail);

    controllGroup->setDefaultButton("Save");

    connect(saveAndExitEB, SIGNAL(leftClicked()), this, SLOT(onSaveAndExitEBClicked()));
    connect(backEB, SIGNAL(leftClicked()), this, SLOT(onBackEBClicked()));
    connect(approveEB, SIGNAL(leftClicked()), this, SLOT(onApproveEBClicked()));
    connect(addEmail, SIGNAL(leftClicked()), this, SLOT(onAddEmailEBClicked()));
    connect(deleteEmail, SIGNAL(leftClicked()), this, SLOT(onDeleteEBClicked()));
    connect(editEmail, SIGNAL(leftClicked()), this, SLOT(onEditEBClicked()));
}

void EmailEditWindow::initScrollLay(){
    int margin = 10;
    int spacing = 5;

    scrollLayout = new QVBoxLayout;
    scrollLayout->setSpacing(spacing);
    scrollLayout->setMargin(margin);

    emailGB = new QGroupBox("Emails");
    emailGB->setStyleSheet("QLabel {border:0px} \
                           QGroupBox{margin-top: 5px;} \
                           QGroupBox::title {subcontrol-origin: margin; \
                                             subcontrol-position: top left;\
                                             left:10 px; bottom:2px}\
                           QCheckBox{border: 0px;}\
                           QGroupBox::title {color: #8B6969}");
    scrollLayout->addWidget(emailGB);

    scrollArea = new QScrollArea(emailGB);
    emailGB->setMinimumHeight(height()-220);
    scrollArea->setStyleSheet("QScrollArea{margin-top:15px;margin-left:5 px; border: 0px}\
                              QScrollBar {background: lightgrey; width: 7px; border:0 px}\
                              QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {width:5 px; height: 5px}\
                              QScrollBar::handle:vertical {background: gray; min-width: 7px; min-height:25px}");
    scrollArea->setFixedHeight(height()-225);
    scrollArea->setFixedWidth(277);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollWidget = new QWidget(scrollArea);
    scrollWidget->setFixedWidth(270);
    scrollWidget->setStyleSheet("border:0px");
    scrollLayout1 = new QVBoxLayout(scrollWidget);
    scrollLayout1->setSpacing(spacing);
    scrollLayout1->setMargin(spacing);
    scrollArea->setWidget(scrollWidget);
}

void EmailEditWindow::clearAllContent(){
    //deleteeeeeeeeeeeeeeeeeeeee
}

void EmailEditWindow::onSaveAndExitEBClicked(){
    controllGroup->closeGroup();
}

void EmailEditWindow::onBackEBClicked(){
    controllGroup->closeGroup();
    StartHideAnim();
}

void EmailEditWindow::onAddEmailEBClicked(){
    controllGroup->closeGroup();
    addNewEmailWindow->setCurrentProfile(currentProfile);
    addNewEmailWindow->StartShowAnim(0, 0, 300, height());

}

void EmailEditWindow::onApproveEBClicked(){
    controllGroup->closeGroup();
}

void EmailEditWindow::onDeleteEBClicked(){
    controllGroup->closeGroup();
}

void EmailEditWindow::onEditEBClicked(){
    controllGroup->closeGroup();
}

void EmailEditWindow::animatedShow(){
    StartShowAnim(0, 0, 300, parentWidget()->height());
    //raise();
}

void EmailEditWindow::fillEmailsTable(){
    int count;
    QString name;
    count = currentProfile->getEmailCount();
    for (int i = 0; i < count; ++i) {
        name =currentProfile->getAccount(i)->GetLogin() ;
        addNewEmailAccount(name);
    }
}

void EmailEditWindow::setCurrentProfile(Profile *profile){
    currentProfile = profile;
    windowCaptionLabel->setText("Manage emails: "+currentProfile->getLogin());
}

void EmailEditWindow::setAddNewEmailWindow(AddNewEmailWindow *window){
    addNewEmailWindow = window;
}

void EmailEditWindow::addNewEmailAccount(const QString &name){
    int margin = 0;
    int spacing = 5;
    QCheckBox *emailSelectionCH;
    ExLabel *emailName;
    ExButton *delEmailExButton;
    QWidget *emailLineWidget;
    QHBoxLayout *emailLineLay;
    scrollWidget->setMinimumHeight(scrollWidget->height()+25);
    emailLineWidget = new QWidget();
    emailLineLay = new QHBoxLayout(emailLineWidget);
    emailLineLay->setSpacing(spacing);
    emailLineLay->setMargin(margin);

    emailSelectionCH = new QCheckBox;
    emailName = new ExLabel(name);
    emailName->setStyleSheet("QLabel {color: #436EEE;font-size: 12px;}");

    delEmailExButton = new ExButton(emailLineWidget, "Delete", 15, 0);
    delEmailExButton->setImage(":/resourses/icons/cancel_nb.png");
    delEmailExButton->setImageMargin(3);
    delEmailExButton->setToolTip("Delete this email.");
    delEmailExButton->setFixedSize(15, 15);
    delEmailExButton->setOnlyPicture(true);

    emailLineLay->addWidget(emailSelectionCH, 0);
    emailLineLay->addWidget(emailName, 1, Qt::AlignLeft);
    emailLineLay->addWidget(delEmailExButton, 1, Qt::AlignRight);
    emailLineLay->addSpacing(10);

    scrollLayout1->addWidget(emailLineWidget, 1);
}
