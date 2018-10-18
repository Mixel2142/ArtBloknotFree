#ifndef WINDOWZWITHS_H
#define WINDOWZWITHS_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include "qdinamicdata.h"
#include <QScroller>
#include <windowceli.h>
namespace Ui {
class WindowZwithS;
}

class WindowZwithS : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowZwithS(QWidget *parent = 0);
    ~WindowZwithS();

private slots:
    void on_pushButton_4_clicked();
void updatetime();
void on_pushButton_3_clicked();


void on_pushButton_clicked();

void on_pushButton_2_clicked();

void on_comboBox_activated(int index);

void on_pushButton_5_clicked();

void on_lineEdit_6_editingFinished();

void on_lineEdit_6_textEdited(const QString &arg1);

void on_comboBox_activated(const QString &arg1);

void on_lineEdit_2_selectionChanged();

void on_lineEdit_4_textChanged(const QString &arg1);

void on_lineEdit_4_returnPressed();

void on_pushButton_6_clicked();

void on_lineEdit_returnPressed();

void on_lineEdit_2_returnPressed();

void on_lineEdit_3_returnPressed();

private:
void SetComboBoxFor(QString name);
QString GetNameComboBox(int num=-1);
    Ui::WindowZwithS *ui;
    QString FND="Sec.txt";//FileNameData
    QTimer *tmr;
    QTime  tm1;
    QDateTime dtm;
    double RaznostT(QTime t1,QTime t2);
    QDinamicData *DataD;
    QVBoxLayout *layout;
    QString X,Y;
    int item=0;
    void SetData();

};

#endif // WINDOWZWITHS_H
