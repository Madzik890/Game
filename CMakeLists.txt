# CMakeLists.txt

# CMake version that the current computer is using
cmake_minimum_required(VERSION "3.16")

# name of the project
project(Game)

option(BUILD_TESTS "Build test programs" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(lib${PROJECT_NAME}
                            src/randomengine.cpp                            
                            src/srandengine.cpp
                            src/gamemanager.cpp)   
#target_include_directories(${PROJECT_NAME}) 
target_link_libraries(lib${PROJECT_NAME})

add_executable(${PROJECT_NAME}
                                src/main.cpp)
target_link_libraries(${PROJECT_NAME} lib${PROJECT_NAME})

#if(BUILD_TESTS)
#  add_executable(${PROJECT_NAME}_mofset_tests                 
#                                tests/mofset_ua_tests.cpp)   
#  target_link_libraries(${PROJECT_NAME}_mofset_tests ${PROJECT_NAME})
#endif(BUIDL_TESTS)