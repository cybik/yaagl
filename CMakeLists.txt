cmake_minimum_required(VERSION 3.21)
project(QAGL LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${PROJECT_SOURCE_DIR}/3rdParty/yaml-cpp")


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
        "${PROJECT_SOURCE_DIR}/3rdParty/wribbon/src"
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
        launcher/Settings.cpp
        launcher/Settings.h
        launcher/Splash.cpp
        launcher/Splash.h
        launcher/util/Constants.h
        launcher/util/Locales.h
        launcher/resources/SASSProcess.cpp
        launcher/resources/SASSProcess.h
        launcher/resources/gear_image.h
        launcher/resources/stylesheets.h
        launcher/about.h

        launcher/ui/widget_baseline.cpp launcher/ui/widget_baseline.h launcher/ui/widget_baseline.ui
        launcher/ui/widget_page.cpp launcher/ui/widget_section.h  launcher/ui/widget_section.ui
        launcher/ui/elements/widget_page.cpp      launcher/ui/elements/widget_page.h      launcher/ui/elements/widget_page.ui
        launcher/ui/elements/widget_combo.cpp     launcher/ui/elements/widget_combo.h     launcher/ui/elements/widget_combo.ui
        launcher/ui/elements/widget_checkbox.cpp  launcher/ui/elements/widget_checkbox.h  launcher/ui/elements/widget_checkbox.ui
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
        "${PROJECT_SOURCE_DIR}/3rdParty/libsass/lib/libsass.a"
)

