#ifndef WINDOWCELI_H
#define WINDOWCELI_H

#include <QMainWindow>
#include "qdinamicdata.h"
namespace Ui {
class WindowCeli;
}

class WindowCeli : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowCeli(QWidget *parent = 0);
    ~WindowCeli();
    void SetXY(QString X,QString Y);
private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_2_activated(int index);

    void SetPGZ(QString X,QString Y,QString Height,QString Area);
    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_comboBox_8_activated(int index);

    void on_pushButton_24_clicked();

    void on_lineEdit_57_returnPressed();

    void on_lineEdit_58_returnPressed();

    void on_lineEdit_60_returnPressed();

    void on_lineEdit_59_returnPressed();

    void on_lineEdit_61_returnPressed();

    void on_lineEdit_62_returnPressed();

private:
    void SetData();
    Ui::WindowCeli *ui;
    QDinamicData *DataD;
    QString FND="Celi.txt";
};

#endif // WINDOWCELI_H
