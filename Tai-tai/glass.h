#ifndef GLASS_H
#define GLASS_H

#include <QLabel>

class Glass : public QLabel
{
    Q_OBJECT
public:
    explicit Glass(QWidget *parent = 0);

signals:

public slots:
protected :
    virtual void paintEvent(QPaintEvent * pe);

};

#endif // GLASS_H
