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
    selectedFont->setBold(true);
    selectedFont->setUnderline(true);

    activeFont->setPixelSize(13);
    activeFont->setBold(true);
    activeFont->setUnderline(true);

    setStyleSheet("QLabel{border: 0 px}");
    activeStyleSheet="QLabel{border: 3px solid gray;}";
    inActiveStyleSheet="QLabel{border: 1px solid gray;}";

    active=false;
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
    }
    QWidget::leaveEvent(event);
    if (pixmap())
        setStyleSheet(inActiveStyleSheet);
    emit mouseLeaved();
}
void ExLabel::enterEvent(QEvent *event){
    if (active){
        setFont(*activeFont);
    }
    else{
        setFont(*selectedFont);
    }
    QWidget::enterEvent(event);
    if (pixmap())
        setStyleSheet(activeStyleSheet);
    emit mouseEntered();
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
    if (pixmap())
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
    if (pixmap())
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
}
void ExLabel::setInActiveStyleSheet(const QString &ss){
    inActiveStyleSheet=ss;
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
}




