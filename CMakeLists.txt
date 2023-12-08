cmake_minimum_required(VERSION 3.14)

project(LifeGame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

set(PROJECT_SOURCE_DIR Source)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/*.cpp)

set(QML_SOURCES Qml/Qml.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LifeGame
        MANUAL_FINALIZATION
        ${HEADERS}
        ${SOURCES}
        ${QML_SOURCES}
    )
else()
    add_executable(LifeGame
        ${HEADERS}
        ${SOURCES}
        ${QML_SOURCES}
    )
endif()

target_link_libraries(LifeGame
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

set_target_properties(LifeGame PROPERTIES
    WIN32_EXECUTABLE TRUE
)

install(TARGETS LifeGame
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(LifeGame)
    qt_finalize_executable(LifeGame)
endif()
