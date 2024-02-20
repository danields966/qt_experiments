QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    window.cpp \
    coloritem.cpp \
    robot.cpp \
    button.cpp \
    calculator.cpp \
    mainwindow.cpp \
    optionsdialog.cpp \
    src/qhexedit.cpp \
    src/chunks.cpp \
    src/commands.cpp \
    searchdialog.cpp

HEADERS += \
    window.h \
    coloritem.h \
    robot.h \
    button.h \
    calculator.h \
    mainwindow.h \
    optionsdialog.h \
    src/qhexedit.h \
    src/chunks.h \
    src/commands.h \
    searchdialog.h


RESOURCES = \
    qhexedit.qrc

FORMS += \
    optionsdialog.ui \
    searchdialog.ui

LIBS += "$$PWD/goLib/goLib.a"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
