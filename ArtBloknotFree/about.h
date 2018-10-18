#ifndef ABOUT_H
#define ABOUT_H

#include <QMainWindow>
#include <kratko.h>
#include <sokr.h>
namespace Ui {
class About;
}

class About : public QMainWindow
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
