cmake_minimum_required(VERSION 3.14)

project(UTests LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

enable_testing()

set(SRC 
        tests_main.cpp
        tests_file_handler.cpp
        tests_car_dealer.cpp
        tests_user_interface.cpp
        tests_app.cpp
        )

add_executable(UTests ${SRC})

find_package(GTest)

target_link_libraries(
        UTests
        lib_car_dealer 
        GTest::gtest_main
        GTest::gtest)
        
configure_file(${CMAKE_SOURCE_DIR}/data/cars.csv ${CMAKE_BINARY_DIR}/tests/unit_tests/cars.csv)

