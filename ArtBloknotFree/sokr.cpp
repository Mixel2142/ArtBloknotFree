#include "sokr.h"
#include "ui_sokr.h"

Sokr::Sokr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sokr)
{
    ui->setupUi(this);
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->textEdit);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
    this->show();
}

Sokr::~Sokr()
{
    delete ui;
}
