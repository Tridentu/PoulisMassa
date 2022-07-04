add_executable(poulismassa)

target_sources(poulismassa PRIVATE
    main.cpp
    poulismassawindow.cpp
    poulismassaview.cpp
)

ecm_qt_declare_logging_category(poulismassa
    HEADER poulismassadebug.h
    IDENTIFIER POULISMASSA
    CATEGORY_NAME "poulismassa"
)
kconfig_add_kcfg_files(poulismassa PoulisMassaSettings.kcfgc)
ki18n_wrap_ui(poulismassa
    poulismassaview.ui
    settings.ui
)

target_link_libraries(poulismassa
    KF5::CoreAddons
    KF5::I18n
    KF5::XmlGui
    KF5::ConfigWidgets
    KF5::DBusAddons
    KF5::Crash
    Qt5::Widgets
)

install(TARGETS poulismassa ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS com.github.tridentu.poulismassa.desktop  DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES com.github.tridentu.poulismassa.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
install(FILES poulismassaui.rc DESTINATION ${KDE_INSTALL_KXMLGUI5DIR}/poulismassa)
