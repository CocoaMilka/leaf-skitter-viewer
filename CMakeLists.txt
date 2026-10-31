cmake_minimum_required(VERSION 3.16)
project(leafskitter LANGUAGES C)
set(CMAKE_C_STANDARD 11)

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

# Create your game executable target as usual
add_executable(
	${PROJECT_NAME} 
	src/main.c
)

# Link to the actual SDL3 library.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
