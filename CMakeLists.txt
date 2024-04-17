cmake_minimum_required(VERSION 3.23)
project(AERSP424_Project_new)
set(CMAKE_CXX_STANDARD 20)
include_directories(${CMAKE_SOURCE_DIR})
add_executable(${AERSP424_Project_new} project_main.cpp game_function.cpp hand.cpp deck.cpp card.cpp pos_messages.cpp 
function.h hand.h deck.h card.h pos_messages.h)