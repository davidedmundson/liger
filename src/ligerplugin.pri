depfile = $$replace(_PRO_FILE_PWD_, ([^/]+$), \\1/\\1_dependencies.pri)
exists($$depfile) {
    include($$depfile)
    isEmpty(QTC_PLUGIN_NAME): \
        error("$$basename(depfile) does not define QTC_PLUGIN_NAME.")
} else {
    isEmpty(QTC_PLUGIN_NAME): \
        error("QTC_PLUGIN_NAME is empty. Maybe you meant to create $$basename(depfile)?")
}
TARGET = $$QTC_PLUGIN_NAME

plugin_deps = $$QTC_PLUGIN_DEPENDS
plugin_recmds = $$QTC_PLUGIN_RECOMMENDS

include(../liger.pri)
# for substitution in the .pluginspec
dependencyList = "<dependencyList>"
for(dep, plugin_deps) {
    dependencies_file =
    for(dir, QTC_PLUGIN_DIRS) {
        exists($$dir/$$dep/$${dep}_dependencies.pri) {
            dependencies_file = $$dir/$$dep/$${dep}_dependencies.pri
            break()
        }
    }
    isEmpty(dependencies_file): \
        error("Plugin dependency $$dep not found")
    include($$dependencies_file)
    dependencyList += "        <dependency name=\"$$QTC_PLUGIN_NAME\" compatVersion=\"$$LIGER_COMPAT_VERSION\"/>"
}
for(dep, plugin_recmds) {
    dependencies_file =
    for(dir, QTC_PLUGIN_DIRS) {
        exists($$dir/$$dep/$${dep}_dependencies.pri) {
            dependencies_file = $$dir/$$dep/$${dep}_dependencies.pri
            break()
        }
    }
    isEmpty(dependencies_file): \
        error("Plugin dependency $$dep not found")
    include($$dependencies_file)
    dependencyList += "        <dependency name=\"$$QTC_PLUGIN_NAME\" compatVersion=\"$$LIGER_COMPAT_VERSION\" type=\"optional\"/>"
}
dependencyList += "    </dependencyList>"
dependencyList = $$join(dependencyList, $$escape_expand(\\n))

# use precompiled header for libraries by default
CONFIG += precompile_header
DEFINES += USING_PCH
isEmpty(PRECOMPILED_HEADER):PRECOMPILED_HEADER = $$PWD/shared/liger_gui_pch.h

isEmpty(USE_USER_DESTDIR) {
    DESTDIR = $$LIGER_PLUGIN_PATH
} else {
    win32 {
        DESTDIRAPPNAME = "liger"
        DESTDIRBASE = "$$(LOCALAPPDATA)"
        isEmpty(DESTDIRBASE):DESTDIRBASE="$$(USERPROFILE)\Local Settings\Application Data"
    } else:macx {
        DESTDIRAPPNAME = "Liger"
        DESTDIRBASE = "$$(HOME)/Library/Application Support"
    } else:unix {
        DESTDIRAPPNAME = "liger"
        DESTDIRBASE = "$$(XDG_DATA_HOME)"
        isEmpty(DESTDIRBASE):DESTDIRBASE = "$$(HOME)/.local/share/data"
        else:DESTDIRBASE = "$$DESTDIRBASE/data"
    }
    DESTDIR = "$$DESTDIRBASE/LigerProject/$$DESTDIRAPPNAME/plugins/$$LIGER_VERSION"
}
LIBS += -L$$DESTDIR

# copy the plugin spec
isEmpty(TARGET) {
    error("ligerplugin.pri: You must provide a TARGET")
}


defineReplace(stripOutDir) {
    return($$relative_path($$1, $$OUT_PWD))
}

PLUGINSPEC = $$_PRO_FILE_PWD_/$${TARGET}.pluginspec
PLUGINSPEC_IN = $${PLUGINSPEC}.in
exists($$PLUGINSPEC_IN) {
    OTHER_FILES += $$PLUGINSPEC_IN
    QMAKE_SUBSTITUTES += $$PLUGINSPEC_IN
    PLUGINSPEC = $$OUT_PWD/$${TARGET}.pluginspec
    copy2build.output = $$DESTDIR/${QMAKE_FUNC_FILE_IN_stripOutDir}
} else {
    # need to support that for external plugins
    OTHER_FILES += $$PLUGINSPEC
    copy2build.output = $$DESTDIR/${QMAKE_FUNC_FILE_IN_stripSrcDir}
}
copy2build.input = PLUGINSPEC
isEmpty(vcproj):copy2build.variable_out = PRE_TARGETDEPS
copy2build.commands = $$QMAKE_COPY ${QMAKE_FILE_IN} ${QMAKE_FILE_OUT}
copy2build.name = COPY ${QMAKE_FILE_IN}
copy2build.CONFIG += no_link no_clean
QMAKE_EXTRA_COMPILERS += copy2build

#   Create a Json file containing the plugin information required by
#   Qt 5's plugin system by running a XSLT sheet on the
#   pluginspec file before moc runs.
XMLPATTERNS = $$targetPath($$[QT_INSTALL_BINS]/xmlpatterns)

pluginspec2json.name = Create Qt 5 plugin json file
pluginspec2json.input = PLUGINSPEC
pluginspec2json.variable_out = GENERATED_FILES
pluginspec2json.output = $${TARGET}.json
pluginspec2json.commands = $$XMLPATTERNS -no-format -output $$pluginspec2json.output $$PWD/pluginjsonmetadata.xsl $$PLUGINSPEC
pluginspec2json.CONFIG += no_link
moc_header.depends += $$pluginspec2json.output
QMAKE_EXTRA_COMPILERS += pluginspec2json

osx {
    QMAKE_LFLAGS_SONAME = -Wl,-install_name,@rpath/PlugIns/
    QMAKE_LFLAGS += -compatibility_version $$QTCREATOR_COMPAT_VERSION
}

include(rpath.pri)

contains(QT_CONFIG, reduce_exports):CONFIG += hide_symbols

TEMPLATE = lib
CONFIG += plugin plugin_with_soname
linux*:QMAKE_LFLAGS += $$QMAKE_LFLAGS_NOUNDEF

!macx {
    target.path = $$LIGER_BUILD_TREE/$$LIGER_LIBRARY_BASENAME/liger/plugins
    pluginspec.files += $${TARGET}.pluginspec
    pluginspec.path = $$LIGER_BUILD_TREE/$$LIGER_LIBRARY_BASENAME/liger/plugins
    INSTALLS += target pluginspec
}

MIMETYPES = $$_PRO_FILE_PWD_/$${TARGET}.mimetypes.xml
exists($$MIMETYPES):DISTFILES += $$MIMETYPES

TARGET = $$qtLibraryTargetName($$TARGET)

