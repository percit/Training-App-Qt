include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

qt5_add_resources(QT_RESOURCES ../qml/qml.qrc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11 -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations -Wno-unused-variable")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT "Training-App")
project(${PROJECT})


if(NOT DEFINED HEADERS)
    file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../inc/*.h)
endif()

if(NOT DEFINED SOURCES)
    file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
endif()

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

if(ANDROID)
add_library(
  ${PROJECT} SHARED ${HEADERS} ${SOURCES} ${QT_RESOURCES}
)
else()
add_executable(
  ${PROJECT} ${HEADERS} ${SOURCES} ${QT_RESOURCES}
)
endif()


# target_compile_definitions(
#   ${PROJECT}
#   PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
# )
target_link_libraries(
  ${PROJECT}
  Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::Sql
)
