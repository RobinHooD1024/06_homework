cmake_minimum_required(VERSION 3.21)
project(06_homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(06_homework src/main.cpp)
add_executable(
        My_linear_array_test
        test/My_linear_array_test.cpp
)

add_executable(
        My_Dynamic_array_test
        test/My_Dynamic_array_test.cpp
)

# Build googletest
add_subdirectory(
        "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
        "googletest"
)
target_include_directories(
        My_linear_array_test PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_include_directories(
        My_Dynamic_array_test PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Link test target against gtest libraries
target_link_libraries(
        My_linear_array_test PRIVATE
        gtest gtest_main
)

target_link_libraries(
        My_Dynamic_array_test PRIVATE
        gtest gtest_main
)
