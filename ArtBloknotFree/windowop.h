#ifndef WINDOWOP_H
#define WINDOWOP_H

#include <QMainWindow>
#include "qdinamicdata.h"
#include <QScroller>
namespace Ui {
class WindowOP;
}

class WindowOP : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowOP(QWidget *parent = 0);
    ~WindowOP();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_3_returnPressed();

    void on_lineEdit_13_returnPressed();

    void on_lineEdit_14_returnPressed();

    void on_lineEdit_12_returnPressed();

    void on_lineEdit_7_returnPressed();

    void on_lineEdit_8_returnPressed();

    void on_lineEdit_10_returnPressed();

private:
    Ui::WindowOP *ui;
    QDinamicData *Data;
    QString FND="Op.txt";//FileNameData
    void SetData();
    void ChangeData();
};

#endif // WINDOWOP_H
