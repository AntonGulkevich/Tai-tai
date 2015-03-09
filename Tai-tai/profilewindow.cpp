#include "profilewindow.h"

ProfileWindow::ProfileWindow(QWidget *parent) :
    QFrame(parent)
{
    resize(0, parent->height());
    move(0, 0);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QFrame{background-color: white }");

    bigLay = new QBoxLayout(QBoxLayout::TopToBottom, this);
    topLay = new QBoxLayout(QBoxLayout::TopToBottom);
    botLay = new QBoxLayout(QBoxLayout::TopToBottom);

    bigLay->setMargin(0);
    bigLay->setSpacing(0);

    bigLay->addLayout(topLay, 1);
    bigLay->addLayout(botLay, 1);

    ExLabel *profileNameLabel = new ExLabel("DEFAULT PROFILE");
    ExLabel *profileAvaLabel = new ExLabel("AVA");

    QLineEdit * profilePasswordEdit = new QLineEdit("*******");

    profileAvaLabel->setStyleSheet("QLabel{border: 1px solid gray;}");

    profileNameLabel->setMaximumSize(200, 20);
    profilePasswordEdit->setFixedSize(200, 20);

    profileAvaLabel->setMaximumSize(200, 220);
    QPixmap avadef(":/resourses/icons/ava_def.jpg");
    profileAvaLabel->setPixmap(avadef);

   // profileAvaLabel->setMask(avadef.mask());

    topLay->addStretch(1);
    topLay->addWidget(profileNameLabel, 0, Qt::AlignHCenter);
    topLay->addWidget(profileAvaLabel, 1, Qt::AlignHCenter);
    topLay->addWidget(profilePasswordEdit, 0, Qt::AlignHCenter);
    topLay->addStretch(1);
    topLay->setSpacing(0);
    topLay->setMargin(10);

    botLay->addStretch(1);

    int margin =5;

    testExButton = new ExButton(this,  "Login", 50, 0);
    testExButton->move(800/4-100+50/2, 600/2+50/2+50);
    testExButton->setRotation(201);
    testExButton->setImage(":/resourses/icons/login_acc.png");
    testExButton->setImageMargin(margin);
    testExButton->setToolTip("Login in current account.");

    createExButton = new ExButton(this,  "Create", 50, 1);
    createExButton->setImage(":/resourses/icons/create_acc.png");
    createExButton->setImageMargin(margin);

    deleteExButton = new ExButton(this,  "Delete", 50, 1);
    deleteExButton->setImage(":/resourses/icons/delete_acc.png");
    deleteExButton->setImageMargin(margin);

    editExButton = new ExButton(this,  "Edit", 50, 1);
    editExButton->setImage(":/resourses/icons/edit_acc.png");
    editExButton->setImageMargin(margin);

    exitExButton = new ExButton(this,  "Logout", 50, 1);
    exitExButton->setImage(":/resourses/icons/logout_acc3.png");
    exitExButton->setImageMargin(margin);

    helpExButton = new ExButton(this,  "Info", 50, 1);
    helpExButton->setImage(":/resourses/icons/info_acc.png");
    helpExButton->setImageMargin(margin);

    groupEx = new GroupExButtons();

    groupEx->setDefaultButton(testExButton);
    groupEx->addButton(createExButton);
    groupEx->addButton(deleteExButton);
    groupEx->addButton(editExButton);
    groupEx->addButton(exitExButton);
    groupEx->addButton(helpExButton);

    hide();
}
ProfileWindow::~ProfileWindow(){

}
void ProfileWindow::StartShowAnim(int left, int top, int width, int height){
    show();
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, 0, height));
    animation->setEndValue(QRect(left, top, width-100, height));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void ProfileWindow::drawButton(){


}

void ProfileWindow::animatedHide(){
    StartHideAnim(0, 0, width(), height());
    emit hide_();
}

void ProfileWindow::StartHideAnim(int left, int top, int width, int height){

    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width-100, height));
    animation->setEndValue(QRect(left, top, 1, height));

    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect (animation, SIGNAL(finished()), this, SLOT(hide()));

}

