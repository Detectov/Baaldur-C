cmake_minimum_required(VERSION 3.10)  

project(Baaldur-C)  

add_executable(${PROJECT_NAME} main.cpp menu.cpp Character.cpp adventure.cpp enemy.cpp) 

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
