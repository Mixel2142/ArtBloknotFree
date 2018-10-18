#ifndef WINDOWPGZ_H
#define WINDOWPGZ_H

#include <QMainWindow>
#include "headers.h"
#include "qdinamicdata.h"
#include <QScroller>
namespace Ui {
class WindowPGZ;
}

class WindowPGZ : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowPGZ(QWidget *parent = 0);
    ~WindowPGZ();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(int index);

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_5_returnPressed();

    void on_lineEdit_6_returnPressed();

    void on_lineEdit_8_returnPressed();

    void on_lineEdit_10_returnPressed();

    void on_lineEdit_9_returnPressed();

private:
    Ui::WindowPGZ *ui;
    QString FND="Pgz.txt";//FileNameData
    QDinamicData *DataD;
    int item=0;
};

#endif // WINDOWPGZ_H
