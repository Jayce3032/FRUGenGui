QT += widgets

MAKE_TARGET_COMPANY = "Personal"
QMAKE_TARGET_DESCRIPTION = "fru gui editor"
QMAKE_TARGET_COPYRIGHT = "All rights reseverd, only for study."
QMAKE_TARGET_PRODUCT = FRU

INCLUDEPATH = "."
RC_ICONS = logo.ico

HEADERS     = window.h \
    fru.h \
    smbios.h

SOURCES     = main.cpp\
              window.cpp\
    fru.cpp \
    config.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/fru
INSTALLS += target

DISTFILES +=
