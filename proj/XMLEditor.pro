#-------------------------------------------------
#
# Project created by QtCreator 2014-09-18T08:09:09
#
#-------------------------------------------------

QT       += core gui
QT       += xml # to allow use of QDom Library
QMAKE_MAC_SDK = macosx10.9

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XMLEditor
TEMPLATE = app

SOURCES += main.cpp \
    CDailyWeatherModel.cpp \
    CLaunchWindow.cpp\
    CWindowSDB.cpp \
    CWindowWDB.cpp \
    CSoil.cpp \
    CSoilLayerModel.cpp \
    CStation.cpp \
    CXMLParser.cpp

HEADERS  += CDailyWeatherModel.h \
    CLaunchWindow.h \
    CWindowSDB.h \
    CWindowWDB.h \
    CSoil.h \
    CSoilLayerModel.h \
    CStation.h \
    CXMLParser.h

FORMS    += ui/launch.ui \
    ui/wdb.ui \
    ui/sdb.ui
