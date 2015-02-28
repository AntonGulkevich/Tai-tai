#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QFrame(parent)
{
    /*Start up properties of main window*/
    QSize mainWindowStartSize;
    QPoint mainWindownStartPoint;

    //temporary settings//
    mainWindowStartSize.setHeight(600);
    mainWindowStartSize.setWidth(800);
    mainWindownStartPoint.setX(400);
    mainWindownStartPoint.setY(100);
    //temporary settings//

    /*End of Start up properties of main window*/

    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    //setAutoFillBackground(true);
    resize(mainWindowStartSize);
    move(mainWindownStartPoint);
    setMinimumSize(500, 550);
    setStyleSheet("QFrame {border: 1px solid lightgrey;}");
    setGrayBackground();

    QPushButton * btn= new QPushButton("test", this);
    btn->resize(100, 100);
    btn->move(100, 100);
    btn->show();
    connect(btn, SIGNAL(pressed()), this, SLOT(btnPressed()));
    connect(btn, SIGNAL(released()), this, SLOT(btnReleased()));

   // QPropertyAnimation * anim = new QPropertyAnimation()

}

MainWindow::~MainWindow()
{

}
void MainWindow::btnPressed(){
    setGrayBackground();
}
void MainWindow::btnReleased(){

    setWhiteBackground();
}


void MainWindow::setWhiteBackground(){
    QPalette ActPal;
    ActPal.setColor(backgroundRole(), Qt::white);
    setPalette(ActPal);

}
void MainWindow::setGrayBackground(){
    QPalette InActPal;
    InActPal.setColor(backgroundRole(), Qt::lightGray);
    setPalette(InActPal);

}

