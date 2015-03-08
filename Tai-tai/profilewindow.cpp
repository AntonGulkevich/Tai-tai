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

    ExButton *testExButton = new ExButton(this,  "Profile", 50, 0);
    //testExButton->setWindowFlags(Qt::WindowStaysOnTopHint);

    testExButton->move(800/4-100+50/2, 600/2+50/2+50);
    testExButton->setRotation(201);
    testExButton->setImage(":/resourses/icons/more.png");
    testExButton->setImageMargin(10);
    testExButton->setToolTip("hello");

    ExButton *createExButton = new ExButton(this,  "Create", 50, 1);
    createExButton->setImage(":/resourses/icons/create_acc.png");
    createExButton->setImageMargin(10);

    ExButton *deleteExButton = new ExButton(this,  "Delete", 50, 1);
    deleteExButton->setImage(":/resourses/icons/delete_acc.png");
    deleteExButton->setImageMargin(10);

    ExButton *editExButton = new ExButton(this,  "Edit", 50, 1);
    editExButton->setImage(":/resourses/icons/ch_left.png");
    editExButton->setImageMargin(10);

    ExButton *exitExButton = new ExButton(this,  "Exit", 50, 1);
    exitExButton->setImage(":/resourses/icons/ch_right.png");
    exitExButton->setImageMargin(10);

    ExButton *helpExButton = new ExButton(this,  "Help", 50, 1);
    helpExButton->setImage(":/resourses/icons/down_def.png");
    helpExButton->setImageMargin(10);

    GroupExButtons* groupEx = new GroupExButtons();
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

