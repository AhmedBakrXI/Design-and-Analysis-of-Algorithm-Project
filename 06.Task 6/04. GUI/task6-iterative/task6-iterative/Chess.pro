#-------------------------------------------------
#
# Project created by QtCreator 2017-04-25T17:19:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp \
    Graph.cpp \
    Square.cpp \
    chess_board.cpp \
    game.cpp \
    chessbox.cpp \
    chessboard.cpp \
    chesspiece.cpp \
    knight.cpp \
    button.cpp

HEADERS  += \
    Graph.h \
    Move.h \
    Square.h \
    chess_board.h \
    game.h \
    chessbox.h \
    chessboard.h \
    chesspiece.h \
    knight.h \
    button.h

FORMS    +=

RESOURCES += \
    resource.qrc
