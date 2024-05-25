find_package(GTest REQUIRED)

# include_directories(${CMAKE_SOURCE_DIR}/src)

# add_library(my_database_library
#     ../src/DataBaseModel.cpp
# )

set(TEST1 "test_sqlite_database")
add_executable(${TEST1}
    ../tests/test_sqlite_database.cpp
)

target_link_libraries(${TEST1}
    GTest::GTest
    GTest::Main
    Qt6::Core
    Qt6::Sql
    # my_database_library
)

set(TEST2 "test2")
add_executable(${TEST2}
    ../tests/test2.cpp
)

target_link_libraries(${TEST2}
    GTest::GTest
    GTest::gmock
    GTest::Main
    Qt6::Core
)

add_test(
    NAME Test1
    COMMAND ${TEST1} --gtest_output=xml:reports/test_report-${TEST1}.xml
)

add_test(
    NAME Test2
    COMMAND ${TEST2} --gtest_output=xml:reports/test_report-${TEST2}.xml
)