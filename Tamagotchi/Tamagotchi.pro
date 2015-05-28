#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T18:49:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tamagotchi
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    jugar.cpp \
    ptamagotchi.cpp \
    nodo.cpp \
    pilas.cpp \
    colas.cpp

HEADERS  += menu.h \
    jugar.h \
    ptamagotchi.h \
    nodo.h \
    pilas.h \
    colas.h

FORMS    += menu.ui \
    jugar.ui

RESOURCES += \
    imagen.qrc
