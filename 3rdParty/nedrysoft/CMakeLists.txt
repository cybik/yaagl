#
# Copyright (C) 2020 Adrian Carpenter
#
# This file is part of Pingnoo (https://github.com/nedrysoft/pingnoo)
#
# An open-source cross-platform traceroute analyser.
#
# Created by Adrian Carpenter on 27/03/2020.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

project(Nedrysoft)

# set any variables required for libraries
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PINGNOO_PLATFORM_ARCH "x86_64")
else()
    set(PINGNOO_PLATFORM_ARCH "x86")
endif()

set(PINGNOO_BINARY_DIR "${CMAKE_BINARY_DIR}/nedrysoft/bin")
set(PINGNOO_BINARY_ROOT "${PINGNOO_BINARY_DIR}/${PINGNOO_PLATFORM_ARCH}/${CMAKE_BUILD_TYPE}")
set(PINGNOO_LIBRARIES_BINARY_DIR "${PINGNOO_BINARY_ROOT}")
message("${PINGNOO_ROOT_DIR} :: ${PINGNOO_BINARY_ROOT} :: ${PINGNOO_LIBRARIES_BINARY_DIR}")

set(NEDRYSOFT_COMPONENTSYSTEM_COMPONENTVIEWER ON)
set(NEDRYSOFT_SETTINGSDIALOG_LIBRARY_DIR ${PINGNOO_LIBRARIES_BINARY_DIR})
set(NEDRYSOFT_COMPONENTSYSTEM_LIBRARY_DIR ${PINGNOO_LIBRARIES_BINARY_DIR})
set(NEDRYSOFT_RIBBON_LIBRARY_DIR ${PINGNOO_LIBRARIES_BINARY_DIR})
set(NEDRYSOFT_THEMESUPPORT_LIBRARY_DIR ${PINGNOO_LIBRARIES_BINARY_DIR})
set(NEDRYSOFT_THEMESUPPORT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/ThemeSupport/include)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(${PROJECT_SOURCE_DIR}/ComponentSystem/src)
include_directories(${PROJECT_SOURCE_DIR}/ComponentSystem/include)
include_directories(${PROJECT_SOURCE_DIR}/SettingsDialog/include)


# libraries to build

add_subdirectory(ThemeSupport)
add_subdirectory(ComponentSystem)
add_subdirectory(Ribbon)
add_subdirectory(SettingsDialog)

