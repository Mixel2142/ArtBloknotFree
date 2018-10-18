#include "qdinamicdata.h"
#include <QMessageBox>
QDinamicData::QDinamicData(QWidget *parent, QWidget *layout,QString FileName)
{
ID=0;
pr=parent;
if(layout!= 0){
vl=new QVBoxLayout();
layout->setLayout(vl);
}//if
dt=new Data();
}

QDinamicData::~QDinamicData()
{

}
QString QDinamicData::str_WhoComboBoxActive(int index)
{

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
      return "Knp.txt";//Knp.txt
     }
     if(index>knp && index<=(op+knp))//выбрали op.txt
     {
        return "Op.txt";//Op.txt
     }
      return "0";//Никто не выбран

}

int QDinamicData::WhoComboBoxActive(int index,int flag)
{

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
      if(flag==1)return index-1;
      return 1;//Knp.txt
     }
     if(index>knp && index<=(op+knp))//выбрали op.txt
     {
        if(flag==2)return index-knp-1;
        return 2;//Knp.txt
     }
      return 0;//Никто не выбран

}



void QDinamicData::setComboBox(QComboBox *qcmbx, QString FileName)
{
    qcmbx->addItem(FileName);
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if(file.open(QIODevice::ReadOnly)){
    QString str="";
    QString knp="";
    int j=0;
    while(!file.atEnd())
    {
        knp="";
         j++;
    str=file.readLine();
    for(int i=0;i<str.length();i++)
    {
      if(str.at(i).isSpace())break;
      knp+=str.at(i);
    }
   knp=QString::number(j)+":"+knp;
   qcmbx->addItem(knp+" ");
    }
    file.close();
}
}

QString QDinamicData::GetDataTabl(QString FileName,QString DT,QString System,QString Snar,QString Zar,QString Dal)
{
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if(file.open(QIODevice::ReadOnly)){
    int j=0;
    while(!file.atEnd())
    {
       j++;
    file.readLine();
    }
    for(int i=0;i<j;i++)
    if(System == GetData(FileName,0,i) && Snar == GetData(FileName,"A:",i) && Zar == GetData(FileName,"B:",i)&& Dal == GetData(FileName,"Q:",i))
    {
        file.close();
        return GetData(FileName,DT,i);
    }

    }
    return "0";
}
void QDinamicData::setComboBoxFromTabl(QComboBox *qcmbx, QString FileName,QString System,QString Snar,QString Zar)
{

QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if((file.exists())&&file.open(QIODevice::ReadOnly)){
QStringList strList;

while(!file.atEnd())
{

strList<<file.readLine();
}
file.close();

    int SizeFont=qcmbx->font().pointSize();
    QFont font=qcmbx->font();
    int two=this->width();
    if(!System.isEmpty() &&!Snar.isEmpty() &&!Zar.isEmpty())
    {

    for(int i=0;i<strList.count();i++){if(System == GetData(strList,0,i) && Snar == GetData(strList,"A:",i) && Zar == GetData(strList,"B:",i))qcmbx->addItem(GetData(strList,"Q:",i));}


    }
else if(!System.isEmpty() &&!Snar.isEmpty()){

QString namezar="0";
for(int i=0;i<strList.count();i++)
if(System == GetData(strList,0,i) && Snar == GetData(strList,"A:",i)&& namezar !=GetData(strList,"B:",i) ){

    namezar=GetData(strList,"B:",i);qcmbx->addItem(GetData(strList,"B:",i));
    int one=QFontMetrics(qcmbx->font()).width(namezar);
    while(1){
    if(one > two)
    {
        font.setPointSize(--SizeFont);
        qcmbx->setFont(font);
        one=QFontMetrics(qcmbx->font()).width(namezar);
    }
    else break;
    }
}


}
else if(!System.isEmpty()){

QString namesnar="0";
for(int i=0;i<strList.count();i++)
if(System == GetData(strList,0,i) && namesnar !=GetData(strList,"A:",i))
{
    namesnar=GetData(strList,"A:",i);qcmbx->addItem(GetData(strList,"A:",i));

    int one=QFontMetrics(qcmbx->font()).width(namesnar);
    while(1){
    if(one > two)
    {
        font.setPointSize(--SizeFont);
        qcmbx->setFont(font);
        one=QFontMetrics(qcmbx->font()).width(namesnar);
    }
    else break;
    }
}

}
else {

QString namesyst="0";
for(int i=0;i<strList.count();i++)if(namesyst != GetData(strList,0,i))
{

    namesyst = GetData(strList,0,i);

    int one=QFontMetrics(qcmbx->font()).width(namesyst);
    while(1){
    if(one > two)
    {
        font.setPointSize(--SizeFont);
        qcmbx->setFont(font);
        one=QFontMetrics(qcmbx->font()).width(namesyst);
    }
    else break;
    }
    qcmbx->addItem(namesyst);
}

}
end1:;
}
}
void QDinamicData::AddData(QString FileName,QString Name,QString Wide,QString Depth,QString X,QString Y,QString Height)
{


}
void QDinamicData::AddDataCeli(QString Name,QString Nomer,QString Front,QString Deep,QString X,QString Y,QString Height,bool K)
{
    ID++;
    QCheckBox *ch=new QCheckBox(pr);
    if(K==false){ dt->CeliAddToFile(Name, Nomer,Front, Deep, X, Y, Height);}
    ch->setStyleSheet("QCheckBox{background:green;}");
    ch->setText(QString::number(ID)+" "+Name +": X:"+ X +" "+"Y:"+ Y +" "+"Выс:"+Height);
    vl->addWidget(ch);


}
void QDinamicData::AddDataPopr(QString Dop,QString DelD,QString Deld)
{
dt->PoprAddToFile(Dop, DelD, Deld);
}
void QDinamicData::AddDataPgz(QString FileName,QString Name, QString X, QString Y, QString Height)
{
dt->PgzAddToFile(FileName,Name,X, Y, Height);
}
void QDinamicData::AddDataKnp(QString FileName,QString Name, QString X, QString Y, QString Height,bool K)
{
ID++;
QCheckBox *ch=new QCheckBox(pr);
if(K==false){dt->KnpAddToFile(FileName,Name,X, Y, Height);}
ch->setStyleSheet("QCheckBox{background:green;}");
ch->setText(QString::number(ID)+" "+Name +": X:"+ X +" "+"Y:"+ Y +" "+"Выс:"+Height);
vl->addWidget(ch);
}
void QDinamicData::AddDataOp(QString FileName,QString Name, QString X, QString Y, QString Napr, QString Height,QString NumOfGun,QString Front,QString MaxDistance,QString MinDistance,QString Dovorot,bool K)
{
ID++;
QCheckBox *ch=new QCheckBox(pr);
if(K==false){dt->OpAddToFile(FileName,Name,X, Y, Napr, Height,NumOfGun,Front,MaxDistance,MinDistance,Dovorot);}
ch->setStyleSheet("QCheckBox{background:green;}");
ch->setText(QString::number(ID)+" "+Name +" X:"+ X +" "+"Y:"+ Y +" "+"Выс:"+Height);//Кирилл? Что выводить в ОП
vl->addWidget(ch);
}

void QDinamicData::AddDataSec(QString FileName,QString Name,QString X,QString Y,QString Napr1,QString Napr2, QString distance,bool K)
{
ID++;
QCheckBox *ch=new QCheckBox(pr);
if(!K)dt->SecAddToFile(FileName,Name,0,0,0,0, distance);

ch->setStyleSheet("QCheckBox{background:green;}");
ch->setText(QString::number(ID)+" "+Name+" Дистанция:"+distance+" ");
vl->addWidget(ch);
}

bool QDinamicData::ChoicePricel(QString Syst)//true это ракетн
{
    QString FileName="Tablstr.txt";
    if(!Syst.isEmpty())
    {
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if((file.exists())&&file.open(QIODevice::ReadOnly))
{
    int j=0;
    while(!file.atEnd())
    {
       j++;
    file.readLine();
    }
    file.close();

    for(int i=0;i<j;i++)if(Syst == GetData(FileName,0,i))if(GetData(FileName,"T:",i) == "1")return true;

}

}
    return false;
}
QString QDinamicData::GetNaibTabl(QString Syst, QString Snar, QString Zar , double Dal)
{
    QString FileName="Tablstr.txt";
    if(!Syst.isEmpty() &&!Snar.isEmpty() &&!Zar.isEmpty())
    {
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if((file.exists())&&file.open(QIODevice::ReadOnly))
{
    int j=0;
    while(!file.atEnd())
    {
       j++;
    file.readLine();
    }
    file.close();

int naim=100000;
int index=-1;
for(int i=0;i<j;i++)
if(Syst == GetData(FileName,0,i) && Snar == GetData(FileName,"A:",i) && Zar == GetData(FileName,"B:",i))
if(abs(naim) > abs(Dal-GetData(FileName,"Q:",i).toInt())){naim=abs(Dal-GetData(FileName,"Q:",i).toInt());index=i;}

if(index>-1)return GetData(FileName,"Q:",index)+" "+GetData(FileName,"W:",index)+" "+GetData(FileName,"E:",index)+" "+GetData(FileName,"R:",index)+" ";
    }

    }
    return "0";
}

void QDinamicData::AddDataTabl(QString FileName , QString Name, QString Snar, QString Zar , QString Dal , QString Ptis , QString Xtis , QString chvd,QString pric )
{
dt->TablAddToFile(FileName, Name, Snar, Zar, Dal, Ptis, Xtis, chvd, pric);
}

void QDinamicData::DeleteTabl(QString FileName,QString System,QString Snar,QString Zar,QString Dal)
{
    if(!System.isEmpty() &&!Snar.isEmpty() &&!Zar.isEmpty() &&!Dal.isEmpty()){
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if(file.open(QIODevice::ReadOnly)){
    int j=0;
    while(!file.atEnd())
    {
    file.readLine();
    j++;
    }
    file.close();
    for(int i=0;i<j;i++)
        if(System == GetData(FileName,0,i) && Snar == GetData(FileName,"A:",i) && Zar == GetData(FileName,"B:",i) && Dal == GetData(FileName,"Q:",i)){dt->DataDeleteFromFile(i,FileName);i--;j--;}
    }
    }
else if(!System.isEmpty() &&!Snar.isEmpty() &&!Zar.isEmpty()){
QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if(file.open(QIODevice::ReadOnly)){
int j=0;
while(!file.atEnd())
{
   j++;
file.readLine();
}
file.close();
for(int i=0;i<j;i++)if(System == GetData(FileName,0,i) && Snar == GetData(FileName,"A:",i) && Zar == GetData(FileName,"B:",i)){dt->DataDeleteFromFile(i,FileName);i--;j--;}

}
}
else if(!System.isEmpty() &&!Snar.isEmpty()){
QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if(file.open(QIODevice::ReadOnly)){
int j=0;
while(!file.atEnd())
{
   j++;
file.readLine();
}
file.close();
for(int i=0;i<j;i++)if(System == GetData(FileName,0,i) && Snar == GetData(FileName,"A:",i) ){dt->DataDeleteFromFile(i,FileName);i--;j--;}

}
}


}
void QDinamicData::deleteData(QString FileName)//сначала удаляется из формы ->обновляется текстовый файл->обновляются номера в свойстве текст
{
QCheckBox *chn;
    for(int i = 0; i <  vl->count(); i++){
    chn=qobject_cast<QCheckBox*>( vl->itemAt(i)->widget());
    if(chn->isChecked()==true){
        chn->hide();
        delete chn;
dt->DataDeleteFromFile(i,FileName);
 i--;//при удалении итема все id последующих изменяется на -1 позицию
    }//if
    chn=nullptr;
    }//for из формы удалено и из файла
QString str;
 for(int i = 0; i <  vl->count(); i++){
chn=qobject_cast<QCheckBox*>( vl->itemAt(i)->widget());
str=chn->text();
for(int j=0;j<str.length();j++)
{
    int x=i+1;
    if(str.at(j).isSpace()){
    str.replace(0,j,QString::number(x));
    break;
    }//if
}//for перебор строки чекбокса
chn->setText(str);
chn=nullptr;
str=nullptr;
 }//for изменяем номера
ID=vl->count();

}


void QDinamicData::ChangeDataOp(QString FileName,QString Name, QString X, QString Y, QString Napr, QString Napr1, QString Height,QString NumOfGun,QString Front,QString MaxDistance,QString MinDistance,QString Dovorot)
{


    QCheckBox *chn;
        for(int i = 0; i <  vl->count(); i++){
        chn=qobject_cast<QCheckBox*>( vl->itemAt(i)->widget());
        if(chn->isChecked()==true){
        dt->OpChangeFile(i, FileName, Name,  X,  Y,  Napr,Napr1,  Height, NumOfGun, Front, MaxDistance, MinDistance, Dovorot);
        chn->setText(QString::number(i+1)+" "+Name +": X:"+ X +" "+"Y:"+ Y +" "+"Выс:"+Height);//Кирилл? Что выводить в ОП
        break;
        }//if
        chn=nullptr;
        }//for в форме изменено и в файле

}


void QDinamicData::ChangeDataCeli(QString Name,QString Nomer,QString Front,QString Deep,QString X,QString Y,QString Height)
{
    QCheckBox *chn;
        for(int i = 0; i <  vl->count(); i++){
        chn=qobject_cast<QCheckBox*>( vl->itemAt(i)->widget());
        if(chn->isChecked()==true){
        dt->CeliChangeFile(i, "Celi.txt", Name, Nomer,Front, Deep, X, Y, Height);
        chn->setText(QString::number(i+1)+" "+Name +": X:"+ X +" "+"Y:"+ Y +" "+"Выс:"+Height);//Кирилл?
        break;
        }//if
        chn=nullptr;
        }//for в форме изменено и в файле

}
void QDinamicData::ChangeDataKnp(QString FileName,QString Name, QString X, QString Y, QString Height)
{
    QCheckBox *chn;
        for(int i = 0; i <  vl->count(); i++){
        chn=qobject_cast<QCheckBox*>( vl->itemAt(i)->widget());
        if(chn->isChecked()==true){
        dt->KnpChangeFile(i, FileName, Name,  X,  Y,  Height);
        chn->setText(QString::number(i+1)+" "+Name +": X:"+ X +" "+"Y:"+ Y +" "+"Выс:"+Height);//Кирилл? Что выводить в KNP
        break;
        }//if
        chn=nullptr;
        }//for в форме изменено и в файле


}
QString QDinamicData::GetData(QString FileName,QString DT,int num)
{
    QStringList strList;
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
    //Считываем исходный файл в контейнер
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
        strList << file.readLine();
        }
        file.close();
    }

QString str=strList.at(num);
if(!DT.isEmpty()){

    int key=0;
        QString number="";
        for(int i=0;i < str.length()-DT.length();i++)
        {
        if(key==DT.length()){
           for(int j=0;j<str.length();j++){
           if(!str.at(i+DT.length()+j-1).isSpace())number+=str.at(i+DT.length()+j-1);
           else return number;
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
      return "0";

}
else{
    return str.left(str.indexOf(":")-2);
}

    return "0";
}

QString QDinamicData::GetData(QStringList strList,QString DT,int num)
{
QString str=strList.at(num);
if(!DT.isEmpty()){

    int key=0;
        QString number="";
        for(int i=0;i < str.length()-DT.length();i++)
        {
        if(key==DT.length()){
           for(int j=0;j<str.length();j++){
           if(!str.at(i+DT.length()+j-1).isSpace())number+=str.at(i+DT.length()+j-1);
           else return number;
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
      return "0";

}
else{
    return str.left(str.indexOf(":")-2);
}

    return "0";
}
void QDinamicData::New_Change_Add_Data(QString FileName,int NumberLine,QString DT,QString number)
{//Пример вызова New_Change_Add_Data(имя файла,номер строки,"P:","123.32")
   if(!DT.isEmpty()){
    QStringList strList;
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
    //Считываем исходный файл в контейнер
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
        strList << file.readLine();
        }
        file.close();
    }
QString str=strList.at(NumberLine);

str.replace(str.indexOf(DT),str.right(str.length()-1-str.indexOf(DT)).indexOf(" ")+1,DT+number);

if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
{
strList.replace(NumberLine,str);
QTextStream stream(&file);
foreach(QString s, strList)
{
    stream<<s;
}
file.close();
//добавление в файл
}}
   else{
       QStringList strList;
       QFile file("/storage/emulated/0/.ArKoData/"+FileName);
       //Считываем исходный файл в контейнер
       if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
       {
           while(!file.atEnd())
           {
           strList << file.readLine();
           }
           file.close();
       }
       QString str=strList.at(NumberLine);

       str.replace(0,str.indexOf(" ")-1,number);
       if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
       {
       strList.replace(NumberLine,str);
       QTextStream stream(&file);
       foreach(QString s, strList)
       {
           stream<<s;
       }
       file.close();
   }
   }
}

void QDinamicData::DeleteAllChekcBox()
{

    QCheckBox *chn;
        for(int i = 0; i <  vl->count(); i++){
        chn=qobject_cast<QCheckBox*>( vl->itemAt(i)->widget());
            chn->hide();
            delete chn;
     i--;//при удалении итема все id последующих изменяется на -1 позицию
        chn=nullptr;
        }//for из формы удалено и из файла
        ID=0;
}

void QDinamicData::Change_Add_Data_Tabl(QString FileName,QString System,QString Snar,QString Zar,QString Dal,QString NewDal,QString NewPtis , QString NewXtis , QString Newchvd,QString NewSystem,QString NewSnar,QString NewZar)
{
    if(!System.isEmpty() &&!Snar.isEmpty() &&!Zar.isEmpty()&&!Dal.isEmpty()){
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if(file.open(QIODevice::ReadOnly)){
    int j=0;
    while(!file.atEnd())
    {
       j++;
    file.readLine();
    }
    for(int i=0;i<j;i++)
    if(System == GetData(FileName,0,i) && Snar == GetData(FileName,"A:",i) && Zar == GetData(FileName,"B:",i)&& Dal == GetData(FileName,"Q:",i))
    {
        New_Change_Add_Data(FileName,i,"Q:", NewDal);
        New_Change_Add_Data(FileName,i,"W:", NewPtis);
        New_Change_Add_Data(FileName,i,"E:", NewXtis);
        New_Change_Add_Data(FileName,i,"R:", Newchvd);
    }
file.close();
    }

    }
else if(!System.isEmpty() &&!Snar.isEmpty()&&!Zar.isEmpty()){
QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if(file.open(QIODevice::ReadOnly)){
int j=-1;
while(!file.atEnd())
{
   j++;
file.readLine();
}
for(int i=0;i<j;i++)
if(System == GetData(FileName,0,i) && Snar == GetData(FileName,"A:",i) && Zar == GetData(FileName,"B:",i))
{
    New_Change_Add_Data(FileName,i,"B:", NewZar);
}
    file.close();
}
}
else if(!System.isEmpty()&&!Snar.isEmpty()){
QFile file("/storage/emulated/0/.ArKoData/"+FileName);
if(file.open(QIODevice::ReadOnly)){
int j=-1;
while(!file.atEnd())
{
   j++;
file.readLine();
}
for(int i=0;i<j;i++)
if(System == GetData(FileName,0,i) && Snar == GetData(FileName,"A:",i) )
{
    New_Change_Add_Data(FileName,i,"A:", NewSnar);
}
    file.close();
}
}
else if(!System.isEmpty()){
        QFile file("/storage/emulated/0/.ArKoData/"+FileName);
        if(file.open(QIODevice::ReadOnly)){
        int j=-1;
        while(!file.atEnd())
        {
           j++;
        file.readLine();
        }
        for(int i=0;i<j;i++)
        if(System == GetData(FileName,0,i) )
        {
           New_Change_Add_Data(FileName,i,0, NewSystem);
        }
            file.close();
        }
}

}

void QDinamicData::Change_Add_Data(QString FileName,int NumberLine,QString DT,QString number)
{
    QStringList strList;
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
    //Считываем исходный файл в контейнер
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
        strList << file.readLine();
        }
        file.close();
    }
QString str=strList.at(NumberLine);
int schetch=0;
if(DT!="0"){

    if(str.indexOf(DT)!= -1){
for(int i=str.indexOf(DT)+DT.length();i<str.length();i++){if(!str.at(i).isSpace())schetch++;else break; }
str.replace(str.indexOf(DT)+DT.length(),schetch,number);
    }//
    else{
        str.remove(str.lastIndexOf(' '),str.length()-str.lastIndexOf(' '));
        str.append(' '+DT+number+" \n");
    }//-1
}//if is !isEmpty
else{
    for(int i=0;i<str.length();i++){if(!str.at(i).isSpace())schetch++;else break; }
   str.replace(0,schetch,number);
}//else

if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
{
strList.replace(NumberLine,str);
QTextStream stream(&file);
foreach(QString s, strList)
{
    stream<<s;
}
file.close();
//добавление в файл
}

}
void QDinamicData::SwapLine(QStringList *strList, int NumberLine1, int NumberLine2)
{
    QString str =strList->at(NumberLine1);
    strList->replace(NumberLine1,strList->at(NumberLine2));
    strList->replace(NumberLine2,str);
}

void QDinamicData::ReSetFile(QString FileName,QString DT)// перестроить строчки по возростанию DT
{
      QStringList strList;
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
    /*Считываем исходный файл в контейнер*/
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
        strList << file.readLine();
        }
        file.close();

     for(int i=0;i<strList.count()-1;i++)for(int j=0;j<(strList.count()-1)-i;j++)if(GetData(strList,DT,j).toInt()>GetData(strList,DT,j+1).toInt())SwapLine(&strList,j,j+1);
     ClearClon(&strList);
     if ((file.exists())&&(file.open(QIODevice::WriteOnly))){
     QTextStream stream(&file);
         foreach(QString s, strList){stream<<s;}
     }
     }
}
void QDinamicData::ReSetFile(QString FileName,QString DT1,QString DT2,QString DT3,QString DT4)// перестроить строчки по возростанию DT
{

    QStringList strList;
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
         strList << file.readLine();
        }
        file.close();





    if(strList.count()>0){
    for(int k=0;k<strList.count();k++)for(int i=0;i<(strList.count()-1)-k;i++)
    {
        if(GetData(strList,DT1,i)>GetData(strList,DT1,i+1))SwapLine(&strList,i,i+1);
    }
    int dt=0;
    QString dtstr="";
    for(int i=dt;i<strList.count()-1;i++)
    {
        dt=0;
     dtstr=GetData(strList,DT1,i);
    for(int k=i;k<strList.count();k++)
    {
        if(dtstr == GetData(strList,DT1,k))dt++;
        else break;
    }
    for(int j=0;j<dt;j++){
    for(int k=i;k<i+(dt-1)-j;k++){
    if(GetData(strList,DT2,k)>GetData(strList,DT2,k+1))SwapLine(&strList,k,k+1);}}
    i+=dt;
    }

dt=0;
    for(int i=dt;i<strList.count()-1;i++)
    {
        dt=0;
     dtstr=GetData(strList,DT2,i);
    for(int k=i;k<strList.count();k++)
    {
        if(dtstr == GetData(strList,DT2,k))dt++;
        else break;
    }
    for(int j=0;j<dt;j++){
    for(int k=i;k<i+(dt-1)-j;k++){
    if(GetData(strList,DT3,k)>GetData(strList,DT3,k+1))SwapLine(&strList,k,k+1);}}
    i+=dt;
    }


dt=0;

    for(int i=dt;i<strList.count()-1;i++)
    {
        dt=0;
     dtstr=GetData(strList,DT3,i);
    for(int k=i;k<strList.count();k++)
    {
        if(dtstr == GetData(strList,DT3,k))dt++;
        else break;
    }
    for(int j=0;j<dt;j++){
    for(int k=i;k<i+(dt-1)-j;k++){
    if(GetData(strList,DT4,k).toDouble()>GetData(strList,DT4,(k+1)).toDouble())SwapLine(&strList,k,k+1);}}
    i+=dt;
    }
    }
    ClearClon(&strList);
    if ((file.exists())&&(file.open(QIODevice::WriteOnly))){
            QTextStream stream(&file);
            foreach(QString s, strList)
            {
                stream<<s;
            }
        file.close();
        }
    }

}

void QDinamicData::ClearClon(QStringList *strList)
{

    for(int i=0;i<strList->count()-1;i++)
    {
        for(int k=i+1;k<strList->count()-1;k++)if(strList->at(i)==strList->at(k)){strList->removeAt(k);}
    }
}

void QDinamicData::OGZ(double X1,double Y1,double X2,double Y2)
{
    double DX=X2-X1;
    double DY=Y2-Y1;
    distance=sqrt((DX*DX)+(DY*DY));//расстояние между точками
    double rumb=atan(fabs(DY/DX));//в радианах возращает//Угол румба
    rumb*=(180.0/M_PI);// перевели в градусы
    double dirugl;
    if(DX > 0 && DY > 0)dirugl=rumb;
    if(DX < 0 && DY > 0)dirugl=180-rumb;
    if(DX < 0 && DY < 0)dirugl=180+rumb;
    if(DX > 0 && DY < 0)dirugl=360-rumb;
    dirTis=dirugl/6.0;//перевели в тысячные (dir2)
    napr=QString::number(dirTis,'d',2).toDouble()*100;
    naprstr=QString::number(dirTis,'d',2).left(QString::number(dirTis,'d',2).indexOf('.'))+"-"+QString::number(dirTis,'d',2).right(QString::number(dirTis,'d',2).length()-QString::number(dirTis,'d',2).indexOf('.')-1);

}

double QDinamicData::getOGZdistance()
{
    return distance;
}
double QDinamicData::getOGZdirTis()
{
     return dirTis;
}
double QDinamicData::getOGZnapr()
{
     return napr;
}

double QDinamicData::getOGZuglmesta()
{
     return uglmesta;
}

QString QDinamicData::getOGZnaprstr()
{
return naprstr;
}

void QDinamicData::PGZ(double distanceP, QString napr1, QString napr2,QString uglmast1, QString uglmast2,QString X,QString Y,QString height)
{
     naprP=(napr1.toDouble()+(napr2.toDouble()/100))*6;
     uglmestaP=(uglmast1+uglmast2).toDouble();

     double delX =cos(naprP*(M_PI/180));
     if(fabs(delX)<0.0000001)delX=0;

     delX=distanceP*delX;

     double delY = sin(naprP*(M_PI/180));
      if(fabs(delY)<0.0000001)delY=0;

     delY=distanceP*delY;

     XP=X.toDouble()+delX;
     YP=Y.toDouble()+delY;
     HeightP=height.toDouble() +(distanceP/1000)*uglmestaP;
}

void QDinamicData::PGZ(double distanceP, QString grad, QString min,QString sec,QString uglmast1, QString uglmast2,QString X,QString Y,QString height)
{
     uglmesta=(uglmast1.toDouble()+uglmast2.toDouble()/60)/6;
     napr = (((sec.toDouble()/60)+min.toDouble()/60)+grad.toDouble());

     double delX =cos(naprP*(M_PI/180));
     if(fabs(delX)<0.0000001)delX=0;

     delX=distanceP*delX;

     double delY = sin(naprP*(M_PI/180));
      if(fabs(delY)<0.0000001)delY=0;

     delY=distanceP*delY;

     XP=X.toDouble()+delX;
     YP=Y.toDouble()+delY;
     HeightP=height.toDouble() +(distanceP/1000)*uglmestaP;
}
double QDinamicData::NumberFromCBox()//получает число после последнего двоеточия из чеакного бокса
{
    QCheckBox *chn;
    for(int i = 0; i <  vl->count(); i++){
    chn=qobject_cast<QCheckBox*>( vl->itemAt(i)->widget());
    if(chn->isChecked()==true){
    return chn->text().right(chn->text().length()-chn->text().indexOf(':')-1).toDouble();
    }//if
        chn=nullptr;
        }//for из формы удалено и из файла
return 11;
}
double QDinamicData::getPGZX()
{
     return XP;
}
double QDinamicData::getPGZY()
{
     return YP;
}
double QDinamicData::getPGZH()
{
     return HeightP;
}

