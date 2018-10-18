#include "DialogSnar.h"
#include "ui_DialogSnar.h"

DialogSnar::DialogSnar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogSnar)
{
    ui->setupUi(this);
    this->setStyleSheet("border: 2px solid black; border-radiu: 3px; padding: 3px 3px 3px 3px; bacground-color: rgb(240,240,240)");
    ui->pushButton->setStyleSheet("bacground-color: rgb(200,200,200)");
    ui->pushButton_2->setStyleSheet("bacground-color: rgb(200,200,200)");
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SIGNAL(click_2()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SIGNAL(click_1()));

}

DialogSnar::~DialogSnar()
{
    delete ui;
}

void DialogSnar::on_pushButton_2_clicked()
{
    this->close();
}

void DialogSnar::on_radioButton_2_clicked()
{
    radio =true;
}

void DialogSnar::on_radioButton_clicked()
{
    radio =false;
}

void DialogSnar::on_pushButton_clicked()
{
    name = ui->lineEdit->text();
    this->close();
}
