cmake_minimum_required(VERSION 3.0.0)
project(testing_binary_exponentiation VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()
add_subdirectory(googletest)
add_subdirectory(benchmark)

set(YourExecutableName main.cpp)
add_executable(${PROJECT_NAME} ${YourExecutableName})

target_link_libraries(${PROJECT_NAME} benchmark::benchmark)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)