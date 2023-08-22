# Specify the minimum version.
cmake_minimum_required(VERSION 3.9)

# Specify the project info.
project(dynamiclibrary VERSION 1.0.0 DESCRIPTION "Demo of dynamic library")

# Declare the library target.
add_library(${PROJECT_NAME} SHARED
    ../Divide.cpp
    ../Add.cpp
    ../dllmain.cpp
    ../Multiply.cpp
    ../Observer.cpp
    ../ObserverApiImplementation.cpp
    ../OperationsApiImplementation.cpp
    ../pch.cpp
    ../Subject.cpp
    ../Subtract.cpp

)

# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE source)

# Set the version property.
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set the shared object version property to the project's major version.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Set the public header property to the one with the actual API.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER source/convert.h)