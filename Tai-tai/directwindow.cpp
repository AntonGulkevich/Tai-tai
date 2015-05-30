#include "directwindow.h"

DirectWindow::DirectWindow(QWidget *parent) :
    QFrame(parent)
{
    resize(220, 270);
    setFixedSize(220, 270);
    move(0, 0);

    setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    setWindowFlags(Qt::Popup);
    setStyleSheet("QWidget{background: rgb(250, 250, 250); border: 1px solid lightgray;}");
    setWindowOpacity(0.0);
    /*Layouts*/
    initLayouts();

}

void DirectWindow::setProfileCaption(const QString &text){
    profileCaptionEL->setText(text);
}

void DirectWindow::addEmail(const QString &text){
    emailBox->addItem(text);
}

void DirectWindow::setComboBoxSS(const QString &text){
    emailBox->setStyleSheet(text);
}

void DirectWindow::setProfileAva(const QString &text){
    QPixmap ava(text);
    profileAvaEL->setPixmap(ava);
}

void DirectWindow::initLayouts(){
    int margin =0;
    int spacing =0;
    int spacingEl= 10;
    int captionFontSize = 14;
    int buttonFonstSize =11;
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(margin);
    mainLayout->setSpacing(spacing);

    QString actSS, inActSS, inActButtonSS, actButtonSS;
    actSS="QLabel{ border: 1px solid gray;  background-color: lightgray;}";
    inActSS ="QLabel{ border: 1px solid lightgray; background-color: white;}";
    inActButtonSS ="QLabel{ border: 0px; border-top: 1px solid lightgray; background-color: rgb(250, 250, 250);}";
    actButtonSS="QLabel{ border: 0px; border-top: 1px solid lightgray; background-color: lightgray;}";
    QString captionSS;
    captionSS="QLabel{border: 0px;}";

    QString buttonSS;
    buttonSS ="QLabel{border: 0px; border-top: 1px solid lightgray;}";

    profileAvaEL = new ExLabel("AVA");
    profileAvaEL->setMaximumSize(100, 110);
    QPixmap avadef(":/resourses/icons/ava_def.jpg");
    profileAvaEL->setPixmap(avadef);
    profileAvaEL->setStyleSheet(inActSS);
    profileAvaEL->setActiveStyleSheet(actSS);
    profileAvaEL->setInActiveStyleSheet(inActSS);
    profileAvaEL->setScaledContents(true);

    profileCaptionEL = new ExLabel ("Profile name");
    profileCaptionEL->setStyleSheet(captionSS);
    profileCaptionEL->setFonts(captionFontSize, captionFontSize, captionFontSize);

    /*
    emailCapionEL = new ExLabel("email@host.dom");
    emailCapionEL->setStyleSheet(captionSS);
    emailCapionEL->setFonts(captionFontSize, captionFontSize, captionFontSize);
    */
    emailBox = new QComboBox(this);

    changeProfileEL = new ExLabel("Change profile");
    changeProfileEL->setStyleSheet(buttonSS);
    changeProfileEL->setFonts(buttonFonstSize, buttonFonstSize, buttonFonstSize);
    changeProfileEL->setActiveStyleSheet(actButtonSS);
    changeProfileEL->setInActiveStyleSheet(inActButtonSS);

    editProfileLE= new ExLabel("Edit profile");
    editProfileLE->setStyleSheet(buttonSS);
    editProfileLE->setFonts(buttonFonstSize, buttonFonstSize, buttonFonstSize);
    editProfileLE->setActiveStyleSheet(actButtonSS);
    editProfileLE->setInActiveStyleSheet(inActButtonSS);

    mainLayout->addSpacing(2*spacingEl);
    mainLayout->addWidget(profileAvaEL, 0, Qt::AlignHCenter);
    mainLayout->addSpacing(spacingEl);
    mainLayout->addWidget(profileCaptionEL, 0,Qt::AlignHCenter);
    mainLayout->addSpacing(spacingEl);
    mainLayout->addWidget(emailBox, 0, Qt::AlignHCenter);
    mainLayout->addSpacing(2*spacingEl);
    mainLayout->addWidget(editProfileLE, 1);
    mainLayout->addWidget(changeProfileEL, 1);

    connect(profileAvaEL, SIGNAL(clicked()), this, SLOT(onProfileAvaClicked()));
    connect(profileCaptionEL, SIGNAL(clicked()), this, SLOT(onProfileCaptionClicked()));
    connect(emailBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onEmailChanged(int)));
    connect(changeProfileEL, SIGNAL(clicked()), this, SLOT(onChangeProfileELClicked()));
    connect(editProfileLE, SIGNAL(clicked()), this, SLOT(onEditProfileLEClicked()));


}

void DirectWindow::animatedShow(const QPoint &globalPos){
    raise();
    setVisible(true);
    this->move(globalPos);
    animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(200);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    emit showA();
}

void DirectWindow::animatedHide(){
    animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(100);
    animation->setStartValue(1.0);
    animation->setEndValue(0.0);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect(animation, SIGNAL(finished()), this, SLOT(hide()));
    emit hideA();
}

void DirectWindow::onProfileAvaClicked(){
    emit profileAvaClicked();
}

void DirectWindow::onProfileCaptionClicked(){
    emit profileCaptionClicked();
}

void DirectWindow::onEmailChanged(int index){
    if (emailBox->count()){
        qDebug()<<index;
        emit emailIndexChanged(index);
        animatedHide();
    }
}

void DirectWindow::onChangeProfileELClicked(){
    emit changeProfileELClicked();
    animatedHide();
}

void DirectWindow::onEditProfileLEClicked(){
    emit editProfileELClicked();
    animatedHide();
}

void DirectWindow::setDefaults(){
    emailBox->clear();
}
