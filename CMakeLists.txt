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

        launcher/about.h

        launcher/resources/gear_image.h
        launcher/resources/stylesheets.h
        launcher/resources/SASSProcess.cpp launcher/resources/SASSProcess.h

        launcher/util/Locales.h
        launcher/util/Constants.h

        launcher/ui/Landing.cpp launcher/ui/Landing.h
        launcher/ui/Splash.cpp launcher/ui/Splash.h

        launcher/ui/settings/SettingsTabs.h
        launcher/ui/settings/SettingsWindow.cpp launcher/ui/settings/SettingsWindow.h
        launcher/ui/settings/SettingsTab.cpp launcher/ui/settings/SettingsTab.h
        launcher/ui/settings/SettingsTabGeneral.cpp launcher/ui/settings/SettingsTabGeneral.h
        launcher/ui/settings/SettingsTabEnhancements.cpp launcher/ui/settings/SettingsTabEnhancements.h
        launcher/ui/settings/SettingsTabRunner.cpp launcher/ui/settings/SettingsTabRunner.h
        launcher/ui/settings/SettingsTabMore.cpp launcher/ui/settings/SettingsTabMore.h
        launcher/ui/settings/SettingsTabGame.cpp launcher/ui/settings/SettingsTabGame.h
        launcher/ui/settings/util/SettingsGroup.cpp launcher/ui/settings/util/SettingsGroup.h
        launcher/ui/settings/util/SettingsButton.cpp launcher/ui/settings/util/SettingsButton.h
        launcher/ui/settings/util/SettingsLabel.cpp launcher/ui/settings/util/SettingsLabel.h
        launcher/ui/settings/util/SettingsCombo.cpp launcher/ui/settings/util/SettingsCombo.h
        launcher/ui/settings/util/SettingsControl.cpp launcher/ui/settings/util/SettingsControl.h
        launcher/ui/settings/util/SettingsCheckbox.cpp launcher/ui/settings/util/SettingsCheckbox.h
        launcher/ui/settings/util/SettingsControl.h launcher/ui/settings/util/SettingsControls.h
)


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

