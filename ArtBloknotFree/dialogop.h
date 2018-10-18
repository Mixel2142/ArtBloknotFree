#ifndef DIALOGOP_H
#define DIALOGOP_H

#include <QDialog>

namespace Ui {
class DialogOP;
}

class DialogOP : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOP(QWidget *parent = 0);
    ~DialogOP();

private:
    Ui::DialogOP *ui;
};

#endif // DIALOGOP_H
