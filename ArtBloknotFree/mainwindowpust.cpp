#include "mainwindowpust.h"
#include "ui_mainwindowpust.h"

MainWindowPust::MainWindowPust(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowPust)
{
    ui->setupUi(this);
     this->show();
}

MainWindowPust::~MainWindowPust()
{
    delete ui;
}

void MainWindowPust::on_pushButton_clicked()
{
    QDynamicButton *button = new QDynamicButton(this);  // Создаем объект динамической кнопки
       /* Устанавливаем текст с номером этой кнопки
        * */
       button->setText("Кнопочка " + QString::number(button->getID()));
       /* Добавляем кнопку в слой с вертикальной компоновкой
        * */
       ui->verticalLayout->addWidget(button);

       /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
        * */
       //connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
}
