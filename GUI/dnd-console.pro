QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += "..\Python310\include"
DEPENDPATH += "..\Python310\libs"
LIBS += -L "..\Python310\libs" -l"Python310"
RESOURCES     = resources.qrc \
    resources.qrc
SOURCES += \
    main.cpp \
    dice.cpp \
    initiative.cpp \
    player.cpp \
    skillcheck.cpp \
    webScrape.cpp \
    widget.cpp


HEADERS += \
    dice.h \
    initiative.h \
    player.h \
    skillcheck.h \
    webScrape.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
