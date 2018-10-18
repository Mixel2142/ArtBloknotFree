#include "about.h"
#include "ui_about.h"
#include "headers.h"
About::About(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->show();
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{


    Kratko* kr=new Kratko(this);


}

void About::on_pushButton_2_clicked()
{
    Sokr* kr=new Sokr(this);
}
