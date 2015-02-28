#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QSize>
#include <QPoint>
#include <QPropertyAnimation>
#include <QPushButton>

#include "agbutton.h"

class MainWindow : public QFrame
{
    Q_OBJECT
private:

public:
    MainWindow(QWidget *parent = 0);
    void setGrayBackground();
    void setWhiteBackground();
    ~MainWindow();
private slots:
    void btnPressed();
    void btnReleased();

};

#endif // MAINWINDOW_H
