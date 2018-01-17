#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QEvent>
#include "widget.h"
#include <QMouseEvent>
#include <QTimer>

class Widget;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::Dialog *ui;
    Widget *w;
};

#endif // DIALOG_H
