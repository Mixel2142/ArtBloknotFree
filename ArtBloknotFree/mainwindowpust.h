#ifndef MAINWINDOWPUST_H
#define MAINWINDOWPUST_H

#include <QMainWindow>
#include "headers.h"
namespace Ui {
class MainWindowPust;
}

class MainWindowPust : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowPust(QWidget *parent = 0);
    ~MainWindowPust();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindowPust *ui;
};

#endif // MAINWINDOWPUST_H
