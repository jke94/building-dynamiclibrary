cmake_minimum_required(VERSION 3.12)

project(ClientDynamicLibrary)

set (CMAKE_CXX_STANDARD 20)

include_directories(
    ${PROJECT_SOURCE_DIR}/../dynamiclibrary
)

add_executable(Main 
    main.cpp
)

target_link_libraries(Main 
    dynamiclibrary)