# After adding classes that inherit QObject and have Q_OBJECT functionality,
# for example signals or slots, you have to "force" qtcreator to reparse the
# subproject (e.g. make a null change to the *.pro file) so that the makefiles
# are regenerated and new MOC files are created for the new or modified classes.

CONFIG  += exceptions
DEFINES += VISUALISATION_LIBRARY

include(../../libs/boost.pri)
include(../../ligerplugin.pri)

# Version check qt
!minQtVersion(5, 6, 0) {
    message("Cannot build Visualisation Pulgin with Qt version $${QT_VERSION}.")
    error("Use at least Qt 5.6.0.")
}

QT += widgets printsupport svg
QT += webenginewidgets webchannel

linux-* {

}

macx {

}

win32 {

}


SOURCES +=  \
    visualisationplugin.cpp \
    qvizparallelcoordinatesnodefactory.cpp \
    qvizparallelcoordinatesnode.cpp \
    qvizscatterplotnodefactory.cpp \
    qvizscatterplotnode.cpp \
    qvizmscatterplotnodefactory.cpp \
    qvizmscatterplotnode.cpp \
    core/selectplotvarsform.cpp \
    core/visualisationdatamodel.cpp \
    core/visualisationviewmodel.cpp \
    qviznode.cpp \
    core/matrixscatterplotwidget.cpp \
    core/parallelcoordinatesplotwidget.cpp \
    core/scatterplotwidget.cpp \
    core/visualisationwidget.cpp \
    iterationinteruptor.cpp

HEADERS +=  \
    visualisationplugin.h  \
    visualisation_global.h  \
    visualisationconstants.h \
    qvizparallelcoordinatesnodefactory.h \
    qvizparallelcoordinatesnode.h \
    qvizscatterplotnodefactory.h \
    qvizscatterplotnode.h \
    qvizmscatterplotnodefactory.h \
    qvizmscatterplotnode.h \
    core/selectplotvarsform.h  \
    core/visualisationdatamodel.h \
    core/visualisationviewmodel.h \
    qviznode.h \
    core/parallelcoordinatesplotwidget.h \
    core/scatterplotwidget.h \
    core/matrixscatterplotwidget.h \
    core/visualisationwidget.h \
    iterationinteruptor.h

RESOURCES += \
    visualisation.qrc

FORMS += \
    core/selectplotvarsform.ui \
    core/visualisationwidget.ui
