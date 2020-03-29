cmake_minimum_required(VERSION 3.8)
project(paint_final)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c commands.c commands.h canvas.c canvas.h write.c write.h addDelete.c addDelete.h saveAndload.c saveAndload.h)
add_executable(paint_final ${SOURCE_FILES})