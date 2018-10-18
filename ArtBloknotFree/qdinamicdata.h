#ifndef QDINAMICDATA_H
#define QDINAMICDATA_H

#include <QWidget>
#include <QPushButton>
#include<QLabel>
#include<QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QComboBox>
#include "data.h"
#include <QScroller>
namespace Ui {
class QDinamicData;
}

class QDinamicData : public QPushButton
{
public:
     QDinamicData(QWidget *parent=0, QWidget *layout = 0,QString FileName=0);
    ~QDinamicData();
    //statuic Статический означает, что он один и тот же на все экземпляры (объекты) класса. Неважно метод это или член класса.
void AddData(QString FileName, QString Name=0, QString Wide=0, QString Depth=0, QString X=0, QString Y=0, QString Height=0);
void AddDataKnp(QString FileName, QString Name, QString X, QString Y, QString Height, bool K=0);
void AddDataSec(QString FileName, QString Name, QString X, QString Y, QString Napr1, QString Napr2, QString distance, bool K=0);
void AddDataOp(QString FileName,QString Name, QString X, QString Y, QString Napr, QString Height,QString NumOfGun,QString Front,QString MaxDistance,QString MinDistance,QString Dovorot,bool K=0);
void AddDataPgz(QString FileName, QString Name, QString X, QString Y, QString Height);
void AddDataPopr(QString Dop,QString DelD,QString Deld);
void AddDataCeli(QString Name, QString Nomer, QString Front, QString Deep, QString X, QString Y, QString Height, bool K=0);
void AddDataTabl(QString FileName, QString Name, QString Snar, QString Zar , QString Dal, QString Ptis, QString Xtis, QString chvd, QString pric);
QString GetNaibTabl(QString Syst, QString Snar, QString Zar , double Dal);
QString GetDataTabl(QString FileName,QString DT,QString System,QString Snar,QString Zar,QString Dal);
bool ChoicePricel(QString Syst);
void ClearClon(QStringList *strList);
void deleteData(QString FileName);
void Change_Add_Data_Tabl(QString FileName,QString System,QString Snar,QString Zar,QString Dal,QString NewDal,QString NewPtis , QString NewXtis , QString Newchvd,QString NewSystem,QString NewSnar,QString NewZar);
void setComboBox(QComboBox *qcmbx, QString FileName);
void setComboBoxAllSystems(QComboBox *qcmbx, QString FileName);
void setComboBoxFromTabl(QComboBox *qcmbx, QString FileName, QString System, QString Snar, QString Zar);
void ChangeDataOp(QString FileName,QString Name, QString X, QString Y, QString Napr, QString Napr1, QString Height,QString NumOfGun,QString Front,QString MaxDistance,QString MinDistance,QString Dovorot);
void ChangeDataKnp(QString FileName, QString Name, QString X, QString Y, QString Height);
void Change_Add_Data(QString FileName,int NumberLine,QString DT,QString number);
void ChangeDataCeli(QString Name, QString Nomer, QString Front, QString Deep, QString X, QString Y, QString Height);
void New_Change_Add_Data(QString FileName,int NumberLine,QString DT,QString number);
void setDataKnp();
void DeleteTabl(QString FileName,QString System,QString Snar,QString Zar,QString Dal);
void DeleteAllChekcBox();
QString GetData(QString FileName, QString DT, int num);
QString GetData(QStringList strList,QString DT,int num);
int WhoComboBoxActive(int index, int flag=0);
QString str_WhoComboBoxActive(int index);
void SwapLine(QStringList *strList, int NumberLine1, int NumberLine2);
void ReSetFile(QString FileName,QString DT);
void ReSetFile(QString FileName, QString DT1, QString DT2, QString DT3, QString DT4);
void OGZ(double X1,double Y1,double X2,double Y2);
double getOGZdistance();
double getOGZdirTis();
double getOGZnapr();
double getOGZuglmesta();
QString getOGZnaprstr();
void PGZ(double distanceP, QString napr1, QString napr2,QString uglmast1, QString uglmast2,QString X,QString Y,QString height);
void PGZ(double distanceP, QString napr1, QString napr2, QString napr3,QString uglmast1, QString uglmast2,QString X,QString Y,QString height);
double getPGZX();
double getPGZY();
double getPGZH();
double NumberFromCBox();
private:
    int ID=0;
QWidget *pr;
     QWidget *lt;
     Data *dt;//работа с файлом
   QVBoxLayout *vl;

   ///OGZ
   double distance=0;
   double dirTis=0;
   double napr=0;
   double uglmesta=0;
   QString naprstr="";
   double naprP=0;
   double uglmestaP=0;
   double XP=0;
   double YP=0;
   double HeightP=0;
};

#endif // QDINAMICDATA_H
