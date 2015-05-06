#include "trackwidget.h"

TrackWidget::TrackWidget(QWidget *parent) :
    QWidget(parent)
{
    mpos=parent->pos();
    canMove= false;
}
void TrackWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)    {
        mpos = event->pos();
        canMove = true;
    }
}

void TrackWidget::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && canMove) {
        canMove = false;
    }
}
void TrackWidget::mouseMoveEvent(QMouseEvent *event){
    if((event->buttons() & Qt::LeftButton) && canMove){
        parentWidget()->move(event->globalPos()-mpos);
    }
}
