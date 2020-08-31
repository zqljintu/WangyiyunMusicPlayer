#-------------------------------------------------
#
# Project created by QtCreator 2016-11-14T20:35:55
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       +=sql
QT       += core gui  quickwidgets
QT       += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wagyiyunyinyue
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    searchwidget.cpp \
    dowidget.cpp \
    qbjectwidget.cpp \
    qbject_showuserwidget.cpp \
    qbject_showmessagewidget.cpp \
    down_playwidget.cpp \
    down_progressbarwidget.cpp \
    down_voicewidget.cpp \
    down_setingwidget.cpp \
    seting_showmusiclistwidget.cpp \
    left_musicbutton.cpp \
    left_musicshowwidget.cpp \
    left_tablewidget.cpp \
    center_tagshow.cpp \
    lrc_mainwindow.cpp

HEADERS  += mainwindow.h \
    searchwidget.h \
    dowidget.h \
    qbjectwidget.h \
    qbject_showuserwidget.h \
    qbject_showmessagewidget.h \
    down_playwidget.h \
    down_progressbarwidget.h \
    down_voicewidget.h \
    down_setingwidget.h \
    seting_showmusiclistwidget.h \
    left_musicbutton.h \
    left_musicshowwidget.h \
    left_tablewidget.h \
    center_tagshow.h \
    lrc_mainwindow.h

RESOURCES += \
    res.qrc
RC_FILE = wangyi.rc

DISTFILES += \
    tagQml.qml
