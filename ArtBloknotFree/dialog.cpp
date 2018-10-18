#include "dialog.h"
#include "ui_dialog.h"
#include <QCheckBox>

Dialog::Dialog(QWidget *parent, int index) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
   // this->setModal(true);
    this->setStyleSheet("border: 2px solid black; border-radiu: 3px; padding: 3px 3px 3px 3px; bacground-color: rgb(250,250,250)");
    this->show();
    DataD=new QDinamicData();
    X=DataD->GetData("Knp.txt","A:",index-1).toDouble();
    Y=DataD->GetData("Knp.txt","B:",index-1).toDouble();
    Height=DataD->GetData("Knp.txt","D:",index-1).toDouble();
 ui->lineEdit->setValidator(new QIntValidator(0,59,this));
 ui->lineEdit_2->setValidator(new QIntValidator(0,99,this));
 ui->lineEdit_4->setValidator(new QIntValidator(-15,15,this));
 ui->lineEdit_3->setValidator(new QIntValidator(0,99,this));
}

Dialog::~Dialog()
{

    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    flag=true;
    double distance= ui->lineEdit_5->text().toDouble();
    double napr;
    double uglmesta;
    napr=(ui->lineEdit->text().toDouble()+(ui->lineEdit_2->text().toDouble()/100))*6;
    QString str= ui->lineEdit_4->text() + ui->lineEdit_3->text();
    uglmesta=str.toDouble();

//DataD->PGZ(ui->lineEdit_5->text().toDouble(),ui->lineEdit->text(),ui->lineEdit_2->text(),);


    double delX =distance*cos(napr*(M_PI/180));
    if(fabs(delX)<0.0000001)delX=0;


    double delY = distance*sin(napr*(M_PI/180));
     if(fabs(delY)<0.0000001)delY=0;


X=delX + X;
Y=delY + Y;
Height =Height+((distance/1000)*uglmesta);
this->close();

}

void Dialog::on_pushButton_clicked()
{
    flag=false;
    this->close();
}

void Dialog::on_pushButton_2_clicked()
{
    flag=true;
    double distance= ui->lineEdit_5->text().toDouble();
    double napr;
    double uglmesta;
    napr=(ui->lineEdit->text().toDouble()+(ui->lineEdit_2->text().toDouble()/100))*6;
    QString str= ui->lineEdit_4->text() + ui->lineEdit_3->text();
    uglmesta=str.toDouble();

//DataD->PGZ(ui->lineEdit_5->text().toDouble(),ui->lineEdit->text(),ui->lineEdit_2->text(),);


    double delX =distance*cos(napr*(M_PI/180));
    if(fabs(delX)<0.0000001)delX=0;


    double delY = distance*sin(napr*(M_PI/180));
     if(fabs(delY)<0.0000001)delY=0;


X=delX + X;
Y=delY + Y;
Height =Height+((distance/1000)*uglmesta);
this->close();

}

double Dialog::GetX()
{
    return X;
}
double Dialog::GetY()
{
    return Y;
}
double Dialog::GetH()
{
    return Dialog::Height;
}

void Dialog::on_lineEdit_editingFinished()
{

}
