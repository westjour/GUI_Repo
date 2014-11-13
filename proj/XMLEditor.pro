#-------------------------------------------------
#
# Project created by QtCreator 2014-09-18T08:09:09
#
#-------------------------------------------------

QT       += core gui
QT       += xml # to allow use of QDom Library

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XMLEditor
TEMPLATE = app

SOURCES += main.cpp \
    CDailyWeatherModel.cpp \
    CLaunchWindow.cpp\
    CWindowSDB.cpp \
    CWindowWDB.cpp \
    CStation.cpp \
    CXMLParser.cpp

HEADERS  += CDailyWeatherModel.h \
    CLaunchWindow.h \
    CWindowSDB.h \
    CWindowWDB.h \
    CStation.h \
    CXMLParser.h

FORMS    += ui/mainwindow.ui \
    ui/launch.ui
