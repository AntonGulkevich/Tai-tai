#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QFrame>
#include <QBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QLineEdit>

#include "exlabel.h"
#include "exbutton.h"
#include "groupexbuttons.h"

class ProfileWindow : public QFrame
{
    Q_OBJECT
public:
    explicit ProfileWindow(QWidget *parent = 0);
    ~ProfileWindow();
    void StartHideAnim(int left, int top, int width, int height);
    void StartShowAnim(int left, int top, int width, int height);

signals:
    void hide_();
    void show_();

public slots:
    void drawButton();
    void animatedHide();
    void setButton1();
    void setButton2();
    void setButton3();
    void setButton4();
    void setButton5();
    void setButton6();

private:
    QPropertyAnimation * animation;
    QBoxLayout * bigLay;
    QBoxLayout * topLay;
    QBoxLayout * botLay;

    GroupExButtons* groupEx;

    ExButton *testExButton;
    ExButton *createExButton;
    ExButton *deleteExButton;
    ExButton *editExButton;
    ExButton *exitExButton;
    ExButton *helpExButton;

};

#endif // PROFILEWINDOW_H
