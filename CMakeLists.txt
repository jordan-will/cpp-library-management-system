cmake_minimum_required(VERSION 3.16)

project(
    LibraryManagementSystem
    VERSION 1.0
    DESCRIPTION "Simple library management system in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    library_core 
    src/Book.cpp
    src/User.cpp
    src/Library.cpp
    src/LoanManager.cpp
    src/CSVStorage.cpp
    src/Storage.cpp
    src/App.cpp
)

target_include_directories(
    library_core 
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(
    library_app
    src/main.cpp
)

target_link_libraries(library_app library_core)