#include "newdialog.h"
#include "ui_newdialog.h"

NEWDIALOG::NEWDIALOG(QWidget *parent, int index) :
    QMainWindow(parent),
    ui(new Ui::NEWDIALOG)
{

     ui->setupUi(this);
     this->setStyleSheet("border: 2px solid black; border-radiu: 3px; padding: 3px 3px 3px 3px; bacground-color: rgb(250,250,250)");
     connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SIGNAL(click_2()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SIGNAL(click_1()));
}

NEWDIALOG::~NEWDIALOG()
{
    delete ui;
}

void NEWDIALOG::Setup(int index)
{
    // this->show();
     DataD=new QDinamicData();
     X=DataD->GetData("Knp.txt","A:",index-1).toDouble();
     Y=DataD->GetData("Knp.txt","B:",index-1).toDouble();
     Height=DataD->GetData("Knp.txt","D:",index-1).toDouble();
  ui->lineEdit->setValidator(new QIntValidator(0,59,this));
  ui->lineEdit_2->setValidator(new QIntValidator(0,99,this));
  ui->lineEdit_4->setValidator(new QIntValidator(-15,15,this));
  ui->lineEdit_3->setValidator(new QIntValidator(0,99,this));
  flag=-1;
  //this->show();

}
void NEWDIALOG::on_pushButton_2_clicked()
{
flag=1;
DataD->PGZ(ui->lineEdit_5->text().toDouble(),ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_4->text(),ui->lineEdit_3->text(),QString::number(X),QString::number(Y),QString::number(Height));
X=DataD->getPGZX();
Y=DataD->getPGZY();
Height =DataD->getPGZH();
this->close();
}
double NEWDIALOG::GetX()
{
    return X;
}
double NEWDIALOG::GetY()
{
    return Y;
}
double NEWDIALOG::GetH()
{
    return NEWDIALOG::Height;
}
void NEWDIALOG::on_pushButton_clicked()
{
    flag=0;
    this->close();
}

void NEWDIALOG::on_pushButton_2_clicked(bool checked)
{
    flag=1;
    DataD->PGZ(ui->lineEdit_5->text().toDouble(),ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_4->text(),ui->lineEdit_3->text(),QString::number(X),QString::number(Y),QString::number(Height));
    X=DataD->getPGZX();
    Y=DataD->getPGZY();
    Height =DataD->getPGZH();
    this->close();
this->close();
}

void NEWDIALOG::on_pushButton_clicked(bool checked)
{
    flag=0;
    this->close();
}
void click_2()
{

}
void click_1()
{

}
