cmake_minimum_required(VERSION 3.12)

project(ClientDynamicLibrary)

set (CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MY_CPP_SOURCES RELATIVE 
    ${CMAKE_SOURCE_DIR} "dynamiclibrary/*.cpp"
)

include_directories(
    dynamiclibrary
)

add_library(dynamiclibrary SHARED ${MY_CPP_SOURCES})

add_executable(clientdynamiclibrary 
    clientdynamiclibrary/main.cpp
    clientdynamiclibrary/DynamicLibraryManager.cpp
)

target_link_libraries(clientdynamiclibrary 
    dynamiclibrary)