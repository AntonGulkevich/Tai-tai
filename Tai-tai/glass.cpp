#include "glass.h"

Glass::Glass(QWidget *parent) :
    QLabel(parent)
{
}

void Glass::paintEvent(QPaintEvent *pe)
{
    QPainter paint;
    paint.begin (this);
    paint.setBrush (QBrush (QColor (255, 255, 255, 180)));
    paint.setPen (Qt::NoPen);
    paint.drawRect (0, 0, width(), height());
    paint.end();
}
