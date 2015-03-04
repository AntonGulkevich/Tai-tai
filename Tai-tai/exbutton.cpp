#include "exbutton.h"

ExButton::ExButton(QWidget *parent, const QString &caption, int r) :
    QFrame(parent), Caption(caption)
{
    isMaxed=true;
    Radius=r;
    SmallRadius=r/2;
    resize(Radius, Radius);

    /*vertical gradient windows button style*/
    defaultSSBig="QWidget{border: 1px solid gray; border-radius: " +QString::number(Radius/2)+"px;\
            background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray)}";
    pressedSSBig ="QWidget{border: 1px solid; border-radius: " +QString::number(Radius/2)+"px;\
        background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1.3,stop:0 white, stop: 1 gray);\
        border-color: #6196c8}";

    defaultSSSmall="QWidget{border: 1px solid gray; border-radius: " +QString::number(SmallRadius/2)+"px;\
        background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray)}";
    pressedSSSmall ="QWidget{border: 1px solid; border-radius: " +QString::number(SmallRadius/2)+"px;\
    background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:1.3,stop:0 white, stop: 1 gray);\
    border-color: #005aff}";

    hoverSS="QWidget{background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:2,stop:0 white, stop: 1 gray);\
            border-color: #6196c8}";


    this->setStyleSheet(defaultSSBig);

    mainLay = new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLay->setMargin(0);
    mainLay->setSpacing(0);
    this->setLayout(mainLay);
/*
    QPalette pal;
    pal.setColor(captionExLabel->foregroundRole(), QColor(0, 90, 255));
*/

    captionExLabel=new QLabel(Caption, this);
    captionExLabel->setStyleSheet("QLabel{border-width: 0px; color: black;}");
    captionExLabel->setAttribute(Qt::WA_TranslucentBackground);
   // captionExLabel->move(captionExLabel->geometry().left()+Radius,captionExLabel->geometry().top());
   // captionExLabel->setPalette(pal);
    mainLay->addWidget(captionExLabel, 0, Qt::AlignCenter);
    imageLabel = new QLabel("Image", parent);

    setMaximumSize(Radius,Radius);
    setMinimumSize(SmallRadius, SmallRadius);
    rotation=0;
}

ExButton::~ExButton(){
    if (imageLabel)
        delete imageLabel;
    if (captionExLabel)
        delete captionExLabel;
    if (mainLay)
        delete mainLay;
    subButtons.clear();
}
void ExButton::setCaption(const QString &caption){
    Caption =caption;
}
void ExButton::setRadius(int radius){
    Radius = radius;
}

void ExButton::setSmallRadius(int radius){
    SmallRadius=radius;
}

void ExButton::addSubbButton(const QString &caption)
{
    ExButton *subButton = new ExButton(this->parentWidget(), caption, Radius);
    subButton->setGeometry(this->geometry());
    subButton->setWindowFlags(Qt::WindowStaysOnBottomHint);
    subButton->lower();
    //connect(subButton, SIGNAL(clicked()), this, SLOT(OnClick()));
    subButtons.append(subButton);
}

void ExButton::open(int scale, int duration){
    int k;
    int buttonCount;
    double angleUnit;
    double koef;
    int rotationStep;
    int top;
    int left;


    k=scale;
    buttonCount= subButtons.count();
    scale = buttonCount*Radius/6.18*scale;
    angleUnit = 6.18/buttonCount;
    koef = 3.14*2/360;
    rotationStep=rotation/5;

    top=this->geometry().top();
    left=this->geometry().left();


    for (int i=0; i<buttonCount; i++){

        ExButton * btn = subButtons.at(i);
        btn->show();
        btn->Locked();
        btn->isMaxed=true;
        btn->captionExLabel->setText(btn->Caption);
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry", this);
        ani->setDuration(duration);
        ani->setEasingCurve(QEasingCurve::OutExpo);


        if(k==1){
            if (scale<Radius){
                scale=Radius;
            }

            ani->setKeyValueAt(0.2, QRect(cos(angleUnit*i+koef*rotationStep*1)*scale*0.2+left,
                                          sin(angleUnit*i+koef*rotationStep*1)*scale*0.2+top, Radius, Radius));
            ani->setKeyValueAt(0.4, QRect(cos(angleUnit*i+koef*rotationStep*2)*scale*0.4+left,
                                          sin(angleUnit*i+koef*rotationStep*2)*scale*0.4+top, Radius, Radius));
            ani->setKeyValueAt(0.6, QRect(cos(angleUnit*i+koef*rotationStep*3)*scale*0.6+left,
                                          sin(angleUnit*i+koef*rotationStep*3)*scale*0.6+top, Radius, Radius));
            ani->setKeyValueAt(0.8, QRect(cos(angleUnit*i+koef*rotationStep*4)*scale*0.8+left,
                                          sin(angleUnit*i+koef*rotationStep*4)*scale*0.8+top, Radius, Radius));
        }
        ani->setEndValue(QRectF(cos(angleUnit*i+koef*rotationStep*5)*scale+left,
                                sin(angleUnit*i+koef*rotationStep*5)*scale+top, Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(Unlocked()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }
}
void ExButton::close(int scale,int duration){
    int buttonCount= subButtons.count();
    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->Locked();
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry", this);
        ani->setDuration(duration);
        ani->setEasingCurve(QEasingCurve::InExpo);
        ani->setEndValue(QRectF(this->geometry().left()+scale/*+SmallRadius/2-Radius/2+scale*/,
                                this->geometry().top()+scale/*+SmallRadius/2-Radius/2+scale*/, Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(Unlocked()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void ExButton::setRotation(int degree)
{
    rotation=degree;
}

void ExButton::preview()
{
    int buttonCount= 3;
    int scale = 5;
    int duration =200;
    double angleUnit = 6.18/buttonCount;
    double koef = 3.14*2/360;

    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->Locked();
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry", this);
        ani->setDuration(duration);
        ani->setEasingCurve(QEasingCurve::OutExpo);
        ani->setEndValue(QRectF(cos(angleUnit*i+koef*rotation)*scale+this->geometry().left(),
                                sin(angleUnit*i+koef*rotation)*scale+this->geometry().top(), Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(Unlocked()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }

}

void ExButton::OnClick(){
    isMaxed=!isMaxed;
    Locked();
    QPropertyAnimation *animation;

    int radOffset;
    radOffset = Radius/2-SmallRadius/2;

    if(!isMaxed){
        open(1, 1000);

        animation = new QPropertyAnimation(this, "geometry", this);
        animation->setDuration(300);
        animation->setEasingCurve(QEasingCurve::InCubic);
        animation->setStartValue(QRect(this->geometry().left(),this->geometry().top(),Radius, Radius ));
        animation->setEndValue(QRect(this->geometry().left()+radOffset, this->geometry().top()+radOffset, SmallRadius, SmallRadius));
        connect(animation, SIGNAL(finished()), this, SLOT(Unlocked()));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
        captionExLabel->setText(Caption.at(0));
    }
    else{
        close(SmallRadius/2-Radius/2, 300);

        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(300);
        animation->setEasingCurve(QEasingCurve::InCubic);
        animation->setStartValue(QRect(this->geometry().left(),this->geometry().top(),SmallRadius, SmallRadius ));
        animation->setEndValue(QRect(this->geometry().left()-radOffset, this->geometry().top()-radOffset, Radius, Radius));

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
    QFrame::mousePressEvent(pe);
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
    QFrame::mouseReleaseEvent(pe);

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
        preview();
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
       close(0, 300);
    }
    QFrame::leaveEvent(event);
}
void ExButton::resizeEvent(QResizeEvent *event)
{

/*
    setStyleSheet("QWidget{border: 1px solid gray; border-radius: " +QString::number(this->geometry().height()/2)+"px;\
                  background: qqradialgradient(cx:0, cy:0, radius: 1,fx:1, fy:1, stop:0 white, stop:1 black) }");*/

    setStyleSheet("QWidget{border: 1px solid gray; border-radius: " +QString::number(this->geometry().height()/2)+"px;\
                  background: qlineargradient(x1:0.5, y1:0, x2:0.5, y2:4,stop:0 white, stop: 1 gray)}");

}

