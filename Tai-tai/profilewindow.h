#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QFrame>
#include <QBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>

#include "exlabel.h"
#include "exbutton.h"

class ProfileWindow : public QFrame
{
    Q_OBJECT
public:
    explicit ProfileWindow(QWidget *parent = 0);
    ~ProfileWindow();
    void StartHideAnim(int left, int top, int width, int height);
    void StartShowAnim(int left, int top, int width, int height);

signals:

public slots:
    void drawButton();

private:
    QPropertyAnimation * animation;
    QBoxLayout * bigLay;
    QBoxLayout * topLay;
    QBoxLayout * botLay;

};

#endif // PROFILEWINDOW_H
