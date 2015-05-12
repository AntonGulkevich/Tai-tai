#ifndef EXLABEL_H
#define EXLABEL_H

#include <QLabel>
#include <QFont>
#include <QMouseEvent>

class ExLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ExLabel(const QString &text, QWidget *parent = 0);
    ~ExLabel();
    void SetSelectedFont(const QFont &font);
    void SetUnSelectedFont(const QFont &font);
    void SetActiveFont(const QFont &font);
    bool isActive();
    void setActive(bool status);    
    void setActiveStyleSheet(const QString& ss);
    void setInActiveStyleSheet(const QString& ss);

    void incActiveFont();
    void incUnselectedFont();
    void incSelectedFont();

    void decrActiveFont();
    void decrUnselectedFont();
    void decrSelectedFont();

    void setActiveFontSize(int size);
    void setSelectedFontSize(int size);
    void setUnselectedFontSize(int size);

    void setFonts(int act , int sel, int uns);
signals:
    void clicked();
    void mouseEntered();
    void mouseLeaved();

public slots:
    void OnClick();

protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void leaveEvent(QEvent * event);
    virtual void enterEvent(QEvent *event);


private:
    QFont *selectedFont;
    QFont *unselectedFont;
    QFont *activeFont;
    bool active;
    QPoint pos;
    QString activeStyleSheet;
    QString inActiveStyleSheet;
};

#endif // EXLABEL_H
