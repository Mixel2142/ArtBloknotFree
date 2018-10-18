#ifndef WINDOWKNP_H
#define WINDOWKNP_H

#include <QMainWindow>
#include "qdinamicdata.h"
#include <QScroller>
namespace Ui {
class WindowKNP;
}

class WindowKNP : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowKNP(QWidget *parent = 0);
    ~WindowKNP();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_3_returnPressed();

private:
    Ui::WindowKNP *ui;
    QDinamicData *Data;
    QString FND="Knp.txt";//FileNameData
    void SetData();
};

#endif // WINDOWKNP_H
