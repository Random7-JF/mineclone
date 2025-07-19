# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define your project name
project(MineClone CXX)
find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image REQUIRED)

# Set the output directory for executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_CXX_STANDARD 17)
# Add compiler flags
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -g)
else()
    add_compile_options(-Wall -Wextra) # Keep warnings for release too
endif()
# Define the source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
# Discover all source files recursively
file(GLOB_RECURSE APP_SOURCES "${SOURCE_DIR}/*.cpp")
# Define the executable target
add_executable(mineclone ${APP_SOURCES})
target_include_directories(mineclone PUBLIC ${SOURCE_DIR})
target_link_libraries(mineclone PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
install(TARGETS mineclone DESTINATION bin)