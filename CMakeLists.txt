cmake_minimum_required(VERSION 2.8)
project(Address_book)

set(INCLUDEDIR ${PROJECT_BINARY_DIR}/../include)
include_directories(${INCLUDEDIR})
aux_source_directory(${PROJECT_BINARY_DIR}/../src SRC_LIST)

set(SOURCE 
    run.cpp 
    ${SRC_LIST}
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
add_executable(aaa ${SOURCE})


#################GTEST#####################
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googleTest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googleTest)
enable_testing()

add_executable(
    mytest
    ${SRC_LIST}
    ${PROJECT_BINARY_DIR}/../test/cmenu_interface_test.cpp
    ${PROJECT_BINARY_DIR}/../test/caddress_interface_test.cpp
)

target_link_libraries(
    mytest
    GTest::gtest_main
)
include(GoogleTest)

gtest_discover_tests(mytest)
###########################################