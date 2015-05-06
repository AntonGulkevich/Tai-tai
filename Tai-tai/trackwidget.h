#ifndef TRACKWIDGET_H
#define TRACKWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class TrackWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TrackWidget(QWidget *parent = 0);

signals:
private:
    QPoint mpos;
    bool canMove;
public slots:

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // TRACKWIDGET_H
