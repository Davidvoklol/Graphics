cmake_minimum_required(VERSION 4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Graphics)

add_executable(Graphics 
	src/main.cpp
	external/glad/src/glad.c
)

find_package(OpenGL REQUIRED)

add_subdirectory(
	external/glfw
	external/glad
)

target_link_libraries(Graphics PRIVATE
	OpenGL::GL
	glfw
)

target_include_directories(Graphics PRIVATE
	external/glfw/include
	external/glad/include
)
