#include "dialogtabl.h"
#include "ui_dialogtabl.h"
#include <QMessageBox>

DialogTabl::DialogTabl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogTabl)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 2px solid black; border-radiu: 3px; padding: 3px 3px 3px 3px; bacground-color: rgb(240,240,240)");
    ui->pushButton->setStyleSheet("bacground-color: rgb(200,200,200)");
    ui->pushButton_2->setStyleSheet("bacground-color: rgb(200,200,200)");
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SIGNAL(click_2()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SIGNAL(click_1()));
    ui->radioButton->setChecked(true);
    oldname=name;
}

DialogTabl::~DialogTabl()
{
    delete ui;
}

void DialogTabl::on_pushButton_2_clicked()
{
    this->close();
}

void DialogTabl::on_radioButton_2_clicked()
{
    radio =true;
}

void DialogTabl::on_radioButton_clicked()
{
    radio =false;
}

void DialogTabl::on_pushButton_clicked()
{
    name = ui->lineEdit->text();
    if(ui->radioButton->isChecked())choice="1";
    else choice="0";
    this->close();
}

void DialogTabl::on_DialogTabl_destroyed()
{

}
