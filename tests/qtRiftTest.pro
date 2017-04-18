INCLUDEPATH += "googletest/include"
INCLUDEPATH += "googletest"
INCLUDEPATH += "googlemock/include"
INCLUDEPATH += "googlemock"
INCLUDEPATH += "../qtRift"
TEMPLATE = app
CONFIG += console c++11
CONFIG += warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    googletest/src/gtest-all.cc \
    googlemock/src/gmock-all.cc \
    ../qtRift/creature.cpp \
    ../qtRift/enemy.cpp \
    ../qtRift/field.cpp \
    ../qtRift/globalPhaseControl.cpp \
    ../qtRift/map.cpp \
    ../qtRift/perks.cpp \
    ../qtRift/player.cpp \
    ../qtRift/stats.cpp


HEADERS += \
    ../qtRift/battlePhaseControl.h \
    ../qtRift/creature.h \
    ../qtRift/creature_defines.h \
    ../qtRift/enemy.h \
    ../qtRift/field.h \
    ../qtRift/globalPhaseControl.h \
    ../qtRift/map.h \
    ../qtRift/map_defines.h \
    ../qtRift/perks.h \
    ../qtRift/player.h \
    ../qtRift/skills.h \
    ../qtRift/stats.h

SUBDIRS += \
    ../qtRift/qtRift.pro
