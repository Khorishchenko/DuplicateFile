cmake_minimum_required(VERSION 3.12) # version can be different

project(SearchDuplicatFile) #name of your project

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)

#Flags passed to the C++ compiler.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 ")

set(SRC_LIST src/main.cpp src/Verifications.h src/SearchDuplicatFile.h src/Directory.h)
set(SRC_LIST_TEST test/mainTest.cpp test/SearchDuplicatFileTests.h test/VerificationsTest.h)

# main Target 
add_executable(
    duplicatFile_App
    ${SRC_LIST}
)

# test Target
add_executable(
    sample
    ${SRC_LIST_TEST}
)

# add src to the include directories for the test target 
target_include_directories(
    sample PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(sample
  GTest::gtest_main
  GTest::gmock_main
)