#include "windowceli.h"
#include "ui_windowceli.h"
#include <QScroller>
#include "dialog.h"
#include <QGraphicsEffect>

WindowCeli::WindowCeli(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::WindowCeli)
{

    ui->setupUi(this);
    DataD=new QDinamicData(this,ui->scrollAreaWidgetContents_7);
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->scrollArea);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
    QAbstractScrollArea *area2=qobject_cast<QAbstractScrollArea*>(ui->scrollArea_2);
    QScroller::grabGesture(area2->viewport(),QScroller::TouchGesture);
    DataD->setComboBox(ui->comboBox_8,"Knp.txt");
    ui->comboBox_8->setItemText(0,"Засечка");
    SetData();

    ui->scrollArea->setMinimumHeight(this->height()/2);
    ui->scrollArea->show();
    this->show();

}
void WindowCeli::SetXY(QString X,QString Y)
{
ui->lineEdit_61->setText(X);ui->lineEdit_62->setText(Y);
}

WindowCeli::~WindowCeli()
{
    delete ui;
}
void WindowCeli::SetData()
{
    int chetchik=0;
    QFile file("/storage/emulated/0/.ArKoData/Celi.txt");
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
            file.readLine();
            chetchik++;
         }//while
        for(int i=0;i<chetchik;i++)DataD->AddDataCeli(DataD->GetData(FND,0,i),0,0,0,DataD->GetData(FND,"A:",i),DataD->GetData(FND,"B:",i),DataD->GetData(FND,"O:",i),true);
    }//if
}
void WindowCeli::on_comboBox_2_activated(int index)
{}
void WindowCeli::on_pushButton_5_clicked()
{}
void WindowCeli::on_pushButton_6_clicked()
{
}
/*
 * 16 57
 * 13 58
 * 14 59
 * 15 60
 * 9  61
 * 11 62
 * 10 63
 * 12 64
 */
void WindowCeli::on_pushButton_4_clicked()
{

}


void WindowCeli::on_pushButton_23_clicked()
{
    if(ui->pushButton_23->text()=="Править"){
    int ID=-1;
        /////////////////////////////////////////////////

        QCheckBox *chn;
            for(int i = 0; i <  ui->scrollAreaWidgetContents_7->layout()->count(); i++){
            chn=qobject_cast<QCheckBox*>( ui->scrollAreaWidgetContents_7->layout()->itemAt(i)->widget());
            if(chn->isChecked()==true){
        ID=i;

                break;
            }//if
            chn=nullptr;
            }//for из формы удалено и из файла

       //нашли чеканый бокс
            /////////////////////////////////////////////
            if(ID<0)goto endd1;
            ui->pushButton_23->setText("Сохранить");

ui->lineEdit_57->setText(DataD->GetData(FND,0,ID));
ui->lineEdit_58->setText(DataD->GetData(FND,"Q:",ID));
ui->lineEdit_59->setText(DataD->GetData(FND,"F:",ID));
ui->lineEdit_60->setText(DataD->GetData(FND,"R:",ID));
ui->lineEdit_61->setText(DataD->GetData(FND,"A:",ID));
ui->lineEdit_62->setText(DataD->GetData(FND,"B:",ID));
ui->lineEdit_63->setText(DataD->GetData(FND,"D:",ID));
    }//if
    else{
    ui->pushButton_23->setText("Править");
    DataD->ChangeDataCeli(ui->lineEdit_57->text(),ui->lineEdit_58->text(),ui->lineEdit_59->text(),ui->lineEdit_60->text(),ui->lineEdit_61->text(),ui->lineEdit_62->text(),ui->lineEdit_63->text());
    }//else
    endd1:
    ;
}

void WindowCeli::on_comboBox_8_activated(int index)
{
    if(index != 0){

         QGraphicsBlurEffect *ef=new QGraphicsBlurEffect();
         ef->setBlurRadius(63);
     ui->scrollArea->setGraphicsEffect(ef);

       ui->scrollArea->setEnabled(false);
        ui->scrollArea_2->setEnabled(false);
        ui->scrollArea->show();
        Dialog *dial;

        dial=new Dialog(this,index);
        dial->exec();
        ui->lineEdit_61->setText(QString::number(dial->GetX()));
        ui->lineEdit_62->setText(QString::number(dial->GetY()));
        ui->lineEdit_63->setText(QString::number(dial->GetH()));
        delete dial;
        ui->scrollArea->setEnabled(true);
         ui->scrollArea_2->setEnabled(true);
         ui->scrollArea->setGraphicsEffect({});
    }
}
void WindowCeli::SetPGZ(QString X,QString Y,QString Height,QString Area)
{



}

void WindowCeli::on_pushButton_22_clicked()
{
DataD->deleteData(FND);
}



void WindowCeli::on_pushButton_24_clicked()
{
    DataD->AddDataCeli(ui->lineEdit_57->text(),ui->lineEdit_58->text(),ui->lineEdit_59->text(),ui->lineEdit_60->text(),ui->lineEdit_61->text(),ui->lineEdit_62->text(),ui->lineEdit_63->text());
}

void WindowCeli::on_lineEdit_57_returnPressed()
{
    ui->lineEdit_58->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowCeli::on_lineEdit_58_returnPressed()
{
    ui->lineEdit_60->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowCeli::on_lineEdit_60_returnPressed()
{
    ui->lineEdit_59->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowCeli::on_lineEdit_59_returnPressed()
{
    ui->lineEdit_61->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowCeli::on_lineEdit_61_returnPressed()
{
    ui->lineEdit_62->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowCeli::on_lineEdit_62_returnPressed()
{
    ui->lineEdit_63->setFocus();
      QGuiApplication::inputMethod()->show();

}
