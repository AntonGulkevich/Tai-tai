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

    ExLabel *profileNameLabel = new ExLabel("default");
    ExLabel *profileAvaLabel = new ExLabel("AVA");
    ExLabel *profilePasswordLabel = new ExLabel("password");


    profileAvaLabel->setStyleSheet("QLabel{border: 1px solid gray; padding: 1px}");

    profileNameLabel->setMaximumSize(220, 20);
    profilePasswordLabel->setMaximumSize(220, 20);

    profileAvaLabel->setMaximumSize(200, 220);
    QPixmap avadef(":/resourses/icons/ava_def.jpg");
    profileAvaLabel->setPixmap(avadef);

   // profileAvaLabel->setMask(avadef.mask());

    topLay->addStretch(1);
    topLay->addWidget(profileNameLabel, 0, Qt::AlignHCenter);
    topLay->addWidget(profileAvaLabel, 1, Qt::AlignHCenter);
    topLay->addWidget(profilePasswordLabel, 0, Qt::AlignHCenter);
    topLay->addStretch(1);
    topLay->setSpacing(10);
    topLay->setMargin(10);

    botLay->addStretch(1);

    QString profileName = "Profile";
    ExButton *testExButton = new ExButton(this,  profileName, 50);
    //testExButton->setWindowFlags(Qt::WindowStaysOnTopHint);

    testExButton->move(800/4-100+50/2, 600/2+50/2+50);
    testExButton->setRotation(201);

    testExButton->addSubbButton("Create");
    testExButton->addSubbButton("Delete");
    testExButton->addSubbButton("Edit");
    testExButton->addSubbButton("Exit");
    testExButton->addSubbButton("Help");

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
void ProfileWindow::StartHideAnim(int left, int top, int width, int height){

    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width-100, height));
    animation->setEndValue(QRect(left, top, 1, height));

    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

