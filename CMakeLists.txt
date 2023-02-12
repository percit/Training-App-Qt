cmake_minimum_required(VERSION 3.14)

project(Training-app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Core Quick Sql Positioning Network PositioningQuick  OpenGL REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Sql Positioning Network PositioningQuick  OpenGL REQUIRED)

enable_testing()
#add_subdirectory(test) testy wgl nie dzialaja, trzeba naprawic cmake w

set(
  PROJECT_SOURCES
  main.cpp
  database.cpp
  DataBaseModel.cpp
  firebase_database.cpp
  qml/qml.qrc
)

if(ANDROID)
add_library(
  Training-app SHARED
  ${PROJECT_SOURCES}
)
else()
add_executable(
  Training-app
  ${PROJECT_SOURCES}
)
endif()


target_compile_definitions(
  Training-app
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)
target_link_libraries(
  Training-app
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::Sql
)

