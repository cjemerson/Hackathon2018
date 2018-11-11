#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(Hackathon2018)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14 -Wall -O3")

include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES 
  src/main.cpp
  src/TextParser.cpp
  src/Node.cpp
)

# Define sources and executable
set(EXECUTABLE_NAME Hackathon2018)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})