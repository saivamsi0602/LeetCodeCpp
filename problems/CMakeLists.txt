project(Problems)

# Get all source files in the sources directory
file(GLOB SUBDIRECTORY_SOURCES "sources/*.cpp")

add_library(${PROJECT_NAME} source/test.cpp)

# Include the directory containing the header files
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)