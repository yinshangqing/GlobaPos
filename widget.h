#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
#include "dialog.h"
#include <QRect>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QRect getRect() {return rect;}
    bool isInWin(QPoint pt);

    void mouseMoveEvent(QMouseEvent *);

public slots:
    void updateRect();

private:
    Ui::Widget *ui;
    QRect rect;
    QTimer *timer;
    QPoint pot;
    QPoint old_pot;
};

#endif // WIDGET_H
