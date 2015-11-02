TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += include
INCLUDEPATH += /usr/local/include

SOURCES += \
    src/game.cpp \
    src/inputsystem.cpp \
    src/main.cpp \
    src/rendersystem.cpp \
    src/movementsystem.cpp \
    src/world.cpp \
    src/collidesystem.cpp \
    src/iasystem.cpp

QMAKE_CXXFLAGS += -std=c++14

LIBS += -lsfml-graphics -lsfml-window -lsfml-system
HEADERS += \
    include/components.hpp \
    include/game.hpp \
    include/system.hpp \
    include/world.hpp

