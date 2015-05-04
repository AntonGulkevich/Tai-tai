#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T11:16:00
#
#-------------------------------------------------
QT       += core gui network webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tai-tai
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    profilewindow.cpp \
    exlabel.cpp \
    exbutton.cpp \
    groupexbuttons.cpp \
    profile.cpp \
    profilesetupwindow.cpp \
    account.cpp \
    domain.cpp \
    baseimap.cpp \
    smtp.cpp \
    message.cpp \
    quotedprintable.cpp \
    imap.cpp \
    threadpop3.cpp \
    threadimap.cpp \
    basepop3.cpp \
    pop3.cpp

HEADERS  += mainwindow.h \
    profilewindow.h \
    exlabel.h \
    exbutton.h \
    groupexbuttons.h \
    profile.h \
    profilesetupwindow.h \
    account.h \
    domain.h \
    basepop3.h \
    baseimap.h \
    imap.h \
    message.h \
    pop3.h \
    quotedprintable.h \
    smtp.h \
    threadimap.h \
    threadpop3.h

RESOURCES += \
    icons.qrc

OTHER_FILES +=
