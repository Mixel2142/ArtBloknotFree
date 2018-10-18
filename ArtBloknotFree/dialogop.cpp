#include "dialogop.h"
#include "ui_dialogop.h"

DialogOP::DialogOP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOP)
{
    ui->setupUi(this);
}

DialogOP::~DialogOP()
{
    delete ui;
}
