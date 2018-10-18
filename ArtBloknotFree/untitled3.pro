#-------------------------------------------------
#
# Project created by QtCreator 2018-07-01T19:36:56
#
#-------------------------------------------------

QT       += \
    core gui \
    androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    windowop.cpp \
    windowpgz.cpp \
    windowknp.cpp \
    windowzwiths.cpp \
    data.cpp \
    qdinamicdata.cpp \
    windowogz.cpp \
    windowpopr.cpp \
    windowceli.cpp \
    dialog.cpp \
    windowogn.cpp \
    newdialog.cpp \
    tabfire.cpp \
    dialogtabl.cpp \
    dialogsnar.cpp \
    dialogzar.cpp \
    dialogchoicesyst.cpp \
    about.cpp \
    kratko.cpp \
    sokr.cpp

HEADERS += \
        mainwindow.h \
    windowop.h \
    windowpgz.h \
    windowknp.h \
    windowzwiths.h \
    data.h \
    headers.h \
    qdinamicdata.h \
    windowogz.h \
    windowpopr.h \
    windowceli.h \
    dialog.h \
    windowogn.h \
    newdialog.h \
    tabfire.h \
    dialogtabl.h \
    dialogsnar.h \
    dialogzar.h \
    dialogchoicesyst.h \
    about.h \
    kratko.h \
    sokr.h

FORMS += \
        mainwindow.ui \
    windowop.ui \
    windowpgz.ui \
    windowknp.ui \
    windowzwiths.ui \
    windowogz.ui \
    windowpopr.ui \
    windowceli.ui \
    dialog.ui \
    windowogn.ui \
    newdialog.ui \
    tabfire.ui \
    dialogtabl.ui \
    dialogsnar.ui \
    dialogzar.ui \
    dialogchoicesyst.ui \
    about.ui \
    kratko.ui \
    sokr.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

RESOURCES += \
    resursi.qrc

