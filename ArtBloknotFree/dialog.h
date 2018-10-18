#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "headers.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0,int index=-1);
    ~Dialog();
    double GetX();
    double GetY();
    double GetH();
    bool flag=0;
signals:

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_editingFinished();

private:

    double X=0;
    double Y=0;
    double Height=0;
    Ui::Dialog *ui;
   QDinamicData *DataD;
};

#endif // DIALOG_H
