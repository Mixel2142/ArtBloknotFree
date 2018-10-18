#ifndef WINDOWOGZ_H
#define WINDOWOGZ_H

#include <QMainWindow>
#include "headers.h"
#include "qdinamicdata.h"
#include <QScroller>
#include <QScrollBar>
namespace Ui {
class WindowOGZ;
}

class WindowOGZ : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowOGZ(QWidget *parent = 0);
    ~WindowOGZ();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_5_returnPressed();

    void on_lineEdit_6_returnPressed();

private:
    Ui::WindowOGZ *ui;
    QString FND="Ogz.txt";//FileNameData
    QDinamicData *DataD;
    int item1=-1,item2=-1;
};

#endif // WINDOWOGZ_H
