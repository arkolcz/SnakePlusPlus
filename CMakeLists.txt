cmake_minimum_required(VERSION 3.10)

project(Snake VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
    SET(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR/bin"})
endif()

set(
    SNAKE_SOURCE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    CACHE PATH
    "Path to Snake executable source code directory"
)

set(
    SNAKE_INCLUDES_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    CACHE PATH
    "Path to Snake executable headers directory"
)

set(SOURCE_FILES
    "${SNAKE_SOURCE_DIR}/snake.cpp"
    "${SNAKE_SOURCE_DIR}/main.cpp"
    "${SNAKE_SOURCE_DIR}/food.cpp"
    "${SNAKE_SOURCE_DIR}/board.cpp"
    "${SNAKE_SOURCE_DIR}/game.cpp"

    "${SNAKE_INCLUDES_DIR}/snake.h"
    "${SNAKE_INCLUDES_DIR}/game.h"
    "${SNAKE_INCLUDES_DIR}/food.h"
    "${SNAKE_INCLUDES_DIR}/board.h"
)

add_executable(Snake ${SOURCE_FILES})
target_include_directories(Snake PRIVATE ${SNAKE_INCLUDES_DIR})