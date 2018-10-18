#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QMainWindow>
#include "headers.h"
namespace Ui {
class NEWDIALOG;
}

class NEWDIALOG : public QMainWindow
{
    Q_OBJECT

public:
    explicit NEWDIALOG(QWidget *parent = 0, int index=-1);
    ~NEWDIALOG();
    void Setup(int index);
    double GetX();
    double GetY();
    double GetH();
    int flag=-1;
signals:
void click_2();
void click_1();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_clicked(bool checked);

private:
    Ui::NEWDIALOG *ui;
    double X=0;
    double Y=0;
    double Height=0;
   QDinamicData *DataD;
};

#endif // NEWDIALOG_H
