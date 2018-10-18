#ifndef KRATKO_H
#define KRATKO_H

#include <QMainWindow>
#include <headers.h>
namespace Ui {
class Kratko;
}

class Kratko : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kratko(QWidget *parent = 0);
    ~Kratko();

private:
    Ui::Kratko *ui;
};

#endif // KRATKO_H
