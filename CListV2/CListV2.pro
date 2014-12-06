TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
CONFIG += -Wall

SOURCES += \
    CDuree.cxx \
    CException.cxx \
    main.cpp

HEADERS += \
    CDuree.h \
    CDuree.hxx \
    CEditable.h \
    CEditable.hxx \
    CException.h \
    CException.hxx \
    CIterator.h \
    CIterator.hxx \
    CList.h \
    CList.hxx \
    CNode.h \
    CNode.hxx \
    CRIterator.h \
    CstCodErr.h \
    IziAssert.h

