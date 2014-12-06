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
    CDuree.h \
    CstCodErr.h \
    CEditable.h \
    CEditable.hxx \
    CDuree.hxx \
    CException.h \
    CException.hxx \
    IziAssert.h \
    CNode.h \
    CNode.hxx \
    CListV2.h \
    CRIterator.h \
    CList.h \
    CList.hxx

