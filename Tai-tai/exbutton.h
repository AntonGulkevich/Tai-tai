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
    void setCaption(const QString & caption);
    void setFullCaption();
    void setShortCaption();
    void setImage(const QString &image);
    void setRadius(int radius);
    void setSmallRadius(int radius);
    void setRotation(int degree);
    void setImageMargin(int margin);
    QString getCaption();
    int getRadius();
    int getSmallRadius();
    void setImageVisible(bool state);
    void setCaptionVisible(bool state);
    int getRotation();
    void setIsMaxed(bool state);
    bool isMaximum();
    bool IsLocked();
signals:
    void rightClicked();
    void leftClicked();
    void mouseEntered();
    void mouseLeaved();
public slots:
    void OnClick();
    void Locked();
    void Unlocked();
    void Redraw(QVariant var);
protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void leaveEvent(QEvent * event);
    virtual void enterEvent(QEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void moveEvent(QMoveEvent *event);
    //virtual void mouseDoubleClickEvent(QMouseEvent *event);
private:
    QString Caption;
    int Radius;
    int SmallRadius;
    bool isMaxed;
    bool isLocked;
    int rotation;
    QBoxLayout *mainLay;
    QLabel *captionExLabel;
    QLabel *imageLabel;

    QString hoverSS;

    QString pressedSSBig;
    QString defaultSSBig;

    QString pressedSSSmall;
    QString defaultSSSmall;
};

#endif // EXBUTTON_H

