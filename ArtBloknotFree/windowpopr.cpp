#include "windowpopr.h"
#include "ui_windowpopr.h"

WindowPopr::WindowPopr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowPopr)
{
    ui->setupUi(this);
    DataD=new QDinamicData(this);
    this->show();
     dt=new Data();
     UpdateComboBox();

}

WindowPopr::~WindowPopr()
{
delete ui;
}

void WindowPopr::on_pushButton_clicked()
{
    DataD->AddDataPopr(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_5->text());
   ui->comboBox->addItem(QString::number(ui->comboBox->count())+":"+ui->lineEdit->text());
    ui->comboBox->setCurrentIndex(ui->comboBox->count()-1);
    ui->comboBox->show();
    item=ui->comboBox->count()-2;
    ui->lineEdit->setFocus();
  QGuiApplication::inputMethod()->show();
}

void WindowPopr::on_comboBox_activated(int index)
{item=index-1;
      if(index != 0){
    ui->lineEdit->setText(DataD->GetData("Popr.txt",0,item));
    ui->lineEdit_2->setText(DataD->GetData("Popr.txt","B:",item));
    ui->lineEdit_5->setText(DataD->GetData("Popr.txt","C:",item));
      }

}

void WindowPopr::on_pushButton_2_clicked()
{
    if(item != -1){
    dt->DataDeleteFromFile(item,"Popr.txt");
    ui->comboBox->removeItem(item+1);
    ui->comboBox->setCurrentIndex(item);
    ui->comboBox->show();
    on_comboBox_activated(item);
    }

}

void WindowPopr::on_pushButton_3_clicked()
{
    if(item > -1){
   DataD->New_Change_Add_Data("Popr.txt",item,"0",ui->lineEdit->text());
   DataD->New_Change_Add_Data("Popr.txt",item,"B:",ui->lineEdit_2->text());
   DataD->New_Change_Add_Data("Popr.txt",item,"C:",ui->lineEdit_5->text());
    }

}


void WindowPopr::UpdateComboBox()
{
    DataD->ReSetFile("Popr.txt","");
    DataD->setComboBox(ui->comboBox,"Popr.txt");
    ui->comboBox->setItemText(0,"Опорная дальность");
    ui->comboBox->show();

}


void WindowPopr::on_WindowPopr_destroyed()
{

}

void WindowPopr::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowPopr::on_lineEdit_2_returnPressed()
{
     ui->lineEdit_5->setFocus();
     QGuiApplication::inputMethod()->show();

}
