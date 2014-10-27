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


SOURCES += main.cpp\
    CDailyWeatherModel.cpp \
    CMainWindow.cpp \
    CStation.cpp \
    CTableView.cpp \
    CXMLParser.cpp \


HEADERS  += \
    CDailyWeatherModel.h \
    CMainWindow.h \
    CStation.h \
    CTableView.h \
    CXMLParser.h


FORMS    += mainwindow.ui
