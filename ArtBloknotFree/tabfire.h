#ifndef TABFIRE_H
#define TABFIRE_H

#include <QMainWindow>
#include <headers.h>
#include "dialogtabl.h"
#include "dialogsnar.h"
#include "dialogzar.h"
namespace Ui {
class TabFire;
}

class TabFire : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabFire(QWidget *parent = 0);
    ~TabFire();

private slots:
    void on_comboBox_2_activated(int index);

    void ClickCount();

    void ClickCancle();

    void ClickCountSnar();

    void ClickCancleSnar();

    void ClickCountZar();

    void ClickCancleZar();

    void on_pushButton_clicked();

    void on_comboBox_3_activated(int index);

    void on_pushButton_2_clicked();

    void on_comboBox_4_activated(int index);

    void on_comboBox_5_activated(int index);

    void on_pushButton_3_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_5_returnPressed();

private:
    Ui::TabFire *ui;
    QDinamicData *DataD;
    DialogTabl *ditab;
    DialogSnar *disnar;
    DialogZar *dizar;
    bool change=false;
    int item3 =-2;
    int item2 =-2;
     int item4 =-2;
      int item5 =-2;
      QString oldsystem="";
    QString FND="Tablstr.txt";
    void UpdateAllComboBox();
};

#endif // TABFIRE_H
