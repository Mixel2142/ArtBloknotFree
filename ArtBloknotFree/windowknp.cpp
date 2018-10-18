#include "windowknp.h"
#include "ui_windowknp.h"

WindowKNP::WindowKNP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowKNP)
{
    ui->setupUi(this);
    this->show();
 Data=new QDinamicData(this,ui->scrollAreaWidgetContents);
 SetData();
    ui->lineEdit_2->setValidator(new QDoubleValidator(0,999999999,0,this));
    ui->lineEdit_3->setValidator(new QDoubleValidator(0,999999999,0,this));
    ui->lineEdit_4->setValidator(new QDoubleValidator(0,999999999,0,this));
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->scrollArea);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
}

WindowKNP::~WindowKNP()
{
    delete ui;
}

void WindowKNP::SetData()
{
    int schetchik=0;
    QFile file("/storage/emulated/0/.ArKoData/"+FND);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {

        while(!file.atEnd())
        {
          file.readLine();
          schetchik++;
        }//while
        }//if
for(int i=0;i<schetchik;i++)Data->AddDataKnp(FND,Data->GetData(FND,0,i),Data->GetData(FND,"A:",i),Data->GetData(FND,"B:",i),Data->GetData(FND,"D:",i),1);
}
void WindowKNP::on_pushButton_2_clicked()
{
   Data->AddDataKnp(FND,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
}

void WindowKNP::on_pushButton_clicked()
{
    Data->deleteData(FND);
}

void WindowKNP::on_pushButton_3_clicked()//править
{

    if(ui->pushButton_3->text()=="Править"){
    int ID=-1;
        /////////////////////////////////////////////////

        QCheckBox *chn;
            for(int i = 0; i <  ui->scrollAreaWidgetContents->layout()->count(); i++){
            chn=qobject_cast<QCheckBox*>( ui->scrollAreaWidgetContents->layout()->itemAt(i)->widget());
            if(chn->isChecked()==true){
        ID=i;

                break;
            }//if
            chn=nullptr;
            }//for из формы удалено и из файла

       //нашли чеканый бокс
            /////////////////////////////////////////////
            if(ID<0)goto endd1;
            ui->pushButton_3->setText("Сохранить");

ui->lineEdit->setText(Data->GetData(FND,0,ID));
ui->lineEdit_2->setText(Data->GetData(FND,"A:",ID));
ui->lineEdit_3->setText(Data->GetData(FND,"B:",ID));
ui->lineEdit_4->setText(Data->GetData(FND,"D:",ID));
    }//if
    else{
    ui->pushButton_3->setText("Править");
    Data->ChangeDataKnp(FND,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
    }//else
    endd1:
    ;
}

void WindowKNP::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowKNP::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_3->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowKNP::on_lineEdit_3_returnPressed()
{
    ui->lineEdit_4->setFocus();
      QGuiApplication::inputMethod()->show();

}
