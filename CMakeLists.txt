cmake_minimum_required(VERSION 3.14)

# set the project name
project(VectorTest)

# Designate the include directories
include_directories(include)

# Use Glob for cxx sources
file(GLOB SOURCES src/*.cxx)

# Set up include and linking for blas++ 
include_directories( /opt/slate/include )
set ( PROJECT_LINK_LIBS libblaspp.so )
link_directories( /opt/slate/lib )

# Completed executable
add_executable(mathVector ${SOURCES})
target_link_libraries(mathVector ${PROJECT_LINK_LIBS})