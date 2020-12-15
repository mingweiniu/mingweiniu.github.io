#edit from 《Linux C/C++視窗程式設計－使用GTK+與Qt》

cmake_minimum_required(VERSION 2.6)
project(gtkDemo C)

find_package(PkgConfig REQUIRED)

PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(gtkDemo gtkDemo.c)
target_link_libraries(gtkDemo ${GTK3_LIBRARIES})
