#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    w = new Widget(this);
    w->show();
    /* 开启鼠标追踪 */
    this->setMouseTracking(true);

    //ui->
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    w->mouseMoveEvent(event);
}




