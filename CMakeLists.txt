cmake_minimum_required(VERSION 3.5)

# Definitions
set(PROJECT_NAME_STR polsl_card_holder)

# Project title and define versioning
project(${PROJECT_NAME_STR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Include paths
set(DEMO_INCLUDES ${DEMO_INCLUDES} ${PROJECT_SOURCE_DIR}/src)
set(DEMO_INCLUDES ${DEMO_INCLUDES} ${PROJECT_SOURCE_DIR}/include)

# Gather all sources except the main entry point
file(GLOB_RECURSE INC_FILES
    include/*.h
)
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)
file(GLOB_RECURSE VENDOR_FILES
    vendor/*.cpp
    vendor/*.h
)

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# Unit tests
add_subdirectory(test)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})

# Build
set(SOURCE_FILES src/main.cpp ${INC_FILES} ${SRC_FILES} ${VENDOR_FILES})
add_executable(polsl_card_holder ${SOURCE_FILES})
target_link_libraries(polsl_card_holder ${Boost_LIBRARIES})
