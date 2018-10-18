#include "tabfire.h"
#include "ui_tabfire.h"
#include "dialogtabl.h"
#include "dialogzar.h"
#include <QScrollBar>
#include <QMessageBox>
TabFire::TabFire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TabFire)
{
    ui->setupUi(this);
    DataD=new QDinamicData(this);
    ui->comboBox_2->addItem("Новая система");
    ui->comboBox_3->addItem("Дальность");
    ui->comboBox_4->addItem("Снаряды");
    ui->comboBox_5->addItem("Заряды");
    DataD->setComboBoxFromTabl(ui->comboBox_2,FND,"","","");
     ditab=new DialogTabl(this);
     disnar=new DialogSnar(this);
     dizar=new DialogZar(this);
    connect(ditab,SIGNAL(click_1()),this,SLOT(ClickCount()));
    connect(ditab,SIGNAL(click_2()),this,SLOT(ClickCancle()));
    connect(disnar,SIGNAL(click_1()),this,SLOT(ClickCountSnar()));
    connect(disnar,SIGNAL(click_2()),this,SLOT(ClickCancleSnar()));
    connect(dizar,SIGNAL(click_1()),this,SLOT(ClickCountZar()));
    connect(dizar,SIGNAL(click_2()),this,SLOT(ClickCancleZar()));

    this->show();
}

TabFire::~TabFire()
{
    delete ui;
}

void TabFire::UpdateAllComboBox()
{
    if(item2 >-1 && item4 >-1 && item5 >-1 && item3 >-1)
     {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItem("Дальность");
        DataD->setComboBoxFromTabl(ui->comboBox_3,FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1));
     }
     else if(item2 >-1 && item4 >-1 && item5 >-1)
    {
        ui->comboBox_5->clear();
        ui->comboBox_5->addItem("Заряды");

        DataD->setComboBoxFromTabl(ui->comboBox_5,FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),"");
        disnar->oldname=ui->comboBox_5->itemText(item5+1);

    }
     else if(item2 >-1 && item4 >-1){
         ui->comboBox_4->clear();
         ui->comboBox_4->addItem("Снаряды");

        DataD->setComboBoxFromTabl(ui->comboBox_4,FND,ui->comboBox_2->itemText(item2+1),"","");
        dizar->oldname=ui->comboBox_4->itemText(item4+1);
    }
    else  if(item2 >-1)
    {
    ui->comboBox_2->clear();
    ui->comboBox_2->addItem("Новая система");

    DataD->setComboBoxFromTabl(ui->comboBox_2,FND,"","","");
    ditab->oldname=ui->comboBox_2->itemText(item2+1);
    }

}
void TabFire::on_comboBox_2_activated(int index)
{item2=index-1;

    if(index==0)
    {
    ditab->show();
    }
if(index>0)
{
    if(item2>-1&&item3>-1&&item4>-1&&item5>-1)
    {
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
    }
    else {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_7->setEnabled(false);
    }
    if(DataD->ChoicePricel(ui->comboBox_2->itemText(item2+1))&& index != 0)
    {
        ui->label_3->setText("Птыс:");
        ui->label_7->setText("∆Хтыс:");

    }
else{
        ui->label_3->setText("П:");
        ui->label_7->setText("∆П:");
    }
    ui->comboBox_4->clear();
    ui->comboBox_4->addItem("Снаряды");
   DataD->setComboBoxFromTabl(ui->comboBox_4,FND,ui->comboBox_2->itemText(item2+1),"","");
   oldsystem=ui->comboBox_2->itemText(item2+1);

}
}
void TabFire::ClickCount()
{
    ui->comboBox_2->addItem(ditab->name);
    ui->comboBox_2->setCurrentIndex( ui->comboBox_2->count()-1);
    ui->comboBox_2->show();
    on_comboBox_2_activated(ui->comboBox_2->count()-1);
    change=false;
    if(ditab->radio == true)
    {
        ui->label_3->setText("П:");
        ui->label_7->setText("∆П:");
    }
    else{
        ui->label_3->setText("Птыс:");
        ui->label_7->setText("∆Хтыс:");
    }

}

void TabFire::ClickCancle()
{
//QMessageBox msgb;
//msgb.setText("Cancle");
//msgb.exec();
    change=false;
}
void TabFire::ClickCountSnar()
{

     if(change== true)
     {
         DataD->Change_Add_Data_Tabl(FND,ditab->oldname,disnar->oldname,dizar->oldname,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_5->text(),ui->lineEdit_7->text(),ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->comboBox_3->itemText(item3+1));
         ui->comboBox_4->addItem(ui->lineEdit->text());
         ui->comboBox_4->setCurrentIndex( ui->comboBox_4->count()-1);
          ui->comboBox_4->show();
          on_comboBox_4_activated(ui->comboBox_4->count()-1);
     }
     else
     {
         ui->comboBox_4->addItem(disnar->name);
         ui->comboBox_4->setCurrentIndex( ui->comboBox_4->count()-1);
          ui->comboBox_4->show();
          on_comboBox_4_activated(ui->comboBox_4->count()-1);
     }
     change=false;
}

void TabFire::ClickCancleSnar()
{
//QMessageBox msgb;
//msgb.setText("Cancle");
//msgb.exec();
    change=false;
}
void TabFire::ClickCountZar()
{

    if(change== true)
    {
        DataD->Change_Add_Data_Tabl(FND,ditab->oldname,disnar->oldname,dizar->oldname,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_5->text(),ui->lineEdit_7->text(),ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->comboBox_3->itemText(item3+1));
        ui->comboBox_5->addItem(ui->lineEdit->text());
        ui->comboBox_5->setCurrentIndex( ui->comboBox_5->count()-1);
         ui->comboBox_5->show();
         on_comboBox_5_activated(ui->comboBox_5->count()-1);
    }
    else
    {
        ui->comboBox_5->addItem(dizar->name);
        ui->comboBox_5->setCurrentIndex( ui->comboBox_5->count()-1);
         ui->comboBox_5->show();
         on_comboBox_5_activated(ui->comboBox_5->count()-1);
    }

     change=false;
}

void TabFire::ClickCancleZar()
{
//QMessageBox msgb;
//msgb.setText("Cancle");
//msgb.exec();
    change=false;
}
void TabFire::on_pushButton_clicked()
{
    if(item2 >-1 && item4 >-1 && item5 >-1  && ui->lineEdit->text() !=""){
    DataD->AddDataTabl(FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_5->text(),ui->lineEdit_7->text(),ditab->choice);
    ui->comboBox_3->addItem(ui->lineEdit->text());
    ui->comboBox_3->setCurrentIndex(ui->comboBox_3->count()-1);
    ui->comboBox_3->show();
    item3=ui->comboBox_3->count()-2;
    ui->lineEdit->setFocus();
    ui->lineEdit->setCursorPosition(2);
      QGuiApplication::inputMethod()->show();
    }
}

void TabFire::on_comboBox_3_activated(int index)
{
    item3=index-1;
          if(index > 0){
        ui->lineEdit->setText(DataD->GetDataTabl(FND,"Q:",ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->comboBox_3->itemText(item3+1)));
        ui->lineEdit_2->setText(DataD->GetDataTabl(FND,"W:",ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->comboBox_3->itemText(item3+1)));
        ui->lineEdit_5->setText(DataD->GetDataTabl(FND,"E:",ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->comboBox_3->itemText(item3+1)));
        ui->lineEdit_7->setText(DataD->GetDataTabl(FND,"R:",ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->comboBox_3->itemText(item3+1)));

          }
     //     if(index>0)
     //     {
     //     UpdateAllComboBox();
     //     }
}

void TabFire::on_pushButton_2_clicked()
{
    if(item2 >-1 && item4 >-1 && item5 >-1 && item3 >-1)
    {
        qDebug() <<ui->comboBox_2->itemText(item2+1)+ui->comboBox_4->itemText(item4+1)+ui->comboBox_5->itemText(item5+1)+ui->comboBox_3->itemText(item3+1);
    DataD->DeleteTabl(FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->comboBox_3->itemText(item3+1));
    ui->comboBox_3->removeItem(item3+1);
    ui->comboBox_3->setCurrentIndex(item3);
    ui->comboBox_3->show();
    on_comboBox_3_activated(item3);
    }
    else if(item2 >-1 && item4 >-1 && item5 >-1)
    {
        DataD->DeleteTabl(FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),0);
        ui->comboBox_5->removeItem(item5+1);
        ui->comboBox_5->setCurrentIndex(item5);
        ui->comboBox_5->show();
        on_comboBox_5_activated(item5);
    }
    else if(item2 >-1 && item4 >-1)
    {
        DataD->DeleteTabl(FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),0,0);
        ui->comboBox_4->removeItem(item4+1);
        ui->comboBox_4->setCurrentIndex(item4);
        ui->comboBox_4->show();
        on_comboBox_4_activated(item4);
    }
    else if(item2 >-1)
    {
        DataD->DeleteTabl(FND,ui->comboBox_2->itemText(item2+1),0,0,0);
        ui->comboBox_2->removeItem(item2+1);
        ui->comboBox_2->setCurrentIndex(item2);
        ui->comboBox_2->show();
        on_comboBox_2_activated(item2);
    }

}

void TabFire::on_comboBox_4_activated(int index)
{
     item4=index-1;
     if(item2>-1&&item3>-1&&item4>-1&&item5>-1)
     {
         ui->lineEdit->setEnabled(true);
         ui->lineEdit_2->setEnabled(true);
         ui->lineEdit_5->setEnabled(true);
         ui->lineEdit_7->setEnabled(true);
     }
     else {
         ui->lineEdit->setEnabled(false);
         ui->lineEdit_2->setEnabled(false);
         ui->lineEdit_5->setEnabled(false);
         ui->lineEdit_7->setEnabled(false);
     }
     if(index==0)
    {
    disnar->show();
    }
     if(index>0)
     {
         ui->comboBox_5->clear();
         ui->comboBox_5->addItem("Заряды");

         DataD->setComboBoxFromTabl(ui->comboBox_5,FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),"");

         disnar->oldname=ui->comboBox_4->itemText(item4+1);
     }
}

void TabFire::on_comboBox_5_activated(int index)
{
    item5=index-1;
    if(item2>-1&&item4>-1&&item5>-1)
    {
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
    }
    else {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_7->setEnabled(false);
    }
    if(index==0)
    {
        dizar->show();
    }
    if(index>0)
    {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItem("Дальность");
        DataD->setComboBoxFromTabl(ui->comboBox_3,FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1));
    dizar->oldname=ui->comboBox_5->itemText(item5+1);
    }
}

void TabFire::on_pushButton_3_clicked()
{

    if(item2 >-1 && item4 >-1 && item5 >-1 && item3 >-1)
    {
    DataD->Change_Add_Data_Tabl(FND,ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1),ui->comboBox_3->itemText(item3+1),ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_5->text(),ui->lineEdit_7->text(),ui->comboBox_2->itemText(item2+1),ui->comboBox_4->itemText(item4+1),ui->comboBox_5->itemText(item5+1));
    ui->comboBox_3->setItemText(item3+1,ui->lineEdit->text());
    }
    else if(item2 >-1 && item4 >-1 && item5 >-1)
    {
      dizar->show();
      change=true;
    }
    else if(item2 >-1 && item4 >-1)
    {
      disnar->show();
       change=true;
    }
    else if(item2 >-1)
    {
       ditab->show();
        change=true;
    }
}



void TabFire::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
      QGuiApplication::inputMethod()->show();

}

void TabFire::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_5->setFocus();
      QGuiApplication::inputMethod()->show();

}

void TabFire::on_lineEdit_5_returnPressed()
{
    ui->lineEdit_7->setFocus();
      QGuiApplication::inputMethod()->show();

}
