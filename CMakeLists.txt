cmake_minimum_required(VERSION 2.8)

find_package(Qt5 COMPONENTS Core Quick Sql Positioning Network PositioningQuick OpenGL REQUIRED)

add_subdirectory(src)
# add_subdirectory(test)
# enable_testing()
