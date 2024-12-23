cmake_minimum_required(VERSION 3.30)
project(GroceryTracker)

set(CMAKE_CXX_STANDARD 20)

add_executable(GroceryTracker main.cpp
        itemManager.cpp
        itemManager.h)
