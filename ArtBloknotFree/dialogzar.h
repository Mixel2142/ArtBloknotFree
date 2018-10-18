#ifndef DialogZar_H
#define DialogZar_H

#include <QMainWindow>

namespace Ui {
class DialogZar;
}

class DialogZar : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogZar(QWidget *parent = 0);
    ~DialogZar();
     bool  radio=false;
     QString name="0";
     QString oldname="0";
signals:
void click_2();
void click_1();
private slots:
    void on_pushButton_2_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogZar *ui;

};

#endif // DialogZar_H
