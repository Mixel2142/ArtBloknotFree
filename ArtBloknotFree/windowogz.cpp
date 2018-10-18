#include "windowogz.h"
#include "ui_windowogz.h"

WindowOGZ::WindowOGZ(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowOGZ)
{
    ui->setupUi(this);
    this->show();
    DataD=new QDinamicData(this);
    ui->comboBox->addItem("Точка1");
    ui->comboBox_2->addItem("Точка2");
    DataD->setComboBox(ui->comboBox,"Knp.txt");
    ui->comboBox->setItemText(1,"КНП");
    int x = ui->comboBox->count();
    DataD->setComboBox(ui->comboBox,"Op.txt");
    ui->comboBox->setItemText(x,"OП");
    DataD->setComboBox(ui->comboBox_2,"Knp.txt");
    ui->comboBox_2->setItemText(1,"КНП");
    DataD->setComboBox(ui->comboBox_2,"Op.txt");
    ui->comboBox_2->setItemText(x,"OП");
    ui->comboBox_2->setItemText(0,"Точка2");
    ui->lineEdit->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_3->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_2->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_3->setValidator(new QDoubleValidator(-999999999,999999999,0,this));

    ui->lineEdit_5->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_6->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_8->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->scrollArea);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);

}

WindowOGZ::~WindowOGZ()
{
    delete ui;
}

void WindowOGZ::on_comboBox_activated(int index)
{ item1=index-1;
    if(DataD->str_WhoComboBoxActive(item1)!= "0"){

      ui->lineEdit->setText(DataD->GetData(DataD->str_WhoComboBoxActive(item1),"A:",DataD->WhoComboBoxActive(item1,DataD->WhoComboBoxActive(item1))));
      ui->lineEdit_2->setText(DataD->GetData(DataD->str_WhoComboBoxActive(item1),"B:",DataD->WhoComboBoxActive(item1,DataD->WhoComboBoxActive(item1))));
      ui->lineEdit_3->setText(DataD->GetData(DataD->str_WhoComboBoxActive(item1),"D:",DataD->WhoComboBoxActive(item1,DataD->WhoComboBoxActive(item1))));
      }

}

void WindowOGZ::on_comboBox_activated(const QString &arg1)
{

}

void WindowOGZ::on_comboBox_2_activated(int index)
{
    item2=index-1;
      if(DataD->str_WhoComboBoxActive(item2)!= "0"){

    ui->lineEdit_5->setText(DataD->GetData(DataD->str_WhoComboBoxActive(item2),"A:",DataD->WhoComboBoxActive(item2,DataD->WhoComboBoxActive(item2))));
    ui->lineEdit_6->setText(DataD->GetData(DataD->str_WhoComboBoxActive(item2),"B:",DataD->WhoComboBoxActive(item2,DataD->WhoComboBoxActive(item2))));
    ui->lineEdit_8->setText(DataD->GetData(DataD->str_WhoComboBoxActive(item2),"D:",DataD->WhoComboBoxActive(item2,DataD->WhoComboBoxActive(item2))));
        }
}

void WindowOGZ::on_pushButton_clicked()
{
    DataD->OGZ(ui->lineEdit->text().toDouble(),ui->lineEdit_2->text().toDouble(),ui->lineEdit_5->text().toDouble(),ui->lineEdit_6->text().toDouble());
    ui->lineEdit_11->setText(QString::number(DataD->getOGZdistance()));//расстояние между точками

  double dir2=DataD->getOGZdirTis();
QString str=QString::number(dir2,'d',2);
 ui->lineEdit_10->setText(str.left(str.indexOf(".")));
 str=str.right(str.length()-str.indexOf(".")-1);
 ui->lineEdit_9->setText(str);


double uglmst=((ui->lineEdit_8->text().toDouble()-ui->lineEdit_3->text().toDouble())/(0.001*DataD->getOGZdistance()))/100.0;
double ugl=uglmst;
ui->lineEdit_12->setText(QString::number(ugl).left(QString::number(ugl).indexOf('.')));
ui->lineEdit_13->setText(QString::number(ugl,'d',2).right(QString::number(ugl,'d',2).length()-QString::number(ugl,'d',2).indexOf('.')-1));
ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->maximumHeight());
}

void WindowOGZ::on_pushButton_2_clicked()
{
    //DataD->New_Change_Add_Data();//Кирилл??? ОГЗ и угол места зачем там
}

void WindowOGZ::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowOGZ::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_3->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowOGZ::on_lineEdit_5_returnPressed()
{
    ui->lineEdit_6->setFocus();
      QGuiApplication::inputMethod()->show();

}

void WindowOGZ::on_lineEdit_6_returnPressed()
{
    ui->lineEdit_8->setFocus();
      QGuiApplication::inputMethod()->show();

}
