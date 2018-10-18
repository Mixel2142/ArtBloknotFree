#include "windowogn.h"
#include "ui_windowogn.h"
#include <QMessageBox>

WindowOgn::WindowOgn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowOgn)
{
    ui->setupUi(this);
    this->show();

    DataD=new QDinamicData(this);
    DataD->setComboBox(ui->comboBox,"Op.txt");
    ui->comboBox->setItemText(0,"ОП");
    DataD->setComboBox(ui->comboBox_2,"Knp.txt");
    ui->comboBox_2->setItemText(0,"Засечка");
     DataD->setComboBox(ui->comboBox_3,"Celi.txt");
     ui->comboBox_3->setItemText(0,"Цели");
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->scrollArea);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
    dial=new NEWDIALOG(this);
    disys=new dialogchoicesyst(this);
    connect(dial,SIGNAL(click_2()),this,SLOT(ClickCount()));
    connect(dial,SIGNAL(click_1()),this,SLOT(ClickCancle()));
    connect(disys,SIGNAL(exit()),this,SLOT(exit2()));
    ui->comboBox->setStyleSheet("background-color: rgb(230,200,200)");
    ui->comboBox_2->setStyleSheet("background-color: rgb(230,200,200)");
    ui->comboBox_3->setStyleSheet("background-color: rgb(230,200,200)");
}

WindowOgn::~WindowOgn()
{
    delete ui;
}
 void WindowOgn::exit2()
{

     ui->pushButton_2->setText(disys->itemstr.left(4)+"|"+disys->item2str.left(4)+"|"+disys->item3str.left(4));
}
void WindowOgn::on_comboBox_activated(int index)
{
    if(index != 0){
item=index;
ui->comboBox->setStyleSheet("background-color: rgb(200,230,200)");
    }
    else ui->comboBox->setStyleSheet("background-color: rgb(230,200,200)");

}

void WindowOgn::on_comboBox_2_activated(int index)
{

    if(index != 0){
        item2=index;
      //  QGraphicsBlurEffect *ef=new QGraphicsBlurEffect();
    //    ef->setBlurRadius(10);
//    ui->scrollArea->setGraphicsEffect(ef);

  //    ui->scrollArea->setEnabled(false);
 //      ui->scrollArea->show();

      dial->Setup(index);
      dial->show();
    //  QMessageBox msgb;
    //  msgb.setText("ComBox");
   //   msgb.exec();
     /*
       // while(dial->flag == -1);
       if(dial->flag !=0){
       ui->lineEdit_6->setText(QString::number(dial->GetX()));
       ui->lineEdit_5->setText(QString::number(dial->GetY()));
       ui->lineEdit_3->setText(QString::number(dial->GetH()));
       }
       delete dial;
       ui->scrollArea->setEnabled(true);
        ui->scrollArea->setGraphicsEffect({});
  */
      ui->comboBox_2->setStyleSheet("background-color: rgb(200,230,200)");
          }
         else  ui->comboBox_2->setStyleSheet("background-color: rgb(230,200,200)");

}

void WindowOgn::on_comboBox_3_activated(int index)
{
    if(index != 0){
        item3=index;
          ui->lineEdit->setText( DataD->GetData("Celi.txt","Q:",index-1));
        ui->lineEdit_6->setText( DataD->GetData("Celi.txt","A:",index-1));
         ui->lineEdit_5->setText(DataD->GetData("Celi.txt","B:",index-1));
         ui->lineEdit_3->setText(DataD->GetData("Celi.txt","D:",index-1));
       ui->lineEdit_2->setText(DataD->GetData("Celi.txt","F:",index-1));
        ui->lineEdit_4->setText(DataD->GetData("Celi.txt","R:",index-1));
          ui->comboBox_3->setStyleSheet("background-color: rgb(200,230,200)");
              }
              else ui->comboBox_3->setStyleSheet("background-color: rgb(230,200,200)");
}

void WindowOgn::on_pushButton_clicked()
{
    if(item > 0){
        QString HTML="";
        QString HTMLpost="";
        QString HTMLpost2="";
        double alphaceli=0;
        QString alphacelistr="";
        double uglPS=0;
        QString uglPSstr="";
        double SHu=0;
        QString Shustr="";
QString Ku="";
    DataD->OGZ(DataD->GetData("Op.txt","A:",item-1).toDouble(),DataD->GetData("Op.txt","B:",item-1).toDouble(),ui->lineEdit_6->text().toDouble(),ui->lineEdit_5->text().toDouble());// зачем тут ещё высота в ОГЗ
    double distanceOpToCeli=DataD->getOGZdistance();
    QString dalstr=QString::number(DataD->getOGZdistance());

//if(DataD->getOGZdistance() > DataD->GetData("Op.txt","K:",item-1).toDouble() && DataD->getOGZdistance() < DataD->GetData("Op.txt","J:",item-1).toDouble())
 //   {
double OP=(DataD->GetData("Op.txt","P:",item-1).toDouble()*100)+DataD->GetData("Op.txt","P1:",item-1).toDouble();
QString dovceltop= QString::number((DataD->getOGZnapr()-OP)/100,'d',2);
if((DataD->getOGZnapr()-OP)>0){dovceltop="+"+dovceltop.left(dovceltop.indexOf('.'))+"-"+dovceltop.right(dovceltop.length()-dovceltop.indexOf('.')-1);}
else {dovceltop=dovceltop.left(dovceltop.indexOf('.'))+"-"+dovceltop.right(dovceltop.length()-dovceltop.indexOf('.')-1);}

HTML.append("<p style=' margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; '>Д<span style=' vertical-align:super;'>ц</span><span style=' vertical-align:sub;'>т</span>=" + dalstr+" ∂<span style=' vertical-align:super;'>ц</span><span style=' vertical-align:sub;'>т</span>= OH"+dovceltop);
QString strDalCI="";
QString strDovCI="";

InterpolPoDal(DataD->getOGZdistance());
strDalCI=QString::number(DataD->getOGZdistance()+sredDalCI);
QString str1=QString::number((((DataD->getOGZnapr()-OP))+sredDovCI)/100,'d',2);
if(str1.toDouble()>0) strDovCI="ОН+"+str1.left(str1.indexOf('.'))+"-"+str1.right(str1.length()-str1.indexOf('.')-1);
else strDovCI="ОН"+str1.left(str1.indexOf('.'))+"-"+str1.right(str1.length()-str1.indexOf('.')-1);
QString HtmlDalCI=strDalCI;
for(int i=0;i<InterpolPoDal(DataD->getOGZdistance());i++)
{
    HtmlDalCI.append("!");
    HtmlDalCI.append("!");
}
double Ur= (ui->lineEdit_3->text().toDouble()-DataD->GetData("Op.txt","D:",item-1).toDouble())*1000.0/dalstr.toDouble();
Ur+=3000;Ur/=100;
QString strUr=QString::number(Ur,'d',2).left(QString::number(Ur,'d',2).indexOf('.'))+"-"+QString::number(Ur,'d',2).right(QString::number(Ur,'d',2).length()-QString::number(Ur,'d',2).indexOf('.')-1);
HTMLpost.append("<p style=' margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; '> Д<span style=' vertical-align:super;'>ц</span><span style=' vertical-align:sub;'>и</span>=" + HtmlDalCI+" ∂<span style=' vertical-align:super;'>ц</span><span style=' vertical-align:sub;'>и</span>="+strDovCI+" Ур=" + strUr +" </p>");
alphaceli=DataD->getOGZnapr();
alphacelistr=DataD->getOGZnaprstr();
HTML.append(" α</span><span style=' vertical-align:sub;'>ц</span>=" + alphacelistr + " </p>");

if(item2>0){
DataD->OGZ(DataD->GetData("Knp.txt","A:",item2-1).toDouble(),DataD->GetData("Knp.txt","B:",item2-1).toDouble(),ui->lineEdit_6->text().toDouble(),ui->lineEdit_5->text().toDouble());
double distanceKnpToCeli=DataD->getOGZdistance();
Ku=QString::number(distanceKnpToCeli/dalstr.toDouble(),'d',2);

double naprKnpToCeli=0;
if(DataD->getOGZnapr()>3000)naprKnpToCeli=DataD->getOGZnapr()-3000;
else naprKnpToCeli=DataD->getOGZnapr()+ 3000;
if(alphaceli>3000)alphaceli-=3000;
else alphaceli+=3000;
uglPS=fabs(naprKnpToCeli-alphaceli);
uglPSstr=QString::number((uglPS/100),'d',2);
uglPSstr=uglPSstr.left(uglPSstr.indexOf('.'))+"-"+uglPSstr.right(uglPSstr.length()-uglPSstr.indexOf('.')-1);
if(uglPS>500)uglPSstr.append("!");
SHu=(uglPS/(0.01*distanceOpToCeli))/100;
Shustr=QString::number(SHu,'d',2).left(QString::number(SHu,'d',2).indexOf('.'))+"-"+QString::number(SHu,'d',2).right(QString::number(SHu,'d',2).length()-QString::number(SHu,'d',2).indexOf('.')-1);
HTMLpost2.append( "<p style=' margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>К</span><span style=' vertical-align:sub;'>у</span>=" + Ku+" Ш</span><span style=' vertical-align:sub;'>у</span>="+Shustr);
if(ui->pushButton_2->text() != "Выбор сист." && DataD->ChoicePricel(disys->itemstr))
{
if((int)Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,strDalCI.toDouble()),3) == (int)Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,dalstr.toDouble()),3))HTMLpost2.append(" ∆Х<span style=' vertical-align:sub;'>тыс</span>="+QString::number(Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,strDalCI.toDouble()),3)));
else HTMLpost2.append(" ∆Х<span style=' vertical-align:super;'>и</span><span style=' vertical-align:sub;'>тыс</span>="+QString::number(Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,strDalCI.toDouble()),3))+" ∆Х<span style=' vertical-align:super;'>т</span><span style=' vertical-align:sub;'>тыс</span>="+QString::number(Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,dalstr.toDouble()),3)));
}
    else if(ui->pushButton_2->text() != "Выбор сист.")
{

 if((int)Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,strDalCI.toDouble()),3) == (int)Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,dalstr.toDouble()),3))HTMLpost2.append(" ∆П="+QString::number(Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,strDalCI.toDouble()),3))+"</p>");
    else HTMLpost2.append(" ∆П<span style=' vertical-align:sub;'>и</span>="+QString::number(Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,strDalCI.toDouble()),3))+" ∆П<span style=' vertical-align:sub;'>т</span>="+QString::number(Number(DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,dalstr.toDouble()),3))+"</p>");
}
HTMLpost2.append("<p style=' margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>ПС="+uglPSstr);
}
double Iv=0;
QString Ivstr="";
if(item3>0 && ui->lineEdit_2->text()!="" ){

Iv=ui->lineEdit_2->text().toDouble()/(DataD->GetData("Op.txt","E:",item-1).toDouble()*0.001*distanceOpToCeli)/100;
Ivstr=QString::number(Iv,'d',2).left(QString::number(Iv,'d',2).indexOf('.'))+"-"+QString::number(Iv,'d',2).right(QString::number(Iv,'d',2).length()-QString::number(Iv,'d',2).indexOf('.')-1);
HTMLpost2.append(" I</span><span style=' vertical-align:sub;'>в</span>=" + Ivstr+"</p>");
}

if(ui->pushButton_2->text() != "Выбор сист." && DataD->ChoicePricel(disys->itemstr))
{
/*
 *if(ChoicePricel == true)
        ui->label_3->setText("Птыс:");
        ui->label_7->setText(" ∆Хтыс:");

    }
else{
        ui->label_3->setText("П:");
        ui->label_7->setText(" ∆П:");


*/
    QString Tablstr=DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,strDalCI.toDouble());
    double razn=fabs(strDalCI.toDouble()-Number(Tablstr,1));
  //  qDebug()<<"strDalCI.toDouble()="+QS
    razn=razn/Number(Tablstr,3);
    double PrCI=0;
    if(strDalCI.toDouble()>Number(Tablstr,1))PrCI=Number(Tablstr,2)+razn;
    else PrCI=Number(Tablstr,2)-razn;

    Tablstr="";
    Tablstr=DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,dalstr.toDouble());
    double raznCT=fabs(dalstr.toDouble()-Number(Tablstr,1));
    raznCT=raznCT/Number(Tablstr,3);
    double PrCT=0;
    if(dalstr.toDouble()>Number(Tablstr,1))PrCT=Number(Tablstr,2)+raznCT;
    else PrCT=Number(Tablstr,2)-raznCT;

HTML.append("<p style=' margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>Пр<span style=' vertical-align:super;'>ц</span><span style=' vertical-align:sub;'>и</span>=" + QString::number(PrCI,'d',1));
if(ui->lineEdit_4->text() != "")
{
   HTML.append(" Ск=" + QString::number((ui->lineEdit_4->text().toDouble()/3.0)/Number(Tablstr,3),'d',1));
if(ui->lineEdit_4->text().toDouble()<100) HTML.append("!");
if(ui->lineEdit_4->text().toDouble()>200) HTML.append("!!");
}
HTML.append(" Пр<span style=' vertical-align:super;'>ц</span><span style=' vertical-align:sub;'>т</span>=" + QString::number(PrCT,'d',1)+"</p>");
}
else if(ui->pushButton_2->text() != "Выбор сист.")
{

    QString Tablstr=DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,strDalCI.toDouble());
   double one = Number(Tablstr,1);
    double razn=fabs(strDalCI.toDouble()-one);
    double tab3=Number(Tablstr,3);
    razn=(razn/50.0)*tab3;
    double PrCI=0;
    double two=Number(Tablstr,1);
    if(strDalCI.toDouble()>two)PrCI=Number(Tablstr,2)+razn;
    else PrCI=Number(Tablstr,2)-razn;
    Tablstr="";
    Tablstr=DataD->GetNaibTabl(disys->itemstr,disys->item2str,disys->item3str,dalstr.toDouble());
    double raznCT=fabs(dalstr.toDouble()-Number(Tablstr,1));
    raznCT=(raznCT/50.0)*Number(Tablstr,3);
    double PrCT=0;
    if(dalstr.toDouble()>Number(Tablstr,1))PrCT=Number(Tablstr,2)+raznCT;
    else PrCT=Number(Tablstr,2)-raznCT;

HTML.append("<p style=' margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>Пр<span style=' vertical-align:super;'>ц</span><span style=' vertical-align:sub;'>и</span>=" + QString::number(PrCI,'d',1));
if(ui->lineEdit_4->text() != "")
{
   HTML.append(" Ск=" + QString::number((ui->lineEdit_4->text().toDouble()/150.0)*Number(Tablstr,3),'d',1));
if(ui->lineEdit_4->text().toDouble()<100) HTML.append("!");
if(ui->lineEdit_4->text().toDouble()>200) HTML.append("!!");
}
HTML.append(" Пр<span style=' vertical-align:super;'>ц</span><span style=' vertical-align:sub;'>т</span>=" + QString::number(PrCT,'d',1)+"</p>");
}



HTML.append(HTMLpost);
HTML.append(HTMLpost2);

/*
int index=0;
for(int i=0;i<6;i++)
{
    index=HTML.indexOf("<p style='",index);
    HTML.insert(index,"background-color: rgb(10,230,10)");
    index+=10;
    if(index>HTML.length())break;
}
*/

ui->textEdit->setHtml(MakeLine( HTML,"", "background-color: rgb(10,230,10);","<p style='",1));

   // }
    //else ui->textEdit->setText("Стрельба на эту дистанцию не возможна! Выберите другой снаряд или систему!");
    }
}


QString WindowOgn::MakeLine(QString HTML,QString HTMLgrand,QString insert, QString Find,bool k)
{
    QString HTMLO=HTML;
    QString NewHTML=HTMLgrand;
    if(HTMLO.indexOf(Find)!=-1)
    {
        if(k){
        NewHTML.append(HTMLO.insert(HTMLO.indexOf(Find)+Find.length(),insert).left(HTMLO.indexOf(insert)+insert.length()));
        qDebug()<<NewHTML;
        return MakeLine(HTMLO.right(HTMLO.length()-(HTMLO.indexOf(Find)+Find.length()+insert.length())),NewHTML,insert,Find,0);
              }
        else{
            NewHTML.append(HTMLO.left(HTMLO.indexOf(Find)+Find.length()));
            qDebug()<<NewHTML;
            return MakeLine(HTMLO.right(HTMLO.length()-(HTMLO.indexOf(Find)+Find.length())),NewHTML,insert,Find,1);

             }
    }

    return NewHTML.append(HTML);
}

double WindowOgn::Number(QString str,int number)
{
int cou=0;
QString ret="";
for(int i=0;i<str.length();i++){if(str.at(i)!=" ")ret.append(str.at(i));else{cou++;if(cou ==number )break;else ret="";}}
return ret.toDouble();
}

 int WindowOgn::InterpolPoDal(double dct)
 {

     int chet=0;
     int flag=0;
     QFile file("/storage/emulated/0/.ArKoData/Popr.txt");
     /*Считываем исходный файл в контейнер*/
     if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
     {
         while(!file.atEnd())
         {
         file.readLine();
         chet++;
         }
         file.close();
     }
     int chetONE=-1;
     int chetTWO=-1;

   for(int i=0;i<chet;i++)
   {
       if(DataD->GetData("Popr.txt","",i).toDouble() < dct)chetONE=i;
       else { chetTWO=i;break;}
   }


   if(chetONE != -1 && chetTWO != -1){


       if(DataD->GetData("Popr.txt","B:",chetONE).toDouble() < DataD->GetData("Popr.txt","B:",chetTWO).toDouble()){//высходящая
          sredDalCI= DataD->GetData("Popr.txt","B:",chetONE).toDouble()+((dct-DataD->GetData("Popr.txt","",chetONE).toDouble())/(DataD->GetData("Popr.txt","",chetTWO).toDouble()-DataD->GetData("Popr.txt","",chetONE).toDouble()))*(DataD->GetData("Popr.txt","B:",chetTWO).toDouble()-DataD->GetData("Popr.txt","B:",chetONE).toDouble());
          sredDovCI=DataD->GetData("Popr.txt","C:",chetONE).toDouble()+((dct-DataD->GetData("Popr.txt","",chetONE).toDouble())/(DataD->GetData("Popr.txt","",chetTWO).toDouble()-DataD->GetData("Popr.txt","",chetONE).toDouble()))*(DataD->GetData("Popr.txt","C:",chetTWO).toDouble()-DataD->GetData("Popr.txt","C:",chetONE).toDouble());
       }
       else{//низходящая
           sredDalCI= DataD->GetData("Popr.txt","B:",chetTWO).toDouble()+((dct-DataD->GetData("Popr.txt","",chetONE).toDouble())/(DataD->GetData("Popr.txt","",chetTWO).toDouble()-DataD->GetData("Popr.txt","",chetONE).toDouble()))*(DataD->GetData("Popr.txt","B:",chetONE).toDouble()-DataD->GetData("Popr.txt","B:",chetTWO).toDouble());
           sredDovCI=DataD->GetData("Popr.txt","C:",chetTWO).toDouble()+((dct-DataD->GetData("Popr.txt","",chetONE).toDouble())/(DataD->GetData("Popr.txt","",chetTWO).toDouble()-DataD->GetData("Popr.txt","",chetONE).toDouble()))*(DataD->GetData("Popr.txt","C:",chetONE).toDouble()-DataD->GetData("Popr.txt","C:",chetTWO).toDouble());
       }
 flag= 0;
   }

   else if(chetTWO != -1){
 sredDalCI=DataD->GetData("Popr.txt","B:",chetTWO).toDouble();
  sredDovCI=DataD->GetData("Popr.txt","C:",chetTWO).toDouble();
   flag= 1;
   if(abs(dct-DataD->GetData("Popr.txt","",chetTWO).toDouble())>1000) flag=2;
   }
   else if(chetONE != -1){
    sredDalCI=DataD->GetData("Popr.txt","B:",chetONE).toDouble();
    sredDovCI=DataD->GetData("Popr.txt","C:",chetONE).toDouble();
     flag= 1;
     if(abs(dct-DataD->GetData("Popr.txt","",chetONE).toDouble())>1000) flag=2;
   }

   return flag;
 }

void WindowOgn::ClickCount()
{
    ui->lineEdit_6->setText(QString::number(dial->GetX()));
    ui->lineEdit_5->setText(QString::number(dial->GetY()));
    ui->lineEdit_3->setText(QString::number(dial->GetH()));
  //  QMessageBox msgb;
  //  msgb.setText("Count");
  //  msgb.exec();
}

void WindowOgn::ClickCancle()
{
//QMessageBox msgb;
//msgb.setText("Cancle");
//msgb.exec();
}


void WindowOgn::on_comboBox_activated(const QString &arg1)
{

}

void WindowOgn::on_pushButton_2_clicked()
{
    disys->show();
}

void WindowOgn::on_lineEdit_returnPressed()
{

}
