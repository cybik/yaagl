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
)
target_link_libraries(
    QAGL
        Qt5::Core
        Qt5::Gui
        Qt5::Xml
        Qt5::Widgets
        Qt5::WebEngine
        Qt5::WebEngineWidgets
)

