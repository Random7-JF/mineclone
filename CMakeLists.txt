# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define your project name
project(MineClone CXX)

# Set the output directory for executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

find_package(SDL3 CONFIG REQUIRED)

# Set the C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED TRUE) # Make sure the standard is strictly enforced
# set(CMAKE_CXX_EXTENSIONS OFF)      # Don't allow GNU extensions

# Add compiler flags
# We can set these globally for all targets or per-target
# This is a common way to add warnings for debug builds
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -g)
else()
    add_compile_options(-Wall -Wextra) # Keep warnings for release too
endif()

# Define the source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Discover all source files recursively
# This command automatically finds all .cpp files under the given directory
# and adds them to the 'APP_SOURCES' variable.
file(GLOB_RECURSE APP_SOURCES "${SOURCE_DIR}/*.cpp")

# Define the executable target
# The executable will be named 'my_program'
# It will be built from all files listed in APP_SOURCES
add_executable(mineclone ${APP_SOURCES})

# Add include directories
# This tells the compiler where to look for header files.
# INTERFACE makes this property propagate to targets that link against this one (though not applicable for an executable itself).
# Here, we just add the 'src' directory. CMake automatically handles subdirectories for #includes.
target_include_directories(mineclone PUBLIC ${SOURCE_DIR})
target_link_libraries(mineclone PRIVATE SDL3::SDL3)
# Optional: Install target (if you want to install your built executable)
install(TARGETS mineclone DESTINATION bin)