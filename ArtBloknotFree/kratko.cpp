#include "kratko.h"
#include "ui_kratko.h"

Kratko::Kratko(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kratko)
{
    ui->setupUi(this);
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->textEdit);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
    this->show();
}

Kratko::~Kratko()
{
    delete ui;
}
