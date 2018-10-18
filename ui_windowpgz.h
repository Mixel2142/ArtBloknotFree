/********************************************************************************
** Form generated from reading UI file 'windowpgz.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWPGZ_H
#define UI_WINDOWPGZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowPGZ
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WindowPGZ)
    {
        if (WindowPGZ->objectName().isEmpty())
            WindowPGZ->setObjectName(QStringLiteral("WindowPGZ"));
        WindowPGZ->resize(365, 333);
        centralwidget = new QWidget(WindowPGZ);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMaximumSize(QSize(500, 500));
        scrollArea->setContextMenuPolicy(Qt::ActionsContextMenu);
        scrollArea->setFrameShape(QFrame::Panel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 328, 293));
        pushButton = new QPushButton(scrollAreaWidgetContents_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 20, 75, 23));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 180, 75, 23));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 340, 75, 23));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 430, 75, 23));
        pushButton_5 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 530, 75, 23));
        pushButton_6 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(70, 640, 75, 23));
        pushButton_7 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(60, 580, 75, 23));
        pushButton_8 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(70, 710, 75, 23));
        pushButton_9 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(50, 780, 75, 23));
        pushButton_10 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(30, 80, 75, 23));
        pushButton_11 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(50, 140, 75, 23));
        pushButton_12 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(50, 250, 75, 23));
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        WindowPGZ->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WindowPGZ);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WindowPGZ->setStatusBar(statusbar);

        retranslateUi(WindowPGZ);

        QMetaObject::connectSlotsByName(WindowPGZ);
    } // setupUi

    void retranslateUi(QMainWindow *WindowPGZ)
    {
        WindowPGZ->setWindowTitle(QApplication::translate("WindowPGZ", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_7->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_8->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_9->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_10->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_11->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
        pushButton_12->setText(QApplication::translate("WindowPGZ", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowPGZ: public Ui_WindowPGZ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWPGZ_H
