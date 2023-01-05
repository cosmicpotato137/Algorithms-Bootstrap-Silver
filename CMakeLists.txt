cmake_minimum_required(VERSION 3.10) # cmake version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

project(Algorithms-Bootstrap-Silver) # VS solution name

# find all source files 
file(GLOB SOURCES "src/*.cpp" "src/*.h")

# add sources to the excecutable
add_executable(Algorithms-Bootstrap-Silver ${SOURCES})
