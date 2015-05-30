#ifndef DIRECTWINDOW_H
#define DIRECTWINDOW_H

#include <QFrame>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QLayout>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>

#include <QDebug>

#include "exlabel.h"

class DirectWindow : public QFrame
{
    Q_OBJECT
public:
    explicit DirectWindow(QWidget *parent = 0);
    void setProfileCaption(const QString &text);
    void addEmail(const QString &text);
    void setComboBoxSS(const QString &text);
    void setProfileAva(const QString &text);
private:
    QPropertyAnimation *animation;
    QVBoxLayout *mainLayout;

    ExLabel *profileAvaEL;
    ExLabel *profileCaptionEL;
    ExLabel *changeProfileEL;
    ExLabel *editProfileLE;
    QComboBox *emailBox;

    QString comboBoxSS;

    void initLayouts();

signals:
    void showA();
    void hideA();
    void profileAvaClicked();
    void profileCaptionClicked();
    void emailIndexChanged(int index);
    void changeProfileELClicked();
    void editProfileELClicked();
public slots:
    void animatedShow(const QPoint &localPos);
    void animatedHide();
    void onProfileAvaClicked();
    void onProfileCaptionClicked();
    void onEmailChanged(int index);
    void onChangeProfileELClicked();
    void onEditProfileLEClicked();
    void setDefaults();

};

#endif // DIRECTWINDOW_H
