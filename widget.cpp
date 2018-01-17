#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QCursor>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updateRect()));
    timer->start(30);
    /* 开启鼠标追踪 */
    this->setMouseTracking(true);

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::isInWin(QPoint pt)
{
    if(pt.x() >= this->mapToGlobal(this->pos()).x() && pt.x() <= (this->mapToGlobal(this->pos()).x() + this->size().width())){
        if(pt.y() >= this->mapToGlobal(this->pos()).y() && pt.y() <= (this->mapToGlobal(this->pos()).y() + this->size().height())){
            return true;
        }
    }
    return false;
}

void Widget::updateRect()
{
    rect = QRect(this->mapToGlobal(this->pos()),this->size());
    qDebug() << this->mapToGlobal(this->pos()).x() << this->mapToGlobal(this->pos()).y();
    pot = QCursor::pos();
    if(isInWin(pot)){
        this->show();
    }else{
        this->hide();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
//    pot = event->globalPos();
    qDebug() << "x: " << pot.x() << "y: " << pot.y();
}


