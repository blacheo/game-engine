cmake_minimum_required(VERSION 3.12)

project(Game_engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Game_engine main.cpp)

# Headers
target_include_directories(Game_engine PUBLIC
	"${PROJECT_SOURCE_DIR}/deps/Vulkan/Include"
	"${PROJECT_SOURCE_DIR}/deps/glm"
	"${PROJECT_SOURCE_DIR}/deps/glfw/include"
)

# Libraries
target_link_directories(Game_engine PUBLIC
	"${PROJECT_SOURCE_DIR}/deps/glfw-build/src/Debug"
	"${PROJECT_SOURCE_DIR}/deps/Vulkan/Lib"
)

target_link_libraries(Game_engine PUBLIC
	"vulkan-1.lib"
	"glfw3.lib"
)

