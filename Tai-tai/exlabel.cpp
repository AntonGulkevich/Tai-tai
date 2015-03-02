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
}
void ExLabel::enterEvent(QEvent *event){
    if (active){
        setFont(*activeFont);
    }
    else{
        setFont(*selectedFont);
    }
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

