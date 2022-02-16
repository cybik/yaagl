cmake_minimum_required(VERSION 3.21)
project(QAGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

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
)

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
)
target_link_libraries(
    QAGL
        Qt5::Core
        Qt5::Gui
        Qt5::Xml
        Qt5::Widgets
        Qt5::WebEngine
        Qt5::WebEngineWidgets
        "${PROJECT_SOURCE_DIR}/3rdParty/libsass/lib/libsass.a"
)

