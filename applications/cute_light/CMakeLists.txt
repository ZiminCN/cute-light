cmake_minimum_required(VERSION 3.20.0)

set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../)

include_directories(${CMAKE_CURRENT_LIST_DIR}/Core/inc)
include_directories(${CMAKE_CURRENT_LIST_DIR}/User/inc)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(cute_light)

# include(${CMAKE_CURRENT_LIST_DIR}/software_version/version.cmake)

file(GLOB USER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/User/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/User/src/*.cpp)
file(GLOB CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Core/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/Core/src/*.cpp)

target_compile_definitions(app PRIVATE)
target_sources(app PRIVATE ${USER_SOURCES} ${CORE_SOURCES})

zephyr_compile_options(-Werror -Wno-unused-function)
