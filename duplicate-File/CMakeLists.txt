cmake_minimum_required(VERSION 3.12) # version can be different

project(my_cpp_project) #name of your project

# TODO:: Практика использования Google Test Framework

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

find_library(PTHREAD_LIBRARY pthread)
find_library(PCRE_LIBRARY pcre)

include_directories(include)
set(CMAKE_CXX_STANDARD 17)

#Flags passed to the C++ compiler.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 ")

# main Target 
add_executable(
    app
    src/main.cpp
    src/functions_app.h
)

target_link_libraries(
    app PRIVATE
)

# test Target
add_executable(
    tests_app
    test/tests_app.cpp
)

# add src to the include directories for the test target 
target_include_directories(
    tests_app PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Linc target against gtest libraries 
target_link_libraries(
    tests_app PRIVATE
    gtest gtest_main
)

# Linc target against gmock libraries 
target_link_libraries(
    tests_app PRIVATE
    gtest gtest_main gmock
)