cmake_minimum_required(VERSION 2.8)
project(Space_Invaders)
find_package(OpenCV REQUIRED)
add_executable(Space_Invaders main.cpp)
target_link_libraries(Space_Invaders ${OpenCV_LIBS})

find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Space_Invaders ${SFML_LIBRARIES})

target_link_libraries(Space_Invaders pthread)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++14)
endif()