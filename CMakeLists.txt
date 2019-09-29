cmake_minimum_required(VERSION 3.12)
set(EXECUTABLE_NAME "sample_fantasy")
project(${EXECUTABLE_NAME})

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        message(STATUS "SFML_DIR: ${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/x64/lib/cmake/SFML")
        set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/x64/lib/cmake/SFML")
    else()
        message(STATUS "SFML_DIR: ${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/x86/lib/cmake/SFML")
        set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/x86/lib/cmake/SFML")
    endif()
    # If you want to link static SFML libraries
    set(SFML_STATIC_LIBRARIES TRUE)
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "SFML_DIR: ${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/linux/lib/cmake/SFML")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/linux/lib/cmake/SFML")
else()
    message(ERROR "Could not find SFML library according to operating system")
endif()

find_package(SFML 2.5 COMPONENTS audio graphics network system window REQUIRED)

add_executable(${EXECUTABLE_NAME}
        src/Main.cpp
        src/Sprite.cpp
        src/TileMap.cpp
        )

include_directories(${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${EXECUTABLE_NAME} sfml-audio sfml-graphics sfml-network sfml-system sfml-window)

#target_include_directories(${EXECUTABLE_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/resources)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)