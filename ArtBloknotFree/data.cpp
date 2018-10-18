#include "data.h"

Data::Data()
{

}
Data::~Data()
{

}


 bool Data::DataDeleteFromFile(int number,QString FileName)
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
     }
     /*Удаляем строку и сохраняем содержимое контейнера в тот же файл*/
     if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
     {
         strList.removeAt(number);
         QTextStream stream(&file);
         foreach(QString s, strList)
         {
             stream<<s;
         }
         file.close();
     }

 }

bool Data::DataAddToFile(QString FileName,QString Name ,QString Wide,QString Depth,QString X,QString Y,QString Height,QString Area)
{

 QFile file("/storage/emulated/0/.ArKoData/"+FileName);
 if(file.open(QIODevice::Append)){
 QTextStream stream(&file);
 stream << QString(Name + " A:" + X + " B:" + Y + " D:" + Height + " " + Wide + " " + Depth + " " + Area + "\n");

 file.close();
 }//if

}

bool Data::TablAddToFile(QString FileName , QString Name ,QString Snar, QString Zar , QString Dal , QString Ptis , QString Xtis , QString chvd,QString pric )
{
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
    if(file.open(QIODevice::Append)){
    QTextStream stream(&file);
    stream << QString(Name +" A:"+ Snar +" B:"+Zar+" Q:"+ Dal +" W:"+Ptis+" E:"+ Xtis+" R:"+ chvd+" T:"+ pric+" \n");
    file.close();
    }//if
}
bool Data::CeliAddToFile(QString Name,QString Nomer,QString Front,QString Deep,QString X,QString Y,QString Height)
{

 QFile file("/storage/emulated/0/.ArKoData/Celi.txt");
 if(file.open(QIODevice::Append)){
 QTextStream stream(&file);
 stream << QString(Name +" Q:"+ Nomer +" F:"+Front+" R:"+ Deep+" A:"+ X+" B:"+ Y+" D:"+ Height+" \n");

 file.close();
 }//if

}

bool Data::PoprAddToFile(QString Dop,QString DelD,QString Deld)
{

 QFile file("/storage/emulated/0/.ArKoData/Popr.txt");
 if(file.open(QIODevice::Append)){
 QTextStream stream(&file);
 stream << QString(Dop+" B:"+ DelD+" C:"+ Deld+" \n");

 file.close();
 }//if

}
bool Data::KnpAddToFile(QString FileName,QString Name ,QString X,QString Y,QString Height)
{
 QFile file("/storage/emulated/0/.ArKoData/"+FileName);
 if(file.open(QIODevice::Append)){
 QTextStream stream(&file);
 stream << QString(Name + " A:" + X + " B:" + Y + " D:" + Height + "\n");
 file.close();
 }//if
}
bool Data::PgzAddToFile(QString FileName,QString Name ,QString X,QString Y,QString Height)
{
 QFile file("/storage/emulated/0/.ArKoData/"+FileName);
 if(file.open(QIODevice::Append)){
 QTextStream stream(&file);
 stream << QString(Name + " A:" + X + " B:" + Y + " D:" + Height + "\n");
 file.close();
 }//if
}
bool Data::OpAddToFile(QString FileName,QString Name, QString X, QString Y, QString Napr, QString Height,QString NumOfGun,QString Front,QString MaxDistance,QString MinDistance,QString Dovorot)
{

 QFile file("/storage/emulated/0/.ArKoData/"+FileName);
 if(file.open(QIODevice::Append)){
 QTextStream stream(&file);
 stream << QString(Name + " A:" + X + " B:" + Y + " P:" + Napr + " D:"+Height + " E:" + NumOfGun + " F:" + Front + " J:" + MaxDistance + " K:" + MinDistance  + " L:" + Dovorot + " \n");
 file.close();
 }//if

}
bool Data::SecAddToFile(QString FileName,QString Name,QString X,QString Y,QString Napr1,QString Napr2, QString distance)
{
    QFile file("/storage/emulated/0/.ArKoData/"+FileName);
    if(file.open(QIODevice::Append)){
    QTextStream stream(&file);
    stream << QString(Name + " O:"+ distance + " A:" + X + " B:" + Y + " C:" + Napr1 + "-" +Napr2+" \n");
    file.close();
    }//if


}
bool Data::OpChangeFile(int number,QString FileName,QString Name, QString X, QString Y, QString Napr, QString Napr1, QString Height,QString NumOfGun,QString Front,QString MaxDistance,QString MinDistance,QString Dovorot)
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
    //Заменяем строку и сохраняем содержимое контейнера в тот же файл
    if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
    {


        strList.replace(number, Name + " A:" + X + " B:" + Y + " P:" + Napr +" P1:" + Napr1+ " D:" + Height + " E:" + NumOfGun + " F:" + Front + " J:" + MaxDistance  + " K:" + MinDistance + " L:" + Dovorot+" \n");
        QTextStream stream(&file);
        foreach(QString s, strList)
        {
            stream<<s;
        }
        file.close();
    }

    //.................................................................................
}
bool Data::CeliChangeFile(int number,QString FileName,QString Name,QString Nomer,QString Front,QString Deep,QString X,QString Y,QString Height)
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
    //Заменяем строку и сохраняем содержимое контейнера в тот же файл
    if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
    {


        strList.replace(number,Name +" Q:"+ Nomer +" F:"+Front+" R:"+ Deep+" A:"+ X+" B:"+ Y+" D:"+ Height+" \n");
        QTextStream stream(&file);
        foreach(QString s, strList)
        {
            stream<<s;
        }
        file.close();
    }



}


bool Data::KnpChangeFile(int i,QString FileName,QString Name,QString  X,QString  Y, QString  Height)
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
    //Заменяем строку и сохраняем содержимое контейнера в тот же файл
    if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
    {


        strList.replace(i, Name + " A:" + X + " B:" + Y + " D:" + Height +" \n");
        QTextStream stream(&file);
        foreach(QString s, strList)
        {
            stream<<s;
        }
        file.close();
    }


}
/*построчное чтение

    QString str="";
    while(!file.atEnd())
    {
    str=file.readLine();
    }
*/

