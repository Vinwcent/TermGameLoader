cmake_minimum_required(VERSION 3.14)
project(CMakeProject)

find_package(GTest REQUIRED)
find_package(Curses REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)


# Project Library
set(PROJECT_SRC)
set(PROJECT_H)

list(APPEND PROJECT_SRC
	src/GameLoader.cpp
	src/GameInitializer.cpp
	)
list(APPEND PROJECT_H
	src/GameLoader.hpp
	src/GameInitializer.hpp
	)
set(ALL_PROJECT_FILES ${PROJECT_SRC} ${PROJECT_H})

add_library(ProjectLib ${ALL_PROJECT_FILES})
target_include_directories(ProjectLib PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR} ${CURSES_INCLUDE_DIR})
target_link_libraries(ProjectLib ${CURSES_LIBRARIES})

# Project executable

set(EXECUTABLE run_project)
add_executable(${EXECUTABLE} src/main.cpp)
target_link_libraries(${EXECUTABLE} ProjectLib)

# Tests
enable_testing()

set(TESTS_SOURCE)

list(APPEND TESTS_SOURCE
	tests/test.cpp
	)

set(TESTS_EXECUTABLE run_test)

add_executable(${TESTS_EXECUTABLE} ${TESTS_SOURCE})
target_link_libraries(${TESTS_EXECUTABLE} ProjectLib GTest::gtest_main)
target_include_directories(${TESTS_EXECUTABLE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${GTEST_INCLUDE_DIRS})
# add_test(NAME Rendering COMMAND launchTestRendering)
