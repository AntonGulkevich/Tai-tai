#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QFrame(parent)
{
    /*Start up properties of main window*/

    //temporary settings//
    mainWindowStartSize.setHeight(600);
    mainWindowStartSize.setWidth(800);
    mainWindownStartPoint.setX(400);
    mainWindownStartPoint.setY(100);
    //temporary settings//

    /*End of Start up properties of main window*/

    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setWindowFlags(Qt::FramelessWindowHint);
    resize(mainWindowStartSize);
    move(mainWindownStartPoint);
    setMinimumSize(500, 550);
    setStyleSheet("QFrame {border: 1px solid lightgrey; background: white}");

    TSTSTSTTS= new QPushButton("holly shit", this);
    TSTSTSTTS->resize(100, 100);
    TSTSTSTTS->move(500, 500);
    TSTSTSTTS->show();
    TSTSTSTTS->setEnabled(true);
    connect(TSTSTSTTS, SIGNAL(clicked()), this, SLOT(showOverLay()));

    QPushButton * btn= new QPushButton("test", this);
    btn->resize(100, 100);
    btn->move(500, 100);
    btn->show();

    connect(btn, SIGNAL(pressed()), this, SLOT(btnPressed()));
    connect(btn, SIGNAL(released()), this, SLOT(btnReleased()));

    overLay = new QWidget(this);
    overLay->setWindowFlags(Qt::FramelessWindowHint);
    overLay->setGeometry(0, 0, width(), height());
    overLay->setStyleSheet("background-color:rgba(130, 130, 130, 50%)");
    overLay->hide();

    MainProfileWindow = new ProfileWindow(this);
    connect (MainProfileWindow, SIGNAL(hide_()), this, SLOT(hideOverLay()));
}

MainWindow::~MainWindow()
{

}
void MainWindow::btnPressed(){

}
void MainWindow::btnReleased(){
    if (MainProfileWindow->isHidden()){
        overLay->show();
        MainProfileWindow->StartShowAnim(0, 0, mainWindowStartSize.width()/2, mainWindowStartSize.height());

    }
    else{
        overLay->hide();
        MainProfileWindow->StartHideAnim(0, 0, mainWindowStartSize.width()/2, mainWindowStartSize.height());
    }
}

void MainWindow::setWhiteBackground(){
    QPalette ActPal;
    ActPal.setColor(backgroundRole(), Qt::white);
    setPalette(ActPal);
}

void MainWindow::showOverLay(){
    overLay->show();
}

void MainWindow::hideOverLay(){
    overLay->hide();
}
void MainWindow::setGrayBackground(){
    QPalette InActPal;
    InActPal.setColor(backgroundRole(), Qt::lightGray);
    setPalette(InActPal);

}

