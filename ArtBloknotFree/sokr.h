#ifndef SOKR_H
#define SOKR_H

#include <QMainWindow>
#include <headers.h>
namespace Ui {
class Sokr;
}

class Sokr : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sokr(QWidget *parent = 0);
    ~Sokr();

private:
    Ui::Sokr *ui;
};

#endif // SOKR_H
