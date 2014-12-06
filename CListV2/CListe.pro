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
    CListV1.h \
    CListV1.hxx \
    CNode.h \
    CNode.hxx \
    CListV2.h \
    CIterator.hxx \
    CIterator.h \
    CRIterator.h

