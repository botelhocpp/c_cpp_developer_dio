cmake_minimum_required(VERSION 3.7.0)
project("GCalc" C)

set(GCALC_DIR ${PROJECT_SOURCE_DIR})

set(CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK "gtk+-3.0")
        
add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})

add_subdirectory(${GCALC_DIR}/app)
add_subdirectory(${GCALC_DIR}/module)
add_subdirectory(${GCALC_DIR}/view)
