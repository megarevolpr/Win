#-------------------------------------------------
#
# Project created by QtCreator 2023-04-04T16:12:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PCS_V1.0.4
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#include         ($$PWD/UI_NumberKeyboard/UI_NumberKeyboard.pri)
#include         ($$PWD/UI_Network/UI_Network.pri)
#include         ($$PWD/Messagebox/Messagebox.pri)
include         ($$PWD/UI_Menu/UI_Menu.pri)
include         ($$PWD/Specification/Specification.pri)
include         ($$PWD/UpgradeTools/UpgradeTools.pri)
include         ($$PWD/GridExpansion/GridExpansion.pri)
include         ($$PWD/FaultTableInterface/FaultTableInterface.pri)

#INCLUDEPATH     +=$$PWD/Messagebox/
INCLUDEPATH     +=$$PWD/UI_Menu/
INCLUDEPATH     +=$$PWD/Specification/
INCLUDEPATH     +=$$PWD/UpgradeTools/
INCLUDEPATH     +=$$PWD/GridExpansion/
INCLUDEPATH     +=$$PWD/FaultTableInterface/


CONFIG += c++11

SOURCES += \
        main.cpp \
        win.cpp \

HEADERS += \
        win.h \

FORMS += \
        win.ui

TRANSLATIONS += \
    $$PWD/Language/CN.ts\
    $$PWD/Language/EN.ts\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    language.qrc \
    faultdescription.qrc

DISTFILES += \
    Language/CN.ts \
    Language/EN.ts
