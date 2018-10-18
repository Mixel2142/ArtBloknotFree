#ifndef DIALOGCHOICESYST_H
#define DIALOGCHOICESYST_H

#include <QMainWindow>
#include "qdinamicdata.h"

namespace Ui {
class dialogchoicesyst;
}

class dialogchoicesyst : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialogchoicesyst(QWidget *parent = 0);
    ~dialogchoicesyst();
    QString itemstr="";
     QString item2str="";
      QString item3str="";
      int item=-1;
      int item2=-1;
      int item3=-1;
signals:
   void exit();
private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_comboBox_3_activated(int index);

private:
    Ui::dialogchoicesyst *ui;
     QDinamicData *DataD;
     QString FND="Tablstr.txt";
};

#endif // DIALOGCHOICESYST_H
