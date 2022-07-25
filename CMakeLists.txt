cmake_minimum_required(VERSION 3.21)
project(QAGL LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${PROJECT_SOURCE_DIR}/3rdParty/yaml-cpp")
add_subdirectory("${PROJECT_SOURCE_DIR}/3rdParty/nedrysoft")

find_package(QT
    NAMES
        Qt5
    COMPONENTS
        Widgets
    REQUIRED
)
find_package(Qt5
    COMPONENTS
        Core
        Gui
        Xml
        Widgets
        WebEngine
        WebEngineWidgets
    REQUIRED
)

include_directories(
    AFTER
        "${PROJECT_SOURCE_DIR}/3rdParty/libsass/include"
        "${PROJECT_SOURCE_DIR}/3rdParty/nedrysoft/Ribbon/include"
        "${PROJECT_SOURCE_DIR}/3rdParty/nedrysoft/ThemeSupport/include"
        "${PROJECT_SOURCE_DIR}/3rdParty/nedrysoft/SettingsDialog/include"
)

# hi https://dev.my-gate.net/2021/08/04/understanding-rpath-with-cmake/
# use, i.e. don't skip the full RPATH for the build tree
set(CMAKE_SKIP_BUILD_RPATH FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_executable(
    QAGL
        main.cpp
        launcher/Landing.cpp
        launcher/Landing.h
        launcher/Splash.cpp
        launcher/Splash.h
        launcher/util/Constants.h
        launcher/util/Locales.h
        launcher/resources/SASSProcess.cpp
        launcher/resources/SASSProcess.h
        launcher/resources/gear_image.h
        launcher/resources/stylesheets.h
        launcher/about.h

        launcher/settings/SettingsWindow.cpp launcher/settings/SettingsWindow.h
        launcher/settings/SettingsTab.cpp launcher/settings/SettingsTab.h
        launcher/settings/SettingsTabGeneral.cpp launcher/settings/SettingsTabGeneral.h
        launcher/settings/SettingsTabEnhancements.cpp launcher/settings/SettingsTabEnhancements.h
        launcher/settings/SettingsTabRunner.cpp launcher/settings/SettingsTabRunner.h
        launcher/settings/SettingsTabMore.cpp launcher/settings/SettingsTabMore.h
        launcher/settings/SettingsTabGame.cpp launcher/settings/SettingsTabGame.h
        launcher/settings/SettingsTabDiscord.cpp launcher/settings/SettingsTabDiscord.h
        launcher/settings/util/SettingsGroup.cpp launcher/settings/util/SettingsGroup.h
        launcher/settings/util/SettingsCombo.cpp launcher/settings/util/SettingsCombo.h
        launcher/settings/util/SettingsCheckbox.cpp launcher/settings/util/SettingsCheckbox.h
        launcher/settings/util/SettingsControl.h launcher/settings/util/SettingsControls.h
)


#launcher/Settings.cpp
#launcher/Settings.h
#launcher/ui/widget_baseline.cpp              launcher/ui/widget_baseline.h              launcher/ui/widget_baseline.ui
#launcher/ui/widget_section.cpp               launcher/ui/widget_section.h               launcher/ui/widget_section.ui
#launcher/ui/elements/widget_page.cpp         launcher/ui/elements/widget_page.h         launcher/ui/elements/widget_page.ui
#launcher/ui/elements/widget_combo.cpp        launcher/ui/elements/widget_combo.h        launcher/ui/elements/widget_combo.ui
#launcher/ui/elements/widget_checkbox.cpp     launcher/ui/elements/widget_checkbox.h     launcher/ui/elements/widget_checkbox.ui
#launcher/ui/elements/widget_set_section.cpp  launcher/ui/elements/widget_set_section.h  launcher/ui/elements/widget_set_section.ui
#launcher/ui/pages/IPage.h
#launcher/ui/pages/page_general.h launcher/ui/pages/page_general.cpp
#launcher/ui/pages/page_enhancements.cpp launcher/ui/pages/page_enhancements.h
#launcher/ui/pages/page_wines.cpp launcher/ui/pages/page_wines.h
#launcher/ui/pages/page_dxvks.cpp launcher/ui/pages/page_dxvks.h
#launcher/ui/pages/page_shaders.cpp launcher/ui/pages/page_shaders.h
#launcher/ui/pages/page_env.cpp launcher/ui/pages/page_env.h
#launcher/ui/pages/page_misc.cpp launcher/ui/pages/page_misc.h
#launcher/ui/qml/qml_settings.cpp launcher/ui/qml/qml_settings.h

target_link_libraries(
    QAGL
        yaml-cpp
        Qt5::Gui
        Qt5::Xml
        Qt5::Core
        Qt5::Widgets
        Qt5::WebEngine
        Qt5::WebEngineWidgets
        Ribbon

        "${PROJECT_SOURCE_DIR}/3rdParty/libsass/lib/libsass.a"
)

