#ifndef EXBUTTON_H
#define EXBUTTON_H

#include <QFrame>
#include <QBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <math.h>

class ExButton :  public QFrame
{
    Q_OBJECT
public:
    explicit ExButton(QWidget *parent = 0,  const QString & caption="ExButton", int r=60);
    ~ExButton();
    void setCaption(const QString & caption);
    void setRadius(int radius);
    void setSmallRadius(int radius);
    void addSubbButton(const QString & caption);
    void open(int scale);
    void close(int scale);
signals:
    void clicked();
public slots:
    void OnClick();
    void Locked();
    void Unlocked();
protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void leaveEvent(QEvent * event);
    virtual void enterEvent(QEvent *event);

    virtual void resizeEvent(QResizeEvent *event);


private:
    QString Caption;
    int Radius;
    int SmallRadius;
    bool isMaxed;
    bool isLocked;
    QLabel *captionExLabel;
    QString hoverSS;

    QString pressedSSBig;
    QString defaultSSBig;

    QString pressedSSSmall;
    QString defaultSSSmall;

    QList <ExButton*> subButtons;

};

#endif // EXBUTTON_H
