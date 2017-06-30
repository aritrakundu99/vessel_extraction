QT += core
QT -= gui

CONFIG += c++11

TARGET = read_pgm
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    image.cpp

HEADERS += \
    image.hpp
