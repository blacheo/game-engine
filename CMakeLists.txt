cmake_minimum_required(VERSION 3.12)
# Set Project Name and Version
project(GAME_ENGINE VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Do not build GFLW test files
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Set GLFW Path
set(GLFW_PATH "D:\\Game Dev\\3rd Party Assets\\glfw")
add_subdirectory(${GLFW_PATH} ./GLFW-BUILD)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(mainConfig.h.in mainConfig.h)

# add the executable
add_executable(GAME_ENGINE main.cpp)

# Comes after project() and add_executable()
target_link_libraries(GAME_ENGINE glfw)