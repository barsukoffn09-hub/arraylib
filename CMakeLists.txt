
cmake_minimum_required(VERSION 3.10)

project(arraylib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(arraylib STATIC arraylib.cpp)

target_include_directories(arraylib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)


add_executable(app main.cpp)
target_link_libraries(app PRIVATE arraylib)


include(CTest)

if (BUILD_TESTING)
    add_executable(test_unit tests/test_arraylib.cpp)
    target_link_libraries(test_unit PRIVATE arraylib)
    target_compile_options(test_unit PRIVATE -UNDEBUG)
    add_test(NAME unit COMMAND test_unit)

    add_executable(test_integration tests/test_integration.cpp)
    target_link_libraries(test_integration PRIVATE arraylib)
    target_compile_options(test_integration PRIVATE -UNDEBUG)
    add_test(NAME integration COMMAND test_integration)
endif()
