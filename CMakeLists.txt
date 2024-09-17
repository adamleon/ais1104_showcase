cmake_minimum_required(VERSION 3.12)
project(ais1104_showcase)

# Add your source files here
set(SOURCES
    src/main.cpp
    src/motor.cpp
    # src/module.cpp
)

# Add your executable target
add_executable(simulator ${SOURCES})

target_include_directories(simulator PUBLIC include/)