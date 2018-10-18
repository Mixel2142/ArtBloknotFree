#ifndef DATA_H
#define DATA_H
#include <QFile>
#include <QDebug>
class Data
{
public:
    Data();
    ~Data();
    bool DataAddToFile(QString FileName=0,QString Name=0,QString Wide=0,QString Depth=0,QString X=0,QString Y=0,QString Height=0,QString Area=0);
    bool DataDeleteFromFile(int number,QString FileName);
    bool KnpAddToFile(QString FileName,QString Name ,QString X,QString Y,QString Height);
    bool SecAddToFile(QString FileName,QString Name,QString X,QString Y,QString Napr1,QString Napr2, QString distance);
    bool OpAddToFile(QString FileName,QString Name, QString X, QString Y, QString Napr, QString Height,QString NumOfGun,QString Front,QString MaxDistance,QString MinDistance,QString Dovorot);
    bool OpChangeFile(int number,QString FileName,QString Name, QString X, QString Y, QString Napr, QString Napr1, QString Height,QString NumOfGun,QString Front,QString MaxDistance,QString MinDistance,QString Dovorot);
    bool KnpChangeFile(int i,QString FileName,QString Name,QString  X,QString  Y, QString  Height);
    bool PgzAddToFile(QString FileName,QString Name ,QString X,QString Y,QString Height);
    bool PoprAddToFile(QString Dop,QString DelD,QString Deld);
    bool CeliAddToFile(QString Name,QString Nomer,QString Front,QString Deep,QString X,QString Y,QString Height);
    bool CeliChangeFile(int number,QString FileName,QString Name,QString Nomer,QString Front,QString Deep,QString X,QString Y,QString Height);
    bool TablAddToFile(QString FileName , QString Name ,QString  Snar,QString Zar, QString Dal , QString Ptis , QString Xtis , QString chvd, QString pric );
private:

};

#endif // DATA_H
