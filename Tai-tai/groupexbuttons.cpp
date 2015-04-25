#include "groupexbuttons.h"

GroupExButtons::GroupExButtons(){
    defaultButton=NULL;
}

GroupExButtons::~GroupExButtons(){
    subButtons.clear();
}

void GroupExButtons::addButton(ExButton *button){
    if (defaultButton==NULL){
        defaultButton = button;
        connect(defaultButton, SIGNAL(rightClicked()), this , SLOT(startAnimation()));
        connect(defaultButton, SIGNAL(mouseEntered()), this, SLOT(onMouseEnter()));
        connect(defaultButton, SIGNAL(mouseLeaved()), this, SLOT(onMouseLeave()));
    }
    else{
        button->hide();
        button->lower();
        button->move(defaultButton->geometry().left(), defaultButton->geometry().top() );
        subButtons.append(button);
    }
}

bool GroupExButtons::delButton(const QString &caption){
    int count = subButtons.count();
    for(int i =0;i<count;++i){
        if(subButtons.at(i)->getCaption()==caption){
            subButtons.removeAt(i);
            return true;
        }
    }
    return false;
}

void GroupExButtons::setDefaultButton(const QString & caption){
    if (defaultButton->getCaption()==caption){
        return;
    }
    ExButton * tempButton = takeAt(caption);

    if (tempButton==NULL){
        return;
    }

    if (defaultButton!=NULL){
        disconnect(defaultButton, SIGNAL(rightClicked()), this , SLOT(startAnimation()));
        disconnect(defaultButton, SIGNAL(mouseEntered()), this, SLOT(onMouseEnter()));
        disconnect(defaultButton, SIGNAL(mouseLeaved()), this, SLOT(onMouseLeave()));
        tempButton->setRotation(defaultButton->getRotation());
        defaultButton->swapButtonsGeometry(tempButton);
        addButton(defaultButton);
    }
    defaultButton = tempButton;
    defaultButton->raise();
    defaultButton->show();
    connect(defaultButton, SIGNAL(rightClicked()), this , SLOT(startAnimation()));
    connect(defaultButton, SIGNAL(mouseEntered()), this, SLOT(onMouseEnter()));
    connect(defaultButton, SIGNAL(mouseLeaved()), this, SLOT(onMouseLeave()));
}

void GroupExButtons::showAnimated(int scale, int duration){
    int buttonCount;
    double angleUnit;
    double koef;
    int top;
    int left;
    int k;

    int Radius;

    k=scale;
    Radius=defaultButton->getRadius();

    top=defaultButton->geometry().top();
    left=defaultButton->geometry().left();

    buttonCount= subButtons.count();
    scale = buttonCount*Radius/6.18*scale;
    angleUnit = 6.18/buttonCount;
    koef = 3.14*2/360*(defaultButton->getRotation())/5;


    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->show();
        btn->blockAnimation();
        btn->setFullCaption();
        btn->setImageVisible(true);
        btn->setCaptionVisible(false);
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
        connect(ani, SIGNAL(finished()), btn, SLOT(unBlockAnimation()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }

    emit showAnimatedFinished();
}

void GroupExButtons::hideAnimated(int scale, int duration){

    int buttonCount;
    int Radius;
    int top;
    int left;

    Radius=defaultButton->getRadius();

    top=defaultButton->geometry().top();
    left=defaultButton->geometry().left();

    buttonCount=subButtons.count();

    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->blockAnimation();
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry", this);
        ani->setDuration(duration);
        ani->setEasingCurve(QEasingCurve::InExpo);
        ani->setEndValue(QRectF(left+scale,top+scale, Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(unBlockAnimation()));
        connect(ani, SIGNAL(finished()), btn, SLOT(hide()));
        connect(ani, SIGNAL(finished()), btn, SLOT(setDefaultSS()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }

    emit hideAnimatedFinished();
}

void GroupExButtons::preview(int scale/*5*/, int duration/*200*/)
{
    int buttonCount;
    int top;
    int left;
    int Radius;

    if (subButtons.count()>=3){
        buttonCount=3;
    }
    else{
        buttonCount=subButtons.count();
    }

    double angleUnit = 6.18/buttonCount;
    double koef = 3.14*2/360*defaultButton->getRotation();

    Radius=defaultButton->getRadius();
    top=defaultButton->geometry().top();
    left=defaultButton->geometry().left();


    for (int i=0; i<buttonCount; i++){
        ExButton * btn = subButtons.at(i);
        btn->blockAnimation();
        btn->show();
        btn->setImageVisible(false);
        QPropertyAnimation * ani = new QPropertyAnimation(btn, "geometry", this);
        ani->setDuration(duration);
        ani->setEasingCurve(QEasingCurve::OutExpo);
        ani->setEndValue(QRectF(cos(angleUnit*i+koef)*scale+left,
                                sin(angleUnit*i+koef)*scale+top, Radius, Radius));
        connect(ani, SIGNAL(finished()), btn, SLOT(unBlockAnimation()));
        ani->start(QAbstractAnimation::DeleteWhenStopped);
    }
    emit prewiewFinished();
}

ExButton *GroupExButtons::getSubButton(const QString &caption){
    int count = subButtons.count();
    for(int i =0;i<count;++i){
        if(subButtons.at(i)->getCaption()==caption){
            return subButtons.at(i);
        }
    }
    return NULL;
}

ExButton *GroupExButtons::takeAt(int pos){
    return subButtons.takeAt(pos);
}

ExButton *GroupExButtons::takeAt(const QString &caption){
    int count = subButtons.count();
    for(int i =0;i<count;++i){
        if(subButtons.at(i)->getCaption()==caption){

            return subButtons.takeAt(i);
        }
    }
    return NULL;
}

bool GroupExButtons::isDefaultButton(ExButton *button){
    if (button->getCaption()==defaultButton->getCaption())
        return true;
    else
        return false;
}

void GroupExButtons::startAnimation(){
    int radOffset;

    radOffset = defaultButton->getRadius()/2-defaultButton->getSmallRadius()/2;

    if (defaultButton->isMaximumSize()){
        defaultButton->minimizeAnimated();
        showAnimated(1, 500);
    }
    else{

        defaultButton->maximizeAnimated();
        hideAnimated(-radOffset, 300);
    }
}

void GroupExButtons::onMouseEnter(){
    if (defaultButton->isMaximumSize()&&!defaultButton->IsAnimationBlocked()){
        preview(5, 200);
    }
}

void GroupExButtons::onMouseLeave(){
    if (defaultButton->isMaximumSize()&&!defaultButton->IsAnimationBlocked())
        hideAnimated(0, 300);

}

