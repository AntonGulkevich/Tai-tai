#include "exbutton.h"

ExButton::ExButton(QWidget *parent, const QString &caption, int r, bool subButton) :
    QFrame(parent), Caption(caption)
{
    Maxed = true;
    AnimationLocked = false;
    Radius = r;
    SmallRadius = r/2;
    countLiteralsShortCaption=1;

    resize(Radius, Radius);

    initSS();

    mainLay = new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLay->setMargin(0);
    mainLay->setSpacing(0);
    this->setLayout(mainLay);

    captionExLabel=new QLabel(this);
    imageLabel = new QLabel(this);

    mainLay->addWidget(captionExLabel, 0, Qt::AlignCenter);
    mainLay->addWidget(imageLabel, 0, Qt::AlignCenter);

    captionExLabel->setStyleSheet("QLabel{border-width: 0px; color: black;}");
    captionExLabel->setAttribute(Qt::WA_TranslucentBackground);
    captionExLabel->setText(Caption);
    captionExLabel->setVisible(false);

    imageLabel->setStyleSheet("QLabel{border-width: 0px; color: black;}");
    imageLabel->setAttribute(Qt::WA_TranslucentBackground);
    imageLabel->setVisible(true);

    setMaximumSize(Radius,Radius);
    setMinimumSize(SmallRadius, SmallRadius);

    if (subButton){
        lower();
        hide();
    }
    rotation=0;
}
void ExButton::initSS(){
    /*vertical gradient windows button style*/
    /*
    backDef = "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray);";
    backHover = "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:2,stop:0 white, stop: 1 gray);";
    backPressed = "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1.3,stop:0 white, stop: 1 gray);";
    */

    setDefaultBackgroundColor("white");
    setHoverBackgroundColor("white");
    setPressedBackgroundColor("white");

    this->setStyleSheet(defaultSSBig);
}

void ExButton::setCountLiteralsShortCaption(int count){
    countLiteralsShortCaption= count;
}

int ExButton::getCountLiteralsShortCaption(){
    return countLiteralsShortCaption;;
}

void ExButton::swapButtonsGeometry(ExButton *target){
   QRect tempRect;
   tempRect=geometry();
   setGeometry(target->geometry());
   target->setGeometry(tempRect);

   bool tempSt;
   tempSt=Maxed;
   Maxed=target->Maxed;
   target->Maxed=tempSt;

   QString tempSS;
   tempSS=styleSheet();
   setStyleSheet(target->styleSheet());
   target->setStyleSheet(tempSS);
}

void ExButton::setDefaultSS(){
    if (Maxed)
        setStyleSheet(defaultSSBig);
    else
        setStyleSheet(defaultSSSmall);
}

ExButton::~ExButton(){
    if (imageLabel)
        delete imageLabel;
    if (captionExLabel)
        delete captionExLabel;
    if (mainLay)
        delete mainLay;
}
void ExButton::setCaption(const QString &caption){
    Caption =caption;
    captionExLabel->setText(Caption);
}

void ExButton::setFullCaption(){
    captionExLabel->setText(Caption);
}

void ExButton::setShortCaption(int count){
    captionExLabel->setText(Caption.left(count));
}

void ExButton::setImage(const QString &image){
    QPixmap im (image);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(im);
}
void ExButton::setRadius(int radius){
    Radius = radius;
}

void ExButton::setSmallRadius(int radius){
    SmallRadius=radius;
}
void ExButton::setRotation(int degree){
    rotation=degree;
}

void ExButton::setImageMargin(int margin){
    imageLabel->setMargin(margin);
}

QString ExButton::getCaption(){
    return Caption;
}

int ExButton::getRadius(){
    return Radius;
}

int ExButton::getSmallRadius(){
    return SmallRadius;
}

void ExButton::setImageVisible(bool state){
    imageLabel->setVisible(state);
}

void ExButton::setCaptionVisible(bool state){
    captionExLabel->setVisible(state);
}

int ExButton::getRotation(){
    return rotation;
}

bool ExButton::isMaximumSize(){
    return Maxed;
}

bool ExButton::IsAnimationBlocked(){
    return AnimationLocked;
}

void ExButton::setDefaultBackgroundColor(const QString &color){
    defaultBackGroudColor = "background-color:" +color+";";

    defaultSSBig="QWidget{border:  solid gray; border-width:1px ;border-radius: "
            +QString::number(Radius/2)+"px;" + defaultBackGroudColor +"}";
    defaultSSSmall="QWidget{border:  solid gray; border-width:1px ; border-radius: "
            +QString::number(SmallRadius/2)+"px;" + defaultBackGroudColor +"}";
}

void ExButton::setHoverBackgroundColor(const QString &color){
    hoverBackGroudColor = "background-color:" +color+";";

    hoverSS="QWidget{"+hoverBackGroudColor+"border-color: #6196c8; border-width:1px}";
}

void ExButton::setPressedBackgroundColor(const QString &color){
    pressedBackGroudColor = "background-color:" +color+";";

    pressedSSBig ="QWidget{border: solid; border-width:2px ; border-radius: "
            +QString::number(Radius/2)+"px;"+pressedBackGroudColor+"border-color: #6196c8}";
    pressedSSSmall ="QWidget{border: solid; border-width:2px ; border-radius: "
            +QString::number(SmallRadius/2)+"px;"+pressedBackGroudColor+"border-color: #6196c8}";
}

void ExButton::unBlockAnimation(){
    AnimationLocked=false;
}

void ExButton::minimizeAnimated(){
    if (IsAnimationBlocked()){
        qDebug()<<"locked";
        return;
    }
    int top;
    int left;
    int radOffset;

    radOffset = Radius/2-SmallRadius/2;
    Maxed=false;
    blockAnimation();
    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setEasingCurve(QEasingCurve::InCubic);

    top=this->geometry().top();
    left=this->geometry().left();

    animation->setStartValue(QRect(left,top,Radius, Radius ));
    animation->setEndValue(QRect(left+radOffset, top+radOffset, SmallRadius, SmallRadius));
    setShortCaption(countLiteralsShortCaption);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect(animation, SIGNAL(finished()), this, SLOT(unBlockAnimation()));

    setStyleSheet(defaultSSSmall+hoverSS);
}

void ExButton::maximizeAnimated(){
    if (IsAnimationBlocked()){
        qDebug()<<"locked";
        return;
    }
    int top;
    int left;
    int radOffset;

    radOffset = Radius/2-SmallRadius/2;
    Maxed=true;
    blockAnimation();
    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setEasingCurve(QEasingCurve::InCubic);

    top=this->geometry().top();
    left=this->geometry().left();

    animation->setStartValue(QRect(left,top,SmallRadius, SmallRadius ));
    animation->setEndValue(QRect(left-radOffset, top-radOffset, Radius, Radius));
    setFullCaption();

    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect(animation, SIGNAL(finished()), this, SLOT(unBlockAnimation()));

    connect(animation, SIGNAL(finished()), captionExLabel,  SLOT(hide()));
    connect(animation, SIGNAL(finished()), imageLabel,      SLOT(show()));

    setStyleSheet(defaultSSBig);


}

void ExButton::blockAnimation(){
    AnimationLocked=true;
}

void ExButton::mousePressEvent(QMouseEvent* pe ){
    if (isMaximumSize()){
        setStyleSheet(pressedSSBig);
    }
    else{
        setStyleSheet(pressedSSSmall);
    }
}
void ExButton::mouseReleaseEvent(QMouseEvent* pe){
    if (!IsAnimationBlocked()&&(pe->button()==Qt::RightButton)){
        emit rightClicked();
    }
    if (!IsAnimationBlocked()&&(pe->button()==Qt::LeftButton)){
        emit leftClicked();
    }
    if (isMaximumSize()){
        setStyleSheet(defaultSSBig+hoverSS);
    }
    else{
        setStyleSheet(defaultSSSmall+hoverSS);
    }
}
void ExButton::enterEvent(QEvent *event){
    emit mouseEntered();
    int r, left, top;
    left = imageLabel->geometry().left();
    top = imageLabel->geometry().top();
    if (isMaximumSize()){
        setStyleSheet(defaultSSBig+hoverSS);
        r=Radius;
        QPropertyAnimation *animation = new QPropertyAnimation(imageLabel, "geometry");
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(200);
        animation->setEndValue(QRect(left+r/2,top+r/2, 0, 0 ));
        animation->start(QPropertyAnimation::DeleteWhenStopped);

        connect(animation, SIGNAL(finished()), captionExLabel,  SLOT(show()));
        connect(animation, SIGNAL(finished()), imageLabel,      SLOT(hide()));
    }
    else{
        setStyleSheet(defaultSSSmall+hoverSS);
        r=SmallRadius;

    }
}
void ExButton::leaveEvent(QEvent *event){
    emit mouseLeaved();
    int r;
    if (isMaximumSize()){
        setStyleSheet(defaultSSBig);
        r=Radius;
        captionExLabel->setVisible(false);
        imageLabel->setVisible(true);

        QPropertyAnimation *animation = new QPropertyAnimation(imageLabel, "geometry");
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->setDuration(200);
        animation->setStartValue(QRect(r/2,r/2, 0, 0 ));
        animation->setEndValue(QRect(0,0, r, r ));
        animation->start(QPropertyAnimation::DeleteWhenStopped);
    }
    else{
        setStyleSheet(defaultSSSmall);
        r=SmallRadius;

    }
}
void ExButton::resizeEvent(QResizeEvent *event){

    /*background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray)*/
    /*
    setStyleSheet("border:1px solid gray; border-radius: " +QString::number(this->geometry().height()/2)+"px;\
                  background-color:white");
    */
}

