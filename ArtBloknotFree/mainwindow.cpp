#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QScrollBar>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

  //  this->setStyleSheet("border: 1px solid black; background: rgb(180,230,180)");
  //  this->setStyleSheet("background: rgb(180,230,180)");

    QDir dr("/storage/emulated/0/.ArKoData");
    QString path = dr.path();
    if(!dr.exists())dr.mkdir(path);
    QAbstractScrollArea *area=qobject_cast<QAbstractScrollArea*>(ui->scrollArea);
    QScroller::grabGesture(area->viewport(),QScroller::TouchGesture);
    ui->scrollArea->verticalScrollBar()->setSingleStep(1);
    DataD=new QDinamicData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()//ОП(Огневая позиция)
{
    mouseReleaseEvent();
   if(btnEnabled==true){
WindowOP *op;
op=new WindowOP(this);
    }

}

void MainWindow::on_pushButton_clicked()//ПГЗ(Прямая геодезическая задача)
{
        mouseReleaseEvent();
     if(btnEnabled==true){
    WindowPGZ *pgz;
    pgz = new WindowPGZ(this);
     }

}

void MainWindow::on_pushButton_3_clicked()//КНП(Командно наблюдательные пункты)
{
        mouseReleaseEvent();
     if(btnEnabled==true){
WindowKNP *knp;
knp=new WindowKNP(this);
     }

}

void MainWindow::on_pushButton_4_clicked()//ОГЗ(Обратная геодезическая задача)
{
    mouseReleaseEvent();
 if(btnEnabled==true){
WindowOGZ *ogz;
ogz=new WindowOGZ(this);
 }

}

void MainWindow::on_pushButton_5_clicked()//Засечка с секундомером
{
        mouseReleaseEvent();
     if(btnEnabled==true){
    WindowZwithS *ZwS;
    ZwS=new WindowZwithS(this);
     }

}

void MainWindow::on_pushButton_6_clicked()
{
        mouseReleaseEvent();
     if(btnEnabled==true){
    WindowPopr *PoPr;
    PoPr=new WindowPopr(this);
     }

}

void MainWindow::on_pushButton_7_clicked()
{
        mouseReleaseEvent();
     if(btnEnabled==true){
    WindowCeli *celi=new WindowCeli(this);

     }

}
void MainWindow::on_pushButton_9_clicked()
{
    mouseReleaseEvent();
 if(btnEnabled==true){
 DataD->ReSetFile("Tablstr.txt","","A:","B:","Q:");
TabFire *tabl;
tabl=new TabFire(this);
 }
}

void MainWindow::on_pushButton_9_pressed()
{
     mousePressEvent();
}
void MainWindow::on_pushButton_8_clicked()
{
        mouseReleaseEvent();
     if(btnEnabled==true){
    DataD->ReSetFile("Popr.txt","");
    DataD->ReSetFile("Tablstr.txt","","A:","B:","Q:");
    WindowOgn *ogn;
    ogn=new WindowOgn(this);
     }

}

void MainWindow::mousePressEvent()
{
    btnEnabled=false;
   m_clickPos.setX(ui->scrollArea->verticalScrollBar()->value());
   m_clickPos.setY(ui->scrollArea->horizontalScrollBar()->value());
    //ui->label->setText("X:"+QString::number( m_clickPos.x())+" Y:"+QString::number( m_clickPos.y())+" delta="+QString::number(m_clickPos.manhattanLength())+" flag="+QString::number(btnEnabled));
 /*   m_clickPos=event->pos();
   ui->label->setText("X:"+QString::number( m_clickPos.x())+" Y:"+QString::number( m_clickPos.y())+" delta="+QString::number(m_clickPos.manhattanLength())+" flag="+QString::number(btnEnabled));
*/
}

void MainWindow::mouseReleaseEvent()
{
    int x=m_clickPos.x();
    m_clickPos.setX(abs(x-ui->scrollArea->verticalScrollBar()->value()));
    if(abs(m_clickPos.x())>1)btnEnabled=false;
    else btnEnabled=true;
//   ui->label->setText("X:"+QString::number( m_clickPos.x())+" Y:"+QString::number( m_clickPos.y())+" delta="+QString::number(m_clickPos.manhattanLength())+" flag="+QString::number(btnEnabled));
   m_clickPos.setX(ui->scrollArea->verticalScrollBar()->value());
   m_clickPos.setY(ui->scrollArea->horizontalScrollBar()->value());
   /*
    m_clickPos=event->pos();
    if(m_clickPos.manhattanLength()>10)btnEnabled=false;
    else btnEnabled=true;
   ui->label->setText("X:"+QString::number( m_clickPos.x())+" Y:"+QString::number( m_clickPos.y())+" delta="+QString::number(m_clickPos.manhattanLength())+" flag="+QString::number(btnEnabled));
*/
}


void MainWindow::on_pushButton_2_pressed()
{
   mousePressEvent();
}

void MainWindow::on_pushButton_6_pressed()
{
    mousePressEvent();
}

void MainWindow::on_pushButton_3_pressed()
{
    mousePressEvent();
}

void MainWindow::on_pushButton_7_pressed()
{
    mousePressEvent();
}

void MainWindow::on_pushButton_5_pressed()
{
    mousePressEvent();
}

void MainWindow::on_pushButton_pressed()
{
    mousePressEvent();
}

void MainWindow::on_pushButton_4_pressed()
{
    mousePressEvent();
}

void MainWindow::on_pushButton_8_pressed()
{
    mousePressEvent();
}




void MainWindow::on_pushButton_10_clicked()
{
  mouseReleaseEvent();
 if(btnEnabled==true){
About *ab=new About(this);

 }
}

void MainWindow::on_pushButton_10_pressed()
{
    mousePressEvent();
}
