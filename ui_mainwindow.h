/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(280, 420);
        MainWindow->setMaximumSize(QSize(1080, 1920));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(12);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        pushButton_2->setFont(font);
        pushButton_2->setAutoRepeatInterval(50);

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(16777215, 16777215));
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(16777215, 16777215));
        pushButton_3->setFont(font);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(16777215, 16777215));
        pushButton_4->setFont(font);

        verticalLayout->addWidget(pushButton_4);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\320\237(\320\236\320\263\320\275\320\265\320\262\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\321\217)", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\223\320\227(\320\237\321\200\321\217\320\274\320\260\321\217 \320\263\320\265\320\276\320\264\320\265\320\267\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260)", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\232\320\235\320\237(\320\232\320\276\320\274\320\260\320\275\320\264\320\275\320\276 \320\275\320\260\320\261\320\273\321\216\320\264\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\277\321\203\320\275\320\272\321\202\321\213)", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\236\320\223\320\227(\320\236\320\261\321\200\320\260\321\202\320\275\320\260\321\217 \320\263\320\265\320\276\320\264\320\265\320\267\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
