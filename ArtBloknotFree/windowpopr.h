#ifndef WINDOWPOPR_H
#define WINDOWPOPR_H

#include <QMainWindow>
#include "qdinamicdata.h"
#include "data.h"
namespace Ui {
class WindowPopr;
}

class WindowPopr : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowPopr(QWidget *parent = 0);
    ~WindowPopr();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_WindowPopr_destroyed();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

private:
    Ui::WindowPopr *ui;
    QDinamicData *DataD;
    Data *dt;
    int item=-1;
void UpdateComboBox();
};

#endif // WINDOWPOPR_H
