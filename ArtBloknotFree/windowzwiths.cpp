#include "windowzwiths.h"
#include "ui_windowzwiths.h"


WindowZwithS::WindowZwithS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowZwithS)
{
    ui->setupUi(this);
    this->show();

    DataD=new QDinamicData(this,ui->scrollAreaWidgetContents);
   SetData();//отображаюся CheckBoxs
    DataD->setComboBox(ui->comboBox,"Knp.txt");
    ui->comboBox->setItemText(0,"КНП");
    int x=ui->comboBox->count();
    DataD->setComboBox(ui->comboBox,"Op.txt");
    ui->comboBox->setItemText(x,"ОП");
    ui->lineEdit->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_2->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_3->setValidator(new QDoubleValidator(-999999999,999999999,0,this));
    ui->lineEdit_4->setValidator(new QIntValidator(0,59,this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,99,this));
    ui->lineEdit_6->setValidator(new QDoubleValidator(0,999999999,1000,this));
tmr = new QTimer();
connect(tmr,SIGNAL(timeout()),this,SLOT(updatetime()));
tm1.setHMS(0,0,0,0);
QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->scrollArea);
QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
}

WindowZwithS::~WindowZwithS()
{
    delete tmr;
    delete ui;
   delete DataD;
}

void WindowZwithS::SetData()
{
    int chetchik=0;
    QFile file("/storage/emulated/0/.ArKoData/Sec.txt");
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
            file.readLine();
            chetchik++;
         }//while
        for(int i=0;i<chetchik;i++)if(DataD->GetData(FND,0,i)=="0")DataD->AddDataSec(FND,DataD->GetData(FND,0,i),0,0,0,0,DataD->GetData(FND,"O:",i),true);
    }//if
}



void WindowZwithS::on_pushButton_4_clicked()
{

    if(ui->pushButton_4->text()== "Пуск")
    {
        tm1.setHMS(0,0,0,0);
         tmr->start(100);
        ui->pushButton_4->setText("Стоп");
    tm1=tm1.currentTime();
    }
    else if(ui->pushButton_4->text()== "Стоп")
    {
       ui->lineEdit_6->setText(QString::number(RaznostT(tm1.currentTime(),tm1)));
        tmr->stop();
       double T,t;
        double distance;
        if(ui->lineEdit->text().isEmpty())T=20;
        else T = ui->lineEdit->text().toDouble();
        double C = 20.041574962*sqrt((T+273.15));//скорость звука в воздухе
        if(!ui->lineEdit_6->text().isEmpty()){
            t = ui->lineEdit_6->text().toDouble();
            distance = C*t;//Расчитанное растояние
            DataD->AddDataSec(FND,GetNameComboBox(),0,0,0,0,QString::number(distance));
        }//if
         ui->pushButton_4->setText("Пуск");
    }
    else{//Решить
        double T,t;
        double distance;
        if(ui->lineEdit->text().isEmpty())T=20;
        else T = ui->lineEdit->text().toDouble();
        double C = 20.041574962*sqrt((T+273.15));//скорость звука в воздухе
        if(!ui->lineEdit_6->text().isEmpty()){
            t = ui->lineEdit_6->text().toDouble();
            distance = C*t;//Расчитанное растояние
            DataD->AddDataSec(FND,GetNameComboBox(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),QString::number(distance));
        }//if
         ui->pushButton_4->setText("Пуск");

    }//else

}
void WindowZwithS::updatetime()
{
ui->lineEdit_6->setText(QString::number(RaznostT(tm1.currentTime(),tm1)));
}

double WindowZwithS::RaznostT(QTime t1, QTime t2)//возращает секунды и ошибка 1 раз в день
{
 double dt1= t1.hour()*360+t1.minute()*60+t1.second()+(double)t1.msec()/1000.0;
 double dt2= t2.hour()*360+t2.minute()*60+t2.second()+(double)t2.msec()/1000.0;
 if(t1>t2) return dt1-dt2;
 else return  (11881-dt2)+dt1;
}

void WindowZwithS::on_pushButton_3_clicked()
{
        QCheckBox *chn;
        double MID=0;
        int scshetchik=0;
        QString name="";
            for(int i = 0; i <  ui->scrollAreaWidgetContents->layout()->count(); i++){
            chn=qobject_cast<QCheckBox*>( ui->scrollAreaWidgetContents->layout()->itemAt(i)->widget());
            if(chn->isChecked()==true){
                scshetchik++; 
               MID+=chn->text().right(chn->text().length()-chn->text().indexOf(':')-1).toDouble();
               name=chn->text().left(chn->text().indexOf(' ',chn->text().indexOf(' ')+1)).remove(0,chn->text().indexOf(" ")+1);

            }//if
            chn=nullptr;
            }//for
            if(scshetchik>0){
            DataD->deleteData(FND);//из формы удалено и из файла
    MID=MID/scshetchik;
    DataD->AddDataSec(FND,name,ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),QString::number(MID));
            }//if
       //нашли чеканые боксы
//////////////////////////////////////////////////////////////
}

void WindowZwithS::on_pushButton_clicked()//delete
{

DataD->deleteData(FND);
}

void WindowZwithS::on_pushButton_2_clicked()
{
    /*
    double R=8.314459848;//Универсальная газовая постоянная
    double Y=7.0/5.0;
    double M=28.98;//грамм/моль
    double T;//температура в Градусах
    double A=0.6337702478;
    double a =sqrt((Y*R)/M);
*/

}

void WindowZwithS::on_comboBox_activated(int index)
{item=index;
    if(DataD->str_WhoComboBoxActive(item)!= "0"){
DataD->DeleteAllChekcBox();
SetComboBoxFor(GetNameComboBox(index));
ui->label_7->setText(GetNameComboBox(index)+" Дальность:"+DataD->GetData(DataD->str_WhoComboBoxActive(index)," O:",DataD->WhoComboBoxActive(index,DataD->WhoComboBoxActive(index)))+" ");
ui->lineEdit_2->setText(DataD->GetData(DataD->str_WhoComboBoxActive(index),"A:",DataD->WhoComboBoxActive(index,DataD->WhoComboBoxActive(index))));
ui->lineEdit_3->setText(DataD->GetData(DataD->str_WhoComboBoxActive(index),"B:",DataD->WhoComboBoxActive(index,DataD->WhoComboBoxActive(index))));
ui->lineEdit_4->setText(DataD->GetData(DataD->str_WhoComboBoxActive(index),"C:",DataD->WhoComboBoxActive(index,DataD->WhoComboBoxActive(index))));
ui->lineEdit_4->setText(DataD->GetData(DataD->str_WhoComboBoxActive(index),"C1:",DataD->WhoComboBoxActive(index,DataD->WhoComboBoxActive(index))));
    }
}//очень тяжело, но коротко

void WindowZwithS::on_pushButton_5_clicked()
{
     double dstnc=0;
    QCheckBox* chn;
    QString numbr="";
    for(int i = 0; i <  ui->scrollAreaWidgetContents->layout()->count(); i++){
    chn=qobject_cast<QCheckBox*>( ui->scrollAreaWidgetContents->layout()->itemAt(i)->widget());
    if(chn->isChecked()==true){
      for(int k=0;k<chn->text().length();k++)
      {
       if(chn->text().at(k)==":")
           for(int g=1;g < chn->text().length()-k;g++)
           {
            if(!chn->text().at(k+g).isSpace())numbr+=chn->text().at(k+g);
            else{
              dstnc=chn->text().right(chn->text().length()-chn->text().indexOf(':')-1).toDouble();
                chn->setChecked(false); goto next;}
           }
      }
     QString str="";
     QString DT="O:";
     QString distance="";
     str=chn->text();
     chn->setStyleSheet("front: rgb(10,230,10)");
     //Found{
     int key=0;
     for(int i=0;i < str.length()-DT.length();i++)
     {
     if(key==DT.length()){
         key=0;
        for(int j=0;j<str.length();j++){
        if(!str.at(i+DT.length()+j-1).isSpace())distance+=str.at(i+DT.length()+j-1);
        else { goto endFound;}//нашли длину числа и её позицию
        }
                         }//if
     else {
         key=0;
         for(int j=0;j<DT.length();j++)
     {
         if(str.at(i+j)==DT.at(j))key++;
     }//for
         }//else

     }//for
     //}Found
      endFound:

     ui->label_7->setText(GetNameComboBox(item)+" Дальность:"+distance+" ");

     goto end;
    }//if
    chn=nullptr;
    }//for
    next:
    if(DataD->str_WhoComboBoxActive(item)!="0")//выбрали КНП или ОП (нужно изменить файл КНП или ОП)
    {
      DataD->Change_Add_Data(DataD->str_WhoComboBoxActive(item),DataD->WhoComboBoxActive(item,DataD->WhoComboBoxActive(item)),"O:",numbr);
     ///////////////////////////решение ПГЗ
    double dstnc=  DataD->GetData(DataD->str_WhoComboBoxActive(item),"O:",DataD->WhoComboBoxActive(item,DataD->WhoComboBoxActive(item))).toDouble();
    double napr=(ui->lineEdit_4->text().toDouble()+(ui->lineEdit_5->text().toDouble()/100))*6;
    double delX =dstnc*cos(napr*(M_PI/180));
    if(fabs(delX)<0.0000001)delX=0;
    double delY = dstnc*sin(napr*(M_PI/180));
    if(fabs(delY)<0.0000001)delY=0;
      ///////////////////////////решение ПГЗ
      QString dal=DataD->GetData(DataD->str_WhoComboBoxActive(item),"O:",DataD->WhoComboBoxActive(item,DataD->WhoComboBoxActive(item))).left(DataD->GetData(DataD->str_WhoComboBoxActive(item),"O:",DataD->WhoComboBoxActive(item,DataD->WhoComboBoxActive(item))).indexOf('.'));
     // ui->label_7->setText(GetNameComboBox(item)+" Дальность:"+dal+" X:"+QString::number(delX + ui->lineEdit_2->text().toDouble())+" Y:"+QString::number(delY+ui->lineEdit_3->text().toDouble()));
      ui->label_7->setText(" Дальность:"+dal+" X:"+QString::number(delX + ui->lineEdit_2->text().toDouble())+" Y:"+QString::number(delY+ui->lineEdit_3->text().toDouble()));

    }
    else{


         double napr=(ui->lineEdit_4->text().toDouble()+(ui->lineEdit_5->text().toDouble()/100))*6;
         double delX =dstnc*cos(napr*(M_PI/180));
         if(fabs(delX)<0.0000001)delX=0;
         double delY = dstnc*sin(napr*(M_PI/180));
         if(fabs(delY)<0.0000001)delY=0;
           ///////////////////////////решение ПГЗ
           ui->label_7->setText(" Дальность:"+QString::number(dstnc)+" X:"+QString::number(delX + ui->lineEdit_2->text().toDouble())+" Y:"+QString::number(delY+ui->lineEdit_3->text().toDouble()));


    }
end:
    ;
}


void WindowZwithS::on_lineEdit_6_textEdited(const QString &arg1)
{
    if(!ui->lineEdit_6->text().isEmpty())ui->pushButton_4->setText("Решить");
    else ui->pushButton_4->setText("Пуск");
}

void WindowZwithS::on_lineEdit_6_editingFinished()
{

}
QString WindowZwithS::GetNameComboBox(int num)//
{
    int TM=item;
    if(num>0)TM=num;
    QString name="";
    for(int i=0;i< ui->comboBox->itemText(TM).length();i++)
    {
        if(ui->comboBox->itemText(TM).at(i)==":"){i++;
            for(int j=i;j < ui->comboBox->itemText(TM).length();j++)
            {
                if(!ui->comboBox->itemText(TM).at(j).isSpace())name+=ui->comboBox->itemText(TM).at(j);
                else return name;
            }}
    }//for
    return "0";

}
void WindowZwithS::SetComboBoxFor(QString name)//
{

    QFile file("/storage/emulated/0/.ArKoData/Knp.txt");
   if(file.open(QIODevice::ReadOnly)){
    int i=-1;
    while(!file.atEnd())
    {
     i++;
    file.readLine();
   if(DataD->GetData("Knp.txt",0,i) == name){
    DataD->AddDataSec(FND,name,0,0,0,0,DataD->GetData("Knp.txt","O:",i),true);
    }
    }
    file.close();
    }

  QFile file1("/storage/emulated/0/.ArKoData/Op.txt");
  if(file1.open(QIODevice::ReadOnly)){
   int i=-1;
   while(!file1.atEnd())
   {
    i++;
   file1.readLine();
   if(DataD->GetData("Op.txt",0,i)==name){
  DataD->AddDataSec(FND,name,0,0,0,0,DataD->GetData("Op.txt","O:",i),true);
   }
   }
   file1.close();
   }

  QFile file2("/storage/emulated/0/.ArKoData/Sec.txt");
  if(file2.open(QIODevice::ReadOnly)){
   int i=-1;
   while(!file2.atEnd())
   {
    i++;
   file2.readLine();
   if(DataD->GetData("Sec.txt",0,i)==name){
  DataD->AddDataSec(FND,name,0,0,0,0,DataD->GetData("Sec.txt","O:",i),true);
   }
   }
   file2.close();
   }
SetData();
}



void WindowZwithS::on_comboBox_activated(const QString &arg1)
{

}

void WindowZwithS::on_lineEdit_2_selectionChanged()
{

}

void WindowZwithS::on_lineEdit_4_textChanged(const QString &arg1)
{
    if(arg1.length()>=2){ui->lineEdit_5->setFocus();}

}

void WindowZwithS::on_lineEdit_4_returnPressed()
{
    ui->lineEdit_5->setFocus();
    QGuiApplication::inputMethod()->show();
    ui->lineEdit_5->selectAll();
}

void WindowZwithS::on_pushButton_6_clicked()
{
    double dstnc=0;
   QCheckBox* chn;
   QString numbr="";
   for(int i = 0; i <  ui->scrollAreaWidgetContents->layout()->count(); i++){
   chn=qobject_cast<QCheckBox*>( ui->scrollAreaWidgetContents->layout()->itemAt(i)->widget());
   if(chn->isChecked()==true){
     for(int k=0;k<chn->text().length();k++)
     {
      if(chn->text().at(k)==":")
          for(int g=1;g < chn->text().length()-k;g++)
          {
           if(!chn->text().at(k+g).isSpace())numbr+=chn->text().at(k+g);
           else{
             dstnc=chn->text().right(chn->text().length()-chn->text().indexOf(':')-1).toDouble();
               chn->setChecked(false); goto next;}
          }
     }
    QString str="";
    QString DT="O:";
    QString distance="";
    str=chn->text();
    chn->setStyleSheet("front: rgb(10,230,10)");
    //Found{
    int key=0;
    for(int i=0;i < str.length()-DT.length();i++)
    {
    if(key==DT.length()){
        key=0;
       for(int j=0;j<str.length();j++){
       if(!str.at(i+DT.length()+j-1).isSpace())distance+=str.at(i+DT.length()+j-1);
       else { goto endFound;}//нашли длину числа и её позицию
       }
                        }//if
    else {
        key=0;
        for(int j=0;j<DT.length();j++)
    {
        if(str.at(i+j)==DT.at(j))key++;
    }//for
        }//else

    }//for
    //}Found
     endFound:

    ui->label_7->setText(GetNameComboBox(item)+" Дальность:"+distance+" ");

    goto end;
   }//if
   chn=nullptr;
   }//for
   next:
   if(DataD->str_WhoComboBoxActive(item)!="0")//выбрали КНП или ОП (нужно изменить файл КНП или ОП)
   {
     DataD->Change_Add_Data(DataD->str_WhoComboBoxActive(item),DataD->WhoComboBoxActive(item,DataD->WhoComboBoxActive(item)),"O:",numbr);
    ///////////////////////////решение ПГЗ
   double dstnc=  DataD->GetData(DataD->str_WhoComboBoxActive(item),"O:",DataD->WhoComboBoxActive(item,DataD->WhoComboBoxActive(item))).toDouble();
   double napr=(ui->lineEdit_4->text().toDouble()+(ui->lineEdit_5->text().toDouble()/100))*6;
   double delX =dstnc*cos(napr*(M_PI/180));
   if(fabs(delX)<0.0000001)delX=0;
   double delY = dstnc*sin(napr*(M_PI/180));
   if(fabs(delY)<0.0000001)delY=0;
     ///////////////////////////решение ПГЗ
     QString dal=DataD->GetData(DataD->str_WhoComboBoxActive(item),"O:",DataD->WhoComboBoxActive(item,DataD->WhoComboBoxActive(item))).left(DataD->GetData(DataD->str_WhoComboBoxActive(item),"O:",DataD->WhoComboBoxActive(item,DataD->WhoComboBoxActive(item))).indexOf('.'));
    // ui->label_7->setText(GetNameComboBox(item)+" Дальность:"+dal+" X:"+QString::number(delX + ui->lineEdit_2->text().toDouble())+" Y:"+QString::number(delY+ui->lineEdit_3->text().toDouble()));
     ui->label_7->setText(" Дальность:"+dal+" X:"+QString::number(delX + ui->lineEdit_2->text().toDouble())+" Y:"+QString::number(delY+ui->lineEdit_3->text().toDouble()));
     WindowCeli *Celi=new WindowCeli(this);
  Celi->SetXY(QString::number(delX + ui->lineEdit_2->text().toDouble()),QString::number(delY+ui->lineEdit_3->text().toDouble()));
   }
   else{


        double napr=(ui->lineEdit_4->text().toDouble()+(ui->lineEdit_5->text().toDouble()/100))*6;
        double delX =dstnc*cos(napr*(M_PI/180));
        if(fabs(delX)<0.0000001)delX=0;
        double delY = dstnc*sin(napr*(M_PI/180));
        if(fabs(delY)<0.0000001)delY=0;
          ///////////////////////////решение ПГЗ
          ui->label_7->setText(" Дальность:"+QString::number(dstnc)+" X:"+QString::number(delX + ui->lineEdit_2->text().toDouble())+" Y:"+QString::number(delY+ui->lineEdit_3->text().toDouble()));
          WindowCeli *Celi=new WindowCeli(this);
       Celi->SetXY(QString::number(delX + ui->lineEdit_2->text().toDouble()),QString::number(delY+ui->lineEdit_3->text().toDouble()));
   }
end:
   ;
}

void WindowZwithS::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowZwithS::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_3->setFocus();
    QGuiApplication::inputMethod()->show();

}

void WindowZwithS::on_lineEdit_3_returnPressed()
{
    ui->lineEdit_4->setFocus();
    QGuiApplication::inputMethod()->show();

}
