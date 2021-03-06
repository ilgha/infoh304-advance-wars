#-------------------------------------------------
#
# Project created by QtCreator 2018-10-23T12:26:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_Graphique
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    infantery.cpp \
    Player.cpp \
    Unit.cpp \
    game.cpp \
    Land.cpp \
    Plain.cpp \
    building.cpp \
    factory.cpp \
    map.cpp \
    bridge.cpp \
    mountain.cpp \
    river.cpp \
    road.cpp \
    woods.cpp \
    AntiAir.cpp \
    BCopter.cpp \
    Bomber.cpp \
    Fighter.cpp \
    MdTank.cpp \
    Mech.cpp \
    MegaTank.cpp \
    NeoTank.cpp \
    Recon.cpp \
    Tank.cpp \
    Airport.cpp \
    City.cpp

HEADERS += \
        mainwindow.h \
    infantery.h \
    Player.h \
    game.h \
    unit.h \
    Land.h \
    Plain.h \
    building.h \
    factory.h \
    map.h \
    bridge.h \
    mountain.h \
    river.h \
    road.h \
    woods.h \
    AntiAir.h \
    BCopter.h \
    Bomber.h \
    Fighter.h \
    MdTank.h \
    Mech.h \
    MegaTank.h \
    NeoTank.h \
    Recon.h \
    Tank.h \
    Airport.h \
    City.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    tileset projet.png

RESOURCES += \
    sprites.qrc
