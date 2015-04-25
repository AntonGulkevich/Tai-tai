#ifndef EXBUTTON_H
#define EXBUTTON_H

#include <QFrame>
#include <QBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <math.h>
#include <QDebug>

class ExButton :  public QFrame
{
    Q_OBJECT
public:
    explicit ExButton(QWidget *parent = 0,  const QString & caption="ExButton", int r=60, bool subButton = false);
    ~ExButton();

    void setCaption(const QString & caption);// set text on button
    QString getCaption();// get text from button
    void setFullCaption();// set full variant of caption
    void setShortCaption(int count);//set short variant of caption ex: was "Caption" now "C+count of literals"
    void setCaptionVisible(bool state);

    void setImage(const QString &image); //set image to button
    void setImageMargin(int margin); //set margins of image
    void setImageVisible(bool state);// make image visible or not

    void setRadius(int radius); // set radius of button in normal size
    int getRadius(); // returns raduis of button in normal size
    void setSmallRadius(int radius); // set radius of button is small size
    int getSmallRadius(); // get radius of button is small size

    void setRotation(int degree); //set degress of rotaion(clockwise)
    int getRotation(); //get degress of rotaion(clockwise)

    bool isMaximumSize(); // return state of button
    bool IsAnimationBlocked(); // return state if locked if not

    void setDefaultBackgroundColor(const QString &color); //set the background in default mod
    void setHoverBackgroundColor(const QString &color); //same in hover mode
    void setPressedBackgroundColor(const QString &color);//same in pressed mod

    void initSS(); // initialize stylesheets for default settings
    void setCountLiteralsShortCaption(int count);//set count of literals in caption of short mod
    int getCountLiteralsShortCaption();//returns count of literals in caption of short mod

    void swapButtonsGeometry(ExButton *target);

signals:
    void rightClicked(); // return signal if clicked right button
    void leftClicked(); //return signal if clicked left button
    void mouseEntered();//return signal if mouse entered the button
    void mouseLeaved(); //return signal if mouse left the button
public slots:
    void blockAnimation(); // block animation
    void unBlockAnimation(); // unblock animation
    void minimizeAnimated();// resize to maximum with animation
    void maximizeAnimated();//resize to minimum with animation
    void setDefaultSS();//set default style sheet to button due to it size
protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void leaveEvent(QEvent * event);
    virtual void enterEvent(QEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    //virtual void mouseDoubleClickEvent(QMouseEvent *event);
private:

    QString Caption; // front text of the button
    int Radius; // button's radius in normal size
    int SmallRadius; //button's radius in small size
    bool Maxed; // true if button's size is normal
    bool AnimationLocked; // true is animation is locked
    int rotation; // the rotation
    int countLiteralsShortCaption; // oblivious
    QBoxLayout *mainLay; // main layout
    QLabel *captionExLabel;// label with shows button's caption
    QLabel *imageLabel; // label with contains and show buttons' image

    QString hoverSS;// style sheet parameter in hover mod

    QString pressedSSBig;// SS parameter in pressed mod if button is maxed
    QString defaultSSBig;// SS parametr in default mod if button is maxed

    QString pressedSSSmall;// SS parameter in pressed mod if button is minimized
    QString defaultSSSmall;//SS parametr in default mod if button is minimized

    QString defaultBackGroudColor;// background color in default mod
    QString hoverBackGroudColor;// background color in hover mod
    QString pressedBackGroudColor;//background color in pressed mod

};

#endif // EXBUTTON_H

