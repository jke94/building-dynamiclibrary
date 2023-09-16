cmake_minimum_required(VERSION 3.12)

project(ClientDynamicLibrary)

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE MY_CPP_SOURCES RELATIVE 
    ${CMAKE_SOURCE_DIR} "dynamiclibrary/*.cpp"
)

file(GLOB_RECURSE MY_CPP_LOGGER RELATIVE 
    ${CMAKE_SOURCE_DIR} "logger/*.cpp"
)

include_directories(
    dynamiclibrary
    logger
)

add_library(dynamiclibrary SHARED ${MY_CPP_SOURCES})
add_library(logger SHARED ${MY_CPP_LOGGER})

add_executable(clientdynamiclibrary 
    clientdynamiclibrary/main.cpp
    clientdynamiclibrary/DynamicLibraryManager.cpp
)

target_link_libraries(clientdynamiclibrary 
    dynamiclibrary
    logger
)