#include "exbutton.h"

ExButton::ExButton(QWidget *parent, const QString &caption, int r) :
    QFrame(parent), Caption(caption)
{
    isMaxed=true;
    Radius=r;
    SmallRadius=r/3;
    resize(Radius, Radius);
    defaultSSBig="QWidget{border: 1px solid gray; border-radius: " +QString::number(Radius/2)+"px;\
            background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray)}";
    pressedSSBig ="QWidget{border: 1px solid; border-radius: " +QString::number(Radius/2)+"px;\
        background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1.3,stop:0 white, stop: 1 gray);\
        border-color: #6196c8}";

    defaultSSSmall="QWidget{border: 1px solid gray; border-radius: " +QString::number(SmallRadius/2)+"px;\
        background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray)}";
    pressedSSSmall ="QWidget{border: 1px solid; border-radius: " +QString::number(SmallRadius/2)+"px;\
    background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1.3,stop:0 white, stop: 1 gray);\
    border-color: #6196c8}";

    hoverSS="QWidget{background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:2,stop:0 white, stop: 1 gray);\
            border-color: #6196c8}";

    this->setStyleSheet(defaultSSBig);

    QBoxLayout *mainLay = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLay->setMargin(0);
    mainLay->setSpacing(0);
    this->setLayout(mainLay);
    captionExLabel=new QLabel(Caption);
    captionExLabel->setStyleSheet("QLabel{border-width: 0px;}");
    captionExLabel->setAttribute(Qt::WA_TranslucentBackground);
    mainLay->addWidget(captionExLabel, 0, Qt::AlignCenter);
    setMaximumSize(Radius,Radius);
    setMinimumSize(SmallRadius, SmallRadius);
   // setSizePolicy(QSizePolicy::Expanding);

}

ExButton::~ExButton(){

}
void ExButton::setCaption(const QString &caption){
    Caption =caption;
}
void ExButton::setRadius(int radius){
    Radius = radius;
}

void ExButton::setSmallRadius(int radius)
{
    SmallRadius=radius;
}

void ExButton::addSubbButton(const QString &caption)
{
    ExButton *subButton = new ExButton(this->parentWidget() , caption, Radius);
    subButton->setGeometry(this->geometry());
    subButton->setWindowFlags(Qt::WindowStaysOnBottomHint);
    subButton->lower();
    //connect(subButton, SIGNAL(clicked()), this, SLOT(OnClick()));
    subButtons.append(subButton);
}

void ExButton::open(int scale){
    int buttonCount= subButtons.count();
    double angleUnit = 6.18/buttonCount;
    double koef = 3.14*2/360;
    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->Locked();
        btn->isMaxed=true;
        btn->captionExLabel->setText(btn->Caption);
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry");
        ani->setDuration(1000);
        ani->setEasingCurve(QEasingCurve::OutExpo);
        if(scale>20){
            ani->setKeyValueAt(0.2, QRect(cos(angleUnit*i+koef*40)*scale*0.2+this->geometry().left(),
                                          sin(angleUnit*i+koef*40)*scale*0.2+this->geometry().top(), Radius, Radius));
            ani->setKeyValueAt(0.4, QRect(cos(angleUnit*i+koef*80)*scale*0.4+this->geometry().left(),
                                          sin(angleUnit*i+koef*80)*scale*0.4+this->geometry().top(), Radius, Radius));
            ani->setKeyValueAt(0.6, QRect(cos(angleUnit*i+koef*120)*scale*0.6+this->geometry().left(),
                                          sin(angleUnit*i+koef*120)*scale*0.6+this->geometry().top(), Radius, Radius));
            ani->setKeyValueAt(0.8, QRect(cos(angleUnit*i+koef*160)*scale*0.8+this->geometry().left(),
                                          sin(angleUnit*i+koef*160)*scale*0.8+this->geometry().top(), Radius, Radius));
        }
        ani->setEndValue(QRectF(cos(angleUnit*i+koef*201)*scale+this->geometry().left(),
                                sin(angleUnit*i+koef*201)*scale+this->geometry().top(), Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(Unlocked()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }
}
void ExButton::close(int scale){
    int buttonCount= subButtons.count();
    for (int i=0; i<buttonCount; i++){

        ExButton * btn = subButtons.at(i);
        btn->Locked();
       // btn->setWindowFlags(Qt::WindowStaysOnBottomHint);
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry");
        ani->setDuration(300);
        ani->setEasingCurve(QEasingCurve::InExpo);
        ani->setEndValue(QRectF(this->geometry().left()-SmallRadius+scale,
                                this->geometry().top()-SmallRadius+scale, Radius, Radius));
        //connect(ani, SIGNAL(finished()), btn, SLOT(hide()));
        connect(ani, SIGNAL(finished()), btn, SLOT(Unlocked()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void ExButton::OnClick(){
    isMaxed=!isMaxed;
    Locked();
    QPropertyAnimation *animation;
    if(!isMaxed){
        open(Radius);

        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(300);
        animation->setEasingCurve(QEasingCurve::InCubic);
        animation->setStartValue(QRect(this->geometry().left(),this->geometry().top(),Radius, Radius ));
        animation->setEndValue(QRect(this->geometry().left()+SmallRadius, this->geometry().top()+SmallRadius, SmallRadius, SmallRadius));
        connect(animation, SIGNAL(finished()), this, SLOT(Unlocked()));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
        captionExLabel->setText(Caption.at(0));
    }
    else{
        close(0);

        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(300);
        animation->setEasingCurve(QEasingCurve::InCubic);
        animation->setStartValue(QRect(this->geometry().left(),this->geometry().top(),SmallRadius, SmallRadius ));
        animation->setEndValue(QRect(this->geometry().left()-SmallRadius, this->geometry().top()-SmallRadius, Radius, Radius));

        animation->start(QAbstractAnimation::DeleteWhenStopped);
        connect(animation, SIGNAL(finished()), this, SLOT(Unlocked()));
        captionExLabel->setText(Caption);
    }
    emit clicked();
}

void ExButton::Locked()
{
    isLocked=true;
}

void ExButton::Unlocked()
{
    isLocked=false;
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
    if (isMaxed){
        setStyleSheet(defaultSSBig);
    }
    else{
        setStyleSheet(defaultSSSmall);
    }
    if (!isLocked)
        OnClick();

}
void ExButton::enterEvent(QEvent *event){
    if (isMaxed){
        setStyleSheet(defaultSSBig+hoverSS);
    }
    else{
        setStyleSheet(defaultSSSmall+hoverSS);
    }
    int buttonCount = subButtons.count();
    if (buttonCount&&isMaxed&&!isLocked){
       open(5);
    }
    QFrame::enterEvent(event);
}
void ExButton::leaveEvent(QEvent *event){
    if (isMaxed){
        setStyleSheet(defaultSSBig);
    }
    else{
        setStyleSheet(defaultSSSmall);
    }
    int buttonCount = subButtons.count();
    if (buttonCount>0&&isMaxed&&!isLocked){
       close(SmallRadius);
    }
    QFrame::leaveEvent(event);
}
void ExButton::resizeEvent(QResizeEvent *event)
{
    setStyleSheet("QWidget{border: 1px solid gray; border-radius: " +QString::number(this->geometry().height()/2)+"px;\
                  background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray)}");

}


