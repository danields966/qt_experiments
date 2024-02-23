QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/main.cpp \
    src/lineedits/lineedits.cpp \
    src/calculator/button.cpp \
    src/calculator/calculator.cpp \
    src/dragdroprobot/coloritem.cpp \
    src/dragdroprobot/robot.cpp \
    src/hexeditor/hexwindow.cpp \
    src/hexeditor/optionsdialog.cpp \
    src/hexeditor/searchdialog.cpp \
    src/hexeditor/qhexedit/qhexedit.cpp \
    src/hexeditor/qhexedit/chunks.cpp \
    src/hexeditor/qhexedit/commands.cpp

HEADERS += \
    src/lineedits/lineedits.h \
    src/calculator/button.h \
    src/calculator/calculator.h \
    src/dragdroprobot/coloritem.h \
    src/dragdroprobot/robot.h \
    src/hexeditor/hexwindow.h \
    src/hexeditor/optionsdialog.h \
    src/hexeditor/searchdialog.h \
    src/hexeditor/qhexedit/qhexedit.h \
    src/hexeditor/qhexedit/chunks.h \
    src/hexeditor/qhexedit/commands.h


RESOURCES = \
    src/hexeditor/qhexedit.qrc

FORMS += \
    src/hexeditor/optionsdialog.ui \
    src/hexeditor/searchdialog.ui

contains(QT_ARCH, i386) {
    LIBS += "$$PWD/goLib/goLib32.a"
} else {
    LIBS += "$$PWD/goLib/goLib64.a"
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
