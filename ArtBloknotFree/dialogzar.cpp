#include "DialogZar.h"
#include "ui_DialogZar.h"

DialogZar::DialogZar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogZar)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 2px solid black; border-radiu: 3px; padding: 3px 3px 3px 3px; bacground-color: rgb(240,240,240)");
    ui->pushButton->setStyleSheet("bacground-color: rgb(200,200,200)");
    ui->pushButton_2->setStyleSheet("bacground-color: rgb(200,200,200)");
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SIGNAL(click_2()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SIGNAL(click_1()));
    oldname=name;
}

DialogZar::~DialogZar()
{
    delete ui;
}

void DialogZar::on_pushButton_2_clicked()
{
    this->close();
}

void DialogZar::on_radioButton_2_clicked()
{
    radio =true;
}

void DialogZar::on_radioButton_clicked()
{
    radio =false;
}

void DialogZar::on_pushButton_clicked()
{
    name = ui->lineEdit->text();
    this->close();
}
