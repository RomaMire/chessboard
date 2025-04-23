QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bishop.cpp \
    Chessboard.cpp \
    Figure.cpp \
    King.cpp \
    Knight.cpp \
    Pawn.cpp \
    Queen.cpp \
    Rook.cpp \
    figurecreation.cpp \
    main.cpp \
    mainwindow.cpp \
    startwindows.cpp


HEADERS += \
    Bishop.h \
    Chessboard.h \
    Figure.h \
    King.h \
    Knight.h \
    Pawn.h \
    Queen.h \
    Rook.h \
    figurecreation.h \
    mainwindow.h \
    startwindows.h

FORMS += \
    mainwindow.ui \
    startwindows.ui

macx-clang {
    QMAKE_APPLE_DEVICE_ARCHS = arm64
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/bbishop.png \
    img/bking.png \
    img/bknight.png \
    img/bpawn.png \
    img/bqueen.png \
    img/brook.png \
    img/wbishop.png \
    img/wking.png \
    img/wknight.png \
    img/wpawn.png \
    img/wqueen.png \
    img/wrook.png \
    img/hero.jpg

RESOURCES += \
    images.qrc
