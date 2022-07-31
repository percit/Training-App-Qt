include_directories(${QtQml_INCLUDE_DIRS})
add_definitions(${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

add_executable(
  unit_tests
  test1.cpp
)
target_link_libraries(
  unit_tests
  Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::Sql
  gtest_main
)

add_test(
        NAME unit_tests
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)
