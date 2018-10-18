#include "dialogchoicesyst.h"
#include "ui_dialogchoicesyst.h"
#include <QComboBox>
#include <QMessageBox>

dialogchoicesyst::dialogchoicesyst(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialogchoicesyst)
{
    ui->setupUi(this);
    DataD=new QDinamicData(this);
    ui->comboBox->addItem("Cистемы");
    ui->comboBox_2->addItem("Снаряды");
    ui->comboBox_3->addItem("Заряды");
    DataD->setComboBoxFromTabl(ui->comboBox,FND,"","","");
    connect(ui->comboBox_3,SIGNAL(activated(int)),this,SIGNAL(exit()));


}

dialogchoicesyst::~dialogchoicesyst()
{
    delete ui;
}





void dialogchoicesyst::on_comboBox_activated(int index)
{
    item=index;
    if(index>0)
    {
        ui->comboBox_2->clear();
        ui->comboBox_2->addItem("Снаряды");
        DataD->setComboBoxFromTabl(ui->comboBox_2,FND,ui->comboBox->itemText(index),"","");
        itemstr=ui->comboBox->itemText(index);
    }
}

void dialogchoicesyst::on_comboBox_2_activated(int index)
{
     item2=index;
    if(index>0)
    {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItem("Заряды");
        DataD->setComboBoxFromTabl(ui->comboBox_3,FND,ui->comboBox->itemText(item),ui->comboBox_2->itemText(index),"");
    item2str=ui->comboBox_2->itemText(index);
    }
}

void dialogchoicesyst::on_comboBox_3_activated(int index)
{
    item3=index;
    if(index>0){
        item3str=ui->comboBox_3->itemText(index);
        this->close();}
}
