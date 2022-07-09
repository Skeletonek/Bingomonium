QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bingo.cpp \
    bingofileparser.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    bingo.h \
    bingofileparser.h \
    mainwindow.h

FORMS += \
    bingo.ui \
    mainwindow.ui

TRANSLATIONS += \
    Bingomonium_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    logo.xpm

RESOURCES += \
    QtResourceFile.qrc

unix:linux: copydata.commands = $(COPY_DIR) $$shell_path($$PWD/bingos) $$shell_path($$OUT_PWD)
else: windows: copydata.commands = $(COPY_DIR) $$shell_path($$PWD/bingos) $$shell_path($$OUT_PWD/bingos)
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
