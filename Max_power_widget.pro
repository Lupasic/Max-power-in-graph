#-------------------------------------------------
#
# Project created by QtCreator 2015-05-05T10:37:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = Max_power_widget
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    ellipsview.cpp \
    Ellips.cpp \
    Line2D.cpp \
    Point2D.cpp \
    GraphNode.cpp \
    graphview.cpp \
    GreedyIndependentSetFinding.cpp \
    IntersectionFinder.cpp \
    IntersectionFinderTest.cpp \
    IntervalIntersectionFinder.cpp \
    MaxIndependentSetFinder.cpp \
    reshenie.cpp \
    Poisk_peresech.cpp

HEADERS  += \
    ellipsview.h \
    mainwindow.h \
    Ellips.h \
    Line2D.h \
    Point2D.h \
    GeometryPrimitives.h \
    Graph.h \
    GraphNode.h \
    graphview.h \
    GreedyIndependentSetFinding.h \
    IntersectionFinder.h \
    IntersectionFinderTest.h \
    IntervalIntersectionFinder.h \
    MaxIndependentSetFinder.h \
    reshenie.h \
    Poisk_peresech.h

FORMS    += \
    mainwindow.ui

DISTFILES +=
