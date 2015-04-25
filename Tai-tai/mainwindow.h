#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QSize>
#include <QPoint>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QGraphicsOpacityEffect>

#include "profilewindow.h"
#include "exbutton.h"


class MainWindow : public QFrame
{
    Q_OBJECT
private:
    ProfileWindow * MainProfileWindow;

    QSize mainWindowStartSize;
    QPoint mainWindownStartPoint;

    QWidget *overLay;
    /*test*/
    QPushButton * TSTSTSTTS;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setGrayBackground();
    void setWhiteBackground();


private slots:
    void showProfileWindow();
    void hideProfileWindow();

    void showOverLay();
    void hideOverLay();
};

#endif // MAINWINDOW_H
