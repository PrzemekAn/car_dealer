cmake_minimum_required(VERSION 3.14)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)

option(BUILD_TESTS              "Builds all tests (gtest required)"         ON)
option(BUILD_UNIT_TESTS         "Builds unit tests (gtest required)"        ON)

project(car_dealer LANGUAGES CXX)

set (EXE_SRC 
        src/main.cpp
    )

set (LIB_SRC
        src/app.cpp
        src/file_handler.cpp
        src/car_dealer.cpp
        src/user_interface.cpp
        )


add_executable(car_dealer ${EXE_SRC})
add_library(lib_car_dealer SHARED ${LIB_SRC})

target_include_directories(car_dealer PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_include_directories(lib_car_dealer PUBLIC ${CMAKE_SOURCE_DIR}/includes)

target_link_libraries(car_dealer lib_car_dealer)


if (${BUILD_TESTS})
    enable_testing()
     
    if (${BUILD_UNIT_TESTS})
        add_subdirectory("tests/unit_tests")
    endif()
endif()
