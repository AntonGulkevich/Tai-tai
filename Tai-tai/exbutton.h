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
    void setImage(const QString &image);
    void setRadius(int radius);
    void setSmallRadius(int radius);
    void addSubbButton(const QString & caption, const QString & imageWay, int margin);
    void open(int scale, int duration);
    void close(int scale,int duration);
    void setRotation(int degree);
    void preview();
    void setImageMargin(int margin);

signals:
    void clicked();
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

    QList <ExButton*> subButtons;

};

#endif // EXBUTTON_H
