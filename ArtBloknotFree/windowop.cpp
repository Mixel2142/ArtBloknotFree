    #include "windowop.h"
#include "ui_windowop.h"

WindowOP::WindowOP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowOP)
{
    ui->setupUi(this);
    this->show();
    Data=new QDinamicData(this,ui->scrollAreaWidgetContents_2);
    SetData();
    ui->lineEdit_2->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_3->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_7->setValidator(new QDoubleValidator(0,999999999,0,this));

    ui->lineEdit_9->setValidator(new QDoubleValidator(0,999999999,0,this));
    ui->lineEdit_10->setValidator(new QDoubleValidator(0,999999999,0,this));
    ui->lineEdit_11->setValidator(new QIntValidator(0,359,this));
    ui->lineEdit_12->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_13->setValidator(new QIntValidator(0,59,this));
    ui->lineEdit_14->setValidator(new QIntValidator(0,200,this));
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->scrollArea);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
}

WindowOP::~WindowOP()
{
    delete ui;
}

void WindowOP::SetData()
{
    int schetchik=0;
    QFile file("/storage/emulated/0/.ArKoData/"+FND);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString str="";
        while(!file.atEnd())
        {
        file.readLine();
        schetchik++;
        }//while
        file.close();
     }//if
    for(int i=0;i<schetchik;i++)Data->AddDataOp(FND,Data->GetData(FND,0,i),Data->GetData(FND,"A:",i),Data->GetData(FND,"B:",i),0,Data->GetData(FND,"D:",i),0,0,0,0,0,1);
}//fun

void WindowOP::on_pushButton_clicked()// записать
{
 Data->AddDataOp(FND,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_13->text()+" P1:"+ui->lineEdit_14->text(),ui->lineEdit_12->text(),ui->lineEdit_7->text()," ",ui->lineEdit_10->text(),ui->lineEdit_9->text(),ui->lineEdit_11->text());
}

void WindowOP::on_pushButton_3_clicked()//очитсить
{
Data->deleteData(FND);
}

void WindowOP::on_pushButton_2_clicked()//Править
{

if(ui->pushButton_2->text()=="Править"){
int ID=-1;
    /////////////////////////////////////////////////

    QCheckBox *chn;
        for(int i = 0; i <  ui->scrollAreaWidgetContents_2->layout()->count(); i++){
        chn=qobject_cast<QCheckBox*>( ui->scrollAreaWidgetContents_2->layout()->itemAt(i)->widget());
        if(chn->isChecked()==true){
    ID=i;
            break;
        }//if
        chn=nullptr;
        }//for из формы удалено и из файла

   //нашли чеканый бокс
        /////////////////////////////////////////////
        if(ID<0)goto endd;
        ui->pushButton_2->setText("Сохранить");
        ui->lineEdit->setText(Data->GetData(FND,0,ID));
         ui->lineEdit_2->setText(Data->GetData(FND,"A:",ID));
          ui->lineEdit_3->setText(Data->GetData(FND,"B:",ID));
           ui->lineEdit_13->setText(Data->GetData(FND,"P:",ID));
           ui->lineEdit_14->setText(Data->GetData(FND,"P1:",ID));
            ui->lineEdit_12->setText(Data->GetData(FND,"D:",ID));
             ui->lineEdit_7->setText(Data->GetData(FND,"E:",ID));

              ui->lineEdit_10->setText(Data->GetData(FND,"J:",ID));
              ui->lineEdit_9->setText(Data->GetData(FND,"K:",ID));
              ui->lineEdit_11->setText(Data->GetData(FND,"L:",ID));
}//if
else{
ui->pushButton_2->setText("Править");
Data->ChangeDataOp(FND,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_13->text(),ui->lineEdit_14->text(),ui->lineEdit_12->text(),ui->lineEdit_7->text()," ",ui->lineEdit_10->text(),ui->lineEdit_9->text(),ui->lineEdit_11->text());
}//else Ошибка при изменении!!! Поля не верно заполняются
endd:
;
}


void WindowOP::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowOP::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_3->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowOP::on_lineEdit_3_returnPressed()
{
    ui->lineEdit_13->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowOP::on_lineEdit_13_returnPressed()
{
    ui->lineEdit_14->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowOP::on_lineEdit_14_returnPressed()
{
    ui->lineEdit_12->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowOP::on_lineEdit_12_returnPressed()
{
    ui->lineEdit_7->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowOP::on_lineEdit_7_returnPressed()
{
    ui->lineEdit_10->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowOP::on_lineEdit_8_returnPressed()
{
    ui->lineEdit_10->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowOP::on_lineEdit_10_returnPressed()
{
    ui->lineEdit_9->setFocus();
    QGuiApplication::inputMethod()->show();

}
