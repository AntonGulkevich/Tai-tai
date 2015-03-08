#ifndef GROUPEXBUTTONS_H
#define GROUPEXBUTTONS_H

#include <QWidget>

#include <exbutton.h>

class GroupExButtons : public QWidget
{
    Q_OBJECT
public:
    GroupExButtons();
    virtual ~GroupExButtons();
    void addButton(ExButton* button);
    bool delButton(const QString & caption);
    void setDefaultButton(ExButton * button);
    void showAnimated(int scale, int duration);
    void hideAnimated(int scale, int duration);
    void preview(int scale, int duration);
    ExButton *getSubButton(const QString & button);
private:
    QList <ExButton*> subButtons;
    ExButton * defaultButton;
signals:
    void hideAnimatedFinished();
    void showAnimatedFinished();
    void prewiewFinished();

public slots:
    void startAnimation();
    void onMouseEnter();
    void onMouseLeave();

};

#endif // GROUPEXBUTTONS_H