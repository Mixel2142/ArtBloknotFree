#include "windowpgz.h"
#include "ui_windowpgz.h"
#include "QtMath"

WindowPGZ::WindowPGZ(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowPGZ)
{
ui->setupUi(this);
this->show();

ui->label_11->hide();
ui->lineEdit_10->hide();
ui->label_13->hide();
ui->label_12->hide();
    DataD = new QDinamicData(this);
    DataD->setComboBox(ui->comboBox,"Knp.txt");
    ui->comboBox->setItemText(0,"КНП");
    int x = ui->comboBox->count();
    DataD->setComboBox(ui->comboBox,"Op.txt");
    ui->comboBox->setItemText(x,"ОП");
    ui->lineEdit->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_2->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_3->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,59,this));
    ui->lineEdit_6->setValidator(new QIntValidator(-15,15,this));
    ui->lineEdit_7->setValidator(new QDoubleValidator(0,999999999,0,this));
    ui->lineEdit_8->setValidator(new QIntValidator(0,99,this));
    ui->lineEdit_9->setValidator(new QIntValidator(0,99,this));
    ui->lineEdit_17->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_18->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_20->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->scrollArea);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
}

WindowPGZ::~WindowPGZ()
{
    delete ui;
}

void WindowPGZ::on_pushButton_clicked()
{
    if(ui->pushButton_2->text()=="Тысячные")DataD->PGZ(ui->lineEdit_7->text().toDouble(),ui->lineEdit_5->text(),ui->lineEdit_8->text(),ui->lineEdit_6->text(),ui->lineEdit_9->text(),ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
    else DataD->PGZ(ui->lineEdit_7->text().toDouble(),ui->lineEdit_5->text(),ui->lineEdit_8->text(),ui->lineEdit_10->text(),ui->lineEdit_6->text(),ui->lineEdit_9->text(),ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
    ui->lineEdit_17->setText(QString::number(DataD->getPGZX()));
    ui->lineEdit_18->setText(QString::number(DataD->getPGZY()));
    ui->lineEdit_20->setText(QString::number(DataD->getPGZH()));
ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximumHeight());
}

void WindowPGZ::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text() == "Градусы"){

      ui->label_11->hide();
      ui->lineEdit_10->hide();
      ui->label_13->hide();
       ui->label_12->hide();
   ui->pushButton_2->setText("Тысячные");
  ui->label_9->setText("-");
  ui->label_8->setText("-");
  ui->lineEdit_5->setValidator(new QIntValidator(0,59,this));
  ui->lineEdit_6->setValidator(new QIntValidator(-15,15,this));
  ui->lineEdit_8->setValidator(new QIntValidator(0,99,this));
  ui->lineEdit_9->setValidator(new QIntValidator(0,99,this));
    }
    else{
        ui->lineEdit_6->setValidator(new QIntValidator(0,359,this));
        ui->lineEdit_9->setValidator(new QIntValidator(0,59,this));
        ui->label_11->show();
        ui->lineEdit_10->show();
        ui->label_13->show();
 ui->label_12->show();
     ui->pushButton_2->setText("Градусы");
     ui->label_9->setText("°");
      ui->label_8->setText("°");
ui->lineEdit_5->setValidator(new QIntValidator(0,359,this));
      ui->lineEdit_8->setValidator(new QIntValidator(0,59,this));
        ui->lineEdit_10->setValidator(new QIntValidator(0,59,this));
    }

}

void WindowPGZ::on_pushButton_3_clicked()
{
DataD->AddDataPgz(FND,ui->comboBox->itemText(item),ui->lineEdit_17->text(),ui->lineEdit_18->text(),ui->lineEdit_20->text());
}

void WindowPGZ::on_comboBox_activated(int index)
{
    item=index;
    int knp=1;
    int op=1;
     QFile file("/storage/emulated/0/.ArKoData/Knp.txt");
     /*Считываем исходный файл в контейнер*/
     if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
     {
         while(!file.atEnd())
         {
         file.readLine();
          knp++;
         }//while

     }

     file.close();
     file.setFileName("/storage/emulated/0/.ArKoData/Op.txt");
     /*Считываем исходный файл в контейнер*/
     if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
     {
         while(!file.atEnd())
         {
          file.readLine();
          op++;
         }//while

     }
     file.close();

     if(index < knp && index > 0)//выбрали knp.txt
     {
      int InDeX= index-1;
      ui->lineEdit->setText(DataD->GetData("Knp.txt","A:",InDeX));
      ui->lineEdit_2->setText(DataD->GetData("Knp.txt","B:",InDeX));
      ui->lineEdit_3->setText(DataD->GetData("Knp.txt","D:",InDeX));
      ui->lineEdit_7->setText(DataD->GetData("Knp.txt","O:",InDeX));
      if(ui->pushButton_2->text()=="Градусы")on_pushButton_2_clicked();
              ui->lineEdit_5->setText(DataD->GetData("Knp.txt","C:",InDeX));
              ui->lineEdit_8->setText(DataD->GetData("Knp.txt","C1:",InDeX));
     }
     if(index>knp && index<=(op+knp))//выбрали op.txt
     {
      int InDeX= index-knp-1;
      ui->lineEdit->setText(DataD->GetData("Op.txt","A:",InDeX));
      ui->lineEdit_2->setText(DataD->GetData("Op.txt","B:",InDeX));
      ui->lineEdit_3->setText(DataD->GetData("Op.txt","D:",InDeX));
      ui->lineEdit_7->setText(DataD->GetData("Op.txt","O:",InDeX));
      if(ui->pushButton_2->text()=="Градусы")on_pushButton_2_clicked();
              ui->lineEdit_5->setText(DataD->GetData("Op.txt","P:",InDeX));
              ui->lineEdit_8->setText(DataD->GetData("Op.txt","P1:",InDeX));
     }

}

void WindowPGZ::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowPGZ::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_3->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowPGZ::on_lineEdit_5_returnPressed()
{
    ui->lineEdit_8->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowPGZ::on_lineEdit_6_returnPressed()
{
    ui->lineEdit_9->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowPGZ::on_lineEdit_8_returnPressed()
{if(ui->pushButton_2->text()=="Тысячные"){
    ui->lineEdit_6->setFocus();
    QGuiApplication::inputMethod()->show();

    }
    else{
        ui->lineEdit_10->setFocus();
        QGuiApplication::inputMethod()->show();

    }
}

void WindowPGZ::on_lineEdit_10_returnPressed()
{
    ui->lineEdit_6->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowPGZ::on_lineEdit_9_returnPressed()
{
    ui->lineEdit_7->setFocus();
    QGuiApplication::inputMethod()->show();

}
