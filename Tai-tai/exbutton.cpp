#include "exbutton.h"

ExButton::ExButton(QWidget *parent, const QString &caption, int r, bool subButton) :
    QFrame(parent), Caption(caption)
{
    isMaxed=true;
    Radius=r;
    SmallRadius=r/2;
    resize(Radius, Radius);
    QString backDef, backHover, backPressed;
    /*vertical gradient windows button style*/
    /*
    backDef = "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray);";
    backHover = "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:2,stop:0 white, stop: 1 gray);";
    backPressed = "background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1.3,stop:0 white, stop: 1 gray);";
    */
    backDef ="background-color:white; ";
    backHover ="background-color:white; ";
    backPressed ="background-color:white; ";

    defaultSSBig="QWidget{border: 0px solid gray; border-radius: "
            +QString::number(Radius/2)+"px;" + backDef +"}";
    pressedSSBig ="QWidget{border: 1px solid; border-radius: "
            +QString::number(Radius/2)+"px;"+backPressed+"border-color: #6196c8}";
    defaultSSSmall="QWidget{border: 0px solid gray; border-radius: "
            +QString::number(SmallRadius/2)+"px;" + backDef +"}";
    pressedSSSmall ="QWidget{border: 1px solid; border-radius: "
            +QString::number(SmallRadius/2)+"px;"+backPressed+"border-color: #6196c8}";

    hoverSS="QWidget{"+backHover+"border-color: #6196c8}";


    this->setStyleSheet(defaultSSBig);

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

    isLocked=false;

    if (subButton){
        lower();
        hide();
    }
    rotation=0;
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

void ExButton::setShortCaption(){
    captionExLabel->setText(Caption.at(0));
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
void ExButton::setRotation(int degree)
{
    rotation=degree;
}

void ExButton::setImageMargin(int margin){
    imageLabel->setMargin(margin);
}

QString ExButton::getCaption()
{
    return Caption;
}

int ExButton::getRadius()
{
    return Radius;
}

int ExButton::getSmallRadius()
{
    return SmallRadius;
}

void ExButton::setImageVisible(bool state)
{
    imageLabel->setVisible(state);
}

void ExButton::setCaptionVisible(bool state)
{
    captionExLabel->setVisible(state);
}

int ExButton::getRotation()
{
    return rotation;
}

void ExButton::setIsMaxed(bool state)
{
    isMaxed = state;
}

bool ExButton::isMaximum(){
    return isMaxed;
}

bool ExButton::IsLocked(){
    return isLocked;
}

void ExButton::OnClick(){
    if (isLocked){
        qDebug()<<"locked";
        return;
    }
    int top;
    int left;
    int radOffset;

    radOffset = Radius/2-SmallRadius/2;
    isMaxed=!isMaxed;
    Locked();
    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(300);
    animation->setEasingCurve(QEasingCurve::InCubic);

    top=this->geometry().top();
    left=this->geometry().left();

    if(!isMaxed){
        animation->setStartValue(QRect(left,top,Radius, Radius ));
        animation->setEndValue(QRect(left+radOffset, top+radOffset, SmallRadius, SmallRadius));
        setShortCaption();
    }
    else{
        animation->setStartValue(QRect(left,top,SmallRadius, SmallRadius ));
        animation->setEndValue(QRect(left-radOffset, top-radOffset, Radius, Radius));
        setFullCaption();
    }
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    connect(animation, SIGNAL(finished()), this, SLOT(Unlocked()));

    if (isMaxed){
        setStyleSheet(defaultSSBig+hoverSS+"QWidget{border-width:1px;}");
    }
    else{
        setStyleSheet(defaultSSSmall+hoverSS+"QWidget{border-width:1px;}");
    }
}

void ExButton::Locked(){
    isLocked=true;
}

void ExButton::Unlocked(){
    isLocked=false;
}

void ExButton::Redraw(QVariant var)
{
    //setStyleSheet("border-radius: " +QString::number(this->geometry().height()/2)+"px;");
}
void ExButton::mousePressEvent(QMouseEvent* pe ){
    if (isMaxed){
        setStyleSheet(pressedSSBig);
    }
    else{
        setStyleSheet(pressedSSSmall);
    }
}
void ExButton::mouseReleaseEvent(QMouseEvent* pe){
    if (!isLocked&&(pe->button()==Qt::RightButton)){
        emit rightClicked();
    }
    if (!isLocked&&(pe->button()==Qt::LeftButton)){
        emit leftClicked();
    }
    OnClick();
}
void ExButton::enterEvent(QEvent *event){
    emit mouseEntered();
    int r, left, top;
    left = imageLabel->geometry().left();
    top = imageLabel->geometry().top();
    if (isMaxed){
        setStyleSheet(defaultSSBig+hoverSS+"QWidget{border-width:1px;}");
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
        setStyleSheet(defaultSSSmall+hoverSS+"QWidget{border-width:1px;}");
        r=SmallRadius;

    }
}
void ExButton::leaveEvent(QEvent *event){
    emit mouseLeaved();
    int r;
    if (isMaxed){
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
    setStyleSheet("border:1px solid gray; border-radius: " +QString::number(this->geometry().height()/2)+"px;\
                  background-color:white");

}

void ExButton::moveEvent(QMoveEvent *event){
    /*
    int ofs;
    ofs=geometry().width();
    imageLabel->move(event->pos().x()+ofs, event->pos().y()+ofs/2-imageLabel->height()/2);
    */
}

