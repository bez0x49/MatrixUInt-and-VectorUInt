cmake_minimum_required(VERSION 3.18.0)
project(Lab4 
    VERSION 0.1.0 
    LANGUAGES CXX
    DESCRIPTION "Lab for overloading operators and associated array"
)

set(CMAKE_CXX_STANDARD 17)

add_library(VectorUInt "./src/VectorUInt.cpp")
target_include_directories(
    VectorUInt PRIVATE include   
)
target_precompile_headers(
    VectorUInt PRIVATE "include/stdafx.h"
)

add_library(MatrixUInt "./src/MatrixUInt.cpp")
target_include_directories(MatrixUInt 
    PRIVATE include
)
target_link_libraries(MatrixUInt 
    PRIVATE VectorUInt 
)
target_precompile_headers(
    MatrixUInt PRIVATE "include/stdafx.h"
)

add_executable(main "./src/main.cpp")
target_include_directories(main PRIVATE include)
target_link_libraries(main PRIVATE MatrixUInt)
target_precompile_headers(
    main PRIVATE "include/stdafx.h"
)