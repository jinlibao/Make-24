#
# CMakeLists.txt - 2020-06-11 19:34
#
# Copyright © 2020 Libao Jin <jinlibao@outlook.com>
# Distributed under terms of the MIT license.
#

cmake_minimum_required (VERSION 2.8)

# projectname is the same as the main-executable
project(src)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions('-g')
add_definitions('-Wall')
add_definitions('-std=c++17')

add_executable(make_24 make_24.cc)
add_executable(game24 game24.cc)
add_executable(game24_2 game24_2.cc)

# add_custom_target(${PROJECT_NAME}-symlink ALL ln --force -s ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/${PROJECT_NAME} DEPENDS ${PROJECT_NAME})
# set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_SOURCE_DIR}/${PROJECT_NAME})
