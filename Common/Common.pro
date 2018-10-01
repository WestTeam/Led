# Copyright (c) 2018 All Rights Reserved WestBot

TEMPLATE = lib
CONFIG = staticlib
CONFIG += c++11

INCLUDEPATH = /usr/local/include

PROTOS = proto/led.proto
LIBS += -L/usr/local/lib/ -lgrpc++ -lgrpc -lgpr -lgrpc++_reflection -lprotobuf

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    led.grpc.pb.cc \
    led.pb.cc

HEADERS += \
    led.grpc.pb.h \
    led.pb.h
