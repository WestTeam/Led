# Copyright (c) 2018 All Rights Reserved WestBot

QT += core
QT -= gui

CONFIG += c++11

TARGET = client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = /usr/local/include

LIBS += -L/usr/local/lib/ -lgrpc++ -lgrpc -lgpr -lgrpc++_reflection -lprotobuf

SOURCES += main.cpp \
    ../Common/led.grpc.pb.cc \
    ../Common/led.pb.cc

HEADERS += \
    ../Common/led.grpc.pb.h \
    ../Common/led.pb.h
