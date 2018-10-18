#ifndef DialogSnar_H
#define DialogSnar_H

#include <QMainWindow>

namespace Ui {
class DialogSnar;
}

class DialogSnar : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogSnar(QWidget *parent = 0);
    ~DialogSnar();
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
    Ui::DialogSnar *ui;

};

#endif // DialogSnar_H
