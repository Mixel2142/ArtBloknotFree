#ifndef WINDOWOGN_H
#define WINDOWOGN_H

#include "headers.h"
#include <QMainWindow>
#include <QScroller>
#include <newdialog.h>
#include "dialogchoicesyst.h"
namespace Ui {

class WindowOgn;
}
class NEWDIALOG;
class WindowOgn : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowOgn(QWidget *parent = 0);
    ~WindowOgn();


private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_comboBox_3_activated(int index);

    void on_pushButton_clicked();

    void ClickCount();

    void ClickCancle();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void exit2();

    void on_lineEdit_returnPressed();

private:

    Ui::WindowOgn *ui;
    NEWDIALOG *dial=NULL;
    QDinamicData *DataD;
    dialogchoicesyst *disys;
    int item=0,item2=0,item3=0;
    int InterpolPoDal(double dct);
    double sredDalCI=0;
    double sredDovCI=0;
    double Number(QString str,int number);
    QString MakeLine(QString HTML, QString HTMLgrand, QString insert, QString Find, bool k);
};

#endif // WINDOWOGN_H
