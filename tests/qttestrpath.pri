linux-* {
    QMAKE_RPATHDIR += $$LIGER_BUILD_TREE/$$LIGER_LIBRARY_BASENAME/liger
    QMAKE_RPATHDIR += $$LIGER_BUILD_TREE/bin
    QMAKE_RPATHDIR += $$LIGER_PLUGIN_PATH
    QMAKE_RPATHDIR += $$LIGER_BUILD_TREE/bin

    LIGER_PLUGIN_RPATH = $$join(QMAKE_RPATHDIR, ":")

    QMAKE_LFLAGS += -Wl,-z,origin \'-Wl,-rpath,$${LIGER_PLUGIN_RPATH}\'
} else:macx {
    QMAKE_LFLAGS += -Wl,-rpath,\"$$LIGER_BIN_PATH/../\"
}
