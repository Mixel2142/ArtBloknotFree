#include "windowredactor.h"
#include "ui_windowredactor.h"

WindowRedactor::WindowRedactor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowRedactor)
{
    ui->setupUi(this);
}

WindowRedactor::~WindowRedactor()
{
    delete ui;
}
