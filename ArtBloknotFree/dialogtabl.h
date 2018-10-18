#ifndef DIALOGTABL_H
#define DIALOGTABL_H

#include <QMainWindow>

namespace Ui {
class DialogTabl;
}

class DialogTabl : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogTabl(QWidget *parent = 0);
    ~DialogTabl();
     bool  radio=false;
     QString name="0";
     QString choice="";
     QString oldname="0";
signals:
void click_2();
void click_1();
private slots:
    void on_pushButton_2_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_clicked();

    void on_DialogTabl_destroyed();

private:
    Ui::DialogTabl *ui;

};

#endif // DIALOGTABL_H
