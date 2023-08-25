cmake_minimum_required(VERSION 3.12)

project(ClientDynamicLibrary)

set (CMAKE_CXX_STANDARD 20)

add_subdirectory(
    dynamiclibrary
)

add_executable(Main main.cpp)

target_link_libraries(Main 
    dynamiclibrary)