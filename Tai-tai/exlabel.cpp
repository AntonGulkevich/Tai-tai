#include "exlabel.h"

ExLabel::ExLabel(const QString &text, QWidget *parent) :
    QLabel(text, parent)
{
    selectedFont= new QFont();
    unselectedFont = new QFont();
    activeFont= new QFont();

    unselectedFont->setPixelSize(12);
    unselectedFont->setBold(false);
    unselectedFont->setUnderline(false);

    selectedFont->setPixelSize(12);
    selectedFont->setBold(false);
    selectedFont->setUnderline(true);

    activeFont->setPixelSize(13);
    activeFont->setBold(false);
    activeFont->setUnderline(true);

    setStyleSheet("QLabel{border: 0 px}");
    activeStyleSheet="QLabel{border: 0px solid gray;}";
    inActiveStyleSheet="QLabel{border: 0px solid gray;}";

    active=false;
    dinamicSS = false;
}
ExLabel::~ExLabel(){
    delete selectedFont;
    delete unselectedFont;
    delete activeFont;

}
void ExLabel::leaveEvent(QEvent *event){
    if (active){
        setFont(*activeFont);
    }
    else{
        setFont(*unselectedFont);
        if (dinamicSS)
            setStyleSheet(inActiveStyleSheet);
    }
    emit mouseLeaved();
    QWidget::leaveEvent(event);
}
void ExLabel::enterEvent(QEvent *event){
    if (active){
        setFont(*activeFont);
    }
    else{
        setFont(*selectedFont);
        if (dinamicSS)
            setStyleSheet(activeStyleSheet);
    }        
    emit mouseEntered();
    QWidget::enterEvent(event);
}

void ExLabel::SetSelectedFont(const QFont &font){
    *selectedFont= font;
}
void ExLabel::SetActiveFont(const QFont &font){
    *activeFont= font;
}
void ExLabel::SetUnSelectedFont(const QFont &font){
    *unselectedFont=font;
}
void ExLabel::mousePressEvent(QMouseEvent *pe){
    if (dinamicSS)
        setStyleSheet(inActiveStyleSheet);
    setFont(*activeFont);
}
void ExLabel::mouseReleaseEvent(QMouseEvent *pe){
    if (active){
        setFont(*activeFont);
    }
    else{
        setFont(*selectedFont);
    }
    OnClick();
    if (dinamicSS)
        setStyleSheet(activeStyleSheet);
}
void ExLabel::setActive(bool status){
    setFont(*activeFont);
    active=status;
}
bool ExLabel::isActive(){
    return active;
}
void ExLabel::OnClick(){
    emit clicked();
}
void ExLabel::setActiveStyleSheet(const QString &ss){
    activeStyleSheet=ss;
    dinamicSS = true;
}
void ExLabel::setInActiveStyleSheet(const QString &ss){
    inActiveStyleSheet=ss;
    dinamicSS = true;
}
void ExLabel::incActiveFont(){
    activeFont->setPixelSize(activeFont->pixelSize()+1);
}
void ExLabel::decrActiveFont(){
    activeFont->setPixelSize(activeFont->pixelSize()-1);
}
void ExLabel::incSelectedFont(){
    selectedFont->setPixelSize(activeFont->pixelSize()+1);
}
void ExLabel::decrSelectedFont(){
    selectedFont->setPixelSize(activeFont->pixelSize()-1);
}
void ExLabel::incUnselectedFont(){
    unselectedFont->setPixelSize(activeFont->pixelSize()+1);
}
void ExLabel::decrUnselectedFont(){
    unselectedFont->setPixelSize(activeFont->pixelSize()-1);
}
void ExLabel::setActiveFontSize(int size){
    activeFont->setPixelSize(size);
}
void ExLabel::setSelectedFontSize(int size){
    selectedFont->setPixelSize(size);
}
void ExLabel::setUnselectedFontSize(int size){
    unselectedFont->setPixelSize(size);
}

void ExLabel::setFonts(int act, int sel, int uns){
    activeFont->setPixelSize(act);
    selectedFont->setPixelSize(sel);
    unselectedFont->setPixelSize(uns);
    setFont(*unselectedFont);
}

void ExLabel::setDinamicSS(bool mode){
    dinamicSS = mode;
}

bool ExLabel::isDinamicSS(){
    return dinamicSS;
}




