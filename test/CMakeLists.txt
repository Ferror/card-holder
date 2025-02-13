cmake_minimum_required(VERSION 3.5)

# Project settings
set(PROJECT_UNIT_TESTS_NAME ${PROJECT_NAME_STR}_unit_tests)

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# Gather the header and source files
file(GLOB_RECURSE UNIT_TESTS_SRC_FILES
    ${PROJECT_SOURCE_DIR}/test/*.cpp
)

# Include paths
set(UNIT_TESTS_INCLUDES
    ${PROJECT_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${UNIT_TESTS_INCLUDES})

# Build unit test
add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES} ${SRC_FILES} ${VENDOR_SRC_FILES})
target_link_libraries(${PROJECT_UNIT_TESTS_NAME} ${Boost_LIBRARIES})

enable_testing()
add_test(MainTest ${PROJECT_UNIT_TESTS_NAME})
