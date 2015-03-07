#include "exbutton.h"

ExButton::ExButton(QWidget *parent, const QString &caption, int r) :
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
    captionExLabel->setText(Caption);
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

void ExButton::addSubbButton(const QString &caption, const QString &imageWay, int margin)
{
    ExButton *subButton = new ExButton(this->parentWidget(), caption, Radius);
    subButton->setGeometry(this->geometry());
    subButton->setWindowFlags(Qt::WindowStaysOnBottomHint);
    subButton->lower();
    subButton->hide();
    subButton->imageLabel->setMargin(margin);
    subButton->setImage(imageWay);
    //connect(subButton, SIGNAL(clicked()), this, SLOT(OnClick()));
    subButtons.append(subButton);
}

void ExButton::open(int scale, int duration){
    int k;
    int buttonCount;
    double angleUnit;
    double koef;
    int top;
    int left;


    k=scale;
    buttonCount= subButtons.count();
    scale = buttonCount*Radius/6.18*scale;
    angleUnit = 6.18/buttonCount;
    koef = 3.14*2/360*rotation/5;

    top=this->geometry().top();
    left=this->geometry().left();


    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->show();
        btn->Locked();
        btn->isMaxed=true;
        btn->captionExLabel->setText(btn->Caption);
        btn->imageLabel->setVisible(true);
        btn->captionExLabel->setVisible(false);
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry", this);
        ani->setDuration(duration);
        ani->setEasingCurve(QEasingCurve::OutExpo);
        if(k==1){
            if (scale<Radius){
                scale=Radius;
            }

            ani->setKeyValueAt(0.2, QRect(cos(angleUnit*i+koef*1)*scale*0.2+left,
                                          sin(angleUnit*i+koef*1)*scale*0.2+top, Radius, Radius));
            ani->setKeyValueAt(0.4, QRect(cos(angleUnit*i+koef*2)*scale*0.4+left,
                                          sin(angleUnit*i+koef*2)*scale*0.4+top, Radius, Radius));
            ani->setKeyValueAt(0.6, QRect(cos(angleUnit*i+koef*3)*scale*0.6+left,
                                          sin(angleUnit*i+koef*3)*scale*0.6+top, Radius, Radius));
            ani->setKeyValueAt(0.8, QRect(cos(angleUnit*i+koef*4)*scale*0.8+left,
                                          sin(angleUnit*i+koef*4)*scale*0.8+top, Radius, Radius));
        }
        ani->setEndValue(QRectF(cos(angleUnit*i+koef*5)*scale+left,
                                sin(angleUnit*i+koef*5)*scale+top, Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(Unlocked()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }
}
void ExButton::close(int scale,int duration){
    int buttonCount= subButtons.count();
    int top;
    int left;

    top=this->geometry().top();
    left=this->geometry().left();
    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->Locked();
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry", this);
        ani->setDuration(duration);
        ani->setEasingCurve(QEasingCurve::InExpo);
        ani->setEndValue(QRectF(left+scale,top+scale, Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(Unlocked()));
        connect(ani, SIGNAL(finished()), btn, SLOT(hide()));
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
    int top;
    int left;

    double angleUnit = 6.18/buttonCount;
    double koef = 3.14*2/360*rotation;
    top=this->geometry().top();
    left=this->geometry().left();


    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->Locked();
        btn->show();
        btn->imageLabel->setVisible(false);
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry", this);
        ani->setDuration(duration);
        ani->setEasingCurve(QEasingCurve::OutExpo);
        ani->setEndValue(QRectF(cos(angleUnit*i+koef)*scale+left,
                                sin(angleUnit*i+koef)*scale+top, Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(Unlocked()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void ExButton::setImageMargin(int margin){
    imageLabel->setMargin(margin);
}

ExButton *ExButton::getSubButton(int number)
{
    int buttonCount= subButtons.count();
    if (buttonCount<number){
        return NULL;
    }
    else
        return subButtons.at(number);
}

void ExButton::OnClick(){

    emit clicked();
}

void ExButton::onRightClicked(){
    int top;
    int left;
    int radOffset;

    radOffset = Radius/2-SmallRadius/2;
    isMaxed=!isMaxed;
    Locked();
    QPropertyAnimation *animation;

    top=this->geometry().top();
    left=this->geometry().left();

    if(!isMaxed){
        open(1, 500);

        animation = new QPropertyAnimation(this, "geometry", this);
        animation->setDuration(300);
        animation->setEasingCurve(QEasingCurve::InCubic);
        animation->setStartValue(QRect(left,top,Radius, Radius ));
        animation->setEndValue(QRect(left+radOffset, top+radOffset, SmallRadius, SmallRadius));
        animation->start(QAbstractAnimation::DeleteWhenStopped);

        connect(animation, SIGNAL(finished()), this, SLOT(Unlocked()));
        captionExLabel->setText(Caption.at(0));
    }
    else{
        close(-radOffset, 300);

        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(300);
        animation->setEasingCurve(QEasingCurve::InCubic);
        animation->setStartValue(QRect(left,top,SmallRadius, SmallRadius ));
        animation->setEndValue(QRect(left-radOffset, top-radOffset, Radius, Radius));
        animation->start(QAbstractAnimation::DeleteWhenStopped);

        connect(animation, SIGNAL(finished()), this, SLOT(Unlocked()));
        captionExLabel->setText(Caption);
    }
    if (isMaxed){
        setStyleSheet(defaultSSBig+hoverSS+"QWidget{border-width:1px;}");
    }
    else{
        setStyleSheet(defaultSSSmall+hoverSS+"QWidget{border-width:1px;}");
    }
    emit rightClicked();
}

void ExButton::Locked()
{
    isLocked=true;
}

void ExButton::Unlocked()
{
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
        onRightClicked();
   }
   else{
       if (!isLocked)
            OnClick();
   }
}
void ExButton::enterEvent(QEvent *event){
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
    int buttonCount = subButtons.count();

    if (buttonCount&&isMaxed&&!isLocked)
        preview();
}
void ExButton::leaveEvent(QEvent *event){
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
    int buttonCount = subButtons.count();
    if (buttonCount>0&&isMaxed&&!isLocked){
       close(0, 300);
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

