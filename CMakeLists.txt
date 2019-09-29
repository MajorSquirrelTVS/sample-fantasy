cmake_minimum_required(VERSION 3.14)
set(EXECUTABLE_NAME "sample_fantasy")
project(${EXECUTABLE_NAME})

set(CMAKE_CXX_STANDARD 11)

# If you want to link static SFML libraries
set(SFML_STATIC_LIBRARIES TRUE)

if(ARCH STREQUAL "x64")
    message(STATUS "SFML_DIR: ${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/x64/lib/cmake/SFML")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/x64/lib/cmake/SFML")
else()
    message(STATUS "SFML_DIR: ${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/x86/lib/cmake/SFML")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/x86/lib/cmake/SFML")
endif()

find_package(SFML 2.5 COMPONENTS audio graphics network system window REQUIRED)

add_executable(${EXECUTABLE_NAME} src/Main.cpp)

target_link_libraries(${EXECUTABLE_NAME} sfml-audio sfml-graphics sfml-network sfml-system sfml-window)