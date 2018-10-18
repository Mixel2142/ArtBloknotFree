#include "superenigma.h"
#include "ui_superenigma.h"
#include "qrandom.h"

SuperEnigma::SuperEnigma(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SuperEnigma)
{
    ui->setupUi(this);
   tm.setHMS(0,0,0,0);
   // this->setStyleSheet("border: 2px solid black; border-radiu: 3px; padding: 3px 3px 3px 3px; bacground-color: rgb(250,250,250)");
    this->show();
    qsrand(tm.currentTime().hour()+tm.currentTime().minute()+tm.currentTime().second());
}

SuperEnigma::~SuperEnigma()
{
    delete ui;
}

void SuperEnigma::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() != "")ui->lineEdit_2->setText(GeneratePublickKey(ui->lineEdit->text()));
}

int SuperEnigma::MyRandom(int low,int height)
{
    return (qrand() %((height +1)-low)+low);
}

void SuperEnigma::on_pushButton_clicked()
{
    PrKey="";
    for(int i=0;i<3;i++)PrKey+=ABC.at(MyRandom(0,44));
    ui->lineEdit->setText(PrKey);
}
QString SuperEnigma::GeneratePublickKey(QString str)
{


}
