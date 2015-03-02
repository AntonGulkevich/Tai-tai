#include "profilewindow.h"

ProfileWindow::ProfileWindow(QWidget *parent) :
    QFrame(parent)
{
    resize(0, parent->height());
    move(0, 0);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("QFrame{background-color: white }");

    QBoxLayout * bigLay = new QBoxLayout(QBoxLayout::TopToBottom, this);
    QBoxLayout * topLay = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout * botLay = new QBoxLayout(QBoxLayout::TopToBottom);

    bigLay->setMargin(0);
    bigLay->setSpacing(0);

    bigLay->addLayout(topLay, 1);
    bigLay->addLayout(botLay, 1);

    ExLabel *profileNameLabel = new ExLabel("default");
    QLabel *profileAvaLabel = new QLabel("AVA");
    ExLabel *profilePasswordLabel = new ExLabel("password");


    profileAvaLabel->setStyleSheet("QLabel{border: 1px solid gray; padding: 2px}");

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


    QLabel *test = new QLabel("test", this);
    botLay->addWidget(test, 1);

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
void ProfileWindow::StartHideAnim(int left, int top, int width, int height){

    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(left, top, width-100, height));
    animation->setEndValue(QRect(left, top, 1, height));

    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

