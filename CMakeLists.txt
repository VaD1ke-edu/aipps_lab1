project(Lab_Rab_1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.6)


set(binary_name Lab_Rab_1)

include_directories(include)
add_library(api1 STATIC src/ConsonantStrategy.cpp)
add_library(api2 STATIC src/VowelStrategy.cpp)
add_executable(${binary_name} src/main.cpp src/CharacterHandler.cpp src/FlyweightFactory.cpp)
target_link_libraries(${binary_name} api1 api2 ncurses panel)
