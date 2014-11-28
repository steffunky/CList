TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CDuree.cxx \
    CException.cxx
CONFIG += c++11
CONFIG += -Wall

HEADERS += \
    CNode.h \
    CNode.hxx \
    CList.h \
    CList.hxx \
    CDuree.h \
    CstCodErr.h \
    CEditable.h \
    CEditable.hxx \
    CDuree.hxx \
    CException.h \
    CException.hxx

