#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headers.h"
#include <QScroller>
#include <QAndroidJniEnvironment>
#include <QandroidJniObject>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();//ОГЗ(Обратная геодезическая задача)

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_8_pressed();

    void on_pushButton_9_clicked();

    void on_pushButton_9_pressed();

    void on_pushButton_10_clicked();

    void on_pushButton_10_pressed();

private:
    Ui::MainWindow *ui;
     QDinamicData *DataD;
     QPoint m_clickPos;
bool btnEnabled=true;
void mousePressEvent();

void mouseReleaseEvent();

};

#endif // MAINWINDOW_H
